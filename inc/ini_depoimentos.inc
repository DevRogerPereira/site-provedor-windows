<?php if ($detect->isMobile()) : ?>
<?php if($dados_rows_depoimentos > 0) { ?>
	<section id="ini-depoimentos">
		<header id="wrap">
			<div class="container">

<?php if ($url_area_cliente == true || $dados_cidade_telefone_2 == true || $teste_velocidade == true || $dados_cidade_telefone == true) { ?>
            	<div class="row">
            		<a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="titulo"><?php echo $tsite ?> serviços</a>
            	</div>
            	<div class="row">
<?php if ($url_area_cliente == true) { ?>
                	<div class="dpm-num-li dpm-num-li-div">
                        <a href="<?php echo $url_area_cliente ?>" target="_blank" class="dpm-num-li-1">2ª via de boleto<span>Emitir agora</span></a>
                    </div>
<?php } ?>
<?php if ($dados_cidade_telefone == true) { ?>
                	<div class="dpm-num-li dpm-num-li-div">
                        <a href="tel:<?php echo $dados_cidade_telefone_whatsapp ?>" target="_blank" class="dpm-num-li-4">Central de atendimento<span><?php echo $dados_cidade_telefone ?></span></a>
                    </div>
<?php } ?>
<?php if ($fone_2 == true) { ?>
                	<div class="dpm-num-li dpm-num-li-div">
                        <a href="<?php echo $fone_2 ?>" target="_blank" class="dpm-num-li-2">WhatsApp<span><?php echo $dados_cidade_telefone_2 ?></span></a>
                    </div>
<?php } ?>
<?php if ($url_4 == true) { ?>
                	<div class="dpm-num-li">
                        <a href="<?php echo $url_4 ?>" target="_blank" class="dpm-num-li-3">Teste de velocidade<span>Testar agora</span></a>
                    </div>
<?php } ?>
            	</div>
<?php } ?>

                        <div class="row">
                            <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="titulo"><?php echo $tsite ?><br>serviços</a>
<?php if ($vnt_1 == true) { ?>
                            <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="dpm-est-li"><?php echo $vnt_1 ?><span><?php echo $vnt_1_intro ?></span></a>

<?php } ?>
<?php if ($vnt_2 == true) { ?>
                            <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="dpm-est-li"><?php echo $vnt_2 ?><span><?php echo $vnt_2_intro ?></span></a>
<?php } ?>
<?php if ($vnt_3 == true) { ?>
                            <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="dpm-est-li"><?php echo $vnt_3 ?><span><?php echo $vnt_3_intro ?></span></a>
<?php } ?>
<?php if ($vnt_4 == true) { ?>
                            <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="dpm-est-li"><?php echo $vnt_4 ?><span><?php echo $vnt_4_intro ?></span></a>
<?php } ?>
                        </div>

                        <div class="row">
                            <span class="titulo">O que nossos clientes dizem sobre nós</span>
                        </div>
                        <ul>
<?php

$sql = mysqli_query($conexao,"SELECT * FROM depoimentos WHERE del = 'N' ORDER BY id DESC LIMIT 2");

while ($dados_depoimentos = mysqli_fetch_object($sql)) {

if ($dados_depoimentos->intro == true) {
	
   $dados_intro = "<span>".$dados_depoimentos->intro."</span>";
   
} else {
	
   $dados_intro = "";
   
}

?>
                            <li>
                                <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="li-depoimento"><?php echo $dados_depoimentos->depoimento ?></a>
                                <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="li-titulo"><?php echo $dados_depoimentos->nome ?></a>
                                <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="li-avaliacao"></a>
                            </li>
<?php } ?>
                        </ul>
			</div>
		</header>
	</section>
<?php } ?>
<?php else : ?>
<?php if($dados_rows_depoimentos > 0) { ?>
	<section id="ini-depoimentos">
		<header id="wrap">
			<div class="container">

<?php if ($url_area_cliente == true || $dados_cidade_telefone_2 == true || $teste_velocidade == true || $dados_cidade_telefone == true) { ?>
            	<div class="row">
            		<a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="titulo"><?php echo $tsite ?> serviços</a>
            	</div>
            	<div class="row">
<?php if ($url_area_cliente == true) { ?>
                	<div class="dpm-num-li dpm-num-li-div">
                        <a href="<?php echo $url_area_cliente ?>" target="_blank" class="dpm-num-li-1">2ª via de boleto<span>Emitir agora</span></a>
                    </div>
<?php } ?>
<?php if ($dados_cidade_telefone == true) { ?>
                	<div class="dpm-num-li dpm-num-li-div">
                        <a href="tel:<?php echo $dados_cidade_telefone_whatsapp ?>" target="_blank" class="dpm-num-li-4">Central de atendimento<span><?php echo $dados_cidade_telefone ?></span></a>
                    </div>
<?php } ?>
<?php if ($fone_2 == true) { ?>
                	<div class="dpm-num-li dpm-num-li-div">
                        <a href="<?php echo $fone_2 ?>" target="_blank" class="dpm-num-li-2">WhatsApp<span><?php echo $dados_cidade_telefone_2 ?></span></a>
                    </div>
<?php } ?>
<?php if ($url_4 == true) { ?>
                	<div class="dpm-num-li">
                        <a href="<?php echo $url_4 ?>" target="_blank" class="dpm-num-li-3">Teste de velocidade<span>Testar agora</span></a>
                    </div>
<?php } ?>
            	</div>
<?php } ?>

            	<div class="row">
                	<div class="cl-col-div cl-grid-5">
                        <div class="row">
                            <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="titulo"><?php echo $tsite ?><br>serviços</a>
<?php if ($vnt_1 == true) { ?>
                            <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="dpm-est-li"><?php echo $vnt_1 ?><span><?php echo $vnt_1_intro ?></span></a>

<?php } ?>
<?php if ($vnt_2 == true) { ?>
                            <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="dpm-est-li"><?php echo $vnt_2 ?><span><?php echo $vnt_2_intro ?></span></a>
<?php } ?>
<?php if ($vnt_3 == true) { ?>
                            <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="dpm-est-li"><?php echo $vnt_3 ?><span><?php echo $vnt_3_intro ?></span></a>
<?php } ?>
<?php if ($vnt_4 == true) { ?>
                            <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="dpm-est-li"><?php echo $vnt_4 ?><span><?php echo $vnt_4_intro ?></span></a>
<?php } ?>
                        </div>
                    	
                    </div>
                	<div class="cl-col cl-grid-7">
                        <div class="row">
                            <span class="titulo">O que nossos clientes<br>dizem sobre nós</span>
                        </div>
                        <ul>
<?php

$sql = mysqli_query($conexao,"SELECT * FROM depoimentos WHERE del = 'N' ORDER BY id DESC LIMIT 2");

while ($dados_depoimentos = mysqli_fetch_object($sql)) {

if ($dados_depoimentos->intro == true) {
	
   $dados_intro = "<span>".$dados_depoimentos->intro."</span>";
   
} else {
	
   $dados_intro = "";
   
}

?>
                            <li>
                                <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="li-depoimento"><?php echo $dados_depoimentos->depoimento ?></a>
                                <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="li-titulo"><?php echo $dados_depoimentos->nome ?></a>
                                <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] . "/assine/" ?>" class="li-avaliacao"></a>
                            </li>
<?php } ?>
                        </ul>

                    </div>
            	</div>
                
			</div>
		</header>
	</section>
<?php } ?>
<?php endif; ?>