<?php
// Diagnostico do ambiente (protegido por token). NAO expoe phpinfo completo.
// Serve para decidir, com dados reais, se vale migrar o handler PHP p/ ganhar OPcache/JIT.
// Uso: /_diag/check.php?token=Dg9Emf844888xZ
$TOKEN = "Dg9Emf844888xZ";
if (!isset($_GET['token']) || $_GET['token'] !== $TOKEN) {
    header("HTTP/1.1 404 Not Found");
    exit;
}
header('Content-Type: text/plain; charset=utf-8');

echo "PHP version: " . PHP_VERSION . "\n";
echo "SAPI: " . php_sapi_name() . "\n";
echo "OS: " . PHP_OS . "\n\n";

$opcache = function_exists('opcache_get_status');
echo "OPcache extensao carregada: " . ($opcache ? "SIM" : "NAO") . "\n";
if ($opcache) {
    $st = @opcache_get_status(false);
    echo "  opcache.enable: " . (ini_get('opcache.enable') ? "on" : "off") . "\n";
    echo "  habilitado em runtime: " . (is_array($st) && !empty($st['opcache_enabled']) ? "SIM" : "NAO") . "\n";
    if (is_array($st) && isset($st['memory_usage'])) {
        echo "  memoria usada: " . round($st['memory_usage']['used_memory'] / 1048576, 1) . " MB\n";
        echo "  scripts em cache: " . ($st['opcache_statistics']['num_cached_scripts'] ?? '?') . "\n";
    }
}
echo "\n";

echo "APCu carregado: " . (function_exists('apcu_enabled') && apcu_enabled() ? "SIM" : "NAO") . "\n";
echo "JIT disponivel (opcache.jit): " . (ini_get('opcache.jit') !== false ? ini_get('opcache.jit') : "n/d") . "\n\n";

echo "realpath_cache_size: " . ini_get('realpath_cache_size') . "\n";
echo "memory_limit: " . ini_get('memory_limit') . "\n";
echo "max_execution_time: " . ini_get('max_execution_time') . "\n";
echo "zlib.output_compression: " . ini_get('zlib.output_compression') . "\n";
echo "mysqli disponivel: " . (function_exists('mysqli_connect') ? "SIM" : "NAO") . "\n";
