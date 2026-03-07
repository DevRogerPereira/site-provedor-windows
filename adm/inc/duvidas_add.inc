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
							<input type="hidden" name="id" id="id" value="<?php echo isset($dados_tb['id']) ? $dados_tb['id'] : ""; ?>" />
                            <div class="row of_form_box">

                                <div class="row">
                                    <span>Pergunta</span>
                                    <input type="text" name="pergunta" id="pergunta" autocomplete="off" placeholder="Digite aqui" value="<?php echo isset($dados_tb['pergunta']) ? $dados_tb['pergunta'] : ""; ?>">
                                </div>

                                <div class="row">
                                    <span>Resposta</span>
                                    <textarea rows="10" name="resposta" id="resposta" placeholder="Digite aqui"><?php echo isset($dados_tb['resposta']) ? $dados_tb['resposta'] : ""; ?></textarea>
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