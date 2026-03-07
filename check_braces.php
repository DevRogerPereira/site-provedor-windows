<?php
$file = 'inc/funcoes.php';
$lines = file($file);
$total = count($lines);
echo "Total de Linhas no servidor: $total\n\n";

$start = max(0, $total - 20);
echo "Ultimas 20 linhas do arquivo:\n";
for($i = $start; $i < $total; $i++) {
    echo ($i+1) . ": " . rtrim($lines[$i]) . "\n";
}
?>
