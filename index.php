<?php 
// ============ FULL PAGE CACHE - ELIMINA 100% DA CARGA NO IIS ============
// No Windows IIS compartilhado, cada requisição PHP abre 25+ queries MySQL.
// Isso esgota o pool FastCGI e derruba o servidor (ERR_ADDRESS_UNREACHABLE).
// Solução: Servir o HTML completo de um arquivo estático no segundo acesso em diante.
$cache_dir_page = __DIR__ . '/cache/';
if (!is_dir($cache_dir_page)) { @mkdir($cache_dir_page, 0777, true); }

// Montar chave de cache baseada na URL completa (cidade, pagina, etc)
$cache_key = md5($_SERVER['REQUEST_URI'] . ($_SERVER['QUERY_STRING'] ?? ''));
$cache_file = $cache_dir_page . $cache_key . '.html';
$cache_ttl = 600; // 10 minutos - tempo para refletir mudanças no painel admin

// Se o cache existe e é recente, servir direto SEM TOCAR no PHP/MySQL
if (file_exists($cache_file) && (time() - filemtime($cache_file)) < $cache_ttl) {
    header('Content-Type: text/html; charset=utf-8');
    header('X-Cache: HIT');
    readfile($cache_file);
    exit;
}

// Cache miss: processar normalmente e capturar o output
ob_start();

require_once "libs/Mobile_Detect.php";
$detect = new Mobile_Detect;

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

// ============ SALVAR FULL PAGE CACHE ============
$html_output = ob_get_clean();
if (isset($cache_file) && !empty($html_output) && strlen($html_output) > 100) {
    @file_put_contents($cache_file, $html_output, LOCK_EX);
}
echo $html_output;
?>
</body>
</html>