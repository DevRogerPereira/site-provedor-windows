<?php

	require_once("../../../conexao.php");
	require_once("../../../inc/funcoes.php");

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{

		//$data = date("Y-m-d H:i:s");
		$idcat = addslashes(getPost('idcat'));
		$status = addslashes(getPost('status'));
		$data_ini = addslashes(getPost('data_ini'));
		$status = addslashes(getPost('status'));
		$tag = addslashes(getPost('tag'));
		$titulo = addslashes(getPost('titulo'));
		$detalhes = addslashes(getPost('detalhes'));

		if ($data_ini == true) {
			
			$data_ini1 = str_replace('/', '-', $data_ini);
			$data_ini = date('Y-m-d H:i:s', strtotime($data_ini1));
			
		} else {

			$data_ini = date("Y-m-d H:i:s");
			
		}

		if(getPost('id') == false)
		{

			if ($titulo == true) {
	
				$url = removeAcentos(utf8_decode(mb_strtolower($titulo)), '-') . "-" . substr(md5(uniqid(time())),-5);
				
			} else {
				
				$url = substr(md5(uniqid(time())), 0, 6);
				
			}

			$sql = "INSERT INTO blog VALUES (NULL, 'N', '". $status ."', '". $url ."', '".$data_ini ."', '". $idcat ."', '".getPost('cat_id_2')."', '".getPost('cat_id_3')."', '".getPost('cat_id_4')."', '". $tag ."', '". $titulo ."', '". $detalhes ."', '".getPost('foto')."')";
			$resultado = mysqli_query($conexao, $sql);
			$query_id = mysqli_insert_id($conexao);

			if ($resultado) {

				echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/blog-img/".$query_id."\"</script>";
					
			} else {
					
				echo "";
					
			}
			
		}
		else
		{

			$dados_blog = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM blog WHERE id = '".getPost('id')."'"));

			if ($dados_blog->titulo == $titulo) {
				
				$url = removeAcentos(utf8_decode(mb_strtolower($dados_blog->url)), '-');
				
			} else {
	
				$url = removeAcentos(utf8_decode(mb_strtolower($titulo)), '-') . "-" . substr(md5(uniqid(time())),-3);
				
			}

			$query = mysqli_query($conexao,"UPDATE blog SET status = '". $status ."', url = '". $url ."', data_ini = '".$data_ini ."', cat_id_1 = '". $idcat ."', cat_id_2 = '".getPost('cat_id_2')."', cat_id_3 = '".getPost('cat_id_3')."', cat_id_4 = '".getPost('cat_id_4')."', tag = '". $tag ."', titulo = '". $titulo ."', detalhes = '". $detalhes ."' WHERE id = '".getPost('id')."'");

			if ($query) {

				echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/blog\"</script>";
					
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