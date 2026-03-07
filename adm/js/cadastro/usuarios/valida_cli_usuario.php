<?php

	include("../../../conexao.php");

	$campo = $_GET['usuario'];
	
	$valida = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM usuarios_dados WHERE usuario = '".$campo."'"));

	if( $valida == 0 )
	
		echo 'false';
		
	else

		echo 'true';
		
	exit();
