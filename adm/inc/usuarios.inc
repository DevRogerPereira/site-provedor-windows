<?php if($disp_detect == "PC") {?>
	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
<?php

$home_busca = "SELECT * FROM usuarios_dados WHERE del = 'N' && status = 'S' ORDER BY id DESC";
//echo $home_busca;

$total_reg = "15";

if(isset($page) == false) {
	
	$page = "1";

}

$inicio = $page-1;
$inicio = $inicio*$total_reg;

$limite = mysqli_query($conexao,"$home_busca LIMIT $inicio,$total_reg");
$todos = mysqli_query($conexao,"$home_busca");
$todos_ac = mysqli_query($conexao,"$home_busca LIMIT $inicio,$total_reg");

$tr = mysqli_num_rows($todos);
$tp = ceil($tr / $total_reg);

if ($tr == 0) {
	$tr_total = "Nenhuma oferta";
} 
elseif ($tr == 1) {
	$tr_total = "$tr oferta";
} 
elseif ($tr > 1) {
	$tr_total = "$tr ofertas";
} 


if(mysqli_num_rows($todos) > 0){
?>
                    <div class="lt_box">
                        <div class="row at_lt_box">
                            <ul>
<?php

while ($dados_paginas = mysqli_fetch_array($limite))	{ 

// URL
$url_list = $urlsite . "/adm/usuarios-add/".$dados_paginas['url']."";
$url_ft = md5(uniqid(time()));

if ($dados_paginas['foto'] != "" && file_exists("image/".$dados_paginas['foto']."")) { 
	$dados_img = "<a href=\"".$url_list."\" class=\"at_lt_img\"><img src=\"".$urlsite."/".$url_ft."/48x48/".$dados_paginas['foto']."\"></a>";
} else {
	//list($width, $height) = getimagesize("img/blog-img1.jpg");
	$dados_img = "<a href=\"".$url_list."\" class=\"at_lt_img\"><img src=\"".$urlsite."/".$url_ft."/48x48/argontec_img_na.jpg\"></a>";
}

if ($dados_paginas['nome_responsavel'] != "") { 
   $dados_nome = "<a href=\"".$url_list."\" class=\"at_lt_titulo\">".$dados_paginas['nome_responsavel']."</a>";
} else {
   $dados_nome = "<a href=\"".$url_list."\" class=\"at_lt_titulo\">Nome não informado.</a>";
}

if ($dados_paginas['nivel_acesso'] != "") { 
   $dados_responsavel = "<a href=\"".$url_list."\" class=\"at_lt_intro\">Nível ".$dados_paginas['nivel_acesso']."</a>";
} else {
   $dados_responsavel = "<a href=\"".$url_list."\" class=\"at_lt_intro\">Nome não informado.</a>";
}




?>
                                <li>
                                    <div class="col grid-10">
										<?php //echo $dados_img ?>
										<?php echo $dados_nome ?>
										<?php echo $dados_responsavel ?>
                                    </div>
                                    <div class="col grid-2">
                                        <form name="form_delete_<?php echo $dados_paginas['id'] ?>" id="form_delete_<?php echo $dados_paginas['id'] ?>" action="" method="post"><input name="id" type="hidden" id="id" value="<?php echo $dados_paginas['id'] ?>" /><a href="<?php echo $url_list ?>" class="at_lt_acoes"><i class="fa fa-pencil" aria-hidden="true"></i></a><button type="submit" name="add" id="add" class="grid-4 at_lt_acoes"><i class="fa fa-trash" aria-hidden="true"></i></button></form>
                                        <a href="<?php echo $url_list ?>" class="at_lt_detalhes" style="display:none">Ver detalhes</a>
                                    </div>
                                </li>
<?php }?>
                            </ul>
                        </div>
                        <div class="at_lt_listar">
                            <a href="#">Ver tudo</a>
                        </div>
                    </div>
<?php } else {?>
                    <div class="lt_box">
                    	<div class="of_box">
                        	<a href="<?php echo $urlsite . "/usuarios-add" ?>"><i class="fa fa-edit" aria-hidden="true"></i></a>
                        	<a href="<?php echo $urlsite . "/usuarios-add" ?>" class="of_na_titulo">Não há unidades cadastradas no momento</a>
                        	<a href="<?php echo $urlsite . "/usuarios-add" ?>" class="of_na_intro">Mantenha sua lista de unidades sempre atualizada</a>
                        	<a href="<?php echo $urlsite . "/usuarios-add" ?>" class="of_na_criar">Cadastrar unidade</a>
                        </div>
                    </div>
<?php } ?>

					<div id="status_msg">
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?>
<?php if($disp_detect == "MV") {?>
<?php } ?>