<?php

	include("../../../conexao.php");

	$campo = isset($_GET['usuario']) ? addslashes($_GET['usuario']) : '';

	$valida = 0;
	if ($campo != '') {
		$query = mysqli_query($conexao,"SELECT id FROM usuarios_dados WHERE del = 'N' && usuario = '".$campo."' LIMIT 1");
		$valida = $query ? mysqli_num_rows($query) : 0;

		// Fallback: usuarios antigos que so existem no banco legado
		if ($valida == 0) {
			require_once("../../../inc/inicial_seguranca.php");
			$legado = conectaBancoLegado();
			if ($legado) {
				$query = mysqli_query($legado,"SELECT id FROM usuarios_dados WHERE usuario = '".$campo."' LIMIT 1");
				$valida = $query ? mysqli_num_rows($query) : 0;
				mysqli_close($legado);
			}
		}
	}

	if( $valida == 0 )

		echo 'false';

	else

		echo 'true';

	exit();
