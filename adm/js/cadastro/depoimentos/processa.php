<?php

	require_once("../../../conexao.php");
	require_once("../../../inc/funcoes.php");

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{

		//$url_ft = md5(uniqid(time()));
		//$data = date("Y-m-d H:i:s");
		//$user_id = $_SESSION["usuarioID"];
		$url1 = utf8_decode(getPost('nome'));
		$url = removeAcentos($url1, '-') . md5(uniqid(time()));

		//$data_ini1 = str_replace('/', '-', getPost('data_ini'));
		//$data_ini = date('Y-m-d', strtotime($data_ini1));

		if( !getPost('id') )
		{

			$query = mysqli_query($conexao,"INSERT INTO depoimentos VALUES (NULL, 'N', '".$url."', '".getPost('nome')."', '".getPost('intro')."', '".getPost('depoimento')."')");
			//$query_id = mysqli_insert_id($conexao);
	
			echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/depoimentos\"</script>";
		}
		else
		{

			$query = mysqli_query($conexao,"UPDATE depoimentos SET url = '".$url."', nome = '".getPost('nome')."', intro = '".getPost('intro')."', depoimento = '".getPost('depoimento')."' WHERE id = '".getPost('id')."'");
			//$query_id = mysqli_insert_id($conexao);
	
			echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/depoimentos\"</script>";
		}

	}
	function getPost( $key ){
		return isset( $_POST[ $key ] ) ? filter( $_POST[ $key ] ) : null;
	}
	function filter( $var ){
		return $var;
	}
?>