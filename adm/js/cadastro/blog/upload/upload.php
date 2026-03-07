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
            
            if($tamanho < 5120) {
			
                $nome_atual = "blog-" . substr(md5(uniqid(time())), 0, 6).$ext;
                $nome_atual_dados = "blog-" . substr(md5(uniqid(time())), 0, 6);
				
                $tmp = $_FILES['imagem']['tmp_name'];
                
                if(move_uploaded_file($tmp,$pasta.$nome_atual)){
				
					$arquivo = "../../../../../images/" . $nome_atual;

					$query = mysqli_query($conexao,"UPDATE blog SET foto = '".$nome_atual."' WHERE id = '".$id_registro."'");
				
					$url_ft = md5(uniqid(time()));
			
					//echo "Arquivo enviado.";
					echo "Arquivo enviado:<br><img src=\"".$urlsite."/".$url_ft."/680x300/".$nome_atual."\">";

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