<?php

	require_once("../../../conexao.php");
	require_once("../../../inc/funcoes.php");

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{

		//$url_ft = md5(uniqid(time()));
		//$data = date("Y-m-d H:i:s");
		//$user_id = $_SESSION["usuarioID"];
		//$url1 = utf8_decode(getPost('nome'));
		//$url = removeAcentos($url1, '-');

		//$data_ini1 = str_replace('/', '-', getPost('data_ini'));
		//$data_ini = date('Y-m-d', strtotime($data_ini1));

		if( !getPost('id') )
		{

			//$query_carrinho = mysqli_query($conexao,"INSERT INTO posts_carrinho VALUES (NULL, 'N', '".$url_ft."', '".$_SESSION["posts_comprar"]."', '".getPost('categorias')."', '1', '".getPost('usuario_id')."', '".getPost('termos')."')");
			//$query = mysqli_query($conexao,"UPDATE posts_carrinho SET cat_id = '".getPost('categorias')."' WHERE ses_id = '".getPost('ses_id')."'");

				$ativo = getPost('locl_id');
			 
				foreach($ativo as $valor){
					
					$url = substr(md5(uniqid(time())), 0, 6);
					$sql = "INSERT INTO contratos VALUES (NULL, 'N', '".$valor."', '".getPost('cat_id')."', '".getPost('titulo')."', '".getPost('foto')."', '".getPost('foto_m')."')";
					$resultado = mysqli_query($conexao, $sql);
					$query_id = mysqli_insert_id($conexao);
					
				}

				if ($resultado) {

					echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/contratos-img/".$query_id."\"</script>";
					
				} else {
					
					echo "";
					
				}
			
		}
		else
		{

			$query = mysqli_query($conexao,"UPDATE contratos SET locl_id = '".getPost('locl_id')."', titulo = '".getPost('titulo')."' WHERE id = '".getPost('id')."'");

			if ($query) {

				echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/contratos-img/".getPost('id')."\"</script>";
					
			} else {
					
				echo "Erro";
					
			}

		}

	}
	function getPost( $key ){
		return isset( $_POST[ $key ] ) ? filter( $_POST[ $key ] ) : null;
	}
	function filter( $var ){
		return $var;
	}
?>