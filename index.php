<?php
// ============ FULL PAGE CACHE - ELIMINA 100% DA CARGA NO IIS ============
// O banco MySQL compartilhado da Locaweb aceita no maximo 30 conexoes simultaneas.
// Este cache serve HTML pronto SEM abrir conexao (HIT = zero carga no banco).
// O ponto critico e o "stampede": quando o cache expira e varios visitantes chegam
// juntos, todos renderizariam de uma vez e abririam 30+ conexoes -> banco cai.
// Por isso: enquanto 1 worker regenera, os demais recebem a copia anterior (stale)
// ou esperam um pouco — nunca dezenas renderizando ao mesmo tempo.

// Rota estatica de imagem redimensionada (/hash/LxA/arquivo) nao passa pelo cache de pagina
$req_uri_cache = isset($_SERVER['REQUEST_URI']) ? $_SERVER['REQUEST_URI'] : '/';

require_once "libs/Mobile_Detect.php";
$detect = new Mobile_Detect;

$cache_dir_page = __DIR__ . '/cache/';
if (!is_dir($cache_dir_page)) { @mkdir($cache_dir_page, 0777, true); }

// Cache key inclui URL + tipo de dispositivo (mobile/desktop servem HTML diferente).
// Ignora query strings de rastreamento (utm_*, gclid, fbclid...) para nao criar
// milhares de chaves diferentes p/ a mesma pagina (o que zeraria o cache e faria
// todo mundo cair como MISS no banco).
$uri_path = parse_url($req_uri_cache, PHP_URL_PATH);
if (!is_string($uri_path) || $uri_path === '') { $uri_path = $req_uri_cache; }
$uri_query = parse_url($req_uri_cache, PHP_URL_QUERY);
$query_cache = '';
if (is_string($uri_query) && $uri_query !== '') {
    parse_str($uri_query, $q_arr);
    foreach (array('utm_source','utm_medium','utm_campaign','utm_term','utm_content','gclid','fbclid','gad_source','msclkid','_ga','ref') as $lixo) {
        unset($q_arr[$lixo]);
    }
    if (!empty($q_arr)) { ksort($q_arr); $query_cache = '?' . http_build_query($q_arr); }
}

$device_type = $detect->isMobile() ? 'mobile' : 'desktop';
$cache_key = md5($uri_path . $query_cache . $device_type);
$cache_file = $cache_dir_page . $cache_key . '.html';
$cache_lock = $cache_file . '.lock';
$cache_ttl = 600; // 10 minutos

// Cache so vale para leitura (GET/HEAD). POST (ex.: fallback de formulario) sempre
// processa e nunca e servido/gravado do cache.
$metodo_http = isset($_SERVER['REQUEST_METHOD']) ? $_SERVER['REQUEST_METHOD'] : 'GET';
$cache_habilitado = ($metodo_http === 'GET' || $metodo_http === 'HEAD');

if (!$cache_habilitado) {
    header('X-Cache: BYPASS');
    $cache_file = null; // desliga leitura e gravacao de cache neste request
}

$cache_existe = $cache_habilitado && file_exists($cache_file);
$cache_idade = $cache_existe ? (time() - filemtime($cache_file)) : PHP_INT_MAX;

// 1) Cache fresco: serve direto, SEM tocar no banco.
if ($cache_existe && $cache_idade < $cache_ttl) {
    header('Content-Type: text/html; charset=utf-8');
    header('X-Cache: HIT');
    readfile($cache_file);
    exit;
}

// 2) Cache vencido/inexistente: apenas 1 worker por URL regenera (pega o lock).
//    O flock e liberado automaticamente quando o processo termina (inclusive em erro fatal),
//    entao nunca fica travado. (POST/HEAD-nao-cacheavel pula direto para renderizar.)
$lock_fp = $cache_habilitado ? @fopen($cache_lock, 'c') : false;
$tenho_lock = $lock_fp && @flock($lock_fp, LOCK_EX | LOCK_NB);

if ($cache_habilitado && !$tenho_lock) {
    // Outro worker ja esta regenerando esta pagina.
    if ($cache_existe) {
        // Serve a copia anterior (um pouco vencida) — protege o banco de um pico de conexoes.
        header('Content-Type: text/html; charset=utf-8');
        header('X-Cache: STALE');
        readfile($cache_file);
        if ($lock_fp) { fclose($lock_fp); }
        exit;
    }
    // Cache frio (ex.: logo apos deploy): espera curta o outro worker gravar, depois serve.
    // Teto de 6s, MUITO abaixo dos 90s do FastCGI — nunca trava o visitante.
    $esperou = 0;
    while ($esperou < 6000000) {
        usleep(150000); // 150ms
        $esperou += 150000;
        clearstatcache(true, $cache_file);
        if (file_exists($cache_file) && (time() - filemtime($cache_file)) < $cache_ttl) {
            header('Content-Type: text/html; charset=utf-8');
            header('X-Cache: HIT-WAIT');
            readfile($cache_file);
            if ($lock_fp) { fclose($lock_fp); }
            exit;
        }
    }
    // Estourou a espera: renderiza mesmo assim (fail-open) para nao deixar o visitante sem pagina.
}

// Cache miss: processar normalmente e capturar o output
if ($cache_habilitado) { header('X-Cache: MISS'); }
ob_start();

// bd
include("adm/conexao.php");

// funcoes
include("inc/funcoes.php");

?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
<?php include("inc/seo.php") ?>

</head>

<body id="site">
<?php

if(isset($include_cabecalho)) {
	
	include($include_cabecalho);
	
}

if(isset($include_centro)) {
	
	include($include_centro);
	
}

if(isset($include_rodape)) {
	
	include($include_rodape);
	
}
?>
<?php
if(isset($conexao)) {
    mysqli_close($conexao);
}

// Fecha o HTML DENTRO do buffer, senao as paginas cacheadas ficam sem </body></html>
echo "</body>\n</html>";

// ============ SALVAR FULL PAGE CACHE ============
// So salva cache se o banco estava conectado — senao uma pagina quebrada
// (renderizada durante uma queda do MySQL) ficaria cacheada por 10 minutos
$html_output = ob_get_clean();
if (isset($cache_file) && !empty($html_output) && strlen($html_output) > 100 && !empty($db_conectado)) {
    // Escrita atomica: grava em arquivo temporario e renomeia, para nunca servir
    // um .html pela metade a outro visitante durante a gravacao.
    $tmp_cache = $cache_file . '.' . getmypid() . '.tmp';
    if (@file_put_contents($tmp_cache, $html_output, LOCK_EX) !== false) {
        if (!@rename($tmp_cache, $cache_file)) {
            @unlink($tmp_cache);
            @file_put_contents($cache_file, $html_output, LOCK_EX);
        }
    }
}
// Libera o lock de regeneracao (se este worker o detinha)
if (isset($lock_fp) && $lock_fp) { @flock($lock_fp, LOCK_UN); @fclose($lock_fp); }
echo $html_output;
?>