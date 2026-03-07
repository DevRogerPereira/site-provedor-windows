<?php if($disp_detect == "PC") {?>
                	<div class="row ct_menu_box summary">
                    	<ul>
                        	<li <?php echo isset($dados_menu_ac_slides) ? $dados_menu_ac_slides : ""; ?>><a href="<?php echo $urlsite . "/adm/slides" ?>" class="ct_menu_item"><i class="fa fa-home"></i>Slides</a></li>
                        	<li <?php echo isset($dados_menu_ac_localidades) ? $dados_menu_ac_localidades : ""; ?>><a href="<?php echo $urlsite . "/adm/localidades" ?>" class="ct_menu_item"><i class="fa fa-home"></i>Cobertura</a></li>
                        	<li <?php echo isset($dados_menu_ac_planos) ? $dados_menu_ac_planos : ""; ?>><a href="<?php echo $urlsite . "/adm/planos" ?>" class="ct_menu_item"><i class="fa fa-home"></i>Internet</a></li>
                        	<li <?php echo isset($dados_menu_ac_contratos) ? $dados_menu_ac_contratos : ""; ?>><a href="<?php echo $urlsite . "/adm/contratos" ?>" class="ct_menu_item"><i class="fa fa-home"></i>Contratos</a></li>
                        	<li <?php echo isset($dados_menu_ac_crm) ? $dados_menu_ac_crm : ""; ?>><a href="<?php echo $urlsite . "/adm/crm" ?>" class="ct_menu_item"><i class="fa fa-home"></i>Cadastros</a></li>
                        	<li <?php echo isset($dados_menu_ac_depoimentos) ? $dados_menu_ac_depoimentos : ""; ?>><a href="<?php echo $urlsite . "/adm/depoimentos" ?>" class="ct_menu_item"><i class="fa fa-home"></i>Depoimentos</a></li>
                        	<li <?php echo isset($dados_menu_ac_duvidas) ? $dados_menu_ac_duvidas : ""; ?>><a href="<?php echo $urlsite . "/adm/duvidas" ?>" class="ct_menu_item"><i class="fa fa-home"></i>Dúvidas</a></li>
                        	<li <?php echo isset($dados_menu_ac_usuarios) ? $dados_menu_ac_usuarios : ""; ?>><a href="<?php echo $urlsite . "/adm/usuarios" ?>" class="ct_menu_item"><i class="fa fa-home"></i>Usuários</a></li>
                        	<li <?php echo isset($dados_menu_ac_configuracoes) ? $dados_menu_ac_configuracoes : ""; ?>><a href="<?php echo $urlsite . "/adm/configuracoes" ?>" class="ct_menu_item"><i class="fa fa-home"></i>Configurações</a></li>
                        	<li><a href="<?php echo $urlsite . "/adm/sair" ?>" class="ct_menu_item"><i class="fa fa-home"></i>Sair</a></li>
                        </ul>
                    </div>
<?php } ?>
<?php if($disp_detect == "MV") { ?>
<?php } ?>