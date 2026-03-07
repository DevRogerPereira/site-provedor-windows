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
                                    <span>Nome do responsável</span>
                                    <input type="text" name="nome_responsavel" id="nome_responsavel" placeholder="Digite aqui" value="<?php echo isset($dados_tb['nome_responsavel']) ? $dados_tb['nome_responsavel'] : ""; ?>">
                                </div>
                                <div class="row">
                                	<div class="cl_col_div cl_grid_6">
                                        <span>Usuário</span>
                                        <input type="text" name="usuario" id="usuario" style="text-transform:lowercase" placeholder="Digite aqui" value="<?php echo isset($dados_tb['usuario']) ? $dados_tb['usuario'] : ""; ?>">
                                    </div>
                                	<div class="cl_col_div cl_grid_6">
                                        <span>Senha</span>
                                        <input type="text" name="senha" id="senha" placeholder="Digite aqui" value="">
                                    </div>
                                </div>
                                <div class="row pg_rod_box">
                                    <button type="submit" name="enviar" id="enviar" class="grid-3 dv_form_enviar">Salvar</button>
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