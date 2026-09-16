<?php
/**
 * O BANNER DO APLICATIVO no carrossel da home.
 *
 * Entra como PRIMEIRO slide e gira junto com os outros: o script do carrossel
 * (`js/slideshow/js/index.js`) procura `.slide` dentro de `.slideshow`, entao
 * um slide estatico no comeco da lista participa do rodizio sem nenhuma
 * mudanca no JavaScript. Quem inclui soma 1 nas bolinhas da paginacao.
 *
 * Por que estatico e nao uma linha na tabela `slides`: o banner tem texto,
 * botoes de loja e QR code de verdade, e nao uma imagem plana com um link por
 * cima. Assim ele fica nitido em qualquer tela, o QR nunca sai borrado e os
 * enderecos das lojas vivem num lugar so (`inc/app_lojas.inc`).
 */
?>
							<div class="slide is-active slide-app">
								<div class="slide-content">
									<div class="container caption">
										<div class="slide-app-bloco">
											<span class="slide-app-tag">Novidade · já disponível</span>
											<span class="slide-app-titulo">O aplicativo da <?php echo $tsite ?><br>chegou para facilitar<br>a sua vida</span>
											<span class="slide-app-intro"><?php echo $app_lj_chamada ?></span>
											<ul class="slide-app-vantagens">
<?php foreach ($app_lj_vantagens as $app_lj_vnt) { ?>
												<li><?php echo $app_lj_vnt ?></li>
<?php } ?>
											</ul>
											<div class="slide-app-acoes">
<?php $app_bt_tam = "g"; $app_bt_tema = "claro"; include("inc/app_lojas_botoes.inc"); ?>
<?php $app_qr_tam = "g"; include("inc/app_lojas_qr.inc"); ?>
											</div>
										</div>
									</div>
								</div>

								<div class="image-container slide-app-fundo"></div>
							</div>
