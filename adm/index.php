<?php

// bd
include("conexao.php");

// funcoes
include("inc/funcoes.php");

// funcoes seguranca
include("inc/funcoes_seguranca.php");

// Identifica dispositivo
$iphone = strpos($_SERVER['HTTP_USER_AGENT'],"iPhone");
$ipad = strpos($_SERVER['HTTP_USER_AGENT'],"iPad");
$android = strpos($_SERVER['HTTP_USER_AGENT'],"Android");
$palmpre = strpos($_SERVER['HTTP_USER_AGENT'],"webOS");
$berry = strpos($_SERVER['HTTP_USER_AGENT'],"BlackBerry");
$ipod = strpos($_SERVER['HTTP_USER_AGENT'],"iPod");
$symbian =  strpos($_SERVER['HTTP_USER_AGENT'],"Symbian");
if ($iphone || $android || $palmpre || $ipod || $berry || $symbian == true){
$disp_detect = "MV";
} else {
$disp_detect = "PC";
}
?>
<?php if($disp_detect == "PC") { ?>
<!--[if IE 8]> <html prefix="og: http://ogp.me/ns#" class="ie8" xml:lang="pt-br" lang="pt-br"> <![endif]-->
<!--[if IE 9]> <html prefix="og: http://ogp.me/ns#" class="ie9" xml:lang="pt-br" lang="pt-br"> <![endif]-->
<!--[if gt IE 8]><!-->
<html xmlns='http://www.w3.org/1999/xhtml' xmlns:og='http://ogp.me/ns#' prefix="og: http://ogp.me/ns#" class="" xml:lang="pt-br" lang="pt-br"> <!--<![endif]-->
<head>
	<?php include("inc/seo.inc")?>
</head>

<body id="site">
<?php

if(isset($include_cabecalho)) {
	
	include($include_cabecalho);
	
}

if(isset($include_centro)) {
	
	include($include_centro);
	
}

if(isset($include_rodape)) {
	
	include($include_rodape);
	
}
?>
</body>
</html>
<?php }?>
<?php
if(isset($conexao)) {
    mysqli_close($conexao);
}
?>