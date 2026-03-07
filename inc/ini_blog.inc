<?php if ($detect->isMobile()) : ?>
<?php if($dados_rows_blog > 0) { ?>
	<section id="ini-blog">
		<header id="wrap">
			<div class="container">
            	<div class="row">
                    <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="blg-titulo">Blog</a>
                </div>
            	<div class="row">
                	<ul>
                    	<li class="blg-li-col blg-li-col-ver">
                            <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="blg-nav-titulo">Acompanhe as novidades.</a>
                            <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="blg-nav-ver">Ver blog</a>
                        </li>
<?php

$key_valor = 0;

$sql = mysqli_query($conexao,"SELECT * FROM blog WHERE del = 'N' ORDER BY data_ini DESC LIMIT 2");

while ($dados_planos = mysqli_fetch_object($sql)) {

$key_valor++;

$url_list = $urlsite . "/" . $cidade . "/blog/" . $dados_planos->url . "/";

if ($dados_planos->foto == true && file_exists("images/".$dados_planos->foto."")) { 
											
	$dados_li_foto = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/374x428/".$dados_planos->foto."\"></a>";
									
} else {
									
	$dados_li_foto = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/374x428/na.jpg\"></a>";
									
}

if ($dados_planos->tag == true) { 

	$dados_tag = "<a href=\"".$url_list."\" class=\"blg-li-tag\">" . $dados_planos->tag . "</a>";
 
} else {
	
	$dados_tag = "";
   
}

if ($dados_planos->titulo == true) { 

	$dados_titulo = "<a href=\"".$url_list."\" class=\"blg-li-titulo\">" . $dados_planos->titulo . "</a>";
 
} else {
	
	$dados_titulo = "";
   
}

if($key_valor == 1) {
  
  $pln_li_div = " class=\"blg-li-col\"";
  
} else {
	
  $pln_li_div = "";
  
}

?>
                    	<li<?php echo $pln_li_div ?>>
                            <?php echo $dados_li_foto . $dados_tag . $dados_titulo ?>
                        </li>
<?php } ?>
                    </ul>
                </div>
			</div>
		</header>
	</section>
<?php } ?>
<?php else : ?>
<?php if($dados_rows_blog > 0) { ?>
	<section id="ini-blog">
		<header id="wrap">
			<div class="container">
            	<div class="row">
                    <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="blg-titulo">Blog</a>
                </div>
            	<div class="row">
                	<ul>
                    	<li class="blg-li-col blg-li-col-ver">
                            <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="blg-nav-titulo">Acompanhe as novidades.</a>
                            <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="blg-nav-ver">Ver blog</a>
                        </li>
<?php

$key_valor = 0;

$sql = mysqli_query($conexao,"SELECT * FROM blog WHERE del = 'N' ORDER BY data_ini DESC LIMIT 2");

while ($dados_planos = mysqli_fetch_object($sql)) {

$key_valor++;

$url_list = $urlsite . "/" . $cidade . "/blog/" . $dados_planos->url . "/";

if ($dados_planos->foto == true && file_exists("images/".$dados_planos->foto."")) { 

	$dados_li_foto = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/374x428/".$dados_planos->foto."\"></a>";
									
} else {
									
	$dados_li_foto = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/374x428/na.jpg\"></a>";
									
}

if ($dados_planos->tag == true) { 

	$dados_tag = "<a href=\"".$url_list."\" class=\"blg-li-tag\">" . $dados_planos->tag . "</a>";
 
} else {
	
	$dados_tag = "";
   
}

if ($dados_planos->titulo == true) { 

	$dados_titulo = "<a href=\"".$url_list."\" class=\"blg-li-titulo\">" . $dados_planos->titulo . "</a>";
 
} else {
	
	$dados_titulo = "";
   
}

if($key_valor == 1) {
  
  $pln_li_div = " class=\"blg-li-col\"";
  
} else {
	
  $pln_li_div = "";
  
}

?>
                    	<li<?php echo $pln_li_div ?>>
                            <?php echo $dados_li_foto . $dados_tag . $dados_titulo ?>
                        </li>
<?php } ?>
                    </ul>
                </div>
			</div>
		</header>
	</section>
<?php } ?>
<?php endif; ?>