<?php

	require_once("../../../conexao.php");
	require_once("../../../inc/funcoes.php");

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{

		$url1 = utf8_decode(getPost('nome'));
		$url = removeAcentos(mb_strtolower($url1), '-');

		if(getPost('id') == false)
		{

			$query = mysqli_query($conexao,"INSERT INTO blog_categorias VALUES (NULL, 'N', '".$url."', '".getPost('nome')."')");
			//$query_id = mysqli_insert_id($conexao);
	
			echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/blog-categorias\"</script>";
		}
		else
		{

			$query = mysqli_query($conexao,"UPDATE blog_categorias SET url = '".$url."', nome = '".getPost('nome')."' WHERE id = '".getPost('id')."'");
			//$query_id = mysqli_insert_id($conexao);
	
			echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/blog-categorias\"</script>";
		}

	}
	function getPost( $key ){
		return isset( $_POST[ $key ] ) ? filter( $_POST[ $key ] ) : null;
	}
	function filter( $var ){
		return $var;
	}
?>