<?php if ($detect->isMobile()) : ?>
<?php if($dados_rows_plano_5 > 0) { ?>
	<section id="planos-cbl">
		<header id="wrap">
			<div class="container">
				<span class="pln-cbl-li-tag">TV HD</span>
				<span class="pln-cbl-li-titulo">Ultravelocidades para navegar sem preocupações</span>
				<span class="pln-cbl-li-planos">Planos</span>
			</div>
		</header>
	</section>

	<section id="planos">
		<header id="wrap">
			<div class="container">
            
            	<div class="row">
                    <span class="pln-titulo">TV HD.</span>
                </div>
                
            	<div class="row pln-ul">
                	<ul>
<?php

$key_valor = 0;

$sql = mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && cat_id = '5' ".$dados_cidade_flt." ORDER BY valor ASC");

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

	$dados_titulo = "<a href=\"".$url_list."\" class=\"pln-li-tag\">TV HD</a><a href=\"".$url_list."\" class=\"pln-li-num\">" . $dados_planos->titulo . "</a>";
 
} else {
	
	$dados_titulo = "";
   
}

if ($dados_planos->valor <> 0.00) {

	$dados_valor = "<a href=\"".$url_list."\" class=\"pln-li-valor\">R$ ". substr($dados_planos->valor, 0, -3) ."". substr(number_format($dados_planos->valor, 2, ',', '.'), -3) ."/mês<span>no boleto via e-mail</span></a><a href=\"".$url_list."\" class=\"pln-li-assine\">Assine já</a>";

} else {
	
	$dados_valor = "";
   
}
										
if ($dados_planos->download == true) {

	$dados_canais = "<a href=\"javascript:;\" class=\"pln-li-vnt\" onClick=\"abreFecha('.nav-modal-".$dados_planos->id ."')\">".$dados_planos->download ." canais em HD<span>Confira os canais</span></a>";
   
} else {
	
	$dados_canais = "";
   
}

if ($dados_planos->vnt_6 == true) {

	$dados_vnt_6 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_6 ."</a>";
	$dados_vnt_6_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_6 = "";
	$dados_vnt_6_css = "";
   
}

if ($dados_planos->vnt_5 == true) {

	$dados_vnt_5 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_5 ."</a>";
	$dados_vnt_5_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_5 = "";
	$dados_vnt_5_css = "";
  
}

if ($dados_planos->vnt_4 == true) {

	$dados_vnt_4 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_4 ."</a>";
	$dados_vnt_4_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_4 = "";
	$dados_vnt_4_css = "";
   
}

if ($dados_planos->vnt_3 == true) {

	$dados_vnt_3 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_3 ."</a>";
	$dados_vnt_3_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_3 = "";
	$dados_vnt_3_css = "";
  
}

if ($dados_planos->vnt_2 == true) {

	$dados_vnt_2 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_2 ."</a>";
	$dados_vnt_2_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_2 = "";
	$dados_vnt_2_css = "";
   
}

if ($dados_planos->vnt_1 == true) {

	$dados_vnt_1 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_1 ."</a>";
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
                            <?php echo $dados_titulo . $dados_valor . $dados_vnt_download . $dados_vnt_1 . $dados_vnt_2 . $dados_vnt_3 . $dados_vnt_4 . $dados_vnt_5 . $dados_vnt_6 . $dados_canais ?>
                        </li>
<?php } ?>
                    </ul>
                </div>
                
			</div>
		</header>
	</section>

<?php

$sql = mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && cat_id = '5' ".$dados_cidade_flt." ORDER BY valor ASC");

