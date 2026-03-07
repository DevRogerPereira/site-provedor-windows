<?php if ($detect->isMobile()) : ?>
<?php include("inc/ini_slides.inc") ?>
<?php include("inc/ini_planos_fibra_res.inc") ?>
<?php include("inc/ini_planos_fibra_emp.inc") ?>
<?php //include("inc/ini_planos_combos.inc") ?>
<?php //include("inc/ini_planos_telefonia.inc") ?>

<?php if ($url_area_cliente == true || $app_android == true || $app_ios == true) { ?>
	<section id="ini-atendimento">
		<header id="wrap">
			<div class="container">
                    <span class="ant-titulo">Atendimento express</span>
                    <span class="ant-intro">Clique e faça você mesmo</span>
<?php if ($url_area_cliente == true) { ?>
                    <a href="<?php echo $url_area_cliente ?>" target="_blank" class="ant-li-1">Segunda via de boletos<span>Emita a 2ª via de boleto.</span></a>
<?php } ?>
<?php if ($fone_2 == true) { ?>
                    <a href="<?php echo $fone_2 ?>" target="_blank" class="ant-li-2">Mudar meu plano<span>Também disponível no App</span></a>
<?php } ?>
<?php if ($app_android == true) { ?>
                    <a href="<?php echo $app_android ?>" target="_blank" class="ant-li-3">Baixar nosso App<span>Baixe nosso aplicativo no seu celular</span></a>
<?php } ?>
<?php if ($app_ios == true) { ?>
                    <a href="<?php echo $app_ios ?>" target="_blank" class="ant-li-4">Baixar nosso App<span>Baixe nosso aplicativo no seu celular</span></a>
<?php } ?>
			</div>
		</header>
	</section>
<?php } ?>
<?php if ($sobre == true) { ?>
	<section id="ini-institucional">
		<header id="wrap">
			<div class="container">
				<a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="int-titulo"><?php echo $tsite ?> é a melhor internet pra você</a>
				<a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="int-intro"><?php echo $sobre ?></a>
			</div>
		</header>
	</section>
<?php } ?>

<?php include("inc/ini_depoimentos.inc") ?>

<?php include("inc/ini_duvidas.inc") ?>

<?php if ($app_android == true || $app_ios == true) { ?>
	<section id="ini-app">
		<header id="wrap">
			<div class="container">
            	<div class="app-ul">
                	<div class="row">
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-titulo">Gerencie seu<br>plano ou resolva<br>tudo pelo celular.</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">2ª via de fatura e pagamento online</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">Suporte técnico</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">Acesse conteúdos digitais</a>
<?php if ($app_android == true) { ?>
                        <a href="<?php echo $app_android ?>" target="_blank" class="cl-col cl-grid-6 app-icon-android"><img src="<?php echo $urlsite ?>/images/app-li-android.jpg"></a>
<?php } ?>
<?php if ($app_ios == true) { ?>
                        <a href="<?php echo $app_ios ?>" target="_blank" class="cl-col cl-grid-6 app-icon-ios"><img src="<?php echo $urlsite ?>/images/app-li-ios.jpg"></a>
<?php } ?>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?>

<?php include("inc/ini_blog.inc") ?>

<?php include("inc/pg_assine.inc") ?>

<?php else : ?>

<?php include("inc/ini_slides.inc") ?>
<?php include("inc/ini_planos_fibra_res.inc") ?>
<?php include("inc/ini_planos_fibra_emp.inc") ?>
<?php //include("inc/ini_planos_combos.inc") ?>
<?php //include("inc/ini_planos_telefonia.inc") ?>

<?php if ($url_area_cliente == true || $app_android == true || $app_ios == true) { ?>
	<section id="ini-atendimento">
		<header id="wrap">
			<div class="container">
            	<div class="ant-ul">
                    <span class="ant-titulo">Atendimento express</span>
                    <span class="ant-intro">Clique e faça você mesmo</span>
<?php if ($url_area_cliente == true) { ?>
                    <a href="<?php echo $url_area_cliente ?>" target="_blank" class="ant-li-1">Segunda via de boletos<span>Emita a 2ª via de boleto.</span></a>
<?php } ?>
<?php if ($fone_2 == true) { ?>
                    <a href="<?php echo $fone_2 ?>" target="_blank" class="ant-li-2">Mudar meu plano<span>Também disponível no App</span></a>
<?php } ?>
<?php if ($app_android == true) { ?>
                    <a href="<?php echo $app_android ?>" target="_blank" class="ant-li-3">Baixar nosso App<span>Baixe nosso aplicativo no seu celular</span></a>
<?php } ?>
<?php if ($app_ios == true) { ?>
                    <a href="<?php echo $app_ios ?>" target="_blank" class="ant-li-4">Baixar nosso App<span>Baixe nosso aplicativo no seu celular</span></a>
<?php } ?>
                </div>
			</div>
		</header>
	</section>
<?php } ?>
<?php if ($sobre == true) { ?>
	<section id="ini-institucional">
		<header id="wrap">
			<div class="container">
				<a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="cl-grid-6 int-titulo"><?php echo $tsite ?> é a<br>melhor internet<br>pra você</a>
				<a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="cl-grid-5 int-intro"><?php echo $sobre ?></a>
			</div>
		</header>
	</section>
<?php } ?>

<?php include("inc/ini_depoimentos.inc") ?>

<?php include("inc/ini_duvidas.inc") ?>

<?php if ($app_android == true || $app_ios == true) { ?>
	<section id="ini-app">
		<header id="wrap">
			<div class="container">
            	<div class="app-ul">
                	<div class="app-col">
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-titulo">Gerencie seu<br>plano ou resolva<br>tudo pelo celular.</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">2ª via de fatura e pagamento online</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">Suporte técnico</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">Acesse conteúdos digitais</a>
<?php if ($app_android == true) { ?>
                        <a href="<?php echo $app_android ?>" target="_blank" class="app-icon-android"><img src="<?php echo $urlsite ?>/images/app-li-android.jpg"></a>
<?php } ?>
<?php if ($app_ios == true) { ?>
                        <a href="<?php echo $app_ios ?>" target="_blank" class="app-icon-ios"><img src="<?php echo $urlsite ?>/images/app-li-ios.jpg"></a>
<?php } ?>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?>

<?php include("inc/ini_blog.inc") ?>

<?php include("inc/pg_assine.inc") ?>
<?php endif; ?>