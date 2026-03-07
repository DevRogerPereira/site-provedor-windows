<?php

	require_once("../../../conexao.php");
	require_once("../../../inc/funcoes.php");

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{

		if(getPost('valor') == true) {

			$preco1 = str_replace(",", ".",getPost('valor'));
			$preco = number_format($preco1, 2, '.', '');

		}

		if(getPost('id') == false) {

			if(getPost('locl_id') == true) {

				$ativo = getPost('locl_id');
			 
				foreach($ativo as $valor){
					
					$url = substr(md5(uniqid(time())), 0, 6);
					$sql = "INSERT INTO planos VALUES (NULL, 'N', '".$url."', '".$valor."', '".getPost('tipo_id')."', '".getPost('cat_id')."', '".getPost('titulo')."', '".getPost('download')."', '".getPost('upload')."', '".$preco."', '".getPost('vnt_1')."', '".getPost('vnt_2')."', '".getPost('vnt_3')."', '".getPost('vnt_4')."', '".getPost('vnt_5')."', '".getPost('vnt_6')."', '".getPost('vnt_7')."', '".getPost('vnt_8')."', '".getPost('vnt_9')."', '".getPost('vnt_10')."', '".getPost('vnt_11')."', '".getPost('vnt_12')."', '".getPost('vnt_13')."', '".getPost('vnt_14')."', '".getPost('vnt_15')."', '".getPost('detalhes')."', '".getPost('foto')."')";
					$resultado = mysqli_query($conexao, $sql);
					
				}

			} else {
				
				$resultado = "";
				
			}
			
				if ($resultado == true) {

					echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/". getPost('url_redir') ."\"</script>";
					
				} else {
					
					echo "Escolha uma localidade.";
					
				}
			
		} else {

			$dados_locl_id = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && locl_id = '".getPost('locl_id')."' && tipo_id = '".getPost('tipo_id')."'"));
			
			if ($dados_locl_id['id'] == true) {

				$query_destaque = mysqli_query($conexao,"UPDATE planos SET tipo_id = '' WHERE id = '".$dados_locl_id['id']."'");
					
			} else {
			}

			$query = mysqli_query($conexao,"UPDATE planos SET titulo = '".getPost('titulo')."', locl_id = '".getPost('locl_id')."', tipo_id = '".getPost('tipo_id')."', cat_id = '".getPost('cat_id')."', download = '".getPost('download')."', upload = '".getPost('upload')."', valor = '".$preco."', vnt_1 = '".getPost('vnt_1')."', vnt_2 = '".getPost('vnt_2')."', vnt_3 = '".getPost('vnt_3')."', vnt_4 = '".getPost('vnt_4')."', vnt_5 = '".getPost('vnt_5')."', vnt_6 = '".getPost('vnt_6')."', vnt_7 = '".getPost('vnt_7')."', vnt_8 = '".getPost('vnt_8')."', vnt_9 = '".getPost('vnt_9')."', vnt_10 = '".getPost('vnt_10')."', vnt_11 = '".getPost('vnt_11')."', vnt_12 = '".getPost('vnt_12')."', vnt_13 = '".getPost('vnt_13')."', vnt_14 = '".getPost('vnt_14')."', vnt_15 = '".getPost('vnt_15')."', detalhes = '".getPost('detalhes')."' WHERE id = '".getPost('id')."'");

			//$query_id = mysqli_insert_id($conexao);
	
			if ($query) {

				echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/". getPost('url_redir') ."\"</script>";
					
			} else {
					
				echo "Erro";
					
			}

			if (getPost('tipo_id') == true) {

				echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/". getPost('url_redir') ."\"</script>";
				/*
				echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/planos-img/".getPost('id')."\"</script>";
				*/
			} else {
					
				echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/". getPost('url_redir') ."\"</script>";
					
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