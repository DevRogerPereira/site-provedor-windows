<?php if ($detect->isMobile()) : ?>
	<section id="cadastro">
		<header id="wrap">
			<div class="container">
            	<div class="row">
                    <a class="cad-li-titulo">Assine já</a>
                    <a class="cad-li-intro">Dúvidas, elogios, sugestões e críticas?<br>Preencha o formulário e a gente responde rapidinho.</a>
            	</div>
            	<div class="row">

                    <div class="row">
                    	<div class="cad-form-ul">
                            <div class="row">
                            	<span class="cad-form-titulo">Preencha com seus dados pessoais</span>
                            </div>
                            <div class="row">
                                <form name="form" id="form" action="" method="post">
<?php if($url == true && $dados_assine_titulo_format == true) { ?>    
                                    <input type="hidden" name="localidade" id="localidade" value="<?php echo mb_strtoupper($dados_cidade['url']) ?>" />
                                    <input type="hidden" name="plano_id" id="plano_id" value="<?php echo $dados_titulo_mail_format ?>" />
<?php } ?>    
                                    <div class="row">
                                        <input type="text" name="input_nome" id="input_nome" autocomplete="off" placeholder="Nome" value="">
                                    </div>
                                    <div class="row">
                                        <input type="text" name="input_email" id="input_email" autocomplete="off" maxlength="40" placeholder="E-mail" value="">
                                    </div>
                                    <div class="row">
                                        <input type="text" name="input_telefone" id="input_telefone" autocomplete="off" maxlength="15" placeholder="Telefone" value="">
                                    </div>
                                    <div class="row">
                                        <textarea rows="6" name="mensagem" id="mensagem" placeholder="Digite aqui"></textarea>
                                    </div>
                                    <div class="row">
                                        <button type="submit" name="enviar" id="enviar">Continuar</button>
                                    </div>
                                </form>
                            </div>
                        </div>
                    </div>
                    
                    <div class="row">
<?php if($url == false) { ?>  
<?php if ($dados_cidade_telefone_2 == true || $url_4 == true || $url_area_cliente == true) { ?>
                    	<div class="cad-form-pln-ul">
                            <div class="row">
                            	<span class="cad-form-pln-titulo">Canais de atendimento</span>
                            </div>
                            <div id="form-confirmacao" class="row">
                            </div>
                            <div class="row">
                                <ul>
<?php if ($dados_cidade_telefone_2 == true) { ?>
                                    <li>
                                        <a href="<?php echo "http://api.whatsapp.com/send?1=pt_BR&phone=".$dados_cidade_telefone_2_whatsapp."&text=Quero falar com a " . $tsite . "\"" ?>" target="_blank" class="cnt-li-1">WhatsApp <?php echo $tsite ?><span>Enviar mensagem</span></a>
                                    </li>
<?php } ?>
<?php if ($url_4 == true) { ?>
                                    <li>
                                        <a href="<?php echo $url_4 ?>" target="_blank" class="cnt-li-2">Teste de velocidade<span>Testar agora</span></a>
                                    </li>
<?php } ?>
<?php if ($url_area_cliente == true) { ?>
                                    <li>
                                        <a href="<?php echo $url_area_cliente ?>" target="_blank" class="cnt-li-3">2ª via de boleto<span>Emitir agora</span></a>
                                    </li>
<?php } ?>
                                </ul>
							</div>
                        </div>
<?php } ?>    
<?php } ?>    
<?php if($url == true) { ?>
                    	<div class="cad-form-pln-ul">
                            <div class="row">
                            	<span class="cad-form-pln-titulo">Plano escolhido</span>
                            </div>
                            <div id="form-confirmacao" class="row">
                            </div>
                            <div class="row">
                            	<?php echo $dados_assine_pln_titulo . $dados_assine_pln_download . $dados_assine_pln_vnt_1 . $dados_assine_pln_vnt_2 . $dados_assine_pln_vnt_3 . $dados_assine_pln_vnt_4 . $dados_assine_pln_vnt_5 . $dados_assine_pln_vnt_6 . $dados_assine_pln_valor . $dados_assine_pln_detalhes ?>
                            </div>
                        </div>
<?php } ?>    
                    </div>

            	</div>
			</div>
		</header>
	</section>
