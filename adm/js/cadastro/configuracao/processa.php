<?php

	require_once("../../../conexao.php");
	require_once("../../../inc/funcoes.php");

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{

		$sobre = addslashes(getPost('sobre'));
		$pixel = addslashes(getPost('pixel'));
		$vnt_1 = addslashes(getPost('vnt_1'));
		$sobre_3 = addslashes(getPost('sobre_3'));
		$pixel_head = addslashes(getPost('pixel_head'));
		$pixel_body = addslashes(getPost('pixel_body'));

		$query = mysqli_query($conexao,"UPDATE tb_config SET  tsite = '".getPost('tsite')."', tslogan = '".getPost('tslogan')."', usite = '".getPost('usite')."', sobre = '".$sobre."', sobre_1 = '".getPost('sobre_1')."', sobre_2 = '".getPost('sobre_2')."', sobre_3 = '". $sobre_3 ."', sobre_rodape = '".getPost('sobre_rodape')."', fone_1 = '".getPost('fone_1')."', fone_2 = '".getPost('fone_2')."', email = '".getPost('email')."', endereco = '".getPost('endereco')."', seo_descricao = '".getPost('seo_descricao')."', seo_keywords = '".getPost('seo_keywords')."', url_area_cliente = '".getPost('url_area_cliente')."', social_facebook = '".getPost('social_facebook')."', social_instagram = '".getPost('social_instagram')."', social_youtube = '".getPost('social_youtube')."', social_twitter = '".getPost('social_twitter')."', app_android = '".getPost('app_android')."', app_ios = '".getPost('app_ios')."', cnpj = '".getPost('cnpj')."', razao_social = '".getPost('razao_social')."', vnt_1 = '".$vnt_1."', vnt_2 = '".getPost('vnt_2')."', vnt_3 = '".getPost('vnt_3')."', vnt_4 = '".getPost('vnt_4')."', url_1 = '".getPost('url_1')."', url_2 = '".getPost('url_2')."', url_3 = '".getPost('url_3')."', url_4 = '".getPost('url_4')."', url_5 = '".getPost('url_5')."', pixel_head = '". $pixel_head ."', pixel_body = '". $pixel_body ."' WHERE id = '1'");
	
		echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/configuracoes\"</script>";

	}
	function getPost( $key ){
		return isset( $_POST[ $key ] ) ? filter( $_POST[ $key ] ) : null;
	}
	function filter( $var ){
		return $var;
	}
?>