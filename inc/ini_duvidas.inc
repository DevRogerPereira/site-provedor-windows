<?php if ($detect->isMobile()) : ?>
<?php if($dados_rows_duvidas > 0) { ?>
	<section id="duvidas">
		<header id="wrap">
			<div class="container">

                    <div class="row">
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="duv-titulo">Tire suas dúvidas</a>
                    </div>
                    <div class="row">
                        <ul>
<?php

$sql = mysqli_query($conexao,"SELECT * FROM duvidas WHERE del = 'N' ORDER BY id DESC");

$key_valor = 0;

while ($dados_duvidas = mysqli_fetch_object($sql)) {

$key_valor++;

$url_list = $urlsite . "/" . $dados_duvidas->url . "";

?>
                            <li>
                                <div class="row">
                                    <a href="javascript:;" onClick="perfil_li('<?php echo $dados_duvidas->id . $key_valor ?>')" class="tlp li1 duv-li-titulo"><?php echo $dados_duvidas->pergunta ?><span>+</span></a>
                                </div>
                                <div class="prf_li rli<?php echo $dados_duvidas->id . $key_valor ?>" style="display:none">
                                    <a class="duv-li-intro"><?php echo $dados_duvidas->resposta ?></a>
                                </div>
                            </li>
<?php } ?>
                        </ul>
                    </div>
			</div>
		</header>
	</section>
<?php } ?>
<?php else : ?>
<?php if($dados_rows_duvidas > 0) { ?>
	<section id="duvidas">
		<header id="wrap">
			<div class="container">
            	<div class="cl-col cl-grid-5">
                &nbsp;
                </div>
            	<div class="cl-col cl-grid-7">
                
                    <div class="row">
                        <a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="duv-titulo">Tire suas dúvidas</a>
                    </div>
                    <div class="row">
                        <ul>

<?php

$sql = mysqli_query($conexao,"SELECT * FROM duvidas WHERE del = 'N' ORDER BY id DESC");

$key_valor = 0;

while ($dados_duvidas = mysqli_fetch_object($sql)) {

$key_valor++;

$url_list = $urlsite . "/" . $dados_duvidas->url . "";

?>
                            <li>
                                <div class="row">
                                    <a href="javascript:;" onClick="perfil_li('<?php echo $dados_duvidas->id . $key_valor ?>')" class="tlp li1 duv-li-titulo"><?php echo $dados_duvidas->pergunta ?><span>+</span></a>
                                </div>
                                <div class="prf_li rli<?php echo $dados_duvidas->id . $key_valor ?>" style="display:none">
                                    <a class="duv-li-intro"><?php echo $dados_duvidas->resposta ?></a>
                                </div>
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