<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

echo "Teste de conexao...<br>";

include("adm/conexao.php");

echo "Conectou ok com: " . mysqli_get_host_info($conexao);
?>
