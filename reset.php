<?php
// Limpa caches apos deploy. Protegido por token para um visitante nao ficar
// derrubando o cache (o que forcaria todos a renderizar e estressaria o banco).
$TOKEN = "Rst7Emf844888xQ2";
if (!isset($_GET['token']) || $_GET['token'] !== $TOKEN) {
    header("HTTP/1.1 404 Not Found");
    exit;
}

if (function_exists('opcache_reset')) {
    opcache_reset();
    echo "OPcache resetado.\n";
} else {
    echo "OPcache inativo.\n";
}
if (function_exists('apcu_clear_cache')) {
    apcu_clear_cache();
    echo "APCu cache resetado.\n";
}

// Limpa tambem o Full Page Cache (cache/*.html) para o deploy entrar em vigor na hora
$apagados = 0;
$arquivos = @glob(__DIR__ . '/cache/*.html');
if (is_array($arquivos)) {
    foreach ($arquivos as $arquivo) {
        if (@unlink($arquivo)) {
            $apagados++;
        }
    }
}
echo "Page cache: " . $apagados . " arquivo(s) removido(s).\n";

echo "Tudo limpo.";
?>
