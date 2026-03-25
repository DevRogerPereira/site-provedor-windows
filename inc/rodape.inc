<?php if($pagina <> "cidade") { // ini if $pagina ?>
<?php if ($detect->isMobile()) : ?>
	<section id="rodape">
		<header id="wrap">
			<div class="container">
            	<div class="row rdp-nav-ul">
                	<div class="row">
<?php if ($fone_2 == true) { ?>
                        <a href="<?php echo $fone_2 ?>" target="_blank" class="rdp-nav-whatsapp">Falar pelo WhatsApp<br><?php echo $tsite ?></a>
<?php } ?>
                    </div>
                </div>
            	<div class="row rdp-ul">
                	<div class="row">
						<a href="<?php echo $urlsite . "/" . $cidade ?>" class="rdp-li-img"><img src="<?php echo $urlsite ?>/images/logomarca-rodape.png"></a>

<?php if ($social_facebook == true) { ?>
                        <a href="<?php echo $social_facebook ?>" target="_blank" class="rod-social-li-facebook"></a>
<?php } ?>
<?php if ($social_instagram == true) { ?>
                        <a href="<?php echo $social_instagram ?>" target="_blank" class="rod-social-li-instagram"></a>
<?php } ?>
<?php if ($social_youtube == true) { ?>
                        <a href="<?php echo $social_youtube ?>" target="_blank" class="rod-social-li-youtube"></a>
<?php } ?>
<?php if ($social_twitter == true) { ?>
                        <a href="<?php echo $social_twitter ?>" target="_blank" class="rod-social-li-twitter"></a>
<?php } ?>
                    </div>
                	<div class="row">
                        <span class="rdp-li-titulo">Menu</span>
<?php if($sobre == true) { ?>
						<a href="<?php echo $urlsite . "/" . $cidade . "#ini-institucional" ?>" class="rdp-li-intro">A <?php echo $tsite ?></a>
<?php } ?>
<?php if($dados_rows_blog > 0) { ?>
						<a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="rdp-li-intro">Blog</a>
<?php } ?>
<?php if($dados_rows_contratos > 0) { ?>
						<a href="javascript:;" onClick="abreFecha('.nav-contratos')" class="rdp-li-intro">Contratos</a>
<?php } ?>
						<a href="<?php echo $urlsite . "/" . $cidade . "/atendimento/" ?>" class="rdp-li-intro">Atendimento</a>
                    </div>
                	<div class="row">
                        <span class="rdp-li-titulo">Fale Conosco</span>
<?php if ($dados_cidade_telefone == true) { ?>
                        <a href="tel:<?php echo $dados_cidade_telefone_whatsapp ?>" target="_blank" class="rdp-li-whatsapp"><?php echo $dados_cidade_telefone ?></a>
<?php } ?>
<?php if ($dados_cidade_telefone_2 == true) { ?>
                        <a href="<?php echo "http://api.whatsapp.com/send?1=pt_BR&phone=55".$dados_cidade_telefone_2_whatsapp."&text=Quero falar com a " . $tsite . "\"" ?>" target="_blank" class="rdp-li-telefone"><?php echo $dados_cidade_telefone_2 ?></a>
<?php } ?>
<?php if ($dados_cidade_endereco == true) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="rdp-li-intro"><?php echo $dados_cidade_endereco ?></a>
<?php } ?>
<?php if ($dados_cidade_funcionamento == true) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="rdp-li-intro"><?php echo $dados_cidade_funcionamento ?></a>
<?php } ?>
                    </div>
                    
                	<div class="row">
                        <span class="rdp-li-titulo">Aviso legal</span>
                        <a class="rdp-li-legal-img"><img src="<?php echo $urlsite ?>/images/rodape-li-anatel.png"></a>
                        <a class="rdp-li-legal-img"><img src="<?php echo $urlsite ?>/images/rodape-li-registro.png"></a>
                    </div>

                </div>
            	<div class="row">
                    <a href="https://driblepropaganda.com.br/drible-especialista-em-sites-para-provedores-rd" target="_blank" class="rdp-copyright"><?php echo "Desenvolvido por <strong>DRIBLE</strong> | ©" . date("Y") . " - " . $tsite ?> – Todos os direitos reservados.<?php if ($cnpj == true) { ?> CNPJ: <?php echo $cnpj ?><?php } ?></a>
                </div>

                <div class="row rpd-whatsapp-item">
                    <a href="<?php echo $fone_2 ?>" target="_blank" class="rpd-whatsapp"><img src="<?php echo $urlsite ?>/images/icon-whatsapp-fixed.png"></a>

                    <div class="rpd-whatsapp-detalhes">
                        <span>Olá! Seja bem vindo<br>a <?php echo $tsite ?>!<br><strong>Podemos conversar?</strong></span>
                    </div>

                </div>

			</div>
		</header>
	</section>

	<section id="cookie">
		<header id="wrap">
			<div class="container">
            	<div class="cookie-ul">
                    <p class="cookie__message">Usamos cookies para garantir que oferecemos a melhor experiência em nosso site. Se você continuar a usar este site, assumiremos que está satisfeito com ele.</p>
                    <button id="cookie__accept" class="button">Concordar</button>
                </div>
			</div>
		</header>
	</section>
