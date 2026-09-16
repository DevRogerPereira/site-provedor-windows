<?php
/**
 * OS BOTOES DAS LOJAS, desenhados uma vez e usados em toda parte.
 *
 * Quem inclui manda o tamanho em $app_bt_tam ("g" para o banner, "p" para as
 * listas) e, se quiser, $app_bt_tema ("claro" sobre fundo escuro, "escuro"
 * sobre fundo claro). As variaveis sao limpas no fim, para o proximo include
 * nao herdar a escolha do anterior.
 *
 * A loja que ainda nao publicou vira um bloco "Em breve" sem link: melhor do
 * que mandar o cliente para uma pagina que nao existe.
 */
$app_bt_tam = isset($app_bt_tam) ? $app_bt_tam : "p";
$app_bt_tema = isset($app_bt_tema) ? $app_bt_tema : "escuro";
$app_bt_classe = "app-lojas app-lojas-" . $app_bt_tam . " app-lojas-" . $app_bt_tema;
?>
<div class="<?php echo $app_bt_classe ?>">
<?php if ($app_lj_ios_no_ar == true) { ?>
	<a href="<?php echo $app_lj_ios ?>" target="_blank" rel="noopener" class="app-loja app-loja-ios" aria-label="Baixar o aplicativo na App Store">
		<span class="app-loja-icone" aria-hidden="true">
			<svg viewBox="0 0 24 24" focusable="false"><path d="M16.365 1.43c0 1.14-.42 2.2-1.26 3.02-.9.9-1.98 1.42-3.12 1.33-.03-1.1.44-2.21 1.25-3 .83-.82 2.06-1.4 3.13-1.35zM20.7 17.2c-.48 1.1-.71 1.6-1.33 2.58-.87 1.36-2.1 3.05-3.62 3.06-1.35.01-1.7-.88-3.53-.87-1.83.01-2.21.89-3.56.88-1.52-.01-2.68-1.54-3.55-2.9-2.44-3.8-2.7-8.26-1.19-10.63C5.14 7.6 6.86 6.62 8.48 6.62c1.65 0 2.69.9 4.05.9 1.32 0 2.13-.9 4.04-.9 1.44 0 2.97.79 4.06 2.15-3.57 1.96-2.99 7.06.07 8.43z"/></svg>
		</span>
		<span class="app-loja-txt">
			<span class="app-loja-txt-1">Baixe na</span>
			<span class="app-loja-txt-2">App Store</span>
		</span>
	</a>
<?php } ?>
<?php if ($app_lj_android_no_ar == true) { ?>
	<a href="<?php echo $app_lj_android ?>" target="_blank" rel="noopener" class="app-loja app-loja-android" aria-label="Baixar o aplicativo no Google Play">
		<span class="app-loja-icone" aria-hidden="true">
			<svg viewBox="0 0 24 24" focusable="false"><path d="M3.6 1.84c-.24.25-.38.64-.38 1.15v18.02c0 .51.14.9.38 1.15l.06.06 10.1-10.1v-.24L3.66 1.78l-.06.06zM17.5 15.9l-3.37-3.37v-.24l3.37-3.37.08.05 3.99 2.27c1.14.64 1.14 1.7 0 2.35l-3.99 2.26-.08.05zM16.6 16.85 13.15 13.4 3.6 22.95c.38.4 1 .45 1.7.06l11.3-6.16M16.6 7.15 5.3.99c-.7-.4-1.32-.35-1.7.05l9.55 9.55 3.45-3.44z"/></svg>
		</span>
		<span class="app-loja-txt">
			<span class="app-loja-txt-1">Baixe no</span>
			<span class="app-loja-txt-2">Google Play</span>
		</span>
	</a>
<?php } else { ?>
	<span class="app-loja app-loja-android app-loja-breve" aria-label="Aplicativo para Android em breve no Google Play">
		<span class="app-loja-icone" aria-hidden="true">
			<svg viewBox="0 0 24 24" focusable="false"><path d="M3.6 1.84c-.24.25-.38.64-.38 1.15v18.02c0 .51.14.9.38 1.15l.06.06 10.1-10.1v-.24L3.66 1.78l-.06.06zM17.5 15.9l-3.37-3.37v-.24l3.37-3.37.08.05 3.99 2.27c1.14.64 1.14 1.7 0 2.35l-3.99 2.26-.08.05zM16.6 16.85 13.15 13.4 3.6 22.95c.38.4 1 .45 1.7.06l11.3-6.16M16.6 7.15 5.3.99c-.7-.4-1.32-.35-1.7.05l9.55 9.55 3.45-3.44z"/></svg>
		</span>
		<span class="app-loja-txt">
			<span class="app-loja-txt-1">Em breve no</span>
			<span class="app-loja-txt-2">Google Play</span>
		</span>
	</span>
<?php } ?>
</div>
<?php unset($app_bt_tam, $app_bt_tema, $app_bt_classe); ?>
