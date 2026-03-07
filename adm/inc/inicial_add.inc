<?php if($disp_detect == "PC") { ?>

<?php //echo $pagina ?>

	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
                    <div class="lt_box">
<?php if($pagina == "inicial") {?>
                        <div id="upload-area-ul">
                            <div id="upload-area">
                                <form id="upload-form" enctype="multipart/form-data">
                                    <a id="upload-link">Carregar imagem</a>
                                    <input type="file" id="file-input" name="files[]" multiple style="display: none;">
                                    <div id="error-message" class="error"></div>
                                    <div id="file-count">Arraste e solte a imagem aqui.</div>
                                    <div class="preview" id="preview"></div>
                                    <button type="submit" id="submit-btn">Enviar</button>
                                </form>
                            </div>
                        </div>

<?php if(file_exists("../images/". $dados_tb_config->foto01) && $dados_tb_config->foto01 == true) { ?>
                        <div id="upload-area-ul">
							<a href="<?php echo $urlsite . "/adm/inicial-del" ?>" class="upload-area-deletar">✖ Deletar imagem</a>
							<img src="<?php echo $urlsite . "/".$url_user_ft."/800x449/". $dados_tb_config->foto01 ?>">
                        </div>
<?php } ?>
<?php } ?>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?>
<?php if($disp_detect == "MV") {?>
<?php } ?>