<?php else : ?>
	<section id="rodape">
		<header id="wrap">
			<div class="container">
            	<div class="row rdp-nav-ul">
                	<div class="cl-col-div cl-grid-6">
<?php if ($fone_2 == true) { ?>
                        <a href="<?php echo $fone_2 ?>" target="_blank" class="rdp-nav-whatsapp">Falar pelo WhatsApp<br><?php echo $tsite ?></a>
<?php } ?>
                    </div>
                	<div class="cl-col cl-grid-6 rdp-nav-ul-dir">
<?php if ($fone_2 == true) { ?>
                        <a href="<?php echo $fone_2 ?>" target="_blank" class="rdp-nav-li-whatsapp">Whatsapp</a>
<?php } ?>
<?php if($dados_rows_plano_1 > 0 || $dados_rows_plano_2 > 0) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "#ini-planos" ?>" class="rdp-nav-li-cursos">Ver planos</a>
<?php } ?>
                    </div>
                </div>
            	<div class="row rdp-ul">
                	<div class="cl-col-div cl-grid-2">
						<a href="<?php echo $urlsite . "/" . $cidade ?>" class="rdp-li-img"><img src="<?php echo $urlsite ?>/images/logomarca-rodape.png"></a>

<?php if ($social_facebook == true) { ?>
                        <a href="<?php echo $social_facebook ?>" target="_blank" class="rod-social-li-facebook"></a>
<?php } ?>
<?php if ($social_instagram == true) { ?>
                        <a href="<?php echo $social_instagram ?>" target="_blank" class="rod-social-li-instagram"></a>
<?php } ?>
<?php if ($social_youtube == true) { ?>
                        <a href="<?php echo $social_youtube ?>" target="_blank" class="rod-social-li-youtube"></a>
<?php } ?>
<?php if ($social_twitter == true) { ?>
                        <a href="<?php echo $social_twitter ?>" target="_blank" class="rod-social-li-twitter"></a>
<?php } ?>
                    </div>
                	<div class="cl-col-div cl-grid-2">
                        <span class="rdp-li-titulo">Planos</span>
						<?php if($dados_rows_plano_1 > 0 || $dados_rows_plano_2 > 0) { ?>
						<a href="<?php echo $urlsite . "/" . $cidade . "#ini-planos" ?>" class="rdp-li-intro">Internet</a>
						<?php } ?>
						<?php if($dados_rows_plano_2 > 0 || $dados_rows_plano_4 > 0) { ?>
						<a href="<?php echo $urlsite . "/" . $cidade . "#ini-planos" ?>" class="rdp-li-intro">Empresas</a>
						<?php } ?>
						<?php if($dados_rows_plano_6 > 0) { ?>
						<a href="<?php echo $urlsite . "/" . $cidade . "#ini-pln-combos" ?>" class="rdp-li-intro">Combos</a>
						<?php } ?>
						<?php if($dados_rows_plano_7 > 0) { ?>
						<a href="<?php echo $urlsite . "/" . $cidade . "#ini-pln-telefonia" ?>" class="rdp-li-intro">Telefonia</a>
						<?php } ?>
                    </div>
                	<div class="cl-col-div cl-grid-2">
                        <a class="rdp-li-titulo">Menu</a>
<?php if($sobre == true) { ?>
						<a href="<?php echo $urlsite . "/" . $cidade . "#ini-institucional" ?>" class="rdp-li-intro">A <?php echo $tsite ?></a>
<?php } ?>
<?php if($dados_rows_blog > 0) { ?>
						<a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="rdp-li-intro">Blog</a>
<?php } ?>
<?php if($dados_rows_contratos > 0) { ?>
						<a href="javascript:;" onClick="abreFecha('.nav-contratos')" class="rdp-li-intro">Contratos</a>
<?php } ?>
						<a href="<?php echo $urlsite . "/" . $cidade . "/atendimento/" ?>" class="rdp-li-intro">Atendimento</a>
                    </div>
                	<div class="cl-col-div cl-grid-3">
                        <span class="rdp-li-titulo">Fale Conosco</span>
