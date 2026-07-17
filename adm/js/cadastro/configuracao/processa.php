<?php
	require_once("../../../inc/guard_ajax.php"); // auth: nao abre banco sem login

	require_once("../../../conexao.php");
	require_once("../../../inc/funcoes.php");

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{

		// Campo que NAO veio no formulario MANTEM o valor atual do banco.
		// (Antes, salvar as configuracoes apagava fone_1, usite, tslogan, urls,
		// endereco, razao_social etc., porque o formulario nao envia todos os campos
		// que o UPDATE gravava — cada salvamento zerava esses dados no site.)
		$atual = mysqli_fetch_assoc(mysqli_query($conexao, "SELECT * FROM tb_config WHERE id = '1'"));

		$campos = array('tsite','tslogan','usite','sobre','sobre_1','sobre_2','sobre_3','sobre_rodape',
			'fone_1','fone_2','email','endereco','seo_descricao','seo_keywords','url_area_cliente',
			'social_facebook','social_instagram','social_youtube','social_twitter','app_android','app_ios',
			'cnpj','razao_social','vnt_1','vnt_2','vnt_3','vnt_4','url_1','url_2','url_3','url_4','url_5',
			'pixel_head','pixel_body');

		$sets = array();
		foreach ($campos as $campo) {
			if (array_key_exists($campo, $_POST)) {
				$valor = $_POST[$campo];
			} else {
				$valor = isset($atual[$campo]) ? $atual[$campo] : '';
			}
			$sets[] = $campo . " = '" . addslashes($valor) . "'";
		}

		$query = mysqli_query($conexao, "UPDATE tb_config SET " . implode(', ', $sets) . " WHERE id = '1'");

		echo "<script language=\"javascript\">window.location=\"" . $urlsite . "/adm/configuracoes\"</script>";

	}
?>
