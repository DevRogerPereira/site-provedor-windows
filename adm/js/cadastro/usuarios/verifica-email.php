<?php
	require_once("../../../inc/guard_ajax.php"); // auth: nao abre banco sem login

	include("../../../conexao.php");

	//Recebe os elementos via GET
	$campo = $_GET['usuario'];
	
	$valida = mysqli_num_rows(mysqli_query($conexao, "SELECT * FROM usuarios_dados WHERE usuario = '$campo'"));

	//Aqui voc� verifica em seu banco de dados, se o login j� foi cadastrado.
	
	if( $valida >= 1 )
		//Se o login j� existir voc� exibe false
		echo 'false';
	else
		//Se o login n�o existir voc� exibe true
		echo 'true';
	exit();