<?php if ($dados_cidade_telefone == true) { ?>
                        <a href="tel:<?php echo $dados_cidade_telefone_whatsapp ?>" target="_blank" class="rdp-li-telefone"><?php echo $dados_cidade_telefone ?></a>
<?php } ?>
<?php if ($dados_cidade_telefone_2 == true) { ?>
                        <a href="<?php echo "http://api.whatsapp.com/send?1=pt_BR&phone=55".$dados_cidade_telefone_2_whatsapp."&text=Quero falar com a " . $tsite . "\"" ?>" target="_blank" class="rdp-li-whatsapp"><?php echo $dados_cidade_telefone_2 ?></a>
<?php } ?>
<?php if ($dados_cidade_endereco == true) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="rdp-li-intro"><?php echo $dados_cidade_endereco ?></a>
<?php } ?>
<?php if ($dados_cidade_funcionamento == true) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="rdp-li-intro"><?php echo $dados_cidade_funcionamento ?></a>
<?php } ?>
                    </div>

                	<div class="cl-col cl-grid-2">
                        <span class="rdp-li-titulo">Aviso legal</span>
                        <a class="rdp-li-legal-img"><img src="<?php echo $urlsite ?>/images/rodape-li-anatel.png"></a>
                        <a class="rdp-li-legal-img"><img src="<?php echo $urlsite ?>/images/rodape-li-registro.png"></a>
                    </div>

                </div>
            	<div class="row">
                    <a href="https://driblepropaganda.com.br/drible-especialista-em-sites-para-provedores-rd" target="_blank" class="rdp-copyright"><?php echo "Desenvolvido por <strong>DRIBLE</strong> | ©" . date("Y") . " - " . $tsite ?> – Todos os direitos reservados.<?php if ($cnpj == true) { ?> CNPJ: <?php echo $cnpj ?><?php } ?></a>
                </div>

                <div class="row rpd-whatsapp-item">
                    <a href="<?php echo $fone_2 ?>" target="_blank" class="rpd-whatsapp"><img src="<?php echo $urlsite ?>/images/icon-whatsapp-fixed.png"></a>

                    <div class="rpd-whatsapp-detalhes">
                        <span>Olá! Seja bem vindo<br>a <?php echo $tsite ?>!<br><strong>Podemos conversar?</strong></span>
                    </div>

                </div>

			</div>
		</header>
	</section>

	<section id="cookie">
		<header id="wrap">
			<div class="container">
            	<div class="cookie-ul">
                    <p class="cookie__message">Usamos cookies para garantir que oferecemos a melhor experiência em nosso site. Se você continuar a usar este site, assumiremos que está satisfeito com ele.</p>
                    <button id="cookie__accept" class="button">Concordar</button>
                </div>
			</div>
		</header>
	</section>
<?php endif; ?>
<?php } // fim if $pagina ?>
<script type="text/javascript" ><?php include("js/jquery.min.js"); ?></script>
<?php if ($detect->isMobile()) : ?>
<script type="text/javascript" ><?php include("js/scripts-m.js"); ?></script>
<?php else : ?>
<script type="text/javascript" ><?php include("js/scripts.js"); ?></script>
<?php endif; ?>
<script type="text/javascript" ><?php include("js/slideshow/js/TweenMax.min.js"); ?></script>
<script type="text/javascript" ><?php include("js/slideshow/js/index.js"); ?></script>

<script type="text/javascript" ><?php include("js/jquery.inputmask.bundle.js"); ?></script>
<script type="text/javascript">
    $(document).ready(function() {
      $("#input_telefone").inputmask({
        mask: ["(99) 9999-9999", "(99) 99999-9999" ],
        keepStatic: true
      });
      $("#cpf").inputmask({
        mask: ["999.999.999-99", "99.999.999/9999-99" ],
        keepStatic: true
      });
      $("#cep").inputmask({
        mask: ["99999-999" ],
        keepStatic: true
      });
    });
</script>

