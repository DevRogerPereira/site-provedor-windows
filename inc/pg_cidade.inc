<?php if ($detect->isMobile()) : ?>
	<section id="ini-cidade">
		<header id="wrap">
			<div class="container">
				<form name="" id="" action="" method="post">
                    <img src="<?php echo $urlsite ?>/images/cidade-logomarca.png" class="cid-logomarca">
                    <span class="cid-titulo"><strong>É a mais Completa!</strong><br>Estável<br>e Inovadora</span>
                    <span class="cid-intro">Onde você está?</span>
					<select name="" id="" class="cid-select" onchange="this.options[this.selectedIndex].value && (window.location = this.options[this.selectedIndex].value);">
						<option selected>Escolha uma localidade</option>
<?php

$sql = mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE del = 'N' ORDER BY url ASC");

while ($dados_planos = mysqli_fetch_object($sql)) {

//$url_list = $urlsite . "/assine";
$url_list = $urlsite . "/" . $dados_planos->url . "";

?>
						<option value="<?php echo $url_list ?>"><?php echo $dados_planos->nome ?></option>
<?php } ?>
					</select>
				</form>
			</div>
		</header>
	</section>
<?php else : ?>
	<section id="ini-cidade">
		<header id="wrap">
			<div class="container">
				<form name="" id="" action="" method="post">
                    <img src="<?php echo $urlsite ?>/images/cidade-logomarca.png" class="cid-logomarca">
                    <span class="cid-titulo"><strong>É a mais Completa!</strong><br>Estável<br>e Inovadora</span>
                    <span class="cid-intro">Onde você está?</span >
					<select name="" id="" class="cl-grid-5 cid-select" onchange="this.options[this.selectedIndex].value && (window.location = this.options[this.selectedIndex].value);">
						<option value="1" selected>Escolha uma localidade</option>
<?php

$sql = mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE del = 'N' ORDER BY url ASC");

while ($dados_planos = mysqli_fetch_object($sql)) {

//$url_list = $urlsite . "/assine";
$url_list = $urlsite . "/" . $dados_planos->url . "";

?>
						<option value="<?php echo $url_list ?>"><?php echo $dados_planos->nome ?></option>
<?php } ?>
					</select>
				</form>
			</div>
		</header>
	</section>
<?php endif; ?>