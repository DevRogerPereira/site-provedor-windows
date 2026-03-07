<?php

//HTACESS
$id = isset($_GET['id']) ? $_GET['id'] : "";
$cidade = isset($_GET['cidade']) ? $_GET['cidade'] : "";
$pagina = isset($_GET['pagina']) ? $_GET['pagina'] : "";
$url = isset($_GET['url']) ? $_GET['url'] : "";
$pg = isset($_GET['pg']) ? $_GET['pg'] : "";
$page = isset($_GET['page']) ? $_GET['page'] : "";




$sql = "SELECT COUNT(*) AS total FROM planos_localidades WHERE del = 'N'";
$res = mysqli_query($conexao, $sql);
$total = (int) mysqli_fetch_assoc($res)['total'];

if (empty($pagina)) {
    $q = mysqli_query($conexao, "SELECT url FROM planos_localidades WHERE del='N' LIMIT 1");
    $c_url = $q ? (mysqli_fetch_assoc($q)['url'] ?? null) : null;
    
    if ($c_url) {
        $cidade = $c_url;
        $pagina = "inicial";
    } else {
        $pagina = "cidade";
    }
}



$url_ft = md5(uniqid(time()));

//Remove acentuacao
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


// PEGA URL
function PegaUrl(){
 $dominio = $_SERVER['HTTP_HOST'];
 $url_full = "http://" . $dominio. $_SERVER['REQUEST_URI'];
 return $url_full;
}


// seo
$seo_data = date("Y-m-d");
$seo_hora = date("H:i:s");
$feed_data_pg = $seo_data . "T" . $seo_hora . "+00:00";


// FORMATAR NUM
	function limpar_texto($str){ 
		return preg_replace("/[^0-9]/", "", $str); 
	}

function numeroMascara($string)
{
	$number_substr = substr($string,0,4);
	$number_strlen = strlen($string);
	//echo $number_substr . "  - ";
	
	if($number_substr == "0800" && $number_strlen == 11) {
		
		$num = "%s%s%s%s %s%s%s %s%s%s%s";
			
	} elseif($number_substr != "0800" && $number_strlen == 11) {
		
		$num = "(%s%s) %s%s%s%s%s %s%s%s%s";
		
	} elseif($number_substr != "0800" && $number_strlen == 10) {
		
		$num = "(%s%s) %s%s%s%s %s%s%s%s";
		
	}

    return  vsprintf($num, str_split($string));
	//echo numeroMascara('73801331903');
}

// inicio background localidade

$dados_tb_config_query = mysqli_query($conexao,"SELECT * FROM tb_config WHERE id = '1'");
$dados_tb_config = $dados_tb_config_query ? mysqli_fetch_object($dados_tb_config_query) : null;

if($dados_tb_config && isset($dados_tb_config->foto01) && file_exists("images/". $dados_tb_config->foto01) && $dados_tb_config->foto01 == true) {

	$dados_tb_config_bg = "background: url('".$urlsite."/images/".$dados_tb_config->foto01."') #131372 no-repeat center top;
	background-size:cover;
";

} else {

	$dados_tb_config_bg = "background: #131372;
";

}

// fim background localidade
	

// entrar / form

