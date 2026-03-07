<?php
$file = 'inc/funcoes.php';
$lines = file($file);
$out = "Lines 195 to 215 on SERVER:\n";
for($i = 194; $i < min(215, count($lines)); $i++) {
    $out .= ($i+1) . ": " . $lines[$i];
}
echo $out;
?>
