	<section id="rodape">
		<header id="wrap">
			<div class="container">
            	<div class="row">
                    <div class="cl_col cl_grid_10 rd_mn_list">
                        <ul>
                            <li>
                                <a href="#" class="rd_titulo">Ajuda</a>
                            </li>
                        </ul>
                    </div>
                </div>
                <div class="row rd_copyright">
					<a>Copyright © <?php echo date("Y") . " - " . $dados_seo_title_format ?></a>
                </div>
			</div>
		</header>
	</section>
    <section class="footer"></section>
<script type="text/javascript" ><?php include("js/jquery.min.js"); ?></script>
<script type="text/javascript" ><?php include("js/menu_acoes/dropit.js"); ?></script>
<script type="text/javascript">
     $(".menu_user").dropit();
</script>

<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery-scrolltofixed-min.js"></script>
<script>
    $(document).ready(function() {

        // Dock the header to the top of the window when scrolled past the banner.
        // This is the default behavior.

        $('.header').scrollToFixed();


        // Dock the footer to the bottom of the page, but scroll up to reveal more
        // content if the page is scrolled far enough.

        $('.footer').scrollToFixed( {
            bottom: 0,
            limit: $('.footer').offset().top
        });


        // Dock each summary as it arrives just below the docked header, pushing the
        // previous summary up the page.

        var summaries = $('.summary');
        summaries.each(function(i) {
            var summary = $(summaries[i]);
            var next = summaries[i + 1];

            summary.scrollToFixed({
                marginTop: $('.header').outerHeight(true) + 10,
                limit: function() {
                    var limit = 0;
                    if (next) {
                        limit = $(next).offset().top - $(this).outerHeight(true) + 1000;
                    } else {
                        limit = $('.footer').offset().top - $(this).outerHeight(true) - 10;
                    }
                    return limit;
                },
                zIndex: 999
            });
        });
    });
</script>
<script>
function abreFecha(sel) {
  $(sel).slideToggle();
}
</script>

