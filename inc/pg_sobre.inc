<?php if ($detect->isMobile()) : ?>
<?php else : ?>
	<section id="institucional">
		<header id="wrap">
			<div class="container">
				<span class="int-titulo">Sobre</span>
				<span class="int-li-img"><img src="<?php echo $urlsite ?>/images/blog-li-img.jpg" width="1103" height="428"></span>
				<span class="int-li-detalhes"><?php echo $sobre ?></span>
			</div>
		</header>
	</section>
<?php endif; ?>