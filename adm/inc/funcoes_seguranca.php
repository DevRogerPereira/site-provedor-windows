<?php

// VALIDACAO USUARIO
if($pagina == "entrar-valida" && $_SERVER['REQUEST_METHOD'] == 'POST'){

	require_once("inc/inicial_seguranca.php");

	$usuario = (isset($_POST['usuario'])) ? $_POST['usuario'] : '';
	$senha = (isset($_POST['senha'])) ? $_POST['senha'] : '';

	if (validaUsuario($usuario, $senha) == true) {

	header("Location: ".$urlsite."/adm/resumo");
	exit();

	} else {
		  
		expulsaVisitante();
		
	}
}

if(isset($_SESSION["usuarioID"]) == true){

	require_once("conexao.php");
	$user = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM usuarios_dados WHERE del = 'N' && id = '".$_SESSION['usuarioID']."'"));
	//$tb_user_cidade = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM cidades_dados WHERE url = '".$user['cidade_id']."'"));

	setcookie ("start_user", $user['usuario'], (time() + (15 * 24 * 3600)), "/", "", false, false);

	$user_id = isset($user['id']) ? $user['id'] : "";
	$user_url = isset($user['url']) ? $user['url'] : "";
	$user_nivel = isset($user['nivel_acesso']) ? $user['nivel_acesso'] : "";
	$user_nome_cliente = isset($user['nome_cliente']) ? $user['nome_cliente'] : "";
	$user_nome_responsavel = isset($user['nome_responsavel']) ? $user['nome_responsavel'] : "";
	$user_cidade = isset($user['cidade_id']) ? $user['cidade_id'] : "";
	$user_foto = isset($user['foto']) ? $user['foto'] : "";
	$user_usuario = isset($user['usuario']) ? $user['usuario'] : "";
	$user_senha = isset($user['senhabk']) ? $user['senhabk'] : "";
	
	$url_user_ft = md5(uniqid(time()));
	
	if(isset($user_foto) && file_exists("image/".$user_foto."")) {
		
		$user_img_avatar = "<a href=\"".$urlsite."/adm/minha-conta\" class=\"ct_avatar_img\"><img src=\"".$urlsite."/adm/".$url_user_ft."/adm/120x120/".$user_foto."\"></a>"; 
		$user_img_topo = "<img src=\"".$urlsite."/adm/".$url_user_ft."/adm/36x36/".$user_foto."\">"; 
		$user_img_post = "<a href=\"".$urlsite."/adm/minha-conta\" class=\"cb_perfil_foto\"><img src=\"".$urlsite."/adm/".$url_user_ft."/adm/48x48/".$user_foto."\"></a>"; 
	
	} else {
		
		$user_img_avatar = "<a href=\"".$urlsite."/adm/minha-conta\" class=\"ct_avatar_img\"><img src=\"".$urlsite."/adm/".$url_user_ft."/adm/120x120/argontec_img_na.jpg\"></a>"; 
		$user_img_topo = "<img src=\"".$urlsite."/adm/".$url_user_ft."/adm/36x36/tualiz_img_na.jpg\">"; 
		$user_img_post = "<a href=\"".$urlsite."/adm/minha-conta\" class=\"cb_perfil_foto\"><img src=\"".$urlsite."/adm/".$url_user_ft."/adm/48x48/argontec_img_na.jpg\"></a>"; 
	
	}

	// menu

	if($ht_url == true) {
		
		$dados_menu_url = "/" . $ht_url; 
		
	} else {
		
		$dados_menu_url = ""; 
		
	}
	
	switch($pagina)
	{
		case "resumo":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/planos.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Resumo</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Resumo</a></li>
                    	<li><a href=\"".$urlsite."/adm/".$pagina."\">Adicionar</a></li>";
			$dados_menu_ac_resumo = "class=\"active\"";

			if($ht_url == true) {

				$dados_filtros = " && locl_id = '".$ht_url."'";

			} else {

				$dados_filtros = "";
				
			}

		break;
		case "minha-conta":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/usuarios_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Minha conta</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Minha conta</a></li>
                    	<li><a href=\"".$urlsite."/adm/".$pagina."-add\">Alterar dados</a></li>";
			$dados_menu_ac_conta = "class=\"active\"";
			$dados_tb = alteraRegistro('usuarios_dados', $user_url);
			//$gravaLog = setLOG($user_id, $disp_detect, $urlsite_full, "3", "entrou na area de cliente.");
		break;
		case "localidades":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/localidades.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/localidades\">Localidades</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/localidades\">Localidades</a></li>
                    	<li><a href=\"".$urlsite."/adm/localidades-add\">Adicionar</a></li>";
			$dados_menu_ac_localidades = "class=\"active\"";
			//$gravaLog = setLOG($user_id, $disp_detect, $urlsite_full, "3", "viu a listagem de noticias.");
		break;
		case "localidades-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/localidades_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/localidades\">Localidades</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/localidades\">Localidades</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/localidades-add\">Adicionar</a></li>";
			$dados_menu_ac_localidades = "class=\"active\"";

			$dados_tb = alteraRegistro('planos_localidades', $ht_url);

		break;
		case "categorias":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/categorias.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/categorias\">Categorias</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/categorias\">Categorias</a></li>
                    	<li><a href=\"".$urlsite."/adm/categorias-add\">Adicionar</a></li>";
			$dados_menu_ac_categorias = "class=\"active\"";
		break;
		case "categorias-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/categorias_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/categorias\">Categorias</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/categorias\">Categorias</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/categorias-add\">Adicionar</a></li>";
			$dados_menu_ac_categorias = "class=\"active\"";
			$dados_tb = alteraRegistro('planos_categorias', $ht_url);

		break;
		case "planos":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/planos.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/planos\">Planos</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/planos\">Planos</a></li>
                    	<li><a href=\"".$urlsite."/adm/planos-add\">Adicionar</a></li>";
			$dados_menu_ac_planos = "class=\"active\"";
			
			if($ht_url == true) {

				$dados_filtros = " && locl_id = '".$ht_url."'";

			} else {
				

				$dados_filtros = "";
				
			}
			
		break;
		case "planos-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/planos_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/planos\">Planos</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/planos\">Planos</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/planos-add\">Adicionar</a></li>";
			$dados_menu_ac_planos = "class=\"active\"";

			if($ht_url == true) {

				$dados_tb = alteraRegistro('planos', $ht_url);

			}

		break;
		case "planos-img":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/planos_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/planos\">Planos</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/planos\">Planos</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/planos-add\">Adicionar</a></li>";
			$dados_menu_ac_planos = "class=\"active\"";
			
			$dados_tb = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && url = '".$ht_url."'"));

			if($dados_tb['foto'] == true) {

				$dados_planos_foto = "<img id=\"visualizar\" src=\"".$urlsite."/".$url_user_ft."/1000x352/".$dados_tb['foto']."\">";

			} else {

				$dados_planos_foto = "<img id=\"visualizar\" src=\"".$urlsite."/".$url_user_ft."/1000x352/slides-bg.jpg\">";
				
			}

		break;
		case "combos":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/combos.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/combos\">Combos</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/combos\">Combos</a></li>
                    	<li><a href=\"".$urlsite."/adm/combos-add\">Adicionar</a></li>";
			$dados_menu_ac_combos = "class=\"active\"";

			if($ht_url == true) {

				$dados_filtros = " && locl_id = '".$ht_url."'";

			} else {

				$dados_filtros = "";
				
			}
		break;
		case "combos-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/combos_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/combos\">Combos</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/combos\">Combos</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/combos-add\">Adicionar</a></li>";
			$dados_menu_ac_combos = "class=\"active\"";

			if($ht_url == true) {

				$dados_tb = alteraRegistro('planos', $ht_url);

			}

		break;
		case "combos-img":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/combos_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/combos\">Combos</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/combos\">Combos</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/combos-add\">Adicionar</a></li>";
			$dados_menu_ac_combos = "class=\"active\"";
			
			$dados_tb = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && url = '".$ht_url."'"));

			if($dados_tb['foto'] == true) {

				$dados_combos_foto = "<img id=\"visualizar\" src=\"".$urlsite."/".$url_user_ft."/1000x352/".$dados_tb['foto']."\">";

			} else {

				$dados_combos_foto = "<img id=\"visualizar\" src=\"".$urlsite."/".$url_user_ft."/1000x352/slides-bg.jpg\">";
				
			}

		break;
		case "telefonia":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/telefonia.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/telefonia\">telefonia</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/telefonia\">telefonia</a></li>
                    	<li><a href=\"".$urlsite."/adm/telefonia-add\">Adicionar</a></li>";
			$dados_menu_ac_telefonia = "class=\"active\"";

			if($ht_url == true) {

				$dados_filtros = " && locl_id = '".$ht_url."'";

			} else {

				$dados_filtros = "";
				
			}
		break;
		case "telefonia-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/telefonia_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/telefonia\">telefonia</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/telefonia\">telefonia</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/telefonia-add\">Adicionar</a></li>";
			$dados_menu_ac_telefonia = "class=\"active\"";

			if($ht_url == true) {

				$dados_tb = alteraRegistro('planos', $ht_url);

			}

		break;
		case "telefonia-img":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/telefonia_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/telefonia\">telefonia</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/telefonia\">telefonia</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/telefonia-add\">Adicionar</a></li>";
			$dados_menu_ac_telefonia = "class=\"active\"";
			
			$dados_tb = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && url = '".$ht_url."'"));

			if($dados_tb['foto'] == true) {

				$dados_telefonia_foto = "<img id=\"visualizar\" src=\"".$urlsite."/".$url_user_ft."/1000x352/".$dados_tb['foto']."\">";

			} else {

				$dados_telefonia_foto = "<img id=\"visualizar\" src=\"".$urlsite."/".$url_user_ft."/1000x352/slides-bg.jpg\">";
				
			}

		break;
		case "tv":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/tv.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/tv\">TV</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/tv\">TV</a></li>
                    	<li><a href=\"".$urlsite."/adm/tv-add\">Adicionar</a></li>";
			$dados_menu_ac_tv = "class=\"active\"";

			if($ht_url == true) {

				$dados_filtros = " && locl_id = '".$ht_url."'";

			} else {

				$dados_filtros = "";
				
			}
		break;
		case "tv-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/tv_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/tv\">TV</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/tv\">TV</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/tv-add\">Adicionar</a></li>";
			$dados_menu_ac_tv = "class=\"active\"";

			if($ht_url == true) {

				$dados_tb = alteraRegistro('planos', $ht_url);

			}

		break;
		case "tv-img":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/tv_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/tv\">TV</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/tv\">TV</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/tv-add\">Adicionar</a></li>";
			$dados_menu_ac_tv = "class=\"active\"";
			
			$dados_tb = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && url = '".$ht_url."'"));

			if($dados_tb['foto'] == true) {

				$dados_tv_foto = "<img id=\"visualizar\" src=\"".$urlsite."/".$url_user_ft."/1000x352/".$dados_tb['foto']."\">";

			} else {

				$dados_tv_foto = "<img id=\"visualizar\" src=\"".$urlsite."/".$url_user_ft."/1000x352/slides-bg.jpg\">";
				
			}

		break;
		case "depoimentos":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/depoimentos.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Depoimentos</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Depoimentos</a></li>
                    	<li><a href=\"".$urlsite."/adm/".$pagina."-add\">Adicionar</a></li>";
			$dados_menu_ac_depoimentos = "class=\"active\"";

		break;
		case "depoimentos-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/depoimentos_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Depoimentos</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/".$pagina."\">Depoimentos</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Adicionar</a></li>";
			$dados_menu_ac_depoimentos = "class=\"active\"";

			if($ht_url == true) {

				$dados_tb = alteraRegistro('depoimentos', $ht_url);

			}
		break;
		case "inicial":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/inicial_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/inicial\">Inicial</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/inicial\">Inicial</a>";
			$dados_menu_ac_inicial = "class=\"active\"";
			
			$dados_tb_config = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM tb_config WHERE id = '1'"));

		break;
		case "inicial-del":

			$dados_tb_config = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM tb_config WHERE id = '1'"));

			$imagem = '../images/' . $dados_tb_config->foto01;
			
			// Verifica se o arquivo existe
			if (file_exists($imagem)) {
				// Tenta deletar o arquivo
				if (unlink($imagem)) {
					//echo "Imagem deletada com sucesso!";
					$del_tb_config = mysqli_query($conexao,"UPDATE tb_config SET foto01 = '' WHERE id = '1'");

					header("Location: ".$urlsite."/adm/inicial");
					break;

				} else {
					//echo "Erro ao tentar deletar a imagem.";

					header("Location: ".$urlsite."/adm/inicial");
					break;

				}
			} else {
				//echo "Imagem não encontrada.";

					header("Location: ".$urlsite."/adm/inicial");
					break;

			}


		break;
		case "slides":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/slides.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/slides\">Slides</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/slides\">Slides</a></li>
                    	<li><a href=\"".$urlsite."/adm/slides-add\">Adicionar</a></li>";
			$dados_menu_ac_slides = "class=\"active\"";

		break;
		case "slides-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/slides_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/slides\">Slides</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/slides\">Slides</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/slides-add\">Adicionar</a></li>";
			$dados_menu_ac_slides = "class=\"active\"";

			if($ht_url == true) {

				$dados_tb = alteraRegistro('slides', $ht_url);

			}

		break;
		case "slides-img":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/slides_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Slides</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/".$pagina."\">Slides</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Adicionar</a></li>";
			$dados_menu_ac_slides = "class=\"active\"";

			if($ht_url == true) {

				$dados_slides = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM slides WHERE id = '". $ht_url ."'"));

			}

		break;
		case "slides-del":

			$dados_slides = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM slides WHERE id = '". $ht_url ."'"));

			$imagem = '../images/' . $dados_slides->foto;
			
			// Verifica se o arquivo existe
			if (file_exists($imagem)) {
				// Tenta deletar o arquivo
				if (unlink($imagem)) {
					//echo "Imagem deletada com sucesso!";
					$del_slides = mysqli_query($conexao,"UPDATE slides SET foto = '' WHERE id = '". $ht_url ."'");

					header("Location: ".$urlsite."/adm/slides");
					break;

				} else {
					//echo "Erro ao tentar deletar a imagem.";

					header("Location: ".$urlsite."/adm/slides");
					break;

				}
			} else {
				//echo "Imagem não encontrada.";

					header("Location: ".$urlsite."/adm/slides");
					break;

			}


		break;
		case "contratos":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/contratos.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/contratos\">Contratos</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/contratos\">Contratos</a></li>
                    	<li><a href=\"".$urlsite."/adm/contratos-add\">Adicionar</a></li>";
			$dados_menu_ac_contratos = "class=\"active\"";

		break;
		case "contratos-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/contratos_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/Contratos\">contratos</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/contratos\">Contratos</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/contratos-add\">Adicionar</a></li>";
			$dados_menu_ac_contratos = "class=\"active\"";

			if($ht_url == true) {

				$dados_tb = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM contratos WHERE id = '". $ht_url ."'"));

			}

		break;
		case "contratos-img":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/contratos_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Contratos</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/".$pagina."\">Contratos</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/contratos-add\">Adicionar</a></li>";
			$dados_menu_ac_contratos = "class=\"active\"";

			if($ht_url == true) {

				$dados_contratos = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM contratos WHERE id = '". $ht_url ."'"));

			}

		break;
		case "contratos-del":

			$dados_contratos = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM contratos WHERE id = '". $ht_url ."'"));

			$imagem = '../images/' . $dados_contratos->foto;
			
			// Verifica se o arquivo existe
			if (file_exists($imagem)) {
				// Tenta deletar o arquivo
				if (unlink($imagem)) {
					//echo "Imagem deletada com sucesso!";
					$del_contratos = mysqli_query($conexao,"UPDATE contratos SET foto = '' WHERE id = '". $ht_url ."'");

					header("Location: ".$urlsite."/adm/contratos");
					break;

				} else {
					//echo "Erro ao tentar deletar a imagem.";

					header("Location: ".$urlsite."/adm/contratos");
					break;

				}
			} else {
				//echo "Imagem não encontrada.";

					header("Location: ".$urlsite."/adm/contratos");
					break;

			}


		break;
		case "blog":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/blog.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/blog\">Blog</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/blog\">Blog</a></li>
                    	<li><a href=\"".$urlsite."/adm/blog-add\">Adicionar</a></li>";
			$dados_menu_ac_blog = "class=\"active\"";

		break;
		case "blog-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/blog_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/blog\">Blog</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/blog\">Blog</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/blog-add\">Adicionar</a></li>";
			$dados_menu_ac_blog = "class=\"active\"";

			if($ht_url == true) {

				$dados_editar = alteraRegistro('blog', $ht_url);
				
				if($dados_editar['cat_id_1'] == true) {
					
					$dados_blog_categorias = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM blog_categorias WHERE id = '". $dados_editar['cat_id_1'] ."'"));
					
				} else {
				}

				if($dados_editar['data_ini'] <> '0000-00-00') {
					
					$data_ini1 = str_replace('/', '-', $dados_editar['data_ini']);
					$data_ini = date('d/m/Y H:i', strtotime($data_ini1));
					
				} else {
					
					$data_ini = date("d/m/Y H:i"); 
				}

			} else{

				$data_ini = date("d/m/Y H:i"); 

			}

		break;
		case "blog-img":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/blog_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/blog\">Blog</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/blog\">Blog</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Adicionar</a></li>";
			$dados_menu_ac_blog = "class=\"active\"";

			if($ht_url == true) {

				$dados_tb = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM blog WHERE id = '".$ht_url."'"));

				if ($dados_tb['foto'] == true) {
					
					$dados_blog = "" . $dados_tb['foto'];
					$url_ft = md5(uniqid(time()));
					
				} else {
				
					$dados_blog = "";
				}
	
				if ($dados_tb['foto_m'] == true) {
					
					$dados_blog_m = "" . $dados_tb['foto_m'];
					$url_ft = md5(uniqid(time()));
					
				} else {
	
					$dados_blog_m = "";
				
				}

			}

		break;
		case "blog-categorias":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/blog_categorias.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/blog-categorias\">Categorias</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/blog-categorias\">Categorias</a></li>
                    	<li><a href=\"".$urlsite."/adm/blog-categorias-add\">Adicionar</a></li>";
			$dados_menu_ac_blog_categorias = "class=\"active\"";

		break;
		case "blog-categorias-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/blog_categorias_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/blog-categorias\">Categorias</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/blog-categorias\">Categorias</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/blog-categorias-add\">Adicionar</a></li>";
			$dados_menu_ac_blog_categorias = "class=\"active\"";

			if($ht_url == true) {

				$dados_editar = alteraRegistro('blog_categorias', $ht_url);

			}

		break;
		case "duvidas":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/duvidas.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/duvidas\">Dúvidas</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/duvidas\">Dúvidas</a></li>
                    	<li><a href=\"".$urlsite."/adm/".$pagina."-add\">Adicionar</a></li>";
			$dados_menu_ac_duvidas = "class=\"active\"";

		break;
		case "duvidas-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/duvidas_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/duvidas\">Dúvidas</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/duvidas\">Dúvidas</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Adicionar</a></li>";
			$dados_menu_ac_duvidas = "class=\"active\"";
			$dados_tb = alteraRegistro('duvidas', $ht_url);
			$dados_tb_cat = alteraRegistro('atuacao_categorias', $id);
		break;
		case "crm":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/crm.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Cadastros</a></li>";
			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Cadastros</a></li>";
			$dados_menu_ac_crm = "class=\"active\"";
		break;
		case "crm-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/crm_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub_cli = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Cadastros</a></li>";
			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/".$pagina."\">Cadastros</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Adicionar</a></li>";
			$dados_menu_ac_crm = "class=\"active\"";
			$dados_tb = alteraRegistro('crm', $ht_url);
		break;
		case "usuarios":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/usuarios.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub = "                        <li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Usuarios</a></li>
                    	<li><a href=\"".$urlsite."/adm/".$pagina."-add\">Adicionar</a></li>";
			$dados_menu_ac_unidades = "class=\"active\"";
		break;
		case "usuarios-add":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/usuarios_add.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/".$pagina."\">Usuários</a></li>
                    	<li class=\"active\"><a href=\"".$urlsite."/adm/".$pagina."\">Adicionar</a></li>";
			$dados_menu_ac_unidades = "class=\"active\"";
			$dados_tb = alteraRegistro('usuarios_dados', $ht_url);
		break;
		case "configuracoes":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/configuracoes.inc";
			$include_rodape = "inc/rodape.inc";

			$dados_menu_sub = "                        <li><a href=\"".$urlsite."/adm/".$pagina."\">Configuração</a></li>";
			$dados_menu_ac_configuracao = "class=\"active\"";
			$dados_tb = alteraRegistro('tb_config', '1');
			//$gravaLog = setLOG($user_id, $disp_detect, $urlsite_full, "3", "adicionou nova unidade.");
			break;
		case "sair":
			//session_start();
			//session_destroy();
			unset($_SESSION['usuarioID']);
			unset($_SESSION['usuarioLogin']);
			unset($_SESSION['usuarioSenha']);
		
			header("Location: ".$urlsite."/adm/");
			break;
	}

} else {
	
}



?>
