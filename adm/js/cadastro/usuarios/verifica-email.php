<?php

	include("../../../conexao.php");

	//Recebe os elementos via GET
	$campo = $_GET['usuario'];
	
	$valida = mysqli_num_rows(mysqli_query($conexao, "SELECT * FROM usuarios_dados WHERE usuario = '$campo'"));

	//Aqui você verifica em seu banco de dados, se o login já foi cadastrado.
	
	if( $valida >= 1 )
		//Se o login já existir você exibe false
		echo 'false';
	else
		//Se o login não existir você exibe true
		echo 'true';
	exit();
