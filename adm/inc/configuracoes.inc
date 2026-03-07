<?php if($disp_detect == "PC") {?>
	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
                    <div class="lt_box">
                        <form name="form" id="form" action="" method="post">
                            <div class="row of_form_box">

                                <div class="row">
                                	<div class="cl_col_div cl_grid_8">
                                        <span>Nome</span>
                                        <input type="text" name="tsite" id="tsite" autocomplete="off" placeholder="Digite aqui" value="<?php echo isset($dados_tb['tsite']) ? $dados_tb['tsite'] : ""; ?>">
                                    </div>
                                	<div class="cl_col cl_grid_4">
                                        <span>cnpj</span>
                                        <input type="text" name="cnpj" id="cnpj" maxlength="19" autocomplete="off" placeholder="Digite aqui" value="<?php echo isset($dados_tb['cnpj']) ? $dados_tb['cnpj'] : ""; ?>">
                                    </div>
                                </div>

                                <div class="row">
                                    <span>Sobre a empresa</span>
                                    <textarea rows="14" name="sobre" id="sobre" placeholder="Digite aqui"><?php echo isset($dados_tb['sobre']) ? $dados_tb['sobre'] : ""; ?></textarea>
                                </div>
<?php if(isset($tmp)) { ?>
                                <div class="row">
                                	<div class="cl_col_div cl_grid_4">
                                        <span>Visão</span>
                                        <textarea rows="8" name="sobre_1" id="sobre_1" placeholder="Digite aqui"><?php echo isset($dados_tb['sobre_1']) ? $dados_tb['sobre_1'] : ""; ?></textarea>
                                    </div>
                                	<div class="cl_col_div cl_grid_4">
                                        <span>Missão</span>
                                        <textarea rows="8" name="sobre_2" id="sobre_2" placeholder="Digite aqui"><?php echo isset($dados_tb['sobre_2']) ? $dados_tb['sobre_2'] : ""; ?></textarea>
                                    </div>
                                	<div class="cl_col cl_grid_4">
                                        <span>Valores</span>
                                        <textarea rows="8" name="sobre_3" id="sobre_3" placeholder="Digite aqui"><?php echo isset($dados_tb['sobre_3']) ? $dados_tb['sobre_3'] : ""; ?></textarea>
                                    </div>
                                </div>
<?php } ?>
                                <div class="row">
                                    <span>Descrição</span>
                                    <textarea rows="3" name="seo_descricao" id="seo_descricao" placeholder="Digite aqui"><?php echo isset($dados_tb['seo_descricao']) ? $dados_tb['seo_descricao'] : ""; ?></textarea>
                                </div>

                                <div class="row">
                                    <span>Palavras-chave</span>
                                    <textarea rows="3" name="seo_keywords" id="seo_keywords" placeholder="Digite aqui"><?php echo isset($dados_tb['seo_keywords']) ? $dados_tb['seo_keywords'] : ""; ?></textarea>
                                </div>

                                <div class="row">
                                	<div class="cl_col_div cl_grid_3">
                                        <span>WhatsApp(URL)</span>
                                        <input type="text" name="fone_2" id="fone_2" autocomplete="off" maxlength="255" placeholder="Digite aqui" value="<?php echo isset($dados_tb['fone_2']) ? $dados_tb['fone_2'] : ""; ?>">
                                    </div>
                                	<div class="cl_col_div cl_grid_3">
                                        <span>E-mail</span>
                                        <input type="text" name="email" id="email" autocomplete="off" maxlength="255" placeholder="Digite aqui" value="<?php echo isset($dados_tb['email']) ? $dados_tb['email'] : ""; ?>">
                                    </div>
                                	<div class="cl_col_div cl_grid_3">
                                        <span>Área do cliente (URL)</span>
                                        <input type="text" name="url_area_cliente" id="url_area_cliente" autocomplete="off" maxlength="255" placeholder="Digite aqui" value="<?php echo isset($dados_tb['url_area_cliente']) ? $dados_tb['url_area_cliente'] : ""; ?>">
                                    </div>
                                	<div class="cl_col cl_grid_3">
                                        <span>Teste velocidade</span>
                                        <input type="text" name="url_4" id="url_4" autocomplete="off" placeholder="Digite aqui" value="<?php echo isset($dados_tb['url_4']) ? $dados_tb['url_4'] : ""; ?>">
                                    </div>
                                </div>
                                
                                <div class="row">
                                	<div class="cl_col_div cl_grid_3">
                                        <span>@facebook</span>
                                        <input type="text" name="social_facebook" id="social_facebook" autocomplete="off" maxlength="255" placeholder="Digite aqui" value="<?php echo isset($dados_tb['social_facebook']) ? $dados_tb['social_facebook'] : ""; ?>">
                                    </div>
                                	<div class="cl_col_div cl_grid_3">
                                        <span>@instagram</span>
                                        <input type="text" name="social_instagram" id="social_instagram" autocomplete="off" maxlength="255" placeholder="Digite aqui" value="<?php echo isset($dados_tb['social_instagram']) ? $dados_tb['social_instagram'] : ""; ?>">
                                    </div>
                                	<div class="cl_col_div cl_grid_3">
                                        <span>@twitter</span>
                                        <input type="text" name="social_twitter" id="social_twitter" autocomplete="off" maxlength="255" placeholder="Digite aqui" value="<?php echo isset($dados_tb['social_twitter']) ? $dados_tb['social_twitter'] : ""; ?>">
                                    </div>
                                	<div class="cl_col cl_grid_3">
                                        <span>@youtube</span>
                                        <input type="text" name="social_youtube" id="social_youtube" autocomplete="off" maxlength="255" placeholder="Digite aqui" value="<?php echo isset($dados_tb['social_youtube']) ? $dados_tb['social_youtube'] : ""; ?>">
                                    </div>
                                </div>
                                
<?php if(isset($tmp)) { ?>
<?php } ?>
                                <div class="row">
                                	<div class="cl_col_div cl_grid_6">
                                        <span>APP Android (https://)</span>
                                        <input type="text" name="app_android" id="app_android" autocomplete="off" maxlength="255" placeholder="Digite aqui" value="<?php echo isset($dados_tb['app_android']) ? $dados_tb['app_android'] : ""; ?>">
                                    </div>
                                	<div class="cl_col cl_grid_6">
                                        <span>APP IOS (https://)</span>
                                        <input type="text" name="app_ios" id="app_ios" autocomplete="off" maxlength="255" placeholder="Digite aqui" value="<?php echo isset($dados_tb['app_ios']) ? $dados_tb['app_ios'] : ""; ?>">
                                    </div>
                                </div>
                                
                                <div class="row">
                                	<div class="cl_col_div cl_grid_3">
                                        <span>Anos de<br>experiência</span>
                                        <input type="text" name="vnt_1" id="vnt_1" autocomplete="off" maxlength="5" onkeyup="somenteNumeros(this);" placeholder="Digite aqui" value="<?php echo $dados_tb['vnt_1'] ?>">
                                    </div>
                                	<div class="cl_col_div cl_grid_3">
                                        <span>Profissionais<br>especialistas</span>
                                        <input type="text" name="vnt_2" id="vnt_2" autocomplete="off" maxlength="5" onkeyup="somenteNumeros(this);" placeholder="Digite aqui" value="<?php echo $dados_tb['vnt_2'] ?>">
                                    </div>
                                	<div class="cl_col_div cl_grid_3">
                                        <span>Localidades<br>atendidas</span>
                                        <input type="text" name="vnt_3" id="vnt_3" autocomplete="off" maxlength="5" onkeyup="somenteNumeros(this);" placeholder="Digite aqui" value="<?php echo $dados_tb['vnt_3'] ?>">
                                    </div>
                                	<div class="cl_col cl_grid_3">
                                        <span>Clientes<br>satisfeitos</span>
                                        <input type="text" name="vnt_4" id="vnt_4" autocomplete="off" maxlength="5" onkeyup="somenteNumeros(this);" placeholder="Digite aqui" value="<?php echo $dados_tb['vnt_4'] ?>">
                                    </div>
                                </div>

                                <div class="row">
                                    <span>Política de Privacidade</span>
                                    <textarea rows="15" name="sobre_3" id="sobre_3" placeholder="Digite aqui"><?php echo isset($dados_tb['sobre_3']) ? $dados_tb['sobre_3'] : ""; ?></textarea>
                                </div>

                                <div class="row">
                                    <span>pixel (head)</span>
                                    <textarea rows="8" name="pixel_head" id="pixel_head" placeholder="Digite aqui"><?php echo isset($dados_tb['pixel_head']) ? $dados_tb['pixel_head'] : ""; ?></textarea>
                                </div>
                                <div class="row">
                                    <span>pixel (body)</span>
                                    <textarea rows="8" name="pixel_body" id="pixel_body" placeholder="Digite aqui"><?php echo isset($dados_tb['pixel_body']) ? $dados_tb['pixel_body'] : ""; ?></textarea>
                                </div>

                                <div class="row pg_rod_box">
                                    <button type="submit" name="enviar" id="enviar" class="cl_grid_2 dv_form_enviar">Salvar</button>
                                </div>
                                <div id="form_status">
                                </div>
                            </div>
                        </form>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?>
<?php if($disp_detect == "MV") {?>
<?php } ?>