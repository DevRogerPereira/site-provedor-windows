<?php
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