<?php else : ?>
	<section id="cadastro">
		<header id="wrap">
			<div class="container">
            	<div class="row">
                    <span class="cad-li-titulo">Assine já</span>
                    <span class="cad-li-intro">Dúvidas, elogios, sugestões e críticas?<br>Preencha o formulário e a gente responde rapidinho.</span>
            	</div>
            	<div class="row">

                    <div class="cl-col-div cl-grid-7">
                    	<div class="cad-form-ul">
                            <div class="row">
                            	<span class="cad-form-titulo">Preencha com seus dados pessoais</span>
                            </div>
                            <div class="row">
                                <form name="form" id="form" action="" method="post">
<?php if($url == true && $dados_assine_titulo_format == true) { ?>    
                                    <input type="hidden" name="localidade" id="localidade" value="<?php echo mb_strtoupper($dados_cidade['url']) ?>" />
                                    <input type="hidden" name="plano_id" id="plano_id" value="<?php echo $dados_titulo_mail_format ?>" />
<?php } ?>    
                                    <div class="row">
                                        <input type="text" name="input_nome" id="input_nome" autocomplete="off" placeholder="Nome" value="">
                                    </div>
                                    <div class="row">
                                        <div class="cl-col-div cl-grid-6">
                                            <input type="text" name="input_email" id="input_email" autocomplete="off" maxlength="40" placeholder="E-mail" value="">
                                        </div>
                                        <div class="cl-col cl-grid-6">
                                            <input type="text" name="input_telefone" id="input_telefone" autocomplete="off" maxlength="15" placeholder="Telefone" value="">
                                        </div>
                                    </div>
                                    <div class="row">
                                        <textarea rows="6" name="mensagem" id="mensagem" placeholder="Digite aqui"></textarea>
                                    </div>
                                    <div class="row">
                                        <button type="submit" name="enviar" id="enviar" class="cl-grid-4">Continuar</button>
                                    </div>
                                </form>
                            </div>
                        </div>
                    </div>
                    
                    <div class="cl-col cl-grid-5">
<?php if($url == false) { ?>  
<?php if ($dados_cidade_telefone_2 == true || $url_4 == true || $url_area_cliente == true) { ?>
                    	<div class="cad-form-pln-ul">
                            <div class="row">
                            	<span class="cad-form-pln-titulo">Canais de atendimento</span>
                            </div>
                            <div id="form-confirmacao" class="row">
                            </div>
                            <div class="row">
                                <ul>
<?php if ($dados_cidade_telefone_2 == true) { ?>
                                    <li>
                                        <a href="<?php echo "http://api.whatsapp.com/send?1=pt_BR&phone=".$dados_cidade_telefone_2_whatsapp."&text=Quero falar com a " . $tsite . "\"" ?>" target="_blank" class="cnt-li-1">WhatsApp <?php echo $tsite ?><span>Enviar mensagem</span></a>
                                    </li>
<?php } ?>
<?php if ($url_4 == true) { ?>
                                    <li>
                                        <a href="<?php echo $url_4 ?>" target="_blank" class="cnt-li-2">Teste de velocidade<span>Testar agora</span></a>
                                    </li>
<?php } ?>
<?php if ($url_area_cliente == true) { ?>
                                    <li>
                                        <a href="<?php echo $url_area_cliente ?>" target="_blank" class="cnt-li-3">2ª via de boleto<span>Emitir agora</span></a>
                                    </li>
<?php } ?>
                                </ul>
							</div>
                        </div>
<?php } ?>    
<?php } ?>    
<?php if($url == true) { ?>
                    	<div class="cad-form-pln-ul">
                            <div class="row">
                            	<span class="cad-form-pln-titulo">Plano escolhido</span>
                            </div>
                            <div id="form-confirmacao" class="row">
                            </div>
                            <div class="row">
                            	<?php echo $dados_assine_pln_titulo . $dados_assine_pln_download . $dados_assine_pln_vnt_1 . $dados_assine_pln_vnt_2 . $dados_assine_pln_vnt_3 . $dados_assine_pln_vnt_4 . $dados_assine_pln_vnt_5 . $dados_assine_pln_vnt_6 . $dados_assine_pln_valor . $dados_assine_pln_detalhes ?>
                            </div>
                        </div>
<?php } ?>    

                    </div>

            	</div>
			</div>
		</header>
	</section>
<?php endif; ?>