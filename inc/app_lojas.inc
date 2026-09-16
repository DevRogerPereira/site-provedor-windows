<?php
/**
 * O APLICATIVO DA LINKNET NAS LOJAS: uma fonte unica para o site inteiro.
 *
 * O aplicativo entrou na App Store em 16/09/2026 (versao 1.0). Este arquivo
 * guarda os enderecos das lojas, o estado de cada uma e os textos, para o
 * banner do carrossel, o cabecalho, o Atendimento express, os Canais de
 * atendimento, o rodape e a janela do QR code dizerem sempre a mesma coisa.
 *
 * QUANDO O GOOGLE APROVAR: trocar $app_lj_android_no_ar para true. E so isso.
 * Ate la o botao da Play Store aparece como "Em breve", sem link morto.
 *
 * O painel do admin continua mandando: se alguem preencher os campos
 * `app_ios` / `app_android` em `tb_config`, eles vencem os padroes daqui.
 */

// ---------------------------------------------------------------------------
// Estado de cada loja
// ---------------------------------------------------------------------------

/** A App Store ja publicou (aprovado em 16/09/2026). */
$app_lj_ios_no_ar = true;

/** A Play Store ainda esta analisando: vira true no dia da aprovacao. */
$app_lj_android_no_ar = false;

// ---------------------------------------------------------------------------
// Enderecos
// ---------------------------------------------------------------------------

$app_lj_ios = ($app_ios == true) ? $app_ios : "https://apps.apple.com/br/app/id6811297754";
$app_lj_android = ($app_android == true) ? $app_android : "https://play.google.com/store/apps/details?id=net.linknetbandalarga.chat";

/** Alguma loja para mostrar? */
$app_lj_tem = ($app_lj_ios_no_ar == true || $app_lj_android_no_ar == true);

// ---------------------------------------------------------------------------
// Textos (um lugar so, para nao divergirem entre as secoes)
// ---------------------------------------------------------------------------

$app_lj_titulo = "Baixe o aplicativo da " . $tsite;
$app_lj_chamada = "Seu plano, sua fatura e o suporte na palma da mão.";
$app_lj_qr_texto = "Aponte a câmera do celular";

/**
 * Os tres motivos que cabem num banner. Mais do que isso ninguem le.
 */
$app_lj_vantagens = array(
	"2ª via de boleto e Pix na hora",
	"Suporte e chat com a nossa equipe",
	"Teste de velocidade e status da conexão"
);
