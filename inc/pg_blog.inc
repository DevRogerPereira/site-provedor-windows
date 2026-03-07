<?php if ($detect->isMobile()) : ?>
	<section id="blog">
		<header id="wrap">
			<div class="container">
            	<div class="row">
                    <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="blg-titulo">Blog</a>
            	</div>
            	<div class="row blg-ul">
                	<ul>
<?php if($url == true) { // ini if url ?>
                        <li>
                            <div class="row">
                            <?php echo $dados_ver_tag . $dados_ver_titulo . $dados_ver_data_format ?>
                            </div>
                            <div class="row prf_li rli<?php echo $dados_blog->id ?>">
                            <?php echo $dados_ver_li_foto . $dados_ver_detalhes ?>
                            </div>
                        </li>
<?php } elseif($url == false) { // elseif url ?>
<?php } // fim if url ?>
<?php

$key_valor = 0;

$sql = mysqli_query($conexao,"SELECT * FROM blog WHERE del = 'N' && url <> '". $url ."' ORDER BY data_ini DESC LIMIT 2");

while ($dados_blog = mysqli_fetch_object($sql)) {

$key_valor++;

$url_list = $urlsite . "/" . $cidade . "/blog/" . $dados_blog->url . "/";

if ($dados_blog->foto == true && file_exists("images/".$dados_blog->foto."")) { 
											
	list($width, $height) = getimagesize("images/".$dados_blog->foto."");
					
	$newWidth = 1103;
	$x = ($newWidth*$height)/$width;
	$x1 = number_format($x, 0, '.', '');

	$dados_li_foto = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/1103x".$x1."/".$dados_blog->foto."\"></a>";
									
} else {
									
	$dados_li_foto = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/1103x428/na.jpg\"></a>";
									
}

if ($dados_blog->tag == true) { 

	$dados_tag = "<a href=\"javascript:;\" onClick=\"perfil_li('" . $dados_blog->id . "')\" class=\"tlp li" . $dados_blog->id . " blg-li-tag\">" . $dados_blog->tag . "</a>";
 
} else {
	
	$dados_tag = "";
   
}

if ($dados_blog->titulo == true) { 

	$dados_titulo = "<a href=\"javascript:;\" onClick=\"perfil_li('" . $dados_blog->id . "')\" class=\"tlp li" . $dados_blog->id . " blg-li-titulo\">" . $dados_blog->titulo . "<span>+</span></a>";
 
} else {
	
	$dados_titulo = "";
   
}

if ($dados_blog->detalhes == true) { 

	$dados_detalhes = "<span class=\"blg-li-detalhes\">". nl2br($dados_blog->detalhes) ."</span>";
 
} else {
	
	$dados_detalhes = "";
   
}

if($dados_blog->data_ini <> '0000-00-00') {
					
	$data_ini1 = str_replace('/', '-', $dados_blog->data_ini);
	$dados_data_ini = date('d/m/Y', strtotime($data_ini1));
	$dados_hora_ini = date('H:i', strtotime($data_ini1));
	$dados_data_format = "<a href=\"javascript:;\" onClick=\"perfil_li('" . $dados_blog->id . "')\" class=\"tlp li" . $dados_blog->id . " blg-li-data\">" . $dados_data_ini . " às " . $dados_hora_ini . "</a>";
					
} else {
					
	$dados_data_ini = date("d/m/Y"); 
	$dados_hora_ini = date("H:i"); 
	$dados_data_format = "<a href=\"javascript:;\" onClick=\"perfil_li('" . $dados_blog->id . "')\" class=\"tlp li" . $dados_blog->id . " blg-li-data\">" . $dados_data_ini . " às " . $dados_hora_ini . "</a>";

}

if($key_valor == 1) {
  
  $pln_li_div = " class=\"blg-li-col\"";
  
} else {
	
  $pln_li_div = "";
  
}

?>
                        <li>
                            <div class="row">
                            <?php echo $dados_tag . $dados_titulo . $dados_data_format ?>
                            </div>
                            <div class="row prf_li rli<?php echo $dados_blog->id ?>" style="display:none">
                            <?php echo $dados_li_foto . $dados_detalhes ?>
                            </div>
                        </li>
<?php } ?>
                    </ul>
            	</div>
			</div>
		</header>
	</section>
