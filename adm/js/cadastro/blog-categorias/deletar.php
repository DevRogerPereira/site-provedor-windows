<?php

	require_once("../../../conexao.php");

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{
			$query = mysqli_query($conexao,"UPDATE blog_categorias SET del = 'S' WHERE id = '".getPost('id')."'");

			echo "<script type=\"text/javascript\">window.location.reload()</script>";

		if( !getPost('id') )
		{
			
		}
		else
		{
			
		}

	}
	function getPost( $key ){
		return isset( $_POST[ $key ] ) ? filter( $_POST[ $key ] ) : null;
	}
	function filter( $var ){
		return $var;//faça o tratamento
	}
?>