if ($cidade == true) {
	
	$dados_cidade = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE del = 'N' && url = '".$cidade."'"));
	$dados_rows_plano_1 = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' && cat_id = '1'"));
	
	$dados_rows_plano_2 = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' && cat_id = '2'"));
	$dados_rows_plano_3 = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' && cat_id = '3'"));
	$dados_rows_plano_4 = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' && cat_id = '4'"));
	$dados_rows_plano_5 = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' && cat_id = '5'"));
	$dados_rows_plano_6 = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' && cat_id = '6'"));
	$dados_rows_plano_7 = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' && cat_id = '7'"));
	$dados_rows_contratos = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM contratos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."'"));
	$dados_rows_blog = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM blog WHERE del = 'N'"));
	$dados_rows_depoimentos = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM depoimentos WHERE del = 'N'"));
	$dados_rows_duvidas = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM duvidas WHERE del = 'N'"));
	$dados_rows_slides = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM slides WHERE del = 'N' && locl_id = '".$dados_cidade['id']."'"));
	$dados_rows_contratos = mysqli_num_rows(mysqli_query($conexao,"SELECT * FROM contratos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."'"));

	$tb_planos_1 = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' && cat_id = '1' && tipo_id = 'S' ORDER BY valor ASC"));
	$tb_planos_2 = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' && cat_id = '2' && tipo_id = 'S' ORDER BY valor ASC"));

	if ($social_facebook == true) {
		
		$dados_social_facebook = "<a href=\"https://facebook.com/".$social_facebook."\" target=\"_blank\" class=\"cad-li-facebook\"></a>";
		$cabecalho_nav_social_facebook = "<a href=\"https://facebook.com/".$social_facebook."\" class=\"cbl-dir-facebook\"></a>";
		$assine_li_facebook = "<a href=\"https://facebook.com/".$social_facebook."\" target=\"_blank\" class=\"asn-li-icon-fone\"></a><a href=\"https://facebook.com/".$social_facebook."\" target=\"_blank\" class=\"asn-li-titulo\">Messenger</a><a href=\"https://facebook.com/".$social_facebook."\" target=\"_blank\" class=\"asn-li-intro\">".$social_facebook."</a>";
		
	}

	if ($social_instagram == true) {
		
		$dados_social_instagram = "<a href=\"https://www.instagram.com/".$social_instagram."\" target=\"_blank\" class=\"cad-li-instagram\"></a>";
		$cabecalho_nav_social_instagram = "<a href=\"https://www.instagram.com/".$social_instagram."\" class=\"cbl-dir-instagram\"></a>";
		
	}

	if (isset($dados_cidade['id']) == true) {
		
		$dados_cidade_flt = " && locl_id = '".$dados_cidade['id']."'";
		
	}
	
	if (isset($dados_cidade['nome'])) {
		
		$dados_cidade_nome = $dados_cidade['nome'];
		$dados_ini_cidade = "<br>" . $dados_cidade['nome'];
		$dados_slide_nome = $dados_cidade['nome'];
		$dados_cidade_seo = " em " . $dados_cidade['nome'];
		
	}

	if (isset($dados_cidade['cep'])) {
		
		$dados_cidade_cep = "<br>" . $dados_cidade['cep'];
		
	}

	if (isset($dados_cidade['endereco']) == true) {
		
		$dados_cidade_endereco = nl2br($dados_cidade['endereco']) . $dados_ini_cidade . $dados_cidade_cep;
		
	}
	if (isset($dados_cidade['funcionamento'])) {
		
		$dados_cidade_funcionamento = nl2br($dados_cidade['funcionamento']);
		
	}
	if (isset($dados_cidade['telefone']) == true) {
		
		$dados_cidade_telefone = numeroMascara(limpar_texto($dados_cidade['telefone']));
		$dados_cidade_telefone_whatsapp = limpar_texto($dados_cidade['telefone']);
		
	} else {
		
		$dados_cidade_telefone = "";
		$dados_cidade_telefone_whatsapp = "";
		
	}

	if (isset($dados_cidade['telefone2']) == true) {
		
		$dados_cidade_telefone_2 = numeroMascara(limpar_texto($dados_cidade['telefone2']));
		$dados_cidade_telefone_2_whatsapp = limpar_texto($dados_cidade['telefone2']);
		
	} else {
		
		$dados_cidade_telefone_2 = "";
		$dados_cidade_telefone_2_whatsapp = "";
		
	}

}

switch($pagina)
	{
		case "cidade":
		
			//$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/pg_cidade.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
			
		break;
            
		case "inicial":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/pg_inicial.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
						
		break;
            
		case "sobre":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/pg_sobre.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
						
		break;
            
		case "atendimento":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/pg_assine.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
						
		break;
            
		case "internet":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/pg-planos-internet.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
			$dados_cbl_li_bg_img = "pln-li-bg-internet.jpg";
			$dados_cbl_li_bg_cor = "#5b84f3";
						
		break;

            
		case "empresas":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/pg-planos-empresas.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
			$dados_cbl_li_bg_img = "pln-li-bg-internet.jpg";
			$dados_cbl_li_bg_cor = "#5b84f3";
						
		break;
            
		case "tv-hd":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/ini_planos_tv.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
			$dados_cbl_li_bg_img = "pln-li-bg-tv-hd.jpg";
			$dados_cbl_li_bg_cor = "#1a859f";
						
		break;
            
		case "fixo":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/ini_planos_fixo.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
			$dados_cbl_li_bg_img = "pln-li-bg-fixo.jpg";
			$dados_cbl_li_bg_cor = "#f8b669";
						
		break;
            
		case "telefonia":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/ini_planos_telefonia.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
			$dados_cbl_li_bg_img = "pln-li-bg-telefonia.jpg";
			$dados_cbl_li_bg_cor = "#f8b669";
						
		break;
            
		case "movel":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/ini_planos_movel.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
			$dados_cbl_li_bg_img = "pln-li-bg-movel.jpg";
			$dados_cbl_li_bg_cor = "#5bcaf3";
						
		break;
            
		case "combos":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/ini_planos_combos.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
			$dados_cbl_li_bg_img = "pln-li-bg-combos.jpg";
			$dados_cbl_li_bg_cor = "#fd929a";
						
		break;
            
		case "politica-privacidade":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/pg_privacidade.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
			$dados_cbl_li_bg_img = "pln-li-bg-combos.jpg";
			$dados_cbl_li_bg_cor = "#fd929a";
						
		break;
            
		case "blog":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/pg_blog.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 
						
			if($url == true) {

				$dados_blog = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM blog WHERE del = 'N' && url = '". $url ."'"));
				$dados_blog_categorias = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM blog_categorias WHERE del = 'N' && url = '". $url ."'"));
				$dados_flt = "&& cat_id_1 = '". $dados_blog_categorias->id ."'";
				$css_pg_format = "";

				$url_list = $urlsite . "/" . $cidade . "/blog/" . $dados_blog->url . "/";

				if ($dados_blog->foto == true && file_exists("images/".$dados_blog->foto."")) { 
															

					list($width, $height) = getimagesize("images/".$dados_blog->foto."");
					
					$newWidth = 640;
					$x = ($newWidth*$height)/$width;
					$x1 = number_format($x, 0, '.', '');

					$dados_ver_li_foto = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/640x".$x1."/".$dados_blog->foto."\"></a>";
					$dados_ver_li_foto_m = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/640x".$x1."/".$dados_blog->foto."\"></a>";
													
				} else {
													
					$dados_ver_li_foto = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/1103x428/na.jpg\"></a>";
													
				}
				
				if ($dados_blog->tag == true) { 
				
					$dados_ver_tag = "<a href=\"".$url_list."\" class=\"blg-li-tag\">" . $dados_blog->tag . "</a>";
				 
				} else {
					
					$dados_ver_tag = "";
				   
				}
				
				if ($dados_blog->titulo == true) { 
				
					$dados_ver_titulo = "<a href=\"".$url_list."\" class=\"blg-li-titulo\">" . $dados_blog->titulo . "</a>";
				 
				} else {
					
					$dados_ver_titulo = "";
				   
				}
				
				if ($dados_blog->detalhes == true) { 
				
					$dados_ver_detalhes = "<span class=\"blg-li-intro\">". nl2br($dados_blog->detalhes) ."</span>";
				 
				} else {
					
					$dados_ver_detalhes = "";
				   
				}
				
				if($dados_blog->data_ini <> '0000-00-00') {
									
					$data_ini1 = str_replace('/', '-', $dados_blog->data_ini);
					$dados_data_ini = date('d/m/Y', strtotime($data_ini1));
					$dados_hora_ini = date('H:i', strtotime($data_ini1));
					$dados_ver_data_format = "<a href=\"".$url_list."\" class=\"blg-li-data\">" . $dados_data_ini . " às " . $dados_hora_ini . "</a>";
									
				} else {
									
					$dados_data_ini = date("d/m/Y"); 
					$dados_hora_ini = date("H:i"); 
					$dados_ver_data_format = "<a href=\"".$url_list."\" class=\"blg-li-data\">" . $dados_data_ini . " às " . $dados_hora_ini . "</a>";
				
				}

			} else {

				$css_pg_format = " class=\"active\"";

			}
			
		break;
            
		case "assine":

			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/pg_assine.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 

			if($id == true) {
				
				$dados_plano = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && url = '".$id."'"));

				if ($dados_plano['vnt_1'] == true) {
				
					$dados_assine_pln_vnt_1 = "<span class=\"cad-form-pln-vnt\">". $dados_plano['vnt_1'] ."</span>";
				   
				} else {
					
					$dados_assine_pln_vnt_1 = "";
				   
				}
	
				if ($dados_plano['vnt_2'] == true) {
				
					$dados_assine_pln_vnt_2 = "<span class=\"cad-form-pln-vnt\">". $dados_plano['vnt_2'] ."</span>";
				   
				} else {
					
					$dados_assine_pln_vnt_2 = "";
				   
				}
				
				if ($dados_plano['vnt_3'] == true) {
				
					$dados_assine_pln_vnt_3 = "<span class=\"cad-form-pln-vnt\">". $dados_plano['vnt_3'] ."</span>";
				   
				} else {
					
					$dados_assine_pln_vnt_3 = "";
				   
				}
				
				if ($dados_plano['vnt_4'] == true) {
				
					$dados_assine_pln_vnt_4 = "<span class=\"cad-form-pln-vnt\">". $dados_plano['vnt_4'] ."</span>";
				   
				} else {
					
					$dados_assine_pln_vnt_4 = "";
				   
				}
				
				if ($dados_plano['vnt_5'] == true) {
				
					$dados_assine_pln_vnt_5 = "<span class=\"cad-form-pln-vnt\">". $dados_plano['vnt_5'] ."</span>";
				   
				} else {
					
					$dados_assine_pln_vnt_5 = "";
				   
				}
				
				if ($dados_plano['vnt_6'] == true) {
				
					$dados_assine_pln_vnt_6 = "<span class=\"cad-form-pln-vnt\">". $dados_plano['vnt_6'] ."</span>";
				   
				} else {
					
					$dados_assine_pln_vnt_6 = "";
				   
				}
				
				if ($dados_plano['download'] == true) {
					
					$dados_categoria = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos_categorias WHERE del = 'N' && id = '".$dados_plano['cat_id']."'"));
					$dados_assine_download = $dados_plano['download'];
					$dados_assine_valor = number_format($dados_plano['valor'], 2, ',', '.');
					$dados_assine_situacao = "S";
					$dados_titulo_mail_format = "PLANO " . $dados_plano['download'] . " MEGA POR R$ " . $dados_assine_valor . "/MÊS";
					$dados_assine_titulo_format = "<span class=\"sld-plano\">" . $dados_categoria['nome'] . " - " . $dados_plano['download'] . " MEGA</span><span class=\"sld-valor\">R$ " . $dados_assine_valor . " por mês</span>";
					
					
				} elseif ($dados_plano['titulo'] == true) {
					
					$dados_categoria = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos_categorias WHERE del = 'N' && id = '".$dados_plano['cat_id']."'"));
					$dados_assine_download = $dados_plano['download'];
					$dados_assine_valor = number_format($dados_plano['valor'], 2, ',', '.');
					$dados_assine_situacao = "S";
					$dados_titulo_mail_format = "PLANO " . $dados_plano['download'] . " MEGA POR R$ " . $dados_assine_valor . "/MÊS";
					$dados_assine_titulo_format = "<span class=\"sld-plano\">" . $dados_categoria['nome'] . " - " . $dados_plano['download'] . " MEGA</span><span class=\"sld-valor\">R$ " . $dados_assine_valor . " por mês</span>";
					
					
				} else {
					
					$dados_assine_download = "";
					$dados_assine_valor = "";
					$dados_assine_situacao = "";
					$dados_assine_titulo_format = "-";
					$dados_assine_pln_download = "";
					
				}
	
				if (isset($dados_categoria['nome']) == true) {
				
					$dados_assine_pln_cat = $dados_categoria['nome'];
				   
				} else {
					
					$dados_assine_pln_cat = "-";
				   
				}


	
				switch($dados_plano['cat_id'])
				{
					case "1":
		
						if ($dados_plano['download'] == true) {
						
							$dados_assine_pln_titulo = "<span class=\"cad-form-pln-intro\">". $dados_assine_pln_cat . " - " . $dados_plano['download'] . " MEGA</span>";
							$dados_assine_pln_download = "<span class=\"cad-form-pln-vnt\">". $dados_assine_download . " MEGA</span>";
					  
						} 

					break;
					case "2":
		
						if ($dados_plano['download'] == true) {
						
							$dados_assine_pln_titulo = "<span class=\"cad-form-pln-intro\">". $dados_assine_pln_cat . " - " . $dados_plano['download'] . " MEGA</span>";
							$dados_assine_pln_download = "<span class=\"cad-form-pln-vnt\">". $dados_assine_download . " MEGA</span>";
					  
						} 

					break;
					case "6":
		
						if ($dados_plano['titulo'] == true) {
						
							$dados_assine_pln_titulo = "<span class=\"cad-form-pln-intro\">". $dados_assine_pln_cat . " - " . $dados_plano['titulo'] . "</span>";
							$dados_assine_pln_download = "";
					  
						} 

					break;
					case "7":
		
						if ($dados_plano['titulo'] == true) {
						
							$dados_assine_pln_titulo = "<span class=\"cad-form-pln-intro\">". $dados_assine_pln_cat . " - " . $dados_plano['titulo'] . "</span>";
							$dados_assine_pln_download = "";
					  
						} 

					break;
				}
				
								
				if ($dados_plano['valor'] == true) {
				
					$dados_valor = substr($dados_plano['valor'], 0, -3);
					$dados_decimal = substr(number_format($dados_plano['valor'], 2, ',', '.'), -3);
					$dados_assine_pln_valor = "<span class=\"cad-form-pln-apenas\">por apenas</span><span class=\"cad-form-pln-valor\">R$ ". number_format($dados_plano['valor'], 2, ',', '.') ."/mês</span>";
				   
				} else {
					
					$dados_valor = "";
					$dados_decimal = "";
					$dados_assine_pln_valor = "<span class=\"cad-form-pln-apenas\">-</span><span class=\"cad-form-pln-valor\">Consulte preços</span>";
				   
				}
				
				if ($dados_plano['detalhes'] == true) {
				
					$dados_assine_pln_detalhes = "<span class=\"cad-form-pln-aviso\">Observações</span><span class=\"cad-form-pln-obs\">". nl2br($dados_plano['detalhes']) ."</span>";
				   
				} else {
				
					$dados_assine_pln_detalhes = "";
				   
				}

			}

		break;
            
		case "confirmacao":

			$dados_crm = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM crm WHERE del = 'N' && url = '".$url."'"));
			$include_cabecalho = "inc/cabecalho.inc";
			$include_centro = "inc/pg_assine.inc";
			$include_rodape = "inc/rodape.inc";
			$dados_seo_title_format = $tsite . $dados_cidade_seo;
			$dados_seo_description_format = $tslogan;
			$dados_seo_og_title = $tsite;
			$feed_foto_social = $urlsite . "/".$url_ft."/seo/800x511/seo.jpg"; 

			if (isset($dados_crm['nome'])) {
				
				$dados_titulo = "Olá, " . $dados_crm['nome'];
				
			} else {
				
				$dados_titulo = "Olá, cliente!";
				
			}

		break;

}
?>