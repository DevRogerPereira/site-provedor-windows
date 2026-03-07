<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);
include("adm/conexao.php");

$sql = "SELECT COUNT(*) AS total FROM planos_localidades WHERE del = 'N'";
$res = mysqli_query($conexao, $sql);
if (!$res) die("Erro SQL: " . mysqli_error($conexao));
$total = (int) mysqli_fetch_assoc($res)['total'];

echo "Total de localidades no DB: " . $total . "<br>";

$q = mysqli_query($conexao, "SELECT url FROM planos_localidades WHERE del='N' LIMIT 1");
$cidade = $q ? (mysqli_fetch_assoc($q)['url'] ?? null) : 'Erro na query';
echo "URL da unica localidade: " . $cidade . "<br>";
echo "URL do site definida no conexao.php (urlsite) = " . $urlsite . "<br>";
?>
