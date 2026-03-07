<?php if ($detect->isMobile()) : ?>
<?php if($dados_rows_plano_3 > 0) { ?>
	<section id="planos-cbl">
		<header id="wrap">
			<div class="container">
				<span class="pln-cbl-li-tag">Fixo</span>
				<span class="pln-cbl-li-titulo">Ultravelocidades para navegar sem preocupações</span>
				<span class="pln-cbl-li-planos">Planos</span>
			</div>
		</header>
	</section>

	<section id="planos">
		<header id="wrap">
			<div class="container">
            
            	<div class="row">
                    <span class="pln-titulo">Fixo_</span>
                </div>
                
            	<div class="row pln-ul">
                	<ul>
<?php

$key_valor = 0;

$sql = mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && cat_id = '3' ".$dados_cidade_flt." ORDER BY valor ASC");

while ($dados_planos = mysqli_fetch_object($sql)) {

$key_valor++;

$dados_categoria = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM planos_categorias WHERE del = 'N' && id = '".$dados_planos->cat_id."'"));

$url_list = $urlsite . "/" . $dados_cidade['url'] . "/assine/". $pagina ."/" . $dados_planos->url . "";

if (isset($dados_categoria->intro)) { 

	$dados_categoria_obs = "<span class=\"pln-obs\">". nl2br($dados_categoria->intro) ."</span>";
 
} else {
	
	$dados_categoria_obs = "";
   
}

if ($dados_planos->titulo == true) { 

	$dados_titulo = "<a href=\"".$url_list."\" class=\"pln-li-tag\">" . $dados_planos->titulo . "</a>";
 
} else {
	
	$dados_titulo = "";
   
}

if ($dados_planos->download == true) { 

	$dados_titulo = $dados_titulo . "<a href=\"".$url_list."\" class=\"pln-li-num\">" . $dados_planos->download . " Minutos</a>";
	$dados_vnt_download = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">" . $dados_planos->download . " minutos".$dados_upload."</a>";
 
} else {
	
	$dados_titulo = "";
	$dados_vnt_download = "";
   
}

if ($dados_planos->valor <> 0.00) {

	$dados_valor = "<a href=\"".$url_list."\" class=\"pln-li-valor\">R$ ". substr($dados_planos->valor, 0, -3) ."". substr(number_format($dados_planos->valor, 2, ',', '.'), -3) ."/mês<span>no boleto via e-mail</span></a><a href=\"".$url_list."\" class=\"pln-li-assine\">Assine já</a>";

} else {
	
	$dados_valor = "";
   
}
										
if ($dados_planos->vnt_6 == true) {

	$dados_vnt_6 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_6 ."</a>";
	$dados_vnt_6_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_6 = "";
	$dados_vnt_6_css = "";
   
}

if ($dados_planos->vnt_5 == true) {

	$dados_vnt_5 = "<a href=\"".$url_list."\" class=\"pln-li-vnt".$dados_vnt_6_css."\">".$dados_planos->vnt_5 ."</a>";
	$dados_vnt_5_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_5 = "";
	$dados_vnt_5_css = "";
  
}

if ($dados_planos->vnt_4 == true) {

	$dados_vnt_4 = "<a href=\"".$url_list."\" class=\"pln-li-vnt".$dados_vnt_5_css."\">".$dados_planos->vnt_4 ."</a>";
	$dados_vnt_4_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_4 = "";
	$dados_vnt_4_css = "";
   
}

if ($dados_planos->vnt_3 == true) {

	$dados_vnt_3 = "<a href=\"".$url_list."\" class=\"pln-li-vnt".$dados_vnt_4_css."\">".$dados_planos->vnt_3 ."</a>";
	$dados_vnt_3_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_3 = "";
	$dados_vnt_3_css = "";
  
}

if ($dados_planos->vnt_2 == true) {

	$dados_vnt_2 = "<a href=\"".$url_list."\" class=\"pln-li-vnt".$dados_vnt_3_css."\">".$dados_planos->vnt_2 ."</a>";
	$dados_vnt_2_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_2 = "";
	$dados_vnt_2_css = "";
   
}

if ($dados_planos->vnt_1 == true) {

	$dados_vnt_1 = "<a href=\"".$url_list."\" class=\"pln-li-vnt".$dados_vnt_2_css."\">".$dados_planos->vnt_1 ."</a>";
 	$dados_vnt_2_css = " pln-li-vnt-borda";
  
} else {
	
	$dados_vnt_1 = "";
	$dados_vnt_2_css = "";
  
}

if ($dados_planos->detalhes == true) {

	$dados_detalhes = "<p>" . $dados_planos->detalhes . "</p>";
   
} else {
	
	$dados_detalhes = "";
   
}

if ($dados_planos->tipo_id == "S") {

	$dados_tipo_id = "featured";
   
} else {
	
	$dados_tipo_id = "";
   
}

if($key_valor == 1 || $key_valor == 2 || $key_valor == 4 || $key_valor == 5 || $key_valor == 7 || $key_valor == 8 || $key_valor == 10 || $key_valor == 11 || $key_valor == 13 || $key_valor == 14) {
  
  $pln_li_div = " class=\"pln-li-col\"";
  
} else {
	
  $pln_li_div = "";
  
}

?>
                    	<li>
                            <?php echo $dados_titulo . $dados_valor . $dados_vnt_download . $dados_vnt_1 . $dados_vnt_2 . $dados_vnt_3 . $dados_vnt_4 . $dados_vnt_5 . $dados_vnt_6 ?>
                        </li>
<?php } ?>
                    </ul>
                </div>
                
			</div>
		</header>
	</section>
<?php } ?>
<?php else : ?>
<?php if($dados_rows_plano_3 > 0) { ?>
	<section id="planos-cbl">
		<header id="wrap">
			<div class="container">
				<span class="pln-cbl-li-tag">Fixo</span>
				<span class="pln-cbl-li-titulo">Ultravelocidades para navegar sem preocupações</span>
				<span class="pln-cbl-li-planos">Planos</span>
			</div>
		</header>
	</section>

	<section id="planos">
		<header id="wrap">
			<div class="container">
            
            	<div class="row">
                    <span class="pln-titulo">Fixo_</span>
                </div>
                
            	<div class="row pln-ul">
                	<ul>
<?php

$key_valor = 0;

$sql = mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && cat_id = '3' ".$dados_cidade_flt." ORDER BY valor ASC");

while ($dados_planos = mysqli_fetch_object($sql)) {

$key_valor++;

$dados_categoria = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM planos_categorias WHERE del = 'N' && id = '".$dados_planos->cat_id."'"));

$url_list = $urlsite . "/" . $dados_cidade['url'] . "/assine/". $pagina ."/" . $dados_planos->url . "";

if (isset($dados_categoria->intro)) { 

	$dados_categoria_obs = "<span class=\"pln-obs\">". nl2br($dados_categoria->intro) ."</span>";
 
} else {
	
	$dados_categoria_obs = "";
   
}

if ($dados_planos->titulo == true) { 

	$dados_titulo = "<a href=\"".$url_list."\" class=\"pln-li-tag\">" . $dados_planos->titulo . "</a>";
 
} else {
	
	$dados_titulo = "";
   
}

if ($dados_planos->download == true) { 

	$dados_titulo = $dados_titulo . "<a href=\"".$url_list."\" class=\"pln-li-num\">" . $dados_planos->download . " Minutos</a>";
	$dados_vnt_download = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">" . $dados_planos->download . " minutos".$dados_upload."</a>";
 
} else {
	
	$dados_titulo = "";
	$dados_vnt_download = "";
   
}

if ($dados_planos->valor <> 0.00) {

	$dados_valor = "<a href=\"".$url_list."\" class=\"pln-li-valor\">R$ ". substr($dados_planos->valor, 0, -3) ."". substr(number_format($dados_planos->valor, 2, ',', '.'), -3) ."/mês<span>no boleto via e-mail</span></a><a href=\"".$url_list."\" class=\"pln-li-assine\">Assine já</a>";

} else {
	
	$dados_valor = "";
   
}
										
if ($dados_planos->vnt_6 == true) {

	$dados_vnt_6 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_6 ."</a>";
	$dados_vnt_6_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_6 = "";
	$dados_vnt_6_css = "";
   
}

if ($dados_planos->vnt_5 == true) {

	$dados_vnt_5 = "<a href=\"".$url_list."\" class=\"pln-li-vnt".$dados_vnt_6_css."\">".$dados_planos->vnt_5 ."</a>";
	$dados_vnt_5_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_5 = "";
	$dados_vnt_5_css = "";
  
}

if ($dados_planos->vnt_4 == true) {

	$dados_vnt_4 = "<a href=\"".$url_list."\" class=\"pln-li-vnt".$dados_vnt_5_css."\">".$dados_planos->vnt_4 ."</a>";
	$dados_vnt_4_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_4 = "";
	$dados_vnt_4_css = "";
   
}

if ($dados_planos->vnt_3 == true) {

	$dados_vnt_3 = "<a href=\"".$url_list."\" class=\"pln-li-vnt".$dados_vnt_4_css."\">".$dados_planos->vnt_3 ."</a>";
	$dados_vnt_3_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_3 = "";
	$dados_vnt_3_css = "";
  
}

if ($dados_planos->vnt_2 == true) {

	$dados_vnt_2 = "<a href=\"".$url_list."\" class=\"pln-li-vnt".$dados_vnt_3_css."\">".$dados_planos->vnt_2 ."</a>";
	$dados_vnt_2_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_2 = "";
	$dados_vnt_2_css = "";
   
}

if ($dados_planos->vnt_1 == true) {

	$dados_vnt_1 = "<a href=\"".$url_list."\" class=\"pln-li-vnt".$dados_vnt_2_css."\">".$dados_planos->vnt_1 ."</a>";
 	$dados_vnt_2_css = " pln-li-vnt-borda";
  
} else {
	
	$dados_vnt_1 = "";
	$dados_vnt_2_css = "";
  
}

if ($dados_planos->detalhes == true) {

	$dados_detalhes = "<p>" . $dados_planos->detalhes . "</p>";
   
} else {
	
	$dados_detalhes = "";
   
}

if ($dados_planos->tipo_id == "S") {

	$dados_tipo_id = "featured";
   
} else {
	
	$dados_tipo_id = "";
   
}

if($key_valor == 1 || $key_valor == 2 || $key_valor == 4 || $key_valor == 5 || $key_valor == 7 || $key_valor == 8 || $key_valor == 10 || $key_valor == 11 || $key_valor == 13 || $key_valor == 14) {
  
  $pln_li_div = " class=\"pln-li-col\"";
  
} else {
	
  $pln_li_div = "";
  
}

?>
                    	<li<?php echo $pln_li_div ?>>
                            <?php echo $dados_titulo . $dados_valor . $dados_vnt_download . $dados_vnt_1 . $dados_vnt_2 . $dados_vnt_3 . $dados_vnt_4 . $dados_vnt_5 . $dados_vnt_6 ?>
                        </li>
<?php } ?>
                    </ul>
                </div>
                
			</div>
		</header>
	</section>
<?php } ?>
<?php endif; ?>