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
                                    <span>Nome</span>
                                    <input type="text" name="nome" id="nome" autocomplete="off" placeholder="Digite aqui" value="<?php echo isset($dados_tb['nome']) ? $dados_tb['nome'] : ""; ?>">
                                </div>

                                <div class="row">
                                    <span>Cliente</span>
                                    <input type="text" name="intro" id="intro" autocomplete="off" placeholder="Digite aqui" value="<?php if(isset($dados_tb['intro'])) { echo $dados_tb['intro']; } else { echo "Cliente desde " .  date("Y"); } ?>">
                                </div>

                                <div class="row">
                                    <span>Depoimento</span>
                                    <input type="text" name="depoimento" id="depoimento" autocomplete="off" placeholder="Digite aqui" value="<?php echo isset($dados_tb['depoimento']) ? $dados_tb['depoimento'] : ""; ?>">
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