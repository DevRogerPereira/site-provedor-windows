<?php if($disp_detect == "PC") {?>
	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
<?php

$home_busca = "SELECT * FROM slides WHERE del = 'N' ORDER BY id DESC";

$total_reg = "20";

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
	$tr_total = $tr . "oferta";
} 
elseif ($tr > 1) {
	$tr_total = $tr . "ofertas";
} 


if(mysqli_num_rows($todos) > 0){
?>
                    <div class="lt_box">
                        <div class="row at_lt_box">
                            <ul>
<?php

while ($dados_paginas = mysqli_fetch_array($limite))	{ 

$dados_localidade = mysqli_fetch_array(mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE del = 'N' && id = '".$dados_paginas['locl_id']."'"));

// URL
$url_list = $urlsite . "/adm/".$pagina."-img/".$dados_paginas['id']."";
$url_list_img = $urlsite . "/adm/".$pagina."-img/".$dados_paginas['id']."";
$url_ft = md5(uniqid(time()));

if (isset($dados_paginas['foto']) && file_exists("../images/".$dados_paginas['foto']."")) { 
	
	$dados_img = "<a href=\"".$url_list."\" class=\"at_lt_img\"><img src=\"".$urlsite."/".$url_ft."/48x48/".$dados_paginas['foto']."\"></a>";
	$dados_img_url = $urlsite."/".$url_ft."/1920x824/".$dados_paginas['foto'];
	
} else {
	//list($width, $height) = getimagesize("img/blog-img1.jpg");
	$dados_img = "<a href=\"".$url_list."\" class=\"at_lt_img\"><img src=\"".$urlsite."/".$url_ft."/48x48/img_na.jpg\"></a>";
	$dados_img_url = "";
}

if (isset($dados_localidade['nome'])) { 

   $dados_nome = "<a href=\"".$url_list."\" class=\"at_lt_titulo\">".$dados_localidade['nome']."</a>";
   
} else {
	
   $dados_nome = "<a href=\"".$url_list."\" class=\"at_lt_titulo\">Slide ".$dados_paginas['id']."</a>";
   
}

if (isset($dados_paginas['intro'])) {
	
   $dados_intro = "<a href=\"".$url_list."\" class=\"at_lt_intro\">".$dados_paginas['intro']."</a>";
   
} else {
	
   $dados_intro = "<a href=\"".$url_list."\" class=\"at_lt_intro\">Tamanho 1920x850px</a>";
   
}




?>
                                <li>
                                    <div class="col grid-10">
										<?php echo $dados_img.$dados_nome.$dados_intro ?>
                                    </div>
                                    <div class="col grid-2 at_ul_acoes">
                                        <form name="form_delete_<?php echo $dados_paginas['id'] ?>" id="form_delete_<?php echo $dados_paginas['id'] ?>" action="" method="post"><input name="id" type="hidden" id="id" value="<?php echo $dados_paginas['id'] ?>" /><a href="<?php echo $dados_img_url ?>" target="_blank" class="at_lt_acoes"><i class="fa fa-image" aria-hidden="true"></i></a><a href="<?php echo $url_list ?>" class="at_lt_acoes"><i class="fa fa-pencil" aria-hidden="true"></i></a><button type="submit" name="add" id="add" class="at_lt_acoes"><i class="fa fa-trash" aria-hidden="true"></i></button></form>
                                    </div>
                                </li>
<?php }?>
                            </ul>
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