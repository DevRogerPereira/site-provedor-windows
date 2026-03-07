<?php if($disp_detect == "PC") {?>
	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
                    <div class="lt_box">
<?php if($pagina == "crm-add") {?>
                        <form name="form" id="form" action="" method="post">
                            <div class="row of_form_box">

                                <div class="row">
                                	<div class="cl_col_div cl_grid_6">
                                        <span>cidade_id</span>
                                        <input type="text" name="cidade_id" id="cidade_id" autocomplete="off" maxlength="40" placeholder="Digite aqui" value="<?php echo isset($dados_tb['cidade_id']) ? $dados_tb['cidade_id'] : ""; ?>">
                                    </div>
                                	<div class="cl_col cl_grid_6">
                                        <span>plano_id</span>
                                        <input type="text" name="plano_id" id="plano_id" autocomplete="off" maxlength="40" placeholder="Digite aqui" value="<?php echo isset($dados_tb['plano_id']) ? $dados_tb['plano_id'] : ""; ?>">
                                    </div>
                                </div>

                                <div class="row">
                                    <span>nome</span>
                                    <input type="text" name="nome" id="nome" autocomplete="off" placeholder="Digite aqui" value="<?php echo isset($dados_tb['nome']) ? $dados_tb['nome'] : ""; ?>">
                                </div>

                                <div class="row">
                                    <span>telefone</span>
                                    <input type="text" name="telefone" id="telefone" autocomplete="off" placeholder="Digite aqui" value="<?php echo isset($dados_tb['telefone']) ? $dados_tb['telefone'] : ""; ?>">
                                </div>

                                <div class="row">
                                    <span>email</span>
                                    <input type="text" name="email" id="email" autocomplete="off" placeholder="Digite aqui" value="<?php echo isset($dados_tb['email']) ? $dados_tb['email'] : ""; ?>">
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