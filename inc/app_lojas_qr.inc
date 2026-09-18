<?php
/**
 * O CARTAO DO QR CODE: a camera do celular aponta e a loja abre.
 *
 * Quem inclui pode mandar $app_qr_tam ("g" no banner, "p" nas secoes). O QR do
 * Android so aparece quando a loja publicou; ate la fica so o da Apple, que e
 * o que resolve para quem esta lendo agora.
 *
 * O TAMANHO TEM QUE CASAR COM O DO BOTAO do mesmo bloco. Desde 18/09/2026 as duas fileiras usam a
 * MESMA largura de coluna, entao botao "g" com QR "p" deixa a de cima 132px mais larga que a de
 * baixo e o bloco volta a parecer torto. Quando este arquivo entrar logo depois de
 * app_lojas_botoes.inc, repita ali o mesmo tamanho. Onde ele aparece sozinho (pg_assine.inc, que
 * lista as lojas em outro desenho) o "p" e o certo.
 *
 * No CELULAR o QR nao serve para nada (a pessoa ja esta com o telefone na mao),
 * entao o CSS esconde este bloco e deixa so os botoes das lojas.
 */
$app_qr_tam = isset($app_qr_tam) ? $app_qr_tam : "p";
?>
<div class="app-qr app-qr-<?php echo $app_qr_tam ?>">
<?php if ($app_lj_ios_no_ar == true) { ?>
	<div class="app-qr-item">
		<img src="<?php echo $urlsite ?>/images/qr-app-ios.svg" alt="QR code para baixar o aplicativo na App Store" class="app-qr-img" width="120" height="120" loading="lazy">
		<span class="app-qr-loja">App Store</span>
	</div>
<?php } ?>
<?php if ($app_lj_android_no_ar == true) { ?>
	<div class="app-qr-item">
		<img src="<?php echo $urlsite ?>/images/qr-app-android.svg" alt="QR code para baixar o aplicativo no Google Play" class="app-qr-img" width="120" height="120" loading="lazy">
		<span class="app-qr-loja">Google Play</span>
	</div>
<?php } ?>
	<span class="app-qr-dica"><?php echo $app_lj_qr_texto ?></span>
</div>
<?php unset($app_qr_tam); ?>
