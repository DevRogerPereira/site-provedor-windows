<?php if ($detect->isMobile()) : ?>
<?php if($dados_rows_contratos > 0) { ?>
	<section id="nav-flt-modal" class="nav-contratos" style="display:none">
		<header id="wrap">
			<div class="container">
            	<div class="row nav-flt-lcld-screen" onClick="abreFecha('.nav-contratos')">
                </div>
            	<div class="row nav-flt-lcld-align">
                    <div class="row nav-flt-lcld-screen-ul">
                        <div class="row">
                        	<span class="nav-flt-tag">Contratos</span>
                        	<span class="nav-flt-titulo"><?php echo $dados_slide_nome ?></span>
                        	<a href="javascript:;" class="nav-flt-lcld-fechar" onClick="abreFecha('.nav-contratos')">✖</a>
                        </div>

                        <div class="nav-modal-contratos-ul">

                            <div class="row">
                                <ul>
<?php

$sql = mysqli_query($conexao,"SELECT * FROM contratos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' ORDER BY id DESC");

$key_valor = 0;

while ($dados_contratos = mysqli_fetch_object($sql)) {

$key_valor++;

if ($dados_contratos->foto == true && file_exists("images/".$dados_contratos->foto."")) { 

	$dados_contratos_arquivo = $urlsite . "/images/" . $dados_contratos->foto;
 
} else {
	
	$dados_contratos_arquivo = "";
   
}

if ($dados_contratos->titulo == true) { 

	$dados_contratos_titulo = $dados_contratos->titulo;
 
} else {
	
	$dados_contratos_titulo = "Contrato SCM";
   
}

?>
<?php if($dados_contratos_arquivo == true) { ?>
                                    <li>
                                        <a href="<?php echo $dados_contratos_arquivo ?>" target="_blank" class="nav-modal-contratos-li-titulo"><?php echo $dados_contratos_titulo ?></a>
                                    </li>
<?php } ?>
<?php } ?>
                                </ul>
                            </div>

                        </div>
                            
                        <div class="row nav-flt-rdp-ul">
                        	<a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="nav-flt-rdp-assine">Assine já</a>
                        </div>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?>

	<section id="ini-cabecalho" class="header">
		<header id="wrap">
			<div class="container">
            	<div class="row">
                	<div class="cl-col cl-grid-10">
                         <a href="<?php echo $urlsite . "/" . $cidade ?>" class="logomarca"><img src="<?php echo $urlsite ?>/images/logomarca.png"></a>
                    </div>
                	<div class="cl-col cl-grid-2">
                    <ul id="menu-acao" class="menu-acao">
						<li><a class="cbl_menu_icone"></a>
							<ul>
					<?php if($pagina == "inicial") { ?>    
                                <li><a href="javascript:;" onClick="scrollToDiv('ini-institucional')" class="cbl-li">Institucional</a></li>
								<?php if($dados_rows_plano_1 > 0 || $dados_rows_plano_2 > 0) { ?>
                                <li><a href="javascript:;" onClick="scrollToDiv('ini-planos')" class="cbl-li">Internet</a></li>
                                <?php } ?>
                                <?php if($dados_rows_plano_2 > 0 || $dados_rows_plano_4 > 0) { ?>
                                <li><a href="javascript:;" onClick="scrollToDiv('ini-planos')" class="cbl-li">Empresas</a></li>
                                <?php } ?>
								<?php if($dados_rows_plano_6 > 0) { ?>
                                <li><a href="javascript:;" onClick="scrollToDiv('ini-pln-combos')" class="cbl-li">Combos</a></li>
                                <?php } ?>
                                <?php if($dados_rows_plano_7 > 0) { ?>
                                <li><a href="javascript:;" onClick="scrollToDiv('ini-pln-telefonia')" class="cbl-li">Telefonia</a></li>
                                <?php } ?>
								<?php if ($dados_rows_blog > 0) { ?>
                                <li><a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="cbl-li">Blog</a></li>
								<?php } ?>
                                <li><a href="javascript:;" onClick="scrollToDiv('cadastro')" class="cbl-li">Atendimento</a></li>
                    <?php } elseif($pagina == "assine" || $pagina == "blog" ||  $pagina == "politica-privacidade") { ?>    
                                <li><a href="<?php echo $urlsite . "/" . $cidade . "#ini-institucional" ?>" class="cbl-li">Institucional</a></li>
								<?php if($dados_rows_plano_1 > 0 || $dados_rows_plano_3 > 0) { ?>
                                <li><a href="<?php echo $urlsite . "/" . $cidade . "#ini-planos" ?>" class="cbl-li">Internet</a></li>
                                <?php } ?>
                                <?php if($dados_rows_plano_2 > 0 || $dados_rows_plano_4 > 0) { ?>
                                <li><a href="<?php echo $urlsite . "/" . $cidade . "#ini-planos" ?>" class="cbl-li">Empresas</a></li>
                                <?php } ?>
								<?php if($dados_rows_plano_6 > 0) { ?>
                                <li><a href="<?php echo $urlsite . "/" . $cidade . "#ini-pln-combos" ?>" class="cbl-li">Combos</a></li>
                                <?php } ?>
                                <?php if($dados_rows_plano_7 > 0) { ?>
                                <li><a href="<?php echo $urlsite . "/" . $cidade . "#ini-pln-telefonia" ?>" class="cbl-li">Telefonia</a></li>
                                <?php } ?>
								<?php if ($dados_rows_blog > 0) { ?>
                                <li><a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="cbl-li">Blog</a></li>
								<?php } ?>
                                <li><a href="<?php echo $urlsite . "/" . $cidade . "#cadastro" ?>" class="cbl-li">Atendimento</a></li>
                    <?php } ?>
<?php if ($url_area_cliente == true) { ?>
                                <li><a href="<?php echo $url_area_cliente ?>" target="_blank">Área do cliente</a></li>
                                <li><a href="<?php echo $url_area_cliente ?>" target="_blank">2ª via de boleto</a></li>
<?php } ?>
							</ul>
						</li>
					</ul>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php else : ?>
<?php if($dados_rows_contratos > 0) { ?>
	<section id="nav-flt-modal" class="nav-contratos" style="display:none">
		<header id="wrap">
			<div class="container">
            	<div class="row nav-flt-lcld-screen" onClick="abreFecha('.nav-contratos')">
                </div>
            	<div class="row nav-flt-lcld-align">
                    <div class="row nav-flt-lcld-screen-ul">
                        <div class="row">
                        	<span class="nav-flt-tag">Contratos</span>
                        	<span class="nav-flt-titulo"><?php echo $dados_slide_nome ?></span>
                        	<a href="javascript:;" class="nav-flt-lcld-fechar" onClick="abreFecha('.nav-contratos')">Fechar</a>
                        </div>

                        <div class="nav-modal-contratos-ul">

                            <div class="row">
                                <ul>
<?php

$sql = mysqli_query($conexao,"SELECT * FROM contratos WHERE del = 'N' && locl_id = '".$dados_cidade['id']."' ORDER BY id DESC");

$key_valor = 0;

while ($dados_contratos = mysqli_fetch_object($sql)) {

$key_valor++;

if ($dados_contratos->foto == true && file_exists("images/".$dados_contratos->foto."")) { 

	$dados_contratos_arquivo = $urlsite . "/images/" . $dados_contratos->foto;
 
} else {
	
	$dados_contratos_arquivo = "";
   
}

if ($dados_contratos->titulo == true) { 

	$dados_contratos_titulo = $dados_contratos->titulo;
 
} else {
	
	$dados_contratos_titulo = "Contrato SCM";
   
}

?>
<?php if($dados_contratos_arquivo == true) { ?>
                                    <li>
                                        <a href="<?php echo $dados_contratos_arquivo ?>" target="_blank" class="nav-modal-contratos-li-titulo"><?php echo $dados_contratos_titulo ?></a>
                                    </li>
<?php } ?>
<?php } ?>
                                </ul>
                            </div>
                        </div>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?> 

	<section id="ini-cabecalho" class="header">
		<header id="wrap">
			<div class="container">
            	<div class="ini-cbl-ul">

            	<div class="cl-col-div cl-grid-2">
                     <a href="<?php echo $urlsite . "/" . $dados_cidade['url'] ?>" class="cbl-logomarca"><img src="<?php echo $urlsite ?>/images/logomarca.png"></a>
				</div>
				<div class="cl-col cl-grid-8">
                    <div class="row">
<?php if ($dados_cidade_telefone == true || $dados_cidade_telefone_2 == true || $url_area_cliente == true) { ?>
<?php if ($dados_cidade_telefone == true) { ?>
						<a href="tel:<?php echo $dados_cidade_telefone_whatsapp ?>" target="_blank" class="cbl-nav-li-fone"><?php echo $dados_cidade_telefone ?></a>
<?php } ?>
<?php if ($dados_cidade_telefone_2 == true) { ?>
                        <a href="<?php echo "http://api.whatsapp.com/send?1=pt_BR&phone=55".$dados_cidade_telefone_2_whatsapp."&text=Quero falar com a " . $tsite . "\"" ?>" target="_blank" class="cbl-nav-li-whatsapp"><?php echo $dados_cidade_telefone_2 ?></a>
<?php } ?>
<?php if ($url_area_cliente == true) { ?>
                        <a href="<?php echo $url_area_cliente ?>" target="_blank" class="cbl-nav-li-boleto">2ª via de boleto</a>
                        <a href="<?php echo $url_area_cliente ?>" target="_blank" class="cbl-nav-li-central">Central do assinante</a>
<?php } ?>
<?php } ?>
                    </div>
                    <div class="row cbl-ul">
					<?php if($pagina == "inicial") { ?>    
                        <a href="javascript:;" onClick="scrollToDiv('ini-institucional')" class="cbl-li">Institucional</a>
                        <?php if($dados_rows_plano_1 > 0) { ?>
                        <a href="javascript:;" onClick="scrollToDiv('ini-planos')" class="cbl-li">Internet</a>
                        <?php } ?>
                        <?php if($dados_rows_plano_2 > 0) { ?>
                        <a href="javascript:;" onClick="scrollToDiv('ini-planos')" class="cbl-li">Empresas</a>
                        <?php } ?>
                        <?php if($dados_rows_plano_6 > 0) { ?>
                        <a href="javascript:;" onClick="scrollToDiv('ini-pln-combos')" class="cbl-li">Combos</a>
                        <?php } ?>
                        <?php if($dados_rows_plano_7 > 0) { ?>
                        <a href="javascript:;" onClick="scrollToDiv('ini-pln-telefonia')" class="cbl-li">Telefonia</a>
                        <?php } ?>
                        <?php if ($dados_rows_blog > 0) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="cbl-li">Blog</a>
                        <?php } ?>
                        <?php if($dados_rows_plano_6 == 0 && $dados_rows_plano_7 == 0) { ?>
                        <a href="javascript:;" onClick="scrollToDiv('cadastro')" class="cbl-li">Atendimento</a>
                        <?php } ?>
                    <?php } elseif($pagina == "assine" || $pagina == "blog" ||  $pagina == "politica-privacidade") { ?>    
                        <a href="<?php echo $urlsite . "/" . $cidade . "#ini-institucional" ?>" class="cbl-li">Institucional</a>
                        <?php if($dados_rows_plano_1 > 0) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "#ini-planos" ?>" class="cbl-li">Internet</a>
                        <?php } ?>
                        <?php if($dados_rows_plano_2 > 0) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "#ini-planos" ?>" class="cbl-li">Empresas</a>
                        <?php } ?>
                        <?php if($dados_rows_plano_6 > 0) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "#ini-pln-combos" ?>" class="cbl-li">Combos</a>
                        <?php } ?>
                        <?php if($dados_rows_plano_7 > 0) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "#ini-pln-telefonia" ?>" class="cbl-li">Telefonia</a>
                        <?php } ?>
                        <?php if ($dados_rows_blog > 0) { ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="cbl-li">Blog</a>
                        <?php } ?>
                        <a href="<?php echo $urlsite . "/" . $cidade . "#cadastro" ?>" class="cbl-li">Atendimento</a>
                    <?php } ?>
                    </div>
				</div>
            	<div class="cl-col cl-grid-2 cbl-ul-assine">
					<a href="<?php echo $urlsite . "/" . $cidade . "/assine/" ?>" class="cbl-li-assine">Assine agora</a>
				</div>

                </div>
			</div>
		</header>
	</section>
<?php endif; ?>