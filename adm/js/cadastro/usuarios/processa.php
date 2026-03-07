<?php

	require_once("../../../conexao.php");

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{

		$url_ft = md5(uniqid(time()));
		$data = date("Y-m-d H:i:s");
		//$user_id = $_SESSION["usuarioID"];

		//if (isset(getPost('senha')) == true) {
		if (getPost('senha') != "") {
			
			$nsenha = addslashes(md5(getPost('senha')));
			$nsenha1 = $nsenha;
			$nsenhabk1 = getPost('senha');
			
		} else {
			
			$dados_usuarios = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM usuarios_dados WHERE id = '".getPost('id')."'"));
			$nsenha1 = $dados_usuarios['senha'];
			$nsenhabk1 = $dados_usuarios['senhabk'];
		}

		if( !getPost('id') )
		{
			
			$query = mysqli_query($conexao,"INSERT INTO usuarios_dados VALUES (NULL, 'S', 'N', '".$data."', '".$url_ft."', '".getPost('nome_cliente')."', '".getPost('nome_responsavel')."', '".getPost('cidade')."', '".getPost('foto')."', '".getPost('usuario')."', '".$nsenha."', '".getPost('senha')."', '1')");
			//$query_id = mysqli_insert_id($conexao);

			echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/usuarios\"</script>";
			
		}
		else
		{

			$query = mysqli_query($conexao,"UPDATE usuarios_dados SET nome_cliente = '".getPost('nome_cliente')."', nome_responsavel = '".getPost('nome_responsavel')."', cidade = '".getPost('cidade')."', usuario = '".getPost('usuario')."', senha = '".$nsenha1."', senhabk = '".$nsenhabk1."' WHERE id = '".getPost('id')."'");
			//$query_id = mysqli_insert_id($conexao);
	
			echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/usuarios\"</script>";
			
		}

	}
	function getPost( $key ){
		return isset( $_POST[ $key ] ) ? filter( $_POST[ $key ] ) : null;
	}
	function filter( $var ){
		return $var;//faça o tratamento
	}
?>