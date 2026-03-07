<?php if($disp_detect == "PC") { ?>
	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
                    <div class="lt_box">
                    
<?php if($pagina == "contratos-add") { ?>
                        <form name="form" id="form" action="" method="post" class="cmp_form">
							<input type="hidden" name="id" id="id" value="" />
                            <div class="row of_form_box">

<?php if($ht_url == false) { ?>
                            	<div class="row">
									<span style="margin:0 0 10px 0;display:block;">Área de cobertura</span>
<?php

$sql = mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE del = 'N' ORDER BY nome ASC");

while ($dados_categorias = mysqli_fetch_object($sql)) {

	echo "<label class=\"cmp_label\"><input type=\"radio\" name=\"locl_id[]\" value=\"" . $dados_categorias->id . "\">" . $dados_categorias->nome . "</label>";
	
}
?>
                                </div>
<?php } else { ?>
                                <div class="row">
                                	<div class="cl_col_ cl_grid_12">
                                        <span>Área de atuação</span>
                                        <input type="hidden" name="locl_id" id="locl_id" value="<?php echo isset($dados_tb['locl_id']) ? $dados_tb['locl_id'] : ""; ?>" />
                                        <select name="" id="" disabled="disabled">
											<?php 
												if(isset($ht_url) == false){
													echo "<option value=\"\" selected=\"selected\">Escolha</option>";
												} else {
													$tb_user_unidade = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE id = '".$dados_tb['locl_id']."'"));
													echo "<option value=\"".$tb_user_unidade['id']."\" selected=\"selected\">".$tb_user_unidade['nome']."</option>";
												}

												/*
												$tb_cat = mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE del = 'N' ORDER BY nome ASC");
													while($tb_cat_dados = mysqli_fetch_array($tb_cat)){
													echo "<option value=\"".$tb_cat_dados['id']."\">".$tb_cat_dados['nome']."</option>";
												}
												*/
											?>
                                        </select>
                                    </div>
<?php } ?>
<?php if(isset($tmp) == true) {?>
                                </div>
<?php } ?>
<?php if(isset($tmp) == true) {?>
<?php } ?>
                                <div class="row">
                                	<div class="cl_col cl_grid_12">
                                        <span>Titulo do plano</span>
                                        <input type="text" name="titulo" id="titulo" autocomplete="off" maxlength="100" placeholder="Digite aqui" value="<?php echo isset($dados_tb['titulo']) ? $dados_tb['titulo'] : ""; ?>">
                                    </div>
                                </div>
                                <div class="row pg_rod_box">
                                    <button type="submit" name="enviar" id="enviar" class="cl_grid_2 dv_form_enviar">Salvar</button>
                                </div>
                                <div id="form_status">
                                </div>
                            </div>
                        </form>
<?php } ?>
<?php if($pagina == "contratos-img") {?>
                        <div id="upload-area-ul">
                            <div id="upload-area">
                                <form id="upload-form" enctype="multipart/form-data">
                                    <input type="hidden" id="id" name="id" value="<?php echo $ht_url ?>">
                                    <a id="upload-link">Carregar documento pdf</a>
                                    <input type="file" id="file-input" name="files[]" multiple accept="application/pdf,.pdf" style="display: none;">
                                    <div id="error-message" class="error"></div>
                                    <div id="file-count">Arraste e solte o documento aqui.</div>
                                    <div class="preview" id="preview"></div>
                                    <button type="submit" id="submit-btn">Enviar</button>
                                </form>
                            </div>
                        </div>

<?php if(file_exists("../images/". $dados_contratos->foto) && $dados_contratos->foto == true) { ?>
                        <div id="upload-area-ul">
							<a href="<?php echo $urlsite . "/adm/contratos-del/" . $ht_url ?>" class="upload-area-deletar-arq">✖ Deletar</a>
							<a href="<?php echo $urlsite . "/images/" . $dados_contratos->foto ?>" target="_blank" class="upload-area-deletar-arq-ver">✔ Ver documento</a>
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