<?php else : ?>
	<section id="blog">
		<header id="wrap">
			<div class="container">
            	<div class="row">
                    <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="blg-titulo">Blog</a>
            	</div>
            	<div class="row blg-ul">
                	<ul>
<?php if($url == true) { // ini if url ?>
                        <li>
                            <div class="row">
                            <?php echo $dados_ver_tag . $dados_ver_titulo . $dados_ver_data_format ?>
                            </div>
                            <div class="row prf_li rli<?php echo $dados_blog->id ?>">
                            <?php echo $dados_ver_li_foto . $dados_ver_detalhes ?>
                            </div>
                        </li>
<?php } elseif($url == false) { // elseif url ?>
<?php } // fim if url ?>
<?php

$key_valor = 0;

$sql = mysqli_query($conexao,"SELECT * FROM blog WHERE del = 'N' && url <> '". $url ."' ORDER BY data_ini DESC LIMIT 2");

while ($dados_blog = mysqli_fetch_object($sql)) {

$key_valor++;

$url_list = $urlsite . "/" . $cidade . "/blog/" . $dados_blog->url . "/";

if ($dados_blog->foto == true && file_exists("images/".$dados_blog->foto."")) { 
											
	list($width, $height) = getimagesize("images/".$dados_blog->foto."");
					
	$newWidth = 1103;
	$x = ($newWidth*$height)/$width;
	$x1 = number_format($x, 0, '.', '');

	$dados_li_foto = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/1103x".$x1."/".$dados_blog->foto."\"></a>";
									
} else {
									
	$dados_li_foto = "<a href=\"".$url_list."\" class=\"blg-li-img\"><img src=\"".$urlsite."/".$url_ft."/1103x428/na.jpg\"></a>";
									
}

if ($dados_blog->tag == true) { 

	$dados_tag = "<a href=\"javascript:;\" onClick=\"perfil_li('" . $dados_blog->id . "')\" class=\"tlp li" . $dados_blog->id . " blg-li-tag\">" . $dados_blog->tag . "</a>";
 
} else {
	
	$dados_tag = "";
   
}

if ($dados_blog->titulo == true) { 

	$dados_titulo = "<a href=\"javascript:;\" onClick=\"perfil_li('" . $dados_blog->id . "')\" class=\"tlp li" . $dados_blog->id . " blg-li-titulo\">" . $dados_blog->titulo . "<span>+</span></a>";
 
} else {
	
	$dados_titulo = "";
   
}

if ($dados_blog->detalhes == true) { 

	$dados_detalhes = "<span class=\"blg-li-detalhes\">". nl2br($dados_blog->detalhes) ."</span>";
 
} else {
	
	$dados_detalhes = "";
   
}

if($dados_blog->data_ini <> '0000-00-00') {
					
	$data_ini1 = str_replace('/', '-', $dados_blog->data_ini);
	$dados_data_ini = date('d/m/Y', strtotime($data_ini1));
	$dados_hora_ini = date('H:i', strtotime($data_ini1));
	$dados_data_format = "<a href=\"javascript:;\" onClick=\"perfil_li('" . $dados_blog->id . "')\" class=\"tlp li" . $dados_blog->id . " blg-li-data\">" . $dados_data_ini . " às " . $dados_hora_ini . "</a>";
					
} else {
					
	$dados_data_ini = date("d/m/Y"); 
	$dados_hora_ini = date("H:i"); 
	$dados_data_format = "<a href=\"javascript:;\" onClick=\"perfil_li('" . $dados_blog->id . "')\" class=\"tlp li" . $dados_blog->id . " blg-li-data\">" . $dados_data_ini . " às " . $dados_hora_ini . "</a>";

}

if($key_valor == 1) {
  
  $pln_li_div = " class=\"blg-li-col\"";
  
} else {
	
  $pln_li_div = "";
  
}

?>
                        <li>
                            <div class="row">
                            <?php echo $dados_tag . $dados_titulo . $dados_data_format ?>
                            </div>
                            <div class="row prf_li rli<?php echo $dados_blog->id ?>" style="display:none">
                            <?php echo $dados_li_foto . $dados_detalhes ?>
                            </div>
                        </li>
<?php } ?>
                    </ul>
            	</div>
			</div>
		</header>
	</section>
<?php endif; ?>