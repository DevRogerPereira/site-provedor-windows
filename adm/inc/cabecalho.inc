<?php if($disp_detect == "PC") { ?>
	<?php if($pagina != "entrar" && $pagina != "entrar-erro") {?>
	<section id="pf_rv_topo">
		<header id="wrap">
			<div class="container">
            	<div class="row">
                	<div class="col grid-3 tp_logomarca_box">
                        <a href="<?php echo $urlsite . "/adm/resumo" ?>"><img src="<?php echo $urlsite . "/adm/" ?>img/cbl-logomarca.png"></a>
                    </div>
                	<div class="col grid-6 tp_logomarca_box">
                        <span>Gerenciador de conteúdo</span></a>
                    </div>
                	<div class="col grid-3">
                    	<div class="col grid-10 tp_perfil_box">
                            <a href="<?php echo $urlsite . "/adm/resumo" ?>" class="tp_perfil_nome"><?php echo $user_nome_responsavel ?></a>
                            <a href="<?php echo $urlsite . "/adm/resumo" ?>" class="tp_perfil_cidade">Em Divinópolis</a>
                        </div>
                    	<div id="fd_acoes_box" class="col grid-2">
                            <ul class="menu_user">
                                <li><a href="<?php echo $urlsite . "/adm/resumo" ?>" class="tp_perfil_img"><i class="fa fa-user-circle"></i></a>
                                    <ul style="display:none">
                                        <li><a href="<?php echo $urlsite . "/adm/resumo" ?>">Início</a></li>
                                        <li><a href="<?php echo $urlsite . "/adm/minha-conta" ?>">Minha conta</a></li>
                                        <li><a href="<?php echo $urlsite . "/adm/sair" ?>">Sair</a></li>
                                    </ul>
                                </li>
                            </ul>
                        </div>
                    </div>
                </div>
			</div>
		</header>
	</section>
	<section id="pf_rv_topo_sub" class="header">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3 ct_avatar_box">
                        <a href="<?php echo $urlsite . "/adm/resumo" ?>" class="ct_avatar_icon"><i class="fa fa-user-circle"></i></a>
                        <a href="<?php echo $urlsite . "/adm/resumo" ?>" class="ct_avatar_nome"><?php echo $user_nome_responsavel ?></a>
                        <a href="<?php echo $urlsite . "/adm/resumo" ?>" class="ct_avatar_intro">Entou a 2 anos</a>
                </div>
                <div class="col grid-9 ts_titulo">
                	<ul>
<?php if($user_nivel == "3") {?>
                    	<?php echo $dados_menu_sub_cli ?>
<?php } else { ?>
                    	<?php echo $dados_menu_sub ?>
<?php } ?>
                    </ul>
                </div>
			</div>
		</header>
	</section>
	<?php } ?>
<?php } ?>
<?php if($disp_detect == "MV") {?>
<?php } ?>