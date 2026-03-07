<?php
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
