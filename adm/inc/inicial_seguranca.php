<?php

$_SG['conectaServidor'] = true;
$_SG['abreSessao'] = true;
$_SG['caseSensitive'] = false;
$_SG['validaSempre'] = true;
$_SG['tabela'] = 'usuarios_dados';
$_SG['paginaLogin'] = $urlsite . '/adm/entrar-erro';

//if ($_SG['abreSessao'] == true)
  //session_start();

// Autentica no banco PRINCIPAL (linknet_2026) — o mesmo banco onde o painel
// cadastra e altera usuários (usuarios-add / minha-conta). O banco legado
// dribletelecom2 fica apenas como fallback: usuários antigos que nunca foram
// migrados ainda conseguem entrar, e uma eventual queda dele não derruba o login.
function validaUsuario($usuario, $senha) {

  global $_SG, $conexao, $db_conectado;

  $nusuario = addslashes($usuario);
  $nsenha = addslashes(md5($senha));

  $principal_ok = isset($conexao) && $conexao && !empty($db_conectado);

  // 1) Banco principal (conexao ja aberta em adm/conexao.php)
  if ($principal_ok) {

    $sql = "SELECT * FROM " . $_SG['tabela'] . " WHERE del = 'N' && usuario = '" . $nusuario . "' && senha = '" . $nsenha . "' LIMIT 1";
    $query = mysqli_query($conexao, $sql);
    $resultado = $query ? mysqli_fetch_assoc($query) : null;

    if (!empty($resultado)) {

      registraSessaoUsuario($resultado, $usuario, $senha);
      return true;
    }

    // Se o usuario EXISTE no banco principal (ativo ou deletado), o principal e
    // autoritativo: senha errada ou usuario deletado = login negado. O fallback
    // legado vale apenas para usuarios que nunca existiram no principal — senao
    // uma senha antiga (ou um usuario excluido) continuaria entrando pelo legado.
    $query = mysqli_query($conexao, "SELECT id FROM " . $_SG['tabela'] . " WHERE usuario = '" . $nusuario . "' LIMIT 1");
    if ($query && mysqli_num_rows($query) > 0) {
      return false;
    }
  }

  // 2) Fallback: banco legado (protegido — se estiver fora do ar, apenas falha o login)
  $legado = conectaBancoLegado();
  if ($legado) {

    $sql = "SELECT * FROM " . $_SG['tabela'] . " WHERE usuario = '" . $nusuario . "' && senha = '" . $nsenha . "' LIMIT 1";
    $query = mysqli_query($legado, $sql);
    $resultado = $query ? mysqli_fetch_assoc($query) : null;
    mysqli_close($legado);

    if (!empty($resultado)) {

      registraSessaoUsuario($resultado, $usuario, $senha);
      return true;
    }
  }

  return false;
}

// Conexao protegida ao banco legado: timeout curto e sem exception/fatal
function conectaBancoLegado() {

  $bd_server = "dribletelecom2.mysql.dbaas.com.br";
  $bd_banco = "dribletelecom2";
  $bd_user = "dribletelecom2";
  $bd_senha = "F_@f830f824dhc";

  mysqli_report(MYSQLI_REPORT_OFF);

  // O Windows (IIS) pode tentar IPv6 primeiro mesmo o server sendo IPv4, causando +1000ms de latencia
  $bd_ip = gethostbyname($bd_server);

  $link = mysqli_init();
  if (!$link) {
    return false;
  }
  mysqli_options($link, MYSQLI_OPT_CONNECT_TIMEOUT, 5);

  if (!@mysqli_real_connect($link, $bd_ip, $bd_user, $bd_senha, $bd_banco)) {
    return false;
  }

  return $link;
}

function registraSessaoUsuario($resultado, $usuario, $senha) {

  global $_SG;

  // Novo ID de sessao no login (evita session fixation)
  if (session_status() == PHP_SESSION_ACTIVE) {
    session_regenerate_id(true);
  }

  $_SESSION['usuarioID'] = $resultado['id'];

  // O banco principal usa nome_responsavel/nome_cliente; o legado usa nome
  if (!empty($resultado['nome_responsavel'])) {
    $_SESSION['usuarioNome'] = $resultado['nome_responsavel'];
  } elseif (!empty($resultado['nome_cliente'])) {
    $_SESSION['usuarioNome'] = $resultado['nome_cliente'];
  } elseif (!empty($resultado['nome'])) {
    $_SESSION['usuarioNome'] = $resultado['nome'];
  } else {
    $_SESSION['usuarioNome'] = $usuario;
  }

  if ($_SG['validaSempre'] == true) {

    $_SESSION['usuarioLogin'] = $usuario;
    $_SESSION['usuarioSenha'] = $senha;
  }
}

function protegePagina() {
  global $_SG;
  if (!isset($_SESSION['usuarioID']) OR !isset($_SESSION['usuarioNome'])) {

    expulsaVisitante();
  } else {

    if ($_SG['validaSempre'] == true) {

      if (!validaUsuario($_SESSION['usuarioLogin'], $_SESSION['usuarioSenha'])) {

        expulsaVisitante();
      }
    }
  }
}

function expulsaVisitante() {
	global $_SG;

	if (session_status() == PHP_SESSION_ACTIVE) {
		session_destroy();
	}
	unset($_SESSION['usuarioID'], $_SESSION['usuarioNome'], $_SESSION['usuarioLogin'], $_SESSION['usuarioSenha']);

	header("Location: ".$_SG['paginaLogin']);
	exit();
}

?>
