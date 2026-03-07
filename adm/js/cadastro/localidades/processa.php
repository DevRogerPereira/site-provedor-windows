<?php

	require_once("../../../conexao.php");

function removeAcentos($string, $slug = false) {

	if(mb_detect_encoding($string.'x', 'UTF-8, ISO-8859-1') == 'UTF-8'){
		$string = utf8_decode(mb_strtolower($string, 'UTF-8'));
	}

	$ascii['a'] = range(224, 230);
	$ascii['e'] = range(232, 235);
	$ascii['i'] = range(236, 239);
	$ascii['o'] = array_merge(range(242, 246), array(240, 248));
	$ascii['u'] = range(249, 252);
	$ascii['b'] = array(223);
	$ascii['c'] = array(231);
	$ascii['d'] = array(208);
	$ascii['n'] = array(241);
	$ascii['y'] = array(253, 255);
	foreach ($ascii as $key=>$item) {
    $acentos = '';
    foreach ($item AS $codigo) $acentos .= chr($codigo);
    $troca[$key] = '/['.$acentos.']/i';
	}
	$string = preg_replace(array_values($troca), array_keys($troca), $string);

	if ($slug) {
    $string = preg_replace('/[^a-z0-9]/i', $slug, $string);
    $string = preg_replace('/' . $slug . '{2,}/i', $slug, $string);
    $string = trim($string, $slug);
  }
  return $string;
}

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{

		//$url_ft = md5(uniqid(time()));
		//$data = date("Y-m-d H:i:s");
		//$user_id = $_SESSION["usuarioID"];
		//$url_tmp = utf8_decode(getPost('nome'));
		//$url1 = strtolower($url_tmp);
		$url = removeAcentos(getPost('nome'), '-');

		//$data_ini1 = str_replace('/', '-', getPost('data_ini'));
		//$data_ini = date('Y-m-d', strtotime($data_ini1));

		if( !getPost('id') )
		{

			$query = mysqli_query($conexao,"INSERT INTO planos_localidades VALUES (NULL, 'N', '".$url."', '".getPost('nome')."', '".getPost('endereco')."', '".getPost('cep')."', '".getPost('telefone')."', '".getPost('telefone2')."', '".getPost('funcionamento')."')");
			//$query_id = mysqli_insert_id($conexao);
	
			if($query)
			{
				echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/localidades\"</script>";
				
			} else {
				
				echo "Erro";
			}
			
		} else { 

			$query = mysqli_query($conexao,"UPDATE planos_localidades SET nome = '".getPost('nome')."', endereco = '".getPost('endereco')."', cep = '".getPost('cep')."', telefone = '".getPost('telefone')."', telefone2 = '".getPost('telefone2')."', funcionamento = '".getPost('funcionamento')."' WHERE id = '".getPost('id')."'");
			//$query_id = mysqli_insert_id($conexao);
	
			if($query)
			{
				echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/localidades\"</script>";
				
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