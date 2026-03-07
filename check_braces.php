<?php
echo "Diretorio Atual: " . __DIR__ . "\n";
echo "Listagem:\n";
$dirs = glob('*', GLOB_ONLYDIR);
foreach($dirs as $d) {
    if ($d == "divinopolis" || $d == "inc") {
        echo "=> $d\n";
    }
}
echo "Tenta ler divinopolis/inc/funcoes.php:\n";
if (file_exists("divinopolis/inc/funcoes.php")) {
    $lines = file("divinopolis/inc/funcoes.php");
    echo "Existe! Linhas: " . count($lines) . "\n";
} else {
    echo "Nao existe.\n";
}
?>