while ($dados_planos = mysqli_fetch_object($sql)) {

$url_list = $urlsite . "/" . $cidade . "/assine/". $pagina ."/" . $dados_planos->url . "";

?>
	<section id="nav-flt-modal" class="nav-modal-<?php echo $dados_planos->id ?>" style="display:none">
		<header id="wrap">
			<div class="container">
            	<div class="row nav-flt-lcld-screen" onClick="abreFecha('.nav-modal-<?php echo $dados_planos->id ?>')">
                </div>
            	<div class="row nav-flt-lcld-align">
                    <div class="row nav-flt-lcld-screen-ul">
                        <div class="row">
                        	<a href="javascript:;" class="nav-flt-tag" onClick="abreFecha('.nav-modal-<?php echo $dados_planos->id ?>')">Plano <?php echo $dados_planos->id ?></a>
                        	<a href="javascript:;" class="nav-flt-titulo" onClick="abreFecha('.nav-modal-<?php echo $dados_planos->id ?>')">21 Canais</a>
                        	<a href="javascript:;" class="nav-flt-lcld-fechar" onClick="abreFecha('.nav-modal-<?php echo $dados_planos->id ?>')"></a>
                        </div>

                        <div class="nav-modal-canais-ul">

                            <div class="row">
                                <ul>
<?php

$sql_2 = mysqli_query($conexao,"SELECT * FROM planos_canais_active WHERE plano_id = '".$dados_planos->id."'");

while ($dados_planos_canais = mysqli_fetch_object($sql_2)) {

$dados_canais = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM planos_canais WHERE del = 'N' && id = '".$dados_planos_canais->canal_id."'"));
?>
                                    <li>
                                        <a href="javascript:;" class="nav-modal-canais-li" onClick="abreFecha('.nav-modal-<?php echo $dados_planos->id ?>')"><img src="<?php echo $urlsite . "/images/" . $dados_canais->foto ?>"></a>
                                    </li>
<?php } ?>
                                </ul>
                            </div>

                        </div>
                            
                        <div class="row nav-flt-rdp-ul">
                        	<a href="<?php echo $url_list ?>" class="nav-flt-rdp-assine">Assine já</a>
                        </div>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?>

<?php } ?>
<?php else : ?>
<?php if($dados_rows_plano_5 > 0) { ?>
	<section id="planos-cbl">
		<header id="wrap">
			<div class="container">
				<span class="pln-cbl-li-tag">TV HD</span>
				<span class="pln-cbl-li-titulo">Ultravelocidades para navegar sem preocupações</span>
				<span class="pln-cbl-li-planos">Planos</span>
			</div>
		</header>
	</section>

	<section id="planos">
		<header id="wrap">
			<div class="container">
            
            	<div class="row">
                    <span class="pln-titulo">TV HD.</span>
                </div>
                
            	<div class="row pln-ul">
                	<ul>
<?php

$key_valor = 0;

$sql = mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && cat_id = '5' ".$dados_cidade_flt." ORDER BY valor ASC");

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

	$dados_titulo = "<a href=\"".$url_list."\" class=\"pln-li-tag\">TV HD</a><a href=\"".$url_list."\" class=\"pln-li-num\">" . $dados_planos->titulo . "</a>";
 
} else {
	
	$dados_titulo = "";
   
}

if ($dados_planos->valor <> 0.00) {

	$dados_valor = "<a href=\"".$url_list."\" class=\"pln-li-valor\">R$ ". substr($dados_planos->valor, 0, -3) ."". substr(number_format($dados_planos->valor, 2, ',', '.'), -3) ."/mês<span>no boleto via e-mail</span></a><a href=\"".$url_list."\" class=\"pln-li-assine\">Assine já</a>";

} else {
	
	$dados_valor = "";
   
}
										
if ($dados_planos->download == true) {

	$dados_canais = "<a href=\"javascript:;\" class=\"pln-li-vnt\" onClick=\"abreFecha('.nav-modal-".$dados_planos->id ."')\">".$dados_planos->download ." canais em HD<span>Confira os canais</span></a>";
   
} else {
	
	$dados_canais = "";
   
}

if ($dados_planos->vnt_6 == true) {

	$dados_vnt_6 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_6 ."</a>";
	$dados_vnt_6_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_6 = "";
	$dados_vnt_6_css = "";
   
}

if ($dados_planos->vnt_5 == true) {

	$dados_vnt_5 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_5 ."</a>";
	$dados_vnt_5_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_5 = "";
	$dados_vnt_5_css = "";
  
}

