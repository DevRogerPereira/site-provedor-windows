<?php 
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);
require_once "libs/Mobile_Detect.php";
$detect = new Mobile_Detect;

// bd
include("adm/conexao.php");

// funcoes
include("inc/funcoes.php");

?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
<?php include("inc/seo.php") ?>

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