<?php if($disp_detect == "PC") {?>
	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
                    <div class="lt_box">
<?php if($pagina == "planos-add") {?>
                        <form name="form" id="form" action="" method="post" class="cmp_form">
							<input type="hidden" name="id" id="id" value="<?php echo isset($dados_tb['id']) ? $dados_tb['id'] : ""; ?>" />
							<input type="hidden" name="url_redir" id="url_redir" value="planos" />
                            <div class="row of_form_box">

<?php if($ht_url == false) { ?>
                            	<div class="row">
									<span style="margin:0 0 10px 0;display:block;">Área de cobertura</span>
<?php

$sql = mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE del = 'N' ORDER BY nome ASC");

while ($dados_categorias = mysqli_fetch_object($sql)) {

	echo "<label class=\"cmp_label\"><input type=\"checkbox\" name=\"locl_id[]\" value=\"" . $dados_categorias->id . "\">" . $dados_categorias->nome . "</label>";
	
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
												if(isset($ht_url)) {
													
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
<?php if(isset($tmp)) { ?>
                                </div>
<?php } ?>
<?php if(isset($tmp)) { ?>
                                <div class="row">
                                	<div class="cl_col cl_grid_12">
                                        <span>Titulo do plano</span>
                                        <input type="text" name="titulo" id="titulo" autocomplete="off" maxlength="100" placeholder="Digite aqui" value="<?php echo $dados_tb['titulo'] ?>">
                                    </div>
                                </div>
<?php } ?>
                                <div class="row">
                                	<div class="cl_col_div cl_grid_3">
                                        <span>Categoria</span>
                                        <select name="cat_id" id="cat_id">
                                                <?php 
                                                    if($ht_url == false){
                                                        echo "<option value=\"\" selected=\"selected\">Escolha</option>";
                                                        echo "<option value=\"\"></option>";
                                                    } else {
                                                        $tb_user_unidade = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos_categorias WHERE id = '".$dados_tb['cat_id']."'"));
                                                        echo "<option value=\"".$tb_user_unidade['id']."\" selected=\"selected\">".$tb_user_unidade['nome']."</option>";
                                                        echo "<option></option>";
                                                    }
    
                                                    $tb_cat = mysqli_query($conexao,"SELECT * FROM planos_categorias WHERE del = 'N' && id != '6' && id != '7' ORDER BY nome ASC");
                                                        while($tb_cat_dados = mysqli_fetch_array($tb_cat)){
                                                        echo "<option value=\"".$tb_cat_dados['id']."\">".$tb_cat_dados['nome']."</option>";
                                                    }
                                                ?>
                                        </select>
                                    </div>
                                	<div class="cl_col_div cl_grid_3">
                                        <span>Download</span>
                                        <input type="text" name="download" id="download" autocomplete="off" maxlength="10" onkeyup="somenteNumeros(this);" placeholder="Digite aqui" value="<?php echo isset($dados_tb['download']) ? $dados_tb['download'] : ""; ?>">
                                    </div>
                                	<div class="cl_col_div cl_grid_3">
                                        <span>Tipo</span>
                                        <select name="upload" id="upload">
                                	    <?php 
                                	    	if($dados_tb['upload'] == "MEGA"){
                                	    		echo "<option value=\"MEGA\" selected=\"selected\">MEGA</option>";
                                	    		echo "<option value=\"GIGA\">GIGA</option>";
                                	    	} elseif($dados_tb['upload'] == "GIGA"){
                                	    		echo "<option value=\"MEGA\">MEGA</option>";
                                	    		echo "<option value=\"GIGA\" selected=\"selected\">GIGA</option>";
                                	    	} else {
                                	    		echo "<option value=\"MEGA\" selected=\"selected\">MEGA</option>";
                                	    		echo "<option value=\"GIGA\">GIGA</option>";
                                	    	}
                                    	?>
                                        </select>
                                    </div>
                                	<div class="cl_col cl_grid_3">
                                        <span>Preço</span>
                                        <input type="text" name="valor" id="valor" autocomplete="off" maxlength="10" placeholder="Digite aqui" value="<?php if(isset($ht_url) == true && isset($dados_tb['valor']) == true){ echo number_format($dados_tb['valor'],2,",",""); } else {  } ?>">
                                    </div>

<?php if(isset($tmp)) {?>
                                	<div class="cl_col cl_grid_3">
                                        <span>Destacar este plano?</span>
                                        <select name="tipo_id" id="tipo_id">
                                	    <?php 
                                	    	if($dados_tb['tipo_id'] == "S"){
                                	    		echo "<option value=\"\">Não</option>";
                                	    		echo "<option value=\"S\" selected=\"selected\">Sim</option>";
                                	    	} else {
                                	    		echo "<option value=\"\" selected=\"selected\">Não</option>";
                                	    		echo "<option value=\"S\">Sim</option>";
                                	    	}
                                    	?>
                                        </select>
                                    </div>
                                	<div class="cl_col_div cl_grid_3">
                                        <span>WIFI INCLUSA</span>
                                        <label class="cmp_form_adc"><input type="checkbox" id="adc_tv" name="adc_tv" <?php if(isset($ht_url) == true && $dados_tb['adc_tv'] == "S"){ echo "value=\"S\" checked=\"checked\""; } else { echo "value=\"S\""; } ?>>Sim</label>
                                    </div>
<?php } ?>
                                </div>







                                <div class="row">
                                	<div class="cl_col_div cl_grid_2">
                                        <span>Globoplay</span>
                                        <label class="cmp_label"><input type="checkbox" name="vnt_7" value="S"<?= (!empty($dados_tb['vnt_7']) && $dados_tb['vnt_7'] === 'S') ? ' checked' : '' ?>>Sim</label>
									</div>
                                	<div class="cl_col_div cl_grid_2">
                                        <span>HBOmax</span>
                                        <label class="cmp_label"><input type="checkbox" name="vnt_8" value="S"<?= (!empty($dados_tb['vnt_8']) && $dados_tb['vnt_8'] === 'S') ? ' checked' : '' ?>>Sim</label>
									</div>
                                	<div class="cl_col_div cl_grid_2">
                                        <span>Watch TV</span>
                                        <label class="cmp_label"><input type="checkbox" name="vnt_9" value="S"<?= (!empty($dados_tb['vnt_9']) && $dados_tb['vnt_9'] === 'S') ? ' checked' : '' ?>>Sim</label>
                                    </div>
                                	<div class="cl_col_div cl_grid_2">
                                        <span>Premiere</span>
                                        <label class="cmp_label"><input type="checkbox" name="vnt_10" value="S"<?= (!empty($dados_tb['vnt_10']) && $dados_tb['vnt_10'] === 'S') ? ' checked' : '' ?>>Sim</label>
                                    </div>
                                	<div class="cl_col cl_grid_2">
                                        <span>Telecine</span>
                                        <label class="cmp_label"><input type="checkbox" name="vnt_11" value="S"<?= (!empty($dados_tb['vnt_11']) && $dados_tb['vnt_11'] === 'S') ? ' checked' : '' ?>>Sim</label>
                                    </div>
                                </div>
                                
                                <div class="row">
                                	<div class="cl_col_div cl_grid_4">
                                        <span>Vantagem 1</span>
                                        <input type="text" name="vnt_1" id="vnt_1" autocomplete="off" maxlength="100" placeholder="Digite aqui" value="<?php echo isset($dados_tb['vnt_1']) ? $dados_tb['vnt_1'] : ""; ?>">
                                    </div>
                                	<div class="cl_col_div cl_grid_4">
                                        <span>Vantagem 2</span>
                                        <input type="text" name="vnt_2" id="vnt_2" autocomplete="off" maxlength="100" placeholder="Digite aqui" value="<?php echo isset($dados_tb['vnt_2']) ? $dados_tb['vnt_2'] : ""; ?>">
                                    </div>
                                	<div class="cl_col cl_grid_4">
                                        <span>Vantagem 3</span>
                                        <input type="text" name="vnt_3" id="vnt_3" autocomplete="off" maxlength="100" placeholder="Digite aqui" value="<?php echo isset($dados_tb['vnt_3']) ? $dados_tb['vnt_3'] : ""; ?>">
                                    </div>
                                </div>

                                <div class="row">
                                	<div class="cl_col_div cl_grid_4">
                                        <span>Vantagem 4</span>
                                        <input type="text" name="vnt_4" id="vnt_4" autocomplete="off" maxlength="100" placeholder="Digite aqui" value="<?php echo isset($dados_tb['vnt_4']) ? $dados_tb['vnt_4'] : ""; ?>">
                                    </div>
                                	<div class="cl_col_div cl_grid_4">
                                        <span>Vantagem 5</span>
                                        <input type="text" name="vnt_5" id="vnt_5" autocomplete="off" maxlength="100" placeholder="Digite aqui" value="<?php echo isset($dados_tb['vnt_5']) ? $dados_tb['vnt_5'] : ""; ?>">
                                    </div>
                                	<div class="cl_col cl_grid_4">
                                        <span>Vantagem 6</span>
                                        <input type="text" name="vnt_6" id="vnt_6" autocomplete="off" maxlength="100" placeholder="Digite aqui" value="<?php echo isset($dados_tb['vnt_6']) ? $dados_tb['vnt_6'] : ""; ?>">
                                    </div>
                                </div>

                                <div class="row">
                                    <span>Detalhes</span>
                                    <textarea rows="3" name="detalhes" id="detalhes" placeholder="Digite aqui"><?php echo isset($dados_tb['detalhes']) ? $dados_tb['detalhes'] : ""; ?></textarea>
                                </div>

<?php if(isset($tmp)) { ?>
                             <div class="row">
                                    <span>Obs</span>
                                    <input type="text" name="obs" id="obs" autocomplete="off" placeholder="Digite aqui" value="<?php echo isset($dados_tb['obs']) ? $dados_tb['obs'] : ""; ?>">
                                </div>
<?php } ?>
                                <div class="row pg_rod_box">
                                    <button type="submit" name="enviar" id="enviar" class="cl_grid_2 dv_form_enviar">Salvar</button>
                                </div>
                                <div id="form_status">
                                </div>
                            </div>
                        </form>
<?php } ?>
<?php if($pagina == "planos-img") {?>
                        <form id="formulario" method="post" enctype="multipart/form-data" action="<?php echo $urlsite ."/adm/js/cadastro/planos/upload/upload.php" ?>" >
							<input type="hidden" name="id" id="id" value="<?php echo $ht_url ?>" />
							<input type="hidden" name="redir_url" id="redir_url" value="<?php echo substr($pagina, 0, -4) . "/" . $ht_url ?>" />
                            <div class="row of_form_box">
                                <div class="row">
									<span>Selecione um arquivo</span>
									<input type="file" id="imagem" name="imagem" accept="image/jpeg,image/png,application/pdf,image/x-eps" />
                                </div>
                                <div class="row pg_rod_box">
                                	<?php echo $dados_planos_foto ?>
                                </div>
                                <div class="row pg_rod_box">
                                    <a href="<?php echo $urlsite ."/adm/planos" ?>" class="dv_form_enviar">Voltar</a>
                                </div>
                            </div>
                        </form>
<?php } ?>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?>
<?php if($disp_detect == "MV") {?>
<?php } ?>