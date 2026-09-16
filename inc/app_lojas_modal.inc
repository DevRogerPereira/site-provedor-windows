<?php
/**
 * A JANELA "Baixe o aplicativo": QR code para quem esta no computador e botao
 * de loja para quem ja esta no celular.
 *
 * Abre pelo link do cabecalho (`data-app-abrir`) e fecha no X, no fundo escuro
 * ou no Esc. Sem biblioteca: e um bloco escondido e vinte linhas de JavaScript,
 * porque um modal de terceiro so para isto pesaria mais que a pagina inteira.
 *
 * Fica no rodape, uma vez por pagina.
 */
?>
<div id="app-modal" class="app-modal" hidden>
	<div class="app-modal-fundo" data-app-fechar></div>
	<div class="app-modal-caixa" role="dialog" aria-modal="true" aria-labelledby="app-modal-titulo">
		<button type="button" class="app-modal-x" data-app-fechar aria-label="Fechar">&times;</button>
		<span class="app-modal-tag">Novidade</span>
		<span class="app-modal-titulo" id="app-modal-titulo"><?php echo $app_lj_titulo ?></span>
		<span class="app-modal-intro"><?php echo $app_lj_chamada ?></span>
		<ul class="app-modal-vantagens">
<?php foreach ($app_lj_vantagens as $app_lj_vnt) { ?>
			<li><?php echo $app_lj_vnt ?></li>
<?php } ?>
		</ul>
<?php $app_qr_tam = "g"; include("inc/app_lojas_qr.inc"); ?>
<?php $app_bt_tam = "g"; $app_bt_tema = "escuro"; include("inc/app_lojas_botoes.inc"); ?>
	</div>
</div>
<script>
(function () {
	var modal = document.getElementById('app-modal');
	if (!modal) return;
	var ultimoFoco = null;

	function abrir(e) {
		if (e) e.preventDefault();
		ultimoFoco = document.activeElement;
		modal.hidden = false;
		document.body.classList.add('app-modal-aberto');
		var x = modal.querySelector('.app-modal-x');
		if (x) x.focus();
	}
	function fechar() {
		modal.hidden = true;
		document.body.classList.remove('app-modal-aberto');
		// devolve o foco para o link que abriu: quem navega por teclado nao
		// volta para o topo da pagina
		if (ultimoFoco && ultimoFoco.focus) ultimoFoco.focus();
	}

	document.addEventListener('click', function (e) {
		var alvo = e.target.closest ? e.target.closest('[data-app-abrir]') : null;
		if (alvo) { abrir(e); return; }
		if (e.target.closest && e.target.closest('[data-app-fechar]')) fechar();
	});
	document.addEventListener('keydown', function (e) {
		if (e.key === 'Escape' && !modal.hidden) fechar();
	});
})();
</script>
