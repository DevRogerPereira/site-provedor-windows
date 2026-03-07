<?php if($disp_detect == "PC") {?>
	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
<?php

$home_busca = "SELECT * FROM planos WHERE del = 'N' && cat_id = '5' ".$dados_filtros." ORDER BY id DESC";
//echo $home_busca;

$total_reg = "150";

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
                    <div class="row">
						<select name="select" id="bnficr_id" class="cl_col cl_grid_4 at_lt_filtros" onchange="this.options[this.selectedIndex].value && (window.location = this.options[this.selectedIndex].value);">
							<?php 
								if($ht_url == false){
												
												echo "<option value=\"\" selected=\"selected\">Filtrar</option>";
												echo "<option value=\"\"></option>";
												
								} else {
												
												$tb_user_centro = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE id = '".$ht_url."'"));
												echo "<option value=\"".$tb_user_centro['id']."\" selected=\"selected\">".$tb_user_centro['nome'] . "</option>";
												echo "<option></option>";
												
								}

								$tb_cat = mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' GROUP BY locl_id");
												while($tb_cat_dados = mysqli_fetch_array($tb_cat)){
												$tb_finc_clientes = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE id = '".$tb_cat_dados['locl_id']."'"));
												echo "<option value=\"".$urlsite."/adm/planos/".$tb_finc_clientes['id']."\">".$tb_finc_clientes['nome'] . "</option>";
								}
							?>
						</select>
                    </div>
                    <div class="lt_box">
                        <div class="row at_lt_box">
                            <ul>
<?php

while ($dados_paginas = mysqli_fetch_array($limite))	{ 

//$url_ft = md5($dados_paginas['id']);
//$query = mysqli_query($conexao,"UPDATE planos SET adc_valor = '5.90' WHERE id = '".$dados_paginas['id']."'");

// URL
$url_list = $urlsite . "/adm/tv-add/".$dados_paginas['url']."";
$url_ft = md5(uniqid(time()));

$dados_categoria = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos_categorias WHERE del = 'N' && id = '".$dados_paginas['cat_id']."'"));

/*
if ($dados_paginas['foto'] != "" && file_exists("../images/".$dados_paginas['foto']."")) { 
	$dados_img = "<a href=\"".$url_list."\" class=\"at_lt_img\"><img src=\"".$urlsite."/".$url_ft."/48x48/".$dados_paginas['foto']."\"></a>";
} else {
	//list($width, $height) = getimagesize("img/blog-img1.jpg");
	$dados_img = "<a href=\"".$url_list."\" class=\"at_lt_img\"><img src=\"".$urlsite."/".$url_ft."/48x48/argontec_img_na.jpg\"></a>";
}
*/
if ($dados_paginas['tipo_id'] == 1) { 

   $dados_tipo_id = "SLIDE 1 - ";
   //$dados_tipo_link = "<a href=\"".$urlsite . "/adm/planos-img/".$dados_paginas['url']."\" class=\"at_lt_acoes\"><i class=\"fa fa-image\" aria-hidden=\"true\"></i></a>";
   
} elseif ($dados_paginas['tipo_id'] == 2) { 

   $dados_tipo_id = "SLIDE 2 - ";
   //$dados_tipo_link = "<a href=\"".$urlsite . "/adm/planos-img/".$dados_paginas['url']."\" class=\"at_lt_acoes\"><i class=\"fa fa-image\" aria-hidden=\"true\"></i></a>";
   
} else {
	
   $dados_tipo_id = "";
   $dados_tipo_link = "";
   
}

if ($dados_categoria['nome'] == true) { 

   $dados_categoria = $dados_categoria['nome'];
   
} else {
	
   $dados_categoria = "";
   
}

if ($dados_paginas['titulo'] == true) { 

   $dados_nome = "<a href=\"".$url_list."\" class=\"at_lt_titulo\">".$dados_tipo_id.$dados_categoria." - ".$dados_paginas['titulo'] . "</a>";
   
} else {
	
   $dados_nome = "<a href=\"".$url_list."\" class=\"at_lt_titulo\">Nome não informado.</a>";
   
}

if ($dados_paginas['valor'] == true) {
	
   $dados_intro = "<a href=\"".$url_list."\" class=\"at_lt_intro\">R$ ".number_format($dados_paginas['valor'],2,",","")."/mês</a>";
   
} else {
	
   $dados_intro = "<a href=\"".$url_list."\" class=\"at_lt_intro\">Nome não informado.</a>";
   
}




?>
                                <li>
                                    <div class="col grid-10">
										<?php echo $dados_nome ?>
										<?php echo $dados_intro ?>
                                    </div>
                                    <div class="col grid-2 at_ul_acoes">
                                        <form name="form_delete_<?php echo $dados_paginas['id'] ?>" id="form_delete_<?php echo $dados_paginas['id'] ?>" action="" method="post"><input name="id" type="hidden" id="id" value="<?php echo $dados_paginas['id'] ?>" /><?php echo $dados_tipo_link ?><a href="<?php echo $url_list ?>" class="at_lt_acoes"><i class="fa fa-pencil" aria-hidden="true"></i></a><button type="submit" name="add" id="add" class="at_lt_acoes"><i class="fa fa-trash" aria-hidden="true"></i></button></form>
                                    </div>
                                </li>
<?php }?>
                            </ul>
                        </div>
                        <div class="at_lt_listar">
                            <a>Ver tudo</a>
                        </div>
                    </div>
<?php } else {
	
	$url_list = $urlsite . "/adm/".$pagina."-add";
	
?>
                    <div class="lt_box">
                    	<div class="of_box">
                        	<a href="<?php echo $url_list ?>"><i class="fa fa-edit" aria-hidden="true"></i></a>
                        	<a href="<?php echo $url_list ?>" class="of_na_titulo">Não há registros cadastradas no momento</a>
                        	<a href="<?php echo $url_list ?>" class="of_na_intro">Mantenha sua lista de sempre atualizada</a>
                        	<a href="<?php echo $url_list ?>" class="of_na_criar">Cadastrar</a>
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