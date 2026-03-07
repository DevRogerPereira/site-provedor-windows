<?php if($disp_detect == "PC") { ?>
	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
                    <div class="lt_box">
<?php if($pagina == "blog-add") {?>
                        <form name="form" id="form" action="" method="post" class="cmp_form of_form_box">
                            <input type="hidden" name="id" id="id" value="<?php echo $dados_editar['id'] ?>" />
                            <div class="row">
                                <div class="cl_col_div cl_grid_3">
                                    <span>Categoria</span>
                                    <select name="idcat" id="idcat">
                                      
                                        <?php

                                        if($dados_editar['cat_id_1'] == true) {
                                            
                                            echo "<option value=\"".$dados_editar['cat_id_1']."\" selected=\"selected\">".$dados_blog_categorias['nome']."</option>";
                        					echo "<option></option>";
                                        
                                        } else {
                                            
                                            echo "<option value=\"\" selected=\"selected\">Selecione</option>";
                        					echo "<option></option>";
                                        
                                        }
                                        
                                        $sql = mysqli_query($conexao,"SELECT * FROM blog_categorias WHERE del = 'N' ORDER BY nome ASC");
                                        
                                        while ($dados_subcat = mysqli_fetch_object($sql)) {
                                        
                                        ?>
												<?php echo "                          <option value=\"".$dados_subcat->id."\">".$dados_subcat->nome."</option>" ?>
                                        <?php } ?>
                    
                                    </select>
                                </div>
                                <div class="cl_col_div cl_grid_3">
                                    <span>Tag</span>
                                    <input type="text" name="tag" id="tag" placeholder="" value="<?php echo $dados_editar['tag'] ?>">
                                </div>
                
                                <div class="cl_col_div cl_grid_3">
                                    <span>Publicação</span>
                                    <input type="text" name="data_ini" id="data_ini" class="docs-date" autocomplete="off" placeholder="00/00/0000" value="<?php echo $data_ini ?>">
                                </div>

                                <div class="cl_col cl_grid_3">
                                    <span>Situação</span>
                                    <select name="status" id="status">
                                	    <?php 
                                	    	if($dados_editar['status'] == "S"){
                                	    		echo "<option value=\"".$dados_editar['status']."\" selected=\"selected\">Publicada</option>";
                                	    		echo "<option value=\"E\">Escrevendo</option>";
                                	    		echo "<option value=\"N\">Pendente</option>";
                                	    	} elseif($dados_editar['status'] == "E"){
                                	    		echo "<option value=\"".$dados_editar['status']."\" selected=\"selected\">Escrevendo</option>";
                                	    		echo "<option value=\"S\">Publicada</option>";
                                	    		echo "<option value=\"N\">Pendente</option>";
                                	    	} elseif($dados_editar['status'] == "N"){
                                	    		echo "<option value=\"".$dados_editar['status']."\" selected=\"selected\">Pendente</option>";
                                	    		echo "<option value=\"S\">Publicada</option>";
                                	    		echo "<option value=\"E\">Escrevendo</option>";
                                	    	} else {
                                	    		echo "<option value=\"E\" selected=\"selected\">Escrevendo</option>";
                                	    		echo "<option value=\"N\">Pendente</option>";
                                	    		echo "<option value=\"S\">Publicada</option>";
                                	    	}
                                    	?>
                                    </select>
                                </div>

                            </div>

                            <div class="row">
                                <span>Título</span>
                                <input type="text" name="titulo" id="titulo" autocomplete="off" placeholder="Digite aqui" value="<?php echo $dados_editar['titulo'] ?>">
                            </div>

                            <div class="row">
                                <span>Texto</span>
                                <textarea id="detalhes" name="detalhes" rows="20" placeholder="Digite aqui"><?php echo $dados_editar['detalhes'] ?></textarea>
                            </div>

                            <div id="form_status">
                            </div>
                            
                            <div class="row pg_rod_box">
                            	<button type="submit" name="enviar" id="enviar" class="cl_grid_2 dv_form_enviar">Salvar</button>
                            </div>
                        </form>

<?php } ?>
<?php if($pagina == "blog-img") {?>
                        <form id="formulario" method="post" enctype="multipart/form-data" action="<?php echo $urlsite ."/adm/js/cadastro/blog/upload/upload.php" ?>">
							<input type="hidden" name="id" id="id" value="<?php echo $ht_url ?>" />
							<input type="hidden" name="redir_url" id="redir_url" value="<?php echo substr($pagina, 0, -4) . "/" . $ht_url ?>" />
                            <div class="row of_form_box">
                                <div class="row">
									<span>Selecione um arquivo em formato .jpg tamanho 1920 x 850px</span>
									<input type="file" id="imagem" name="imagem" accept="image/jpeg,image/png,application/pdf,image/x-eps" />
                                </div>
                                <div id="visualizar" class="row pg_rod_box">
<?php if($dados_slide == true) { ?>
                                    <img src="<?php echo $urlsite . "/".$url_ft."/680x300/".$dados_slide ?>">
<?php } ?>
                                </div>
                                <div class="row pg_rod_box">
                                    <a href="<?php echo $urlsite ."/adm/blog" ?>" class="dv_form_enviar">Voltar</a>
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