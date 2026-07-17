<?php
// Valvula de seguranca manual: mata conexoes 'Sleep' presas que seguram slots
// contra o limite de 30 conexoes do MySQL compartilhado da Locaweb.
// Protegido por token para NAO ser acionavel por qualquer visitante.
// Uso: https://SEUDOMINIO/kill_sleep.php?token=Lk9x2Qw7Emf844888
$TOKEN = "Lk9x2Qw7Emf844888";
if (!isset($_GET['token']) || $_GET['token'] !== $TOKEN) {
    header("HTTP/1.1 404 Not Found");
    exit;
}

include("adm/conexao.php");

$result = mysqli_query($conexao, "SHOW PROCESSLIST");
if ($result) {
    while ($row = mysqli_fetch_assoc($result)) {
        if ($row['Command'] == 'Sleep' && $row['Time'] > 10) {
            $process_id = $row['Id'];
            mysqli_query($conexao, "KILL $process_id");
            echo "Killed Sleep process $process_id <br>";
        }
    }
    echo "Limpeza concluida.";
} else {
    echo "Erro ao buscar processos: " . mysqli_error($conexao);
}
mysqli_close($conexao);
?>