if ($dados_planos->vnt_4 == true) {

	$dados_vnt_4 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_4 ."</a>";
	$dados_vnt_4_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_4 = "";
	$dados_vnt_4_css = "";
   
}

if ($dados_planos->vnt_3 == true) {

	$dados_vnt_3 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_3 ."</a>";
	$dados_vnt_3_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_3 = "";
	$dados_vnt_3_css = "";
  
}

if ($dados_planos->vnt_2 == true) {

	$dados_vnt_2 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_2 ."</a>";
	$dados_vnt_2_css = " pln-li-vnt-borda";
   
} else {
	
	$dados_vnt_2 = "";
	$dados_vnt_2_css = "";
   
}

if ($dados_planos->vnt_1 == true) {

	$dados_vnt_1 = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">".$dados_planos->vnt_1 ."</a>";
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
                            <?php echo $dados_titulo . $dados_valor . $dados_vnt_download . $dados_vnt_1 . $dados_vnt_2 . $dados_vnt_3 . $dados_vnt_4 . $dados_vnt_5 . $dados_vnt_6 . $dados_canais ?>
                        </li>
<?php } ?>
                    </ul>
                </div>
                
			</div>
		</header>
	</section>

<?php

$sql = mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && cat_id = '5' ".$dados_cidade_flt." ORDER BY valor ASC");

while ($dados_planos = mysqli_fetch_object($sql)) {

$url_list = $urlsite . "/" . $cidade . "/assine/". $pagina ."/" . $dados_planos->url . "";

?>
	<section id="nav-flt-modal" class="nav-modal-<?php echo $dados_planos->id ?>" style="display:none">
		<header id="wrap">
			<div class="container">
            	<div class="row nav-flt-lcld-screen" onClick="abreFecha('.nav-modal-<?php echo $dados_planos->id ?>')">
                </div>
            	<div class="row nav-flt-lcld-align">
                    <div class="row nav-flt-lcld-screen-ul">
                        <div class="row">
                        	<a href="javascript:;" class="nav-flt-lcld-fechar" onClick="abreFecha('.nav-modal-<?php echo $dados_planos->id ?>')" class="nav-flt-tag">Plano <?php echo $dados_planos->id ?></a>
                        	<a href="javascript:;" class="nav-flt-lcld-fechar" onClick="abreFecha('.nav-modal-<?php echo $dados_planos->id ?>')" class="nav-flt-titulo">21 Canais</a>
                        	<a href="javascript:;" class="nav-flt-lcld-fechar" onClick="abreFecha('.nav-modal-<?php echo $dados_planos->id ?>')">Fechar</a>
                        </div>

                        <div class="nav-modal-canais-ul">

                            <div class="row">
                                <ul>
<?php

$sql_2 = mysqli_query($conexao,"SELECT * FROM planos_canais_active WHERE plano_id = '".$dados_planos->id."'");

while ($dados_planos_canais = mysqli_fetch_object($sql_2)) {

$dados_canais = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM planos_canais WHERE del = 'N' && id = '".$dados_planos_canais->canal_id."'"));
?>
                                    <li>
                                        <a href="javascript:;" class="nav-flt-lcld-fechar" class="nav-modal-canais-li" onClick="abreFecha('.nav-modal-<?php echo $dados_planos->id ?>')"><img src="<?php echo $urlsite . "/images/" . $dados_canais->foto ?>"></a>
                                    </li>
<?php } ?>
                                </ul>
                            </div>

                        </div>
                            
                        <div class="row nav-flt-rdp-ul">
                        	<a href="<?php echo $url_list ?>" class="nav-flt-rdp-preco">--<span>no boleto via e-mail</span></a>
                        	<a href="<?php echo $url_list ?>" class="nav-flt-rdp-assine">Assine já</a>
                        </div>
                    </div>
                </div>
			</div>
		</header>
	</section>
<?php } ?>

<?php } ?>
<?php endif; ?>