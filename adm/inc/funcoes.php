<?php

//HTACESS
$id = isset($_GET['id']) ? $_GET['id'] : "";
$ht_url = isset($_GET['url']) ? $_GET['url'] : "";
$pagina = isset($_GET['pagina']) ? $_GET['pagina'] : "";

// define pagina entrar
if(empty($pagina)){
	$pagina = "entrar";
}

// remove acentuacao
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

// formata telefone
function limpar_fone($str) { 
				
	return preg_replace("/[^0-9]/", "", $str); 
				
}

// FORMATAR NUM
function numeroMascara($string)
{
	$number_substr = substr($string,0,4);
	$number_strlen = strlen($string);
	//echo $number_substr . "  - ";
	
	if($number_substr == "0800" && $number_strlen == 11) {
		
		$num = "%s%s%s%s %s%s%s %s%s%s%s";
			
	} elseif($number_substr <> "0800" && $number_strlen == 11) {
		
		$num = "(%s%s) %s%s%s%s%s %s%s%s%s";
		
	} elseif($number_substr <> "0800" && $number_strlen == 10) {
		
		$num = "(%s%s) %s%s%s%s %s%s%s%s";
		
	}

    return  vsprintf($num, str_split($string));
	//echo numeroMascara('73801331903');
}


// DADOS SEO
$feed_foto_social = $urlsite . "/tl-content/600x315/img_facebook.png";
$seo_data = date("Y-m-d");
$seo_hora = date("H:i:s");
$feed_data_pg = $seo_data . "T" . $seo_hora . "+00:00";

// PEGA URL
function PegaUrl(){
 $dominio = $_SERVER['HTTP_HOST'];
 $url_full = "http://" . $dominio. $_SERVER['REQUEST_URI'];
 return $url_full;
}

$dados_seo_title_format = $tsite;

// entrar / form
if ($ht_url == "entrar" && isset($_SESSION["usuarioID"]) == true) {
	
	header('Location: ' . $urlsite . "/adm/resumo");
	exit();

} else {
	
	if(true === array_key_exists('start_user', $_COOKIE) && strlen($_COOKIE['start_user']) > 0) {
		$entrar_input = $_COOKIE['start_user'];
	}
	
}

// forms / tb
function alteraRegistro($tb_alterar,$ht_url) {
	
	if($ht_url == true) {
		
		include("conexao.php");
	
		$db_alterar = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM ".$tb_alterar." WHERE url = '".$ht_url."'"));

		return $db_alterar;
		
	}
}


// entrar / folha estilos

if($pagina == "entrar" || $pagina == "entrar-erro" && $ht_url == "") {
	
	$entrar_css = "_entrar";
	$include_centro = "inc/entrar.inc";
	
} else {
	
	$entrar_css = "";
	$include_centro = "";
	
}

?>