<?php if($pagina == "entrar"  ||  $pagina == "entrar-erro") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script type="text/javascript">
<!-- cupons/login/usuarios }, -->
$(document).ready(function(){
		$('#form_login').validate({
			rules: {
				usuario: { required: true, minlength: 3, maxlength: 40, remote: 'http://argontec.com.br/adm/js/cadastro/usuarios/valida_cli_usuario.php' },
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
<?php if($pagina == "inicial" ) { ?>
<script>
    const uploadArea = document.getElementById('upload-area');
    const uploadLink = document.getElementById('upload-link');
    const fileInput = document.getElementById('file-input');
    const preview = document.getElementById('preview');
    const errorMessage = document.getElementById('error-message');
    const fileCount = document.getElementById('file-count');
    const uploadForm = document.getElementById('upload-form');
    const submitBtn = document.getElementById('submit-btn');

    // Abrir a seleção de arquivos ao clicar no link
    uploadLink.addEventListener('click', (e) => {
        e.preventDefault();
        fileInput.click();
    });

    // Atualizar a pré-visualização ao selecionar arquivos
    fileInput.addEventListener('change', handleFiles);

    // Arrastar e soltar arquivos na área de upload
    uploadArea.addEventListener('dragover', (e) => {
        e.preventDefault();
        uploadArea.classList.add('hover');
    });

    uploadArea.addEventListener('dragleave', () => {
        uploadArea.classList.remove('hover');
    });

    uploadArea.addEventListener('drop', (e) => {
        e.preventDefault();
        uploadArea.classList.remove('hover');
        handleFiles(e.dataTransfer);
    });

    function handleFiles(files) {
        errorMessage.textContent = ''; // Limpar mensagens de erro
        preview.innerHTML = ''; // Limpar pré-visualização
        submitBtn.style.display = 'none'; // Esconder o botão inicialmente

        let fileList = files.files || fileInput.files;

        // Limitar a quantidade de arquivos a 8
        if (fileList.length > 1) {
            errorMessage.textContent = 'Você pode enviar no máximo 1 imagem.';
            fileInput.value = ''; // Limpar o input de arquivos
            return;
        }

        // Exibir a quantidade de fotos selecionadas
        if (fileList.length > 0) {
            fileCount.textContent = `${fileList.length} foto(s) selecionada(s)`;
        } else {
            fileCount.textContent = 'Arraste e solte as fotos aqui ou clique em "Carregar Foto(s)".';
        }

        for (let i = 0; i < fileList.length; i++) {
            let file = fileList[i];

            // Verificar o tipo de arquivo
            if (!['image/jpeg', 'image/png'].includes(file.type)) {
                errorMessage.textContent = 'Permitido apenas arquivos .jpg, .jpeg e .png.';
                return;
            }

            // Verificar o tamanho do arquivo (máximo 5MB)
            if (file.size > 5 * 1024 * 1024) {
                errorMessage.textContent = 'O arquivo deve ter no máximo 5MB.';
                return;
            }

            // Pré-visualização das imagens
            let reader = new FileReader();
            reader.onload = function (e) {
                let img = document.createElement('img');
                img.src = e.target.result;
                preview.appendChild(img);
            };
            reader.readAsDataURL(file);
        }

        // Mostrar o botão "Enviar" se pelo menos uma foto for selecionada
        if (fileList.length > 0) {
            submitBtn.style.display = 'block';
        }
    }

    // Enviar arquivos via AJAX
    uploadForm.addEventListener('submit', (e) => {
        e.preventDefault();

        // Exibir "Carregando..." e desabilitar o botão
        submitBtn.textContent = 'Carregando...';
        submitBtn.disabled = true;

        let formData = new FormData(uploadForm);

        fetch('<?php echo $urlsite ?>/adm/js/cadastro/inicial/upload.php', {
            method: 'POST',
            body: formData
        })
        .then(response => response.json())
        .then(result => {
			if (result.success) {
				location.reload(); // Atualiza a página
				submitBtn.style.display = 'none'; // Esconder o botão novamente após o upload
				fileCount.textContent = 'Arraste e solte as fotos aqui ou clique em "Carregar Foto(s)".'; // Resetar a contagem
			} else {
				errorMessage.textContent = result.error;
			}

            // Reverter o botão para o estado normal após o upload
            submitBtn.textContent = 'Enviar';
            submitBtn.disabled = false;
        })
        .catch(error => {
            errorMessage.textContent = 'Erro ao fazer upload.';

            // Reverter o botão para o estado normal em caso de erro
            submitBtn.textContent = 'Enviar';
            submitBtn.disabled = false;
        });
    });
</script>
<?php } ?>
<?php if($pagina == "slides" ) { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/slides/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "slides-add" ) { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
$(document).ready(function(){
		$('#form').validate({
			rules: {

				locl_id: { required: true },
				titulo: { required: true, minlength: 1, maxlength: 100 }
				
			},
			messages: {

				locl_id: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				titulo: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/slides/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
		});
	});
</script>
<script>
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
<?php if($pagina == "slides-img") { ?>
<script>
    const uploadArea = document.getElementById('upload-area');
    const uploadLink = document.getElementById('upload-link');
    const fileInput = document.getElementById('file-input');
    const preview = document.getElementById('preview');
    const errorMessage = document.getElementById('error-message');
    const fileCount = document.getElementById('file-count');
    const uploadForm = document.getElementById('upload-form');
    const submitBtn = document.getElementById('submit-btn');

    // Abrir a seleção de arquivos ao clicar no link
    uploadLink.addEventListener('click', (e) => {
        e.preventDefault();
        fileInput.click();
    });

    // Atualizar a pré-visualização ao selecionar arquivos
    fileInput.addEventListener('change', handleFiles);

    // Arrastar e soltar arquivos na área de upload
    uploadArea.addEventListener('dragover', (e) => {
        e.preventDefault();
        uploadArea.classList.add('hover');
    });

    uploadArea.addEventListener('dragleave', () => {
        uploadArea.classList.remove('hover');
    });

    uploadArea.addEventListener('drop', (e) => {
        e.preventDefault();
        uploadArea.classList.remove('hover');
        handleFiles(e.dataTransfer);
    });

    function handleFiles(files) {
        errorMessage.textContent = ''; // Limpar mensagens de erro
        preview.innerHTML = ''; // Limpar pré-visualização
        submitBtn.style.display = 'none'; // Esconder o botão inicialmente

        let fileList = files.files || fileInput.files;

        // Limitar a quantidade de arquivos a 8
        if (fileList.length > 1) {
            errorMessage.textContent = 'Você pode enviar no máximo 1 imagem.';
            fileInput.value = ''; // Limpar o input de arquivos
            return;
        }

        // Exibir a quantidade de fotos selecionadas
        if (fileList.length > 0) {
            fileCount.textContent = `${fileList.length} foto(s) selecionada(s)`;
        } else {
            fileCount.textContent = 'Arraste e solte as fotos aqui ou clique em "Carregar Foto(s)".';
        }

        for (let i = 0; i < fileList.length; i++) {
            let file = fileList[i];

            // Verificar o tipo de arquivo
            if (!['image/jpeg', 'image/png'].includes(file.type)) {
                errorMessage.textContent = 'Permitido apenas arquivos .jpg, .jpeg e .png.';
                return;
            }

            // Verificar o tamanho do arquivo (máximo 5MB)
            if (file.size > 5 * 1024 * 1024) {
                errorMessage.textContent = 'O arquivo deve ter no máximo 5MB.';
                return;
            }

            // Pré-visualização das imagens
            let reader = new FileReader();
            reader.onload = function (e) {
                let img = document.createElement('img');
                img.src = e.target.result;
                preview.appendChild(img);
            };
            reader.readAsDataURL(file);
        }

        // Mostrar o botão "Enviar" se pelo menos uma foto for selecionada
        if (fileList.length > 0) {
            submitBtn.style.display = 'block';
        }
    }

    // Enviar arquivos via AJAX
    uploadForm.addEventListener('submit', (e) => {
        e.preventDefault();

        // Exibir "Carregando..." e desabilitar o botão
        submitBtn.textContent = 'Carregando...';
        submitBtn.disabled = true;

        let formData = new FormData(uploadForm);

        fetch('<?php echo $urlsite ?>/adm/js/cadastro/slides/upload.php', {
            method: 'POST',
            body: formData
        })
        .then(response => response.json())
        .then(result => {
			if (result.success) {
				location.reload(); // Atualiza a página
				submitBtn.style.display = 'none'; // Esconder o botão novamente após o upload
				fileCount.textContent = 'Arraste e solte as fotos aqui ou clique em "Carregar Foto(s)".'; // Resetar a contagem
			} else {
				errorMessage.textContent = result.error;
			}

            // Reverter o botão para o estado normal após o upload
            submitBtn.textContent = 'Enviar';
            submitBtn.disabled = false;
        })
        .catch(error => {
            errorMessage.textContent = 'Erro ao fazer upload.';

            // Reverter o botão para o estado normal em caso de erro
            submitBtn.textContent = 'Enviar';
            submitBtn.disabled = false;
        });
    });
</script>
<?php } ?>
<?php if($pagina == "contratos" ) { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/contratos/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "contratos-add" ) { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
$(document).ready(function(){
		$('#form').validate({
			rules: {

				locl_id: { required: true },
				titulo: { required: true, minlength: 1, maxlength: 100 }
				
			},
			messages: {

				locl_id: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				titulo: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/contratos/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
		});
	});
</script>
<script>
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
<?php if($pagina == "contratos-img") { ?>
<script>
    const uploadArea = document.getElementById('upload-area');
    const uploadLink = document.getElementById('upload-link');
    const fileInput = document.getElementById('file-input');
    const preview = document.getElementById('preview');
    const errorMessage = document.getElementById('error-message');
    const fileCount = document.getElementById('file-count');
    const uploadForm = document.getElementById('upload-form');
    const submitBtn = document.getElementById('submit-btn');

    // Abrir a seleção de arquivos ao clicar no link
    uploadLink.addEventListener('click', (e) => {
        e.preventDefault();
        fileInput.click();
    });

    // Atualizar a pré-visualização ao selecionar arquivos
    fileInput.addEventListener('change', handleFiles);

    // Arrastar e soltar arquivos na área de upload
    uploadArea.addEventListener('dragover', (e) => {
        e.preventDefault();
        uploadArea.classList.add('hover');
    });

    uploadArea.addEventListener('dragleave', () => {
        uploadArea.classList.remove('hover');
    });

    uploadArea.addEventListener('drop', (e) => {
        e.preventDefault();
        uploadArea.classList.remove('hover');
        handleFiles(e.dataTransfer);
    });

    function handleFiles(files) {
        errorMessage.textContent = ''; // Limpar mensagens de erro
        preview.innerHTML = ''; // Limpar pré-visualização
        submitBtn.style.display = 'none'; // Esconder o botão inicialmente

        let fileList = files.files || fileInput.files;

        // Limitar a quantidade de arquivos a 8
        if (fileList.length > 1) {
            errorMessage.textContent = 'Você pode enviar no máximo 1 imagem.';
            fileInput.value = ''; // Limpar o input de arquivos
            return;
        }

        // Exibir a quantidade de fotos selecionadas
        if (fileList.length > 0) {
            fileCount.textContent = `${fileList.length} foto(s) selecionada(s)`;
        } else {
            fileCount.textContent = 'Arraste e solte as fotos aqui ou clique em "Carregar Foto(s)".';
        }

        for (let i = 0; i < fileList.length; i++) {
            let file = fileList[i];

			// Verificar o tipo de arquivo
			if (!['application/pdf', 'application/msword', 'application/vnd.openxmlformats-officedocument.wordprocessingml.document'].includes(file.type)) {
				errorMessage.textContent = 'Permitido apenas arquivos .pdf, .doc e .docx.';
				return;
			}
			
            // Verificar o tamanho do arquivo (máximo 5MB)
            if (file.size > 5 * 1024 * 1024) {
                errorMessage.textContent = 'O arquivo deve ter no máximo 5MB.';
                return;
            }

			// Exibir o nome do arquivo
			let fileName = document.createElement('div');
			fileName.textContent = file.name; // Define o nome do arquivo
			preview.appendChild(fileName);

        }

        // Mostrar o botão "Enviar" se pelo menos uma foto for selecionada
        if (fileList.length > 0) {
            submitBtn.style.display = 'block';
        }
    }

    // Enviar arquivos via AJAX
    uploadForm.addEventListener('submit', (e) => {
        e.preventDefault();

        // Exibir "Carregando..." e desabilitar o botão
        submitBtn.textContent = 'Carregando...';
        submitBtn.disabled = true;

        let formData = new FormData(uploadForm);

        fetch('<?php echo $urlsite ?>/adm/js/cadastro/contratos/upload.php', {
            method: 'POST',
            body: formData
        })
        .then(response => response.json())
        .then(result => {
			if (result.success) {
				location.reload(); // Atualiza a página
				submitBtn.style.display = 'none'; // Esconder o botão novamente após o upload
				fileCount.textContent = 'Arraste e solte as fotos aqui ou clique em "Carregar Foto(s)".'; // Resetar a contagem
			} else {
				errorMessage.textContent = result.error;
			}

            // Reverter o botão para o estado normal após o upload
            submitBtn.textContent = 'Enviar';
            submitBtn.disabled = false;
        })
        .catch(error => {
            errorMessage.textContent = 'Erro ao fazer upload.';

            // Reverter o botão para o estado normal em caso de erro
            submitBtn.textContent = 'Enviar';
            submitBtn.disabled = false;
        });
    });
</script>
<?php } ?>
<?php if($pagina == "blog" ) { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/blog/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "blog-add" ) { ?>
<link rel="stylesheet" href="<?php echo $urlsite ?>/adm/js/datepicker/css/datepicker.css">
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/datepicker.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/datepicker.pt-BR.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/main.js"></script>
<script type="text/javascript" ><?php include("js/jquery.inputmask.bundle.js"); ?></script>
<script type="text/javascript">
    $(document).ready(function() {
      $("#data_ini").inputmask({
        mask: ["99/99/9999 99:99" ],
        keepStatic: true
      });
    });
</script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
$(document).ready(function(){
		$('#form').validate({
			rules: {

				idcat: { required: true },
				tag: { required: true, minlength: 3, maxlength: 100 },
				data_ini: { required: true, minlength: 1, maxlength: 20 },
				titulo: { required: true, minlength: 1, maxlength: 200 },
				detalhes: { required: true, minlength: 1, maxlength: 1000 }
				
			},
			messages: {

				idcat: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				tag: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				data_ini: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				titulo: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				detalhes: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/blog/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
		});
	});
</script>
<script>
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
<?php if($pagina == "blog-img") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/cadastro/blog/upload/jquery.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/cadastro/blog/upload/jquery.form.js"></script>
<script type="text/javascript">
$(document).ready(function(){

     $('#imagem').live('change',function(){
		 
		$('#visualizar').html('<img src="<?php echo $urlsite ?>/adm/js/cadastro/blog/upload/ajax-loader.gif"/>');
		
		$('#formulario').ajaxForm({
			
            target:'#visualizar'
			
         }).submit();
		 
     });
})
</script>
<?php } ?>
<?php if($pagina == "blog-categorias" ) { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/blog-categorias/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "blog-categorias-add" ) { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
$(document).ready(function(){
		$('#form').validate({
			rules: {

				nome: { required: true, minlength: 1, maxlength: 100 }
				
			},
			messages: {

				nome: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/blog-categorias/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
		});
	});
</script>
<?php } ?>
<?php if($pagina == "localidades") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/localidades/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "localidades-add") { ?>
<script type="text/javascript" ><?php include("js/jquery.inputmask.bundle.js"); ?></script>
<script type="text/javascript">
    $(document).ready(function() {
      $("#telefone").inputmask({
        mask: ["(99) 9999-9999", "(99) 99999-9999", "9999 999 9999", ],
        keepStatic: true
      });
      $("#telefone2").inputmask({
        mask: ["(99) 9999-9999", "(99) 99999-9999", "9999 999 9999", ],
        keepStatic: true
      });
      $("#cep").inputmask({
        mask: ["99999-999" ],
        keepStatic: true
      });
    });
</script>
<link rel="stylesheet" href="<?php echo $urlsite ?>/adm/js/datepicker/css/datepicker.css">
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/datepicker.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/datepicker.pt-BR.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/main.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
<!-- cupons/form/usuarios -->
$(document).ready(function(){
		$('#form').validate({
			rules: {

				nome: { required: true, minlength: 1, maxlength: 100 }
				
			},
			messages: {

				nome: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/localidades/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
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
<?php if($pagina == "categorias") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/categorias/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "categorias-add") { ?>
<link rel="stylesheet" href="<?php echo $urlsite ?>/adm/js/datepicker/css/datepicker.css">
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/datepicker.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/datepicker.pt-BR.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/main.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
<!-- cupons/form/usuarios -->
$(document).ready(function(){
		$('#form').validate({
			rules: {

				titulo: { required: true, minlength: 1, maxlength: 400 }				
			},
			messages: {

				titulo: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/categorias/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
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
<?php if($pagina == "planos") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/planos/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "planos-add") { ?>
<script type="text/javascript" ><?php include("js/jquery.inputmask.bundle.js"); ?></script>
<script type="text/javascript">
    $(document).ready(function() {
      $("#valor").inputmask({
        mask: ["9,99", "99,99", "999,99", "9999,99", "9999,99", "99999,99", ],
        keepStatic: true
      });
    });
</script>

<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
<!-- cupons/form/usuarios -->
$(document).ready(function(){
		$('#form').validate({
			rules: {

				locl_id: { required: true, minlength: 1, maxlength: 100 },
				titulo: { required: true, minlength: 1, maxlength: 100 },
				cat_id: { required: true, minlength: 1, maxlength: 100 }
				
			},
			messages: {

				locl_id: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				titulo: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				cat_id: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/planos/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
		});
	});
</script>
<script>
<!-- mascara numeros -->
   function somenteNumeros(num) {
        var er = /[^0-9,.]/;
        er.lastIndex = 0;
        var campo = num;
        if (er.test(campo.value)) {
          campo.value = "";
        }
    }
</script>
<?php } ?>
<?php if($pagina == "planos-img") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/jquery.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/jquery.form.js"></script>
<script type="text/javascript">
$(document).ready(function(){

     $('#imagem').live('change',function(){
		 
		$('#visualizar').html('<img src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/ajax-loader.gif"/>');
		
		$('#formulario').ajaxForm({
			
            target:'#visualizar'
			
         }).submit();
		 
     });
 })
</script>
<?php } ?>
<?php if($pagina == "combos") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/planos/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "combos-add") { ?>
<script type="text/javascript" ><?php include("js/jquery.inputmask.bundle.js"); ?></script>
<script type="text/javascript">
    $(document).ready(function() {
      $("#valor").inputmask({
        mask: ["9,99", "99,99", "999,99", "9999,99", "9999,99", "99999,99", ],
        keepStatic: true
      });
    });
</script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
<!-- cupons/form/usuarios -->
$(document).ready(function(){
		$('#form').validate({
			rules: {

				locl_id: { required: true, minlength: 1, maxlength: 100 },
				titulo: { required: true, minlength: 1, maxlength: 100 },
				cat_id: { required: true, minlength: 1, maxlength: 100 }
				
			},
			messages: {

				locl_id: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				titulo: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				cat_id: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/planos/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
		});
	});
</script>
<script>
<!-- mascara numeros -->
   function somenteNumeros(num) {
        var er = /[^0-9,.]/;
        er.lastIndex = 0;
        var campo = num;
        if (er.test(campo.value)) {
          campo.value = "";
        }
    }
</script>
<?php } ?>
<?php if($pagina == "combos-img") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/jquery.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/jquery.form.js"></script>
<script type="text/javascript">
$(document).ready(function(){

     $('#imagem').live('change',function(){
		 
		$('#visualizar').html('<img src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/ajax-loader.gif"/>');
		
		$('#formulario').ajaxForm({
			
            target:'#visualizar'
			
         }).submit();
		 
     });
 })
</script>
<?php } ?>
<?php if($pagina == "telefonia") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/planos/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "telefonia-add") { ?>
<script type="text/javascript" ><?php include("js/jquery.inputmask.bundle.js"); ?></script>
<script type="text/javascript">
    $(document).ready(function() {
      $("#valor").inputmask({
        mask: ["9,99", "99,99", "999,99", "9999,99", "9999,99", "99999,99", ],
        keepStatic: true
      });
    });
</script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
<!-- cupons/form/usuarios -->
$(document).ready(function(){
		$('#form').validate({
			rules: {

				locl_id: { required: true },
				titulo: { required: true, minlength: 1, maxlength: 100 },
				cat_id: { required: true, minlength: 1, maxlength: 100 }
				
			},
			messages: {

				locl_id: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				titulo: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				cat_id: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/planos/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
		});
	});
</script>
<script>
<!-- mascara numeros -->
   function somenteNumeros(num) {
        var er = /[^0-9,.]/;
        er.lastIndex = 0;
        var campo = num;
        if (er.test(campo.value)) {
          campo.value = "";
        }
    }
</script>
<?php } ?>
<?php if($pagina == "telefonia-img") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/jquery.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/jquery.form.js"></script>
<script type="text/javascript">
$(document).ready(function(){

     $('#imagem').live('change',function(){
		 
		$('#visualizar').html('<img src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/ajax-loader.gif"/>');
		
		$('#formulario').ajaxForm({
			
            target:'#visualizar'
			
         }).submit();
		 
     });
 })
</script>
<?php } ?>
<?php if($pagina == "tv") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/planos/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "tv-add") { ?>
<script type="text/javascript" ><?php include("js/jquery.inputmask.bundle.js"); ?></script>
<script type="text/javascript">
    $(document).ready(function() {
      $("#valor").inputmask({
        mask: ["9,99", "99,99", "999,99", "9999,99", "9999,99", "99999,99", ],
        keepStatic: true
      });
    });
</script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
<!-- cupons/form/usuarios -->
$(document).ready(function(){
		$('#form').validate({
			rules: {

				locl_id: { required: true, minlength: 1, maxlength: 100 },
				titulo: { required: true, minlength: 1, maxlength: 100 },
				cat_id: { required: true, minlength: 1, maxlength: 100 }
				
			},
			messages: {

				locl_id: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				titulo: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				cat_id: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/planos/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
		});
	});
</script>
<script>
<!-- mascara numeros -->
   function somenteNumeros(num) {
        var er = /[^0-9,.]/;
        er.lastIndex = 0;
        var campo = num;
        if (er.test(campo.value)) {
          campo.value = "";
        }
    }
</script>
<?php } ?>
<?php if($pagina == "tv-img") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/jquery.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/jquery.form.js"></script>
<script type="text/javascript">
$(document).ready(function(){

     $('#imagem').live('change',function(){
		 
		$('#visualizar').html('<img src="<?php echo $urlsite ?>/adm/js/cadastro/planos/upload/ajax-loader.gif"/>');
		
		$('#formulario').ajaxForm({
			
            target:'#visualizar'
			
         }).submit();
		 
     });
 })
</script>
<?php } ?>
<?php if($pagina == "depoimentos") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/depoimentos/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "depoimentos-add") { ?>
<link rel="stylesheet" href="<?php echo $urlsite ?>/adm/js/datepicker/css/datepicker.css">
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/datepicker.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/datepicker.pt-BR.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/main.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
<!-- cupons/form/usuarios -->
$(document).ready(function(){
		$('#form').validate({
			rules: {

				nome: { required: true, minlength: 1, maxlength: 100 },
				intro: { required: true, minlength: 1, maxlength: 400 },
				depoimento: { required: true, minlength: 1 }
				
			},
			messages: {

				nome: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				intro: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				depoimento: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/depoimentos/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
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
<?php if($pagina == "duvidas") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/duvidas/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "duvidas-add") { ?>
<link rel="stylesheet" href="<?php echo $urlsite ?>/adm/js/datepicker/css/datepicker.css">
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/datepicker.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/datepicker.pt-BR.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/datepicker/js/main.js"></script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
<!-- cupons/form/usuarios -->
$(document).ready(function(){
		$('#form').validate({
			rules: {

				pergunta: { required: true, minlength: 1, maxlength: 100 },
				resposta: { required: true, minlength: 1 }
				
			},
			messages: {

				pergunta: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				resposta: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/duvidas/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
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





<?php if($pagina == "crm") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/crm/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "usuarios") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
	<?php
		
	//mysqli_query($conexao,"SELECT * FROM paginas_dados WHERE del = 'N'");
    while($query_dados = mysqli_fetch_object($todos_ac))
    {
    ?>
    <script type="text/javascript">$(document).ready(function(){$("#form_delete_<?php echo $query_dados->id; ?>").validate({rules:{},messages:{},submitHandler:function(e){var a=$(e).serialize();return $.ajax({type:"POST",url:"<?php echo $urlsite . "/adm/js/cadastro/usuarios/deletar.php" ?>",data:a,success:function(e){$("#status_msg").html(e)}}),!1}})});</script>
    <?php } ?>
<?php } ?>
<?php if($pagina == "minha-conta" || $pagina == "usuarios-add") { ?>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
<!-- cupons/form/usuarios -->
$(document).ready(function(){
		$('#form').validate({
			rules: {
				nome_cliente: { required: true },
				nome_responsavel: { required: true },
				usuario: { required: true, minlength: 3, maxlength: 40<?php if($pagina == "usuarios-add" && $pagina == "") { echo ", remote: '".$urlsite."/adm/js/cadastro/usuarios/valida_usuario_novo.php'"; } ?> },
<?php if($pagina == "usuarios-add" && $pagina == "") { ?>
				senha: { required: true },
<?php } ?>
				nivel_acesso: { required: true }
			},
			messages: {
				nome_cliente: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				nome_responsavel: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				usuario: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', remote: '<h1 class="en_input_alerta">Usuário já cadastrado. Digite outro.</h1>' },
<?php if($ht_url == "usuarios-add" && $ht_url == "") { ?>
				senha: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
<?php } ?>
				nivel_acesso: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }
			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/usuarios/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
		});
	});
</script>
<script>
<!-- cupons/login/usuarios -->
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
<?php if($pagina == "configuracoes") { ?>
<script type="text/javascript" ><?php include("js/jquery.inputmask.bundle.js"); ?></script>
<script type="text/javascript">
    $(document).ready(function() {
      $("#cnpj").inputmask({
        mask: ["99.999.999/9999-99" ],
        keepStatic: true
      });
    });
</script>
<script type="text/javascript" src="<?php echo $urlsite ?>/adm/js/jquery.validate.js"></script>
<script>
<!-- cupons/form/usuarios -->
$(document).ready(function(){
		$('#form').validate({
			rules: {

				tsite: { required: true },
				missao: { required: true },
				visao: { required: true },
				num_vant_1: { required: true },
				num_vant_2: { required: true },
				num_vant_3: { required: true }
				
			},
			messages: {

				tsite: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				missao: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				visao: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				num_vant_1: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				num_vant_2: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' },
				num_vant_3: { required: '<h1 class="en_input_alerta">Preencha este campo.</h1>', minlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>', maxlength: '<h1 class="en_input_alerta">Preencha este campo.</h1>' }

			},
			submitHandler: function( form ){
				var dados = $( form ).serialize();

				$.ajax({
					type: "POST",
					url: "<?php echo $urlsite ?>/adm/js/cadastro/configuracao/processa.php",
					data: dados,
					success: function( data )
					{
						$("input[name='none']").val( '' );
						$('#form_status').html(data);
					}
				});

				return false;
			}
		});
	});
</script>
<script>
<!-- cupons/login/usuarios -->
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
