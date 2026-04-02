<?php

$_SG['conectaServidor'] = true;
$_SG['abreSessao'] = true;
$_SG['caseSensitive'] = false;
$_SG['validaSempre'] = true;
$_SG['tabela'] = 'usuarios_dados';
$_SG['paginaLogin'] = $urlsite . '/adm/entrar-erro';

//if ($_SG['abreSessao'] == true)
  //session_start();

function validaUsuario($usuario, $senha) {


$bd_server = "dribletelecom2.mysql.dbaas.com.br";
$bd_banco = "dribletelecom2";
$bd_user = "dribletelecom2";
$bd_senha = "F_@f830f824dhc";

// O Windows (IIS) pode tentar IPv6 primeiro mesmo o server sendo IPv4, causando +1000ms de latencia
$bd_ip = gethostbyname($bd_server);
$link = new mysqli($bd_ip, $bd_user, $bd_senha, $bd_banco);
if(mysqli_connect_errno()) trigger_error(mysqli_connect_error());

  global $_SG;
  $cS = ($_SG['caseSensitive']) ? 'BINARY' : '';

  $nusuario = addslashes($usuario);

  $nsenha = addslashes(md5($senha));

  $sql = "SELECT * FROM ".$_SG['tabela']." WHERE usuario = '".$nusuario."' && senha = '".$nsenha."' LIMIT 1";
  $query = mysqli_query($link,$sql);
  $resultado = mysqli_fetch_assoc($query);

  if (empty($resultado)) {

    return false;
  } else {

    $_SESSION['usuarioID'] = $resultado['id']; 
    $_SESSION['usuarioNome'] = $resultado['nome'];

    if ($_SG['validaSempre'] == true) {

      $_SESSION['usuarioLogin'] = $usuario;
      $_SESSION['usuarioSenha'] = $senha;
    }
    return true;
  }
}

function protegePagina() {
  global $_SG;
  if (!isset($_SESSION['usuarioID']) OR !isset($_SESSION['usuarioNome'])) {

    expulsaVisitante();
  } else if (!isset($_SESSION['usuarioID']) OR !isset($_SESSION['usuarioNome'])) {

    if ($_SG['validaSempre'] == true) {

      if (!validaUsuario($_SESSION['usuarioLogin'], $_SESSION['usuarioSenha'])) {

        expulsaVisitante();
      }
    }
  }
}

function expulsaVisitante() {
	global $_SG;

	session_destroy();
	unset($_SESSION['usuarioID'], $_SESSION['usuarioNome'], $_SESSION['usuarioLogin'], $_SESSION['usuarioSenha']);

	header("Location: ".$_SG['paginaLogin']);
	exit();
}

?>