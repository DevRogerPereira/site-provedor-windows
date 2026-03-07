<?php if($disp_detect == "PC") {?>
	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
                    <div class="lt_box">
<?php if($pagina == "categorias-add") {?>
                        <form name="form" id="form" action="" method="post">
							<input type="hidden" name="id" id="id" value="<?php echo $dados_tb['id'] ?>" />
                            <div class="row of_form_box">

                                <div class="row">
                                    <span>Nome</span>
                                    <input type="text" name="nome" id="nome" autocomplete="off" placeholder="Digite aqui" value="<?php echo $dados_tb['nome'] ?>">
                                </div>
                                
                                <div class="row">
                                    <span>Observações</span>
                                    <textarea rows="3" name="intro" id="intro" placeholder="Digite aqui"><?php echo isset($dados_tb['intro']) ? $dados_tb['intro'] : ""; ?></textarea>
                                </div>

                                <div class="row pg_rod_box">
                                    <button type="submit" name="enviar" id="enviar" class="cl_grid_2 dv_form_enviar">Salvar</button>
                                </div>
                                <div id="form_status">
                                </div>
                            </div>
                        </form>
<?php } ?>
<?php if($pagina == "categorias-img") {?>
                        <form id="formulario" method="post" enctype="multipart/form-data" action="<?php echo $urlsite ."/adm/js/cadastro/".$pagina."/upload/upload.php" ?>">
							<input type="hidden" name="id" id="id" value="<?php echo $id ?>" />
							<input type="hidden" name="redir_url" id="redir_url" value="<?php echo substr($pagina, 0, -4) . "/" . $ht_url ?>" />
                            <div class="row of_form_box">
                                <div class="row">
									<span>Selecione um arquivo</span>
									<input type="file" id="imagem" name="imagem" accept="image/jpeg,image/png,application/pdf,image/x-eps" />
                                </div>
                                <div id="visualizar" class="row pg_rod_box">
                                </div>
                                <div class="row pg_rod_box">
                                    <a href="<?php echo $urlsite ."/adm/".$pagina."" ?>" class="dv_form_enviar">Voltar</a>
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