<?php

	include("../../../../conexao.php");
	
    $pasta = "../../../../../images/";
    
    $permitidos = array(".jpg",".jpeg",".png");
    
    if(isset($_POST)) {
		
        $nome_imagem    = $_FILES['imagem']['name'];
        $tamanho_imagem = $_FILES['imagem']['size'];
		$id_registro = addslashes($_POST['id']);
		$data = date("Y-m-d H:i:s");
        
        $ext = strtolower(strrchr($nome_imagem,"."));
        
        if(in_array($ext,$permitidos)){
            
            $tamanho = round($tamanho_imagem / 5120);
            
            if($tamanho < 5120){
			
                $nome_atual = "argontec-soldagem-e-inspecao-por-ensaios-nao-destrutivos-e-curitiba-pr-" . md5(uniqid(time())).$ext;
                $nome_atual_dados = "argontec-soldagem-e-inspecao-por-ensaios-nao-destrutivos-e-curitiba-pr-" . md5(uniqid(time()));
				
                $tmp = $_FILES['imagem']['tmp_name'];
                
                if(move_uploaded_file($tmp,$pasta.$nome_atual)){
				
					$arquivo = "../../../../../images/" . $nome_atual;

					//$query = mysqli_query($conexao,"INSERT INTO obras VALUES (NULL, 'N', '".$data."', '".$url."', '".$id_registro."', '".$id_tipo."', '".$nome_atual_dados."', '".$nome_atual."')");
					$query = mysqli_query($conexao,"UPDATE atuacao SET foto = '".$nome_atual."' WHERE id = '".$id_registro."'");
				
					$url_ft = md5(uniqid(time()));
			
					echo "Arquivo enviado:<br><img src=\"http://argontec.com.br/".$url_ft."/480x165/".$nome_atual."\">";
					/*
                    echo "<script language=\"javascript\">window.location=\"http://riachinho.mg.gov.br/adm/".$redir_url."\"</script>";
					*/
				} else {
					
                    echo "Falha ao enviar";
                }
            } else {
                echo "O arquivo deve ser de no máximo 5MB";
            }
        }else{
            echo "Somente são aceitos arquivos do tipo Imagem";
        }
    }else{
        echo "Selecione uma imagem";
        exit;
    }
   
?>