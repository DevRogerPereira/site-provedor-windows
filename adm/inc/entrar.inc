<?php if($disp_detect == "PC") {?>
	<section id="entrar">
		<header id="wrap">
			<div class="container">
            	<div class="cl_col cl_grid_6 en_info">
					<img src="<?php echo $urlsite . "/adm/img/cbl-logomarca-entrar.png" ?>" class="en_logomarca">
                </div>
            	<div class="cl_col cl_grid_6 en_form">
					<form name="form_login" id="form_login" action="<?php echo $urlsite . "/adm/entrar-valida" ?>" method="post">
                        <img src="<?php echo $urlsite . "/" ?>adm/img/entrar-icon.png" class="en_logomarca" width="50" height="61">
                        <span class="en_form_intro">Digite seu usuário e senha para entrar</span>
						<input type="text" id="usuario" name="usuario" placeholder="Usuário" />
						<input type="password" id="senha" name="senha" placeholder="Senha" />
						<button type="submit" name="add" id="add">Entrar</button>
						<?php if($pagina == "entrar-erro") { echo "<span class=\"en_form_error\">Tente novamente com outro usuário ou senha.</span>"; } ?>
						<a href="#" class="en_form_criar">Esqueci minha senha</a>
						<a href="#" class="en_form_developer">@ 2019  Desenvolvido por <span>DRIBLE</span></a>
					</form>
                </div>
			</div>
		</header>
	</section>

<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.min.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script type="text/javascript">
<!-- cupons/login/usuarios }, -->
$(document).ready(function(){
		$('#form_login').validate({
			rules: {
				usuario: { required: true, minlength: 3, maxlength: 40, remote: '<?php echo $urlsite ?>/adm/js/cadastro/usuarios/valida_cli_usuario.php' },
				senha: { required: true, minlength: 2, maxlength: 40 }
			},
			messages: {
				usuario: { required: '<span class="en_input_alerta">Preencha este campo.</span>', number: '<span class="en_input_alerta">Preencha este campo.</span>', minlength: '<span class="en_input_alerta">Preencha este campo.</span>', maxlength: '<span class="en_input_alerta">Preencha este campo.</span>', remote: '<span class="en_input_alerta">Esqueceu seu usuário? Tente outro telefone.</span>' },
				senha: { required: '<span class="en_input_alerta">Preencha este campo.</span>', number: '<span class="en_input_alerta">Preencha este campo.</span>', minlength: '<span class="en_input_alerta">Preencha este campo.</span>', maxlength: '<span class="en_input_alerta">Preencha este campo.</span>' }
			},
		});
	});
</script>
<script>
<!-- mascara numeros -->
   function somenteNumeros(num) {
        var er = /[^0-9.]/;
        er.lastIndex = 0;
        var campo = num;
        if (er.test(campo.value)) {
          campo.value = "";
        }
    }
</script>
<?php } ?>
<?php if($disp_detect == "MV") {?>
<?php } ?>