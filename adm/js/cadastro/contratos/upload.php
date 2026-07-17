<?php
	require_once("../../../inc/guard_ajax.php"); // auth: nao abre banco sem login
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
	
    // Limite de arquivos
    if (count($_FILES['files']['name']) > 1) {
        echo json_encode(['success' => false, 'error' => 'Você pode enviar no máximo 1 documento.']);
        exit;
    }

    // Conexão ao banco de dados MySQL
	include("../../../conexao.php");
    
    // Reutiliza a conexao ja aberta em conexao.php (evita conexao MySQL duplicada)
    $conn = $conexao;
    if (empty($db_conectado)) {
        die('Erro de conexão: ' . mysqli_connect_error());
    }

    $id = $_POST['id'];
    $targetDir = "../../../../images/";
    $allowTypes = ['pdf', 'doc', 'docx'];

    for ($i = 0; $i < count($_FILES['files']['name']); $i++) {

		$fileName = basename($_FILES["files"]["name"][$i]);
        $targetFilePath = $targetDir . uniqid() . '-' . str_replace(' ', '-', mb_strtolower($fileName));
		$targetDir_tamanho = mb_strlen($targetDir, 'UTF-8');
        $dados_targetFilePath = substr($targetFilePath, $targetDir_tamanho);
        $fileType = pathinfo($targetFilePath, PATHINFO_EXTENSION);

        // Verificar tipo de arquivo
        if (in_array($fileType, $allowTypes)) {
            // Redimensionar imagem
            $tempFilePath = $_FILES["files"]["tmp_name"][$i];

            // Mover o arquivo para o servidor
            if (move_uploaded_file($tempFilePath, $targetFilePath)) {
                // Registrar no banco de dados

				$stmt = $conn->prepare("UPDATE contratos SET foto = ? WHERE id = ?");
				if ($stmt) {
					$stmt->bind_param("si", $dados_targetFilePath, $id);
					$stmt->execute();
					$stmt->close();
				}

            }
        }
    }

    $conn->close();
    echo json_encode(['success' => true]);
}

?>