<script type="text/javascript"><?php include("js/jquery.validate.js"); ?></script>
<script type="text/javascript">
$(document).ready(function(){
		$('#form').validate({
			rules: {
				input_nome: { required: true, minlength: 2 },
				input_telefone: { required: true, minlength: 2 },
				cpf: { required: true, minlength: 10 }
			},
			messages: {
				input_nome: { required: '<h6 class="en_input_alerta">Diga seu nome.</h6>', minlength: '<h6 class="en_input_alerta"><i class="ad_iten_icon_alerta fa fa-info-circle" aria-hidden="true"></i>Preencha este campo.</h6>' },
				input_telefone: { required: '<h6 class="en_input_alerta">Diga seu telefone.</h6>', minlength: '<h6 class="en_input_alerta"><i class="ad_iten_icon_alerta fa fa-info-circle" aria-hidden="true"></i>Preencha este campo.</h6>' },
				cpf: { required: '<h6 class="en_input_alerta">Diga seu CPF.</h6>', minlength: '<h6 class="en_input_alerta">Preencha este campo.</h6>' }
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/js/orcamento/processa.php",
					data: dados,
					beforeSend: function(data) {
						$("#form-carrega").html( '' );
						$("#form").html("<div class=\"row\"><span class=\"cad-form-conf-titulo\">Enviando.</span><span class=\"cad-form-conf-intro\">Aguarde enquanto enviamos sua mensagem.</span></div>");
					},
					success: function( data )
					{
						$("input[name='nome']").val( '' );
						$("input[name='email']").val( '' );
						$("input[name='telefone']").val( '' );
						$("textarea[name='mensagem']").val( '' );
						$('#form').html(data);
					}
				});

				return false;
			}
		});
	});
</script>

<?php if ($detect->isMobile()) : ?>
<script type="text/javascript"><?php include("js/menu_acoes/dropit.js"); ?></script>
<script type="text/javascript">
(function($){$(document).ready(function(){
	$('#menu-acao').dropit(); $('#menu-acao2').dropit(); });hljs.initHighlightingOnLoad();})(window.jQuery);
</script>
<?php else : ?>
<?php endif; ?>

<script>
function abreFecha(sel) {
  $(sel).slideToggle();
}
</script>

<script type="text/javascript" ><?php include("js/jquery-scrolltofixed-min.js"); ?></script>

<script type="text/javascript">
    $(document).ready(function() {

        $('.header').scrollToFixed();

        $('.footer').scrollToFixed( {
            bottom: 0,
            limit: $('.footer').offset().top
        });

        var summaries = $('.summary');
        summaries.each(function(i) {
            var summary = $(summaries[i]);
            var next = summaries[i + 1];

            summary.scrollToFixed({
                marginTop: $('.header').outerHeight(true) + 10,
                limit: function() {
                    var limit = 0;
                    if (next) {
                        limit = $(next).offset().top - $(this).outerHeight(true) + 1000;
                    } else {
                        limit = $('.footer').offset().top - $(this).outerHeight(true) - 10;
                    }
                    return limit;
                },
                zIndex: 999
            });
        });
    });
</script>

<section class="melhorplano-selos-flutuantes" aria-label="Selos Melhor Provedor">
	<a class="melhorplano-selo melhorplano-selo-2026" href="https://melhorplano.net/internet-banda-larga/mg/divinopolis#premio" title="Vencedor Melhor Provedor Divinopolis 2026">
		<img width="150px" height="87.02px" src="https://cdn.melhorplano.net/strapi/melhor_provedor_municipal_2026_d68c7f659c.svg" alt="Vencedor Melhor Provedor Divinopolis 2026">
	</a>
	<a class="melhorplano-selo melhorplano-selo-2025" href="https://melhorplano.net/internet-banda-larga/mg/divinopolis#premio" title="Vencedor Melhor Provedor Divinopolis 2025">
		<img width="150px" height="87.02px" src="https://cdn.melhorplano.net/cms/2025/01/24/67939e9cc2db3selo-melhor-provedor-municipal-2025.svg" alt="Vencedor Melhor Provedor Divinopolis 2025">
	</a>
</section>

<script>
	const cookieAlert = document.querySelector("#cookie");
	const cookieAcceptButton = document.querySelector("#cookie__accept");
	const cookie__accept = localStorage.getItem("cookie__accept");

	window.onload = function() {
	cookieAlert.classList.add('show');

	if (cookie__accept == "true") {
		cookieAlert.style.display = "none";
		cookieAlert.classList.remove('show');
	} else {
		localStorage.setItem("cookie__accept", "false");
	}

	function acceptCookie() {
		localStorage.setItem("cookie__accept", "true");
		cookieAlert.classList.add("fade-out");

		setTimeout(() => {
			cookieAlert.style.display = "none";
		}, 300);
	}

	cookieAcceptButton.addEventListener("click", acceptCookie);
	};
</script>
<?php if(isset($pixel_body)) { echo $pixel_body; } ?>