<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
	
    // Limite de arquivos
    if (count($_FILES['files']['name']) > 1) {
        echo json_encode(['success' => false, 'error' => 'Você pode enviar no máximo 1 foto.']);
        exit;
    }

    // Conexão ao banco de dados MySQL
	include("../../../conexao.php");
    
    $conn = new mysqli($server, $user, $senha, $banco);
    if ($conn->connect_error) {
        die('Erro de conexão: ' . $conn->connect_error);
    }

    $id = $_POST['id'];
    $targetDir = "../../../../images/";
    $allowTypes = ['jpg', 'jpeg', 'png'];

    for ($i = 0; $i < count($_FILES['files']['name']); $i++) {
        $fileName = basename($_FILES["files"]["name"][$i]);
        $targetFilePath = $targetDir . uniqid() . '-slide-' . str_replace(' ', '-', mb_strtolower($fileName));
		$targetDir_tamanho = mb_strlen($targetDir, 'UTF-8');
        $dados_targetFilePath = substr($targetFilePath, $targetDir_tamanho);
        $fileType = pathinfo($targetFilePath, PATHINFO_EXTENSION);

        // Verificar tipo de arquivo
        if (in_array($fileType, $allowTypes)) {
            // Redimensionar imagem
            $tempFilePath = $_FILES["files"]["tmp_name"][$i];
            resizeImage($tempFilePath, $fileType, 1920);

            // Mover o arquivo para o servidor
            if (move_uploaded_file($tempFilePath, $targetFilePath)) {
                // Registrar no banco de dados

				$stmt = $conn->prepare("UPDATE slides SET foto = ? WHERE id = ?");
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

// Função para redimensionar a imagem
function resizeImage($file, $fileType, $maxWidth) {
    list($width, $height) = getimagesize($file);

    if ($width > $maxWidth) {
        $ratio = $maxWidth / $width;
        $newWidth = $maxWidth;
        $newHeight = $height * $ratio;
        $newImage = imagecreatetruecolor($newWidth, $newHeight);

        if ($fileType === 'jpg' || $fileType === 'jpeg') {
            $source = imagecreatefromjpeg($file);
            imagecopyresampled($newImage, $source, 0, 0, 0, 0, $newWidth, $newHeight, $width, $height);
            imagejpeg($newImage, $file, 80);
        } elseif ($fileType === 'png') {
            $source = imagecreatefrompng($file);
            imagecopyresampled($newImage, $source, 0, 0, 0, 0, $newWidth, $newHeight, $width, $height);
            imagepng($newImage, $file, 8);
        }

        imagedestroy($source);
        imagedestroy($newImage);
    }
}
?>