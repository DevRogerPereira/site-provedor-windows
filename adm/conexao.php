<?php

if (session_status() == PHP_SESSION_NONE) {
    session_start();
}

date_default_timezone_set('America/Sao_Paulo');

if((isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] === 'on') || (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] === 'https') || (isset($_SERVER['HTTP_X_CLIENT_PROTO']) && $_SERVER['HTTP_X_CLIENT_PROTO'] === 'https')){
    
	$url_server = "https://";
	
} else {
    
	$url_server = "http://";
	
	// Força o redirecionamento para HTTPS
	header("HTTP/1.1 301 Moved Permanently");
	header("Location: https://" . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
	exit();
}

$urlsite = $url_server . $_SERVER['HTTP_HOST'] . "";

header('Content-Type: text/html; charset=utf-8');

$server = "linknet_2026_2.mysql.dbaas.com.br";
$banco = "linknet_2026_2";
$user = "linknet_2026_2";
$senha = "Emf@844888";

$conexao = new mysqli($server, $user, $senha, $banco);

if (mysqli_connect_errno()) trigger_error(mysqli_connect_error());

$sql = mysqli_query($conexao, "SELECT * FROM tb_config WHERE id = '1'");

$tsite = "";
$tslogan = "";
$usite = "";
$sobre = "";
$sobre_1 = "";
$sobre_2 = "";
$sobre_3 = "";
$sobre_rodape = "";
$fone_1 = "";
$fone_2 = "";
$email = "";
$endereco = "";
$seo_descricao = "";
$seo_keywords = "";
$app_android = "";
$app_ios = "";
$watch_app_android = "";
$watch_app_ios = "";
$cnpj = "";
$social_facebook = "";
$social_instagram = "";
$social_youtube = "";
$social_twitter = "";
$url_1 = "";
$url_2 = "";
$url_3 = "";
$url_4 = "";
$url_5 = "";
$url_area_cliente = "";

while ($linha = mysqli_fetch_array($sql)) {
	
	$tsite = isset($linha['tsite']) ? $linha['tsite'] : "";
	$tslogan = isset($linha['tslogan']) ? $linha['tslogan'] : "";
	$usite = isset($linha['usite']) ? $linha['usite'] : "";
	$sobre = isset($linha['sobre']) ? nl2br($linha['sobre']) : "";
	$sobre_1 = isset($linha['sobre_1']) ? nl2br($linha['sobre_1']) : "";
	$sobre_2 = isset($linha['sobre_2']) ? nl2br($linha['sobre_2']) : "";
	$sobre_3 = isset($linha['sobre_3']) ? nl2br($linha['sobre_3']) : "";
	$sobre_rodape = isset($linha['sobre_rodape']) ? $linha['sobre_rodape'] : "";
	$fone_1 = isset($linha['fone_1']) ? $linha['fone_1'] : "";
	$fone_2 = isset($linha['fone_2']) ? $linha['fone_2'] : "";
	$email = isset($linha['email']) ? $linha['email'] : "";
	$endereco = isset($linha['endereco']) ? nl2br($linha['endereco']) : "";
	$seo_descricao = isset($linha['seo_descricao']) ? $linha['seo_descricao'] : "";
	$seo_keywords = isset($linha['seo_keywords']) ? $linha['seo_keywords'] : "";
	$app_android = isset($linha['app_android']) ? $linha['app_android'] : "";
	$app_ios = isset($linha['app_ios']) ? $linha['app_ios'] : "";
	$watch_app_android = isset($linha['watch_app_android']) ? $linha['watch_app_android'] : "";
	$watch_app_ios = isset($linha['watch_app_ios']) ? $linha['watch_app_ios'] : "";
	$cnpj = isset($linha['cnpj']) ? $linha['cnpj'] : "";

	if ($linha['vnt_1'] == 0) {

		$vnt_1 = $linha['vnt_1'];
		$vnt_1_intro = "ano de<br>experiência";

	} 
	elseif ($linha['vnt_1'] == 1) {

		$vnt_1 = $linha['vnt_1'];
		$vnt_1_intro = "ano de<br>experiência";

	} 
	elseif ($linha['vnt_1'] > 1) {

		$vnt_1 = $linha['vnt_1'];
		$vnt_1_intro = "anos de<br>experiência";

	} else {

		$vnt_1 = "";
		$vnt_1_intro = "";

	}

	if ($linha['vnt_2'] == 0) {

		$vnt_2 = $linha['vnt_2'];
		$vnt_2_intro = "profissional<br>especialista";

	} 
	elseif ($linha['vnt_2'] == 1) {

		$vnt_2 = $linha['vnt_2'];
		$vnt_2_intro = "profissional<br>especialista";

	} 
	elseif ($linha['vnt_2'] > 1) {

		$vnt_2 = $linha['vnt_2'];
		$vnt_2_intro = "profissionais<br>especialistas";

	} else {

		$vnt_2 = "";
		$vnt_2_intro = "";

	}

	if ($linha['vnt_3'] == 0) {

		$vnt_3 = $linha['vnt_3'];
		$vnt_3_intro = "localidade<br>atendida";

	} 
	elseif ($linha['vnt_3'] == 1) {

		$vnt_3 = $linha['vnt_3'];
		$vnt_3_intro = "localidade<br>atendida";

	} 
	elseif ($linha['vnt_3'] > 1) {

		$vnt_3 = $linha['vnt_3'];
		$vnt_3_intro = "localidades<br>atendidas";

	} else {

		$vnt_3 = "";
		$vnt_3_intro = "";

	}

	if ($linha['vnt_4'] == 0) {

		$vnt_4 = $linha['vnt_4'];
		$vnt_4_intro = "cliente<br>satisfeito";

	} 
	elseif ($linha['vnt_4'] == 1) {

		$vnt_4 = $linha['vnt_4'];
		$vnt_4_intro = "cliente<br>satisfeito";

	} 
	elseif ($linha['vnt_4'] > 1) {

		$vnt_4 = $linha['vnt_4'];
		$vnt_4_intro = "clientes<br>satisfeitos";

	} else {

		$vnt_4 = "";
		$vnt_4_intro = "";

	}

	if ($linha['social_facebook'] == true) {

		$social_facebook_substr = substr($linha['social_facebook'],0,5);
		//$social_facebook_strlen = strlen($linha['social_facebook']);
		
		if($social_facebook_substr == "http") {

			$social_facebook = "" . $linha['social_facebook'];

		} elseif($social_facebook_substr == "https") {

			$social_facebook = "" . $linha['social_facebook'];

		} elseif($social_facebook_substr <> "https") {

			$social_facebook = "https://www.facebook.com/" . $linha['social_facebook'];

		}

	} else {

		$social_facebook = "";

	}

	if ($linha['social_instagram'] == true) {

		$social_instagram_substr = substr($linha['social_instagram'],0,5);
		//$social_instagram_strlen = strlen($linha['social_instagram']);
		
		if($social_instagram_substr == "http") {

			$social_instagram = "" . $linha['social_instagram'];

		} elseif($social_instagram_substr == "https") {

			$social_instagram = "" . $linha['social_instagram'];

		} elseif($social_instagram_substr <> "https") {

			$social_instagram = "https://www.instagram.com/" . $linha['social_instagram'];

		}

	} else {

		$social_instagram = "";

	}

	if ($linha['social_youtube'] == true) {

		$social_youtube_substr = substr($linha['social_youtube'],0,5);
		//$social_youtube_strlen = strlen($linha['social_youtube']);
		
		if($social_youtube_substr == "http") {

			$social_youtube = "" . $linha['social_youtube'];

		} elseif($social_youtube_substr == "https") {

			$social_youtube = "" . $linha['social_youtube'];

		} elseif($social_youtube_substr <> "https") {

			$social_youtube = "https://www.youtube.com/" . $linha['social_youtube'];

		}

	} else {

		$social_youtube = "";

	}

	if ($linha['social_twitter'] == true) {

		$social_twitter_substr = substr($linha['social_twitter'],0,5);
		//$social_twitter_strlen = strlen($linha['social_twitter']);
		
		if($social_twitter_substr == "http") {

			$social_twitter = "" . $linha['social_twitter'];

		} elseif($social_twitter_substr == "https") {

			$social_twitter = "" . $linha['social_twitter'];

		} elseif($social_twitter_substr <> "https") {

			$social_twitter = "https://www.twitter.com/" . $linha['social_twitter'];

		}

	} else {

		$social_twitter = "";

	}

	// url_1: 
	
	if ($linha['url_1'] == true) {

		$url_1_substr = substr($linha['url_1'],0,5);
		//$url_1_strlen = strlen($linha['url_1']);
		
		if($url_1_substr == "http:") {

			$url_1 = "" . $linha['url_1'];

		} elseif($url_1_substr == "https") {

			$url_1 = "" . $linha['url_1'];

		} elseif($url_1_substr <> "https") {

			$url_1 = "https://" . $linha['url_1'];

		}

	} else {

		$url_1 = "";

	}

	// url_2: Clube de vantagens
	
	if ($linha['url_2'] == true) {

		$url_2_substr = substr($linha['url_2'],0,5);
		//$url_2_strlen = strlen($linha['url_2']);
		
		if($url_2_substr == "http:") {

			$url_2 = "" . $linha['url_2'];

		} elseif($url_2_substr == "https") {

			$url_2 = "" . $linha['url_2'];

		} elseif($url_2_substr <> "https") {

			$url_2 = "https://" . $linha['url_2'];

		}

	} else {

		$url_2 = "";

	}

	// url_3: Consulta cobertura
	
	if ($linha['url_3'] == true) {

		$url_3_substr = substr($linha['url_3'],0,5);
		//$url_3_strlen = strlen($linha['url_3']);
		
		if($url_3_substr == "http:") {

			$url_3 = "" . $linha['url_3'];

		} elseif($url_3_substr == "https") {

			$url_3 = "" . $linha['url_3'];

		} elseif($url_3_substr <> "https") {

			$url_3 = "https://" . $linha['url_3'];

		}

	} else {

		$url_3 = "";

	}

	// url_4: Teste velocidade
	
	if ($linha['url_4'] == true) {

		$url_4_substr = substr($linha['url_4'],0,5);
		//$url_4_strlen = strlen($linha['url_4']);
		
		if($url_4_substr == "http:") {

			$url_4 = "" . $linha['url_4'];

		} elseif($url_4_substr == "https") {

			$url_4 = "" . $linha['url_4'];

		} elseif($url_4_substr <> "https") {

			$url_4 = "https://" . $linha['url_4'];

		}

	} else {

		$url_4 = "";

	}

	//url_5: Pague com PIX
	
	if ($linha['url_5'] == true) {

		$url_5_substr = substr($linha['url_5'],0,5);
		//$url_5_strlen = strlen($linha['url_5']);
		
		if($url_5_substr == "http:") {

			$url_5 = "" . $linha['url_5'];

		} elseif($url_5_substr == "https") {

			$url_5 = "" . $linha['url_5'];

		} elseif($url_5_substr <> "https") {

			$url_5 = "https://" . $linha['url_5'];

		}

	} else {

		$url_5 = "";

	}

	//url_area_cliente
	
	if ($linha['url_area_cliente'] == true) {

		$url_area_cliente_substr = substr($linha['url_area_cliente'],0,5);
		//$url_area_cliente_strlen = strlen($linha['url_area_cliente']);
		
		if($url_area_cliente_substr == "http:") {

			$url_area_cliente = "" . $linha['url_area_cliente'];

		} elseif($url_area_cliente_substr == "https") {

			$url_area_cliente = "" . $linha['url_area_cliente'];

		} elseif($url_area_cliente_substr <> "https") {

			$url_area_cliente = "https://" . $linha['url_area_cliente'];

		}

	} else {

		$url_area_cliente = "";

	}

}

?>