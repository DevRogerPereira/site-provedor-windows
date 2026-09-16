<?php if ($detect->isMobile()) : ?>
<?php include("inc/ini_slides.inc") ?>
<?php include("inc/ini_planos_fibra_res.inc") ?>
<?php include("inc/ini_planos_fibra_emp.inc") ?>
<?php //include("inc/ini_planos_combos.inc") ?>
<?php //include("inc/ini_planos_telefonia.inc") ?>

<?php if ($url_area_cliente == true || $app_lj_tem == true) { ?>
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
<?php if ($app_lj_tem == true) { ?>
                    <div class="ant-app">
                        <span class="ant-app-titulo">Resolva tudo pelo aplicativo</span>
                        <span class="ant-app-intro"><?php echo $app_lj_chamada ?></span>
<?php $app_bt_tam = "p"; $app_bt_tema = "escuro"; include("inc/app_lojas_botoes.inc"); ?>
<?php $app_qr_tam = "p"; include("inc/app_lojas_qr.inc"); ?>
                    </div>
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

<?php if ($app_lj_tem == true) { ?>
	<section id="ini-app">
		<header id="wrap">
			<div class="container">
            	<div class="app-ul">
                	<div class="row">
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-titulo">Gerencie seu<br>plano ou resolva<br>tudo pelo celular.</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">2ª via de fatura e pagamento online</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">Suporte técnico</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">Acesse conteúdos digitais</a>
<?php $app_bt_tam = "g"; $app_bt_tema = "claro"; include("inc/app_lojas_botoes.inc"); ?>
<?php $app_qr_tam = "p"; include("inc/app_lojas_qr.inc"); ?>
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

<?php if ($url_area_cliente == true || $app_lj_tem == true) { ?>
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
<?php if ($app_lj_tem == true) { ?>
                    <div class="ant-app">
                        <span class="ant-app-titulo">Resolva tudo pelo aplicativo</span>
                        <span class="ant-app-intro"><?php echo $app_lj_chamada ?></span>
<?php $app_bt_tam = "p"; $app_bt_tema = "escuro"; include("inc/app_lojas_botoes.inc"); ?>
<?php $app_qr_tam = "p"; include("inc/app_lojas_qr.inc"); ?>
                    </div>
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

<?php if ($app_lj_tem == true) { ?>
	<section id="ini-app">
		<header id="wrap">
			<div class="container">
            	<div class="app-ul">
                	<div class="app-col">
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-titulo">Gerencie seu<br>plano ou resolva<br>tudo pelo celular.</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">2ª via de fatura e pagamento online</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">Suporte técnico</a>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="app-intro">Acesse conteúdos digitais</a>
<?php $app_bt_tam = "g"; $app_bt_tema = "claro"; include("inc/app_lojas_botoes.inc"); ?>
<?php $app_qr_tam = "p"; include("inc/app_lojas_qr.inc"); ?>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?>

<?php include("inc/ini_blog.inc") ?>

<?php include("inc/pg_assine.inc") ?>
<?php endif; ?>