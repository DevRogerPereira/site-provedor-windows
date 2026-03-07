<?php
$start = microtime(true);
$server = "linknet_2026.mysql.dbaas.com.br";
$banco = "linknet_2026";
$user = "linknet_2026";
$senha = "Emf@844888";

echo "Resolving DNS...<br>";
$ip_server = gethostbyname($server);
echo "IP: " . $ip_server . " - Time: " . round((microtime(true) - $start)*1000) . " ms<br>";

echo "Connecting to MySQL...<br>";
$conexao = new mysqli($ip_server, $user, $senha, $banco);
if (mysqli_connect_errno()) {
    echo "Erro: " . mysqli_connect_error() . "<br>";
} else {
    echo "Connected. Time: " . round((microtime(true) - $start)*1000) . " ms<br>";
}

echo "Query 1...<br>";
$q1 = mysqli_query($conexao, "SELECT * FROM tb_config LIMIT 1");
echo "Done. Time: " . round((microtime(true) - $start)*1000) . " ms<br>";

echo "Query 2...<br>";
$q2 = mysqli_query($conexao, "SELECT COUNT(id) FROM planos LIMIT 1");
echo "Done. Time: " . round((microtime(true) - $start)*1000) . " ms<br>";
?>
