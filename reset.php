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
echo "Tudo limpo.";
?>
