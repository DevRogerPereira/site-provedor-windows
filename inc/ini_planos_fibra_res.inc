<?php if ($detect->isMobile()) : ?>
<?php if($dados_rows_plano_1 > 0) { ?>
	<section id="ini-planos">
		<header id="wrap">
			<div class="container">
            	<div class="row pln-cbl-ul">
                    <span class="pln-tag">Conheça nossos</span>
                    <span class="pln-titulo">Planos fibra residenciais</span>
                    <span class="pln-intro">Tudo o que você precisa em serviços digitais está na <?php echo $tsite ?>!<br>Aproveite vantagens únicas e simplifique sua vida.</span>
                </div>
            	<div class="row">
					<ul>
<?php

$key_valor = 0;

$sql = mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && cat_id = '1' ".$dados_cidade_flt." ORDER BY valor ASC");

while ($dados_planos = mysqli_fetch_object($sql)) {

$key_valor++;

$dados_categoria = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM planos_categorias WHERE del = 'N' && id = '".$dados_planos->cat_id."'"));

$url_list = $urlsite . "/" . $dados_cidade['url'] . "/assine/". $pagina ."/" . $dados_planos->url . "";

if (isset($dados_categoria->intro)) { 

	$dados_categoria_obs = "<span class=\"pln-obs\">". nl2br($dados_categoria->intro) ."</span>";
 
} else {
	
	$dados_categoria_obs = "";
   
}

if (isset($dados_planos->download)) { 

	$dados_titulo = "<a href=\"".$url_list."\" class=\"pln-li-tag\">FIBRA ÓPTICA</a><a href=\"".$url_list."\" class=\"pln-li-mega\">" . $dados_planos->download . " MB</a>";
	$dados_vnt_download = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">Download até " . $dados_planos->download . " Mbps</a>";
 
} else {
	
	$dados_titulo = "";
	$dados_vnt_download = "";
   
}

if ($dados_planos->titulo == true) { 

	$dados_li_titulo = "<a href=\"".$url_list."\" class=\"pln-li-titulo\">" . $dados_planos->titulo . "</a>";
 
} else {
	
	$dados_li_titulo = "";
   
}

if ($dados_planos->valor <> 0.00) {

	$dados_valor = "<a href=\"".$url_list."\" class=\"pln-li-apenas\">A PARTIR DE</a><a href=\"".$url_list."\" class=\"pln-li-valor\"><strong>R$ ". substr($dados_planos->valor, 0, -3) ."". substr(number_format($dados_planos->valor, 2, ',', '.'), -3) ."</strong>/mês</a><a href=\"".$url_list."\" class=\"pln-li-assine\">Assine já</a><a href=\"".$url_list."\" class=\"pln-li-obs\">Consulte valores e condições.</a>";

} else {
	
	$dados_valor = "";
   
}
										
if ($dados_planos->vnt_11 == true) {

	$dados_vnt_11 = "<a href=\"".$url_list."\"><img src=\"".$urlsite."/images/planos-app-li-5.jpg\" /></a>";
   
} else {
	
	$dados_vnt_11 = "";
   
}
										
if ($dados_planos->vnt_10 == true) {

	$dados_vnt_10 = "<a href=\"".$url_list."\"><img src=\"".$urlsite."/images/planos-app-li-4.jpg\" /></a>";
   
} else {
	
	$dados_vnt_10 = "";
   
}

if ($dados_planos->vnt_9 == true) {

	$dados_vnt_9 = "<a href=\"".$url_list."\"><img src=\"".$urlsite."/images/planos-app-li-3.jpg\" /></a>";
   
} else {
	
	$dados_vnt_9 = "";
  
}

if ($dados_planos->vnt_8 == true) {

	$dados_vnt_8 = "<a href=\"".$url_list."\"><img src=\"".$urlsite."/images/planos-app-li-2.jpg\" /></a>";
   
} else {
	
	$dados_vnt_8 = "";
   
}

if ($dados_planos->vnt_7 == true) {

	$dados_vnt_7 = "<a href=\"".$url_list."\"><img src=\"".$urlsite."/images/planos-app-li-1.jpg\" /></a>";
  
} else {
	
	$dados_vnt_7 = "";
  
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
	$dados_vnt_3_css = "";
   
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

?>
                    	<li>
<?php
$itens = [
    $dados_titulo ?? null,
    $dados_vnt_download ?? null,
    $dados_vnt_1 ?? null,
    $dados_vnt_2 ?? null,
    $dados_vnt_3 ?? null,
    $dados_vnt_4 ?? null,
    $dados_vnt_5 ?? null,
    $dados_vnt_6 ?? null
];

// remove null, false, "", 0, "0"
$itens_validos = array_filter($itens, function($v){
    return isset($v) && trim((string)$v) !== '';
});

if (!empty($itens_validos)) {
?>
    <div class="row">
        <?= implode('', $itens_validos) ?>
    </div>
<?php } ?>
<?php
$apps = array_filter([
    $dados_vnt_7,
    $dados_vnt_8,
    $dados_vnt_9,
    $dados_vnt_10,
    $dados_vnt_11
], function($v){
    return !empty($v) && $v !== 'N' && $v !== false;
});

if (!empty($apps)) {
?>
    <div class="pln-li-app-img">
        <a href="<?= $url_list ?>" class="pln-li-app-titulo">Apps inclusos</a>
        <?= implode('', $apps); ?>
    </div>
<?php } ?><?php if($dados_valor == true) { ?>
			            	<div class="row">
								<?php echo $dados_valor ?>
                            </div>
<?php } ?>
                        </li>
<?php } ?>

                    </ul>
                </div>
            	<div class="row">
                	<?php echo $dados_categoria_obs ?>
                </div>
			</div>
		</header>
	</section>

<?php } ?>
<?php else : ?>
<?php if($dados_rows_plano_1 > 0) { ?>
	<section id="ini-planos">
		<header id="wrap">
			<div class="container">
            	<div class="row pln-cbl-ul">
                    <span class="pln-tag">Conheça nossos</span>
                    <span class="pln-titulo">Planos fibra residenciais</span>
                    <span class="pln-intro">Tudo o que você precisa em serviços digitais está na <?php echo $tsite ?>!<br>Aproveite vantagens únicas e simplifique sua vida.</span>
                </div>
            	<div class="row">
					<ul>
<?php

$key_valor = 0;

$sql = mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && cat_id = '1' ".$dados_cidade_flt." ORDER BY valor ASC");

while ($dados_planos = mysqli_fetch_object($sql)) {

$key_valor++;

$dados_categoria = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM planos_categorias WHERE del = 'N' && id = '".$dados_planos->cat_id."'"));

$url_list = $urlsite . "/" . $dados_cidade['url'] . "/assine/". $pagina ."/" . $dados_planos->url . "";

if (isset($dados_categoria->intro)) { 

	$dados_categoria_obs = "<span class=\"pln-obs\">". nl2br($dados_categoria->intro) ."</span>";
 
} else {
	
	$dados_categoria_obs = "";
   
}

if ($dados_planos->download == true) { 

	$dados_titulo = "<a href=\"".$url_list."\" class=\"pln-li-tag\">FIBRA ÓPTICA</a><a href=\"".$url_list."\" class=\"pln-li-mega\">" . $dados_planos->download . " MB</a>";
	$dados_vnt_download = "<a href=\"".$url_list."\" class=\"pln-li-vnt pln-li-vnt-borda\">Download até " . $dados_planos->download . " Mbps</a>";
 
} else {
	
	$dados_titulo = "";
	$dados_vnt_download = "";
   
}

if ($dados_planos->titulo == true) { 

	$dados_li_titulo = "<a href=\"".$url_list."\" class=\"pln-li-titulo\">" . $dados_planos->titulo . "</a>";
 
} else {
	
	$dados_li_titulo = "";
   
}

if ($dados_planos->valor <> 0.00) {

	$dados_valor = "<a href=\"".$url_list."\" class=\"pln-li-apenas\">A PARTIR DE</a><a href=\"".$url_list."\" class=\"pln-li-valor\"><strong>R$ ". substr($dados_planos->valor, 0, -3) ."". substr(number_format($dados_planos->valor, 2, ',', '.'), -3) ."</strong>/mês</a><a href=\"".$url_list."\" class=\"pln-li-assine\">Assine já</a><a href=\"".$url_list."\" class=\"pln-li-obs\">Consulte valores e condições.</a>";

} else {
	
	$dados_valor = "";
   
}
										
if ($dados_planos->vnt_11 == true) {

	$dados_vnt_11 = "<a href=\"".$url_list."\"><img src=\"".$urlsite."/images/planos-app-li-5.jpg\" /></a>";
   
} else {
	
	$dados_vnt_11 = "";
   
}
										
if ($dados_planos->vnt_10 == true) {

	$dados_vnt_10 = "<a href=\"".$url_list."\"><img src=\"".$urlsite."/images/planos-app-li-4.jpg\" /></a>";
   
} else {
	
	$dados_vnt_10 = "";
   
}

if ($dados_planos->vnt_9 == true) {

	$dados_vnt_9 = "<a href=\"".$url_list."\"><img src=\"".$urlsite."/images/planos-app-li-3.jpg\" /></a>";
   
} else {
	
	$dados_vnt_9 = "";
  
}

if ($dados_planos->vnt_8 == true) {

	$dados_vnt_8 = "<a href=\"".$url_list."\"><img src=\"".$urlsite."/images/planos-app-li-2.jpg\" /></a>";
   
} else {
	
	$dados_vnt_8 = "";
   
}

if ($dados_planos->vnt_7 == true) {

	$dados_vnt_7 = "<a href=\"".$url_list."\"><img src=\"".$urlsite."/images/planos-app-li-1.jpg\" /></a>";
  
} else {
	
	$dados_vnt_7 = "";
  
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
	$dados_vnt_3_css = "";
   
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

?>
                    	<li>
<?php
$itens = [
    $dados_titulo ?? null,
    $dados_vnt_download ?? null,
    $dados_vnt_1 ?? null,
    $dados_vnt_2 ?? null,
    $dados_vnt_3 ?? null,
    $dados_vnt_4 ?? null,
    $dados_vnt_5 ?? null,
    $dados_vnt_6 ?? null
];

// remove null, false, "", 0, "0"
$itens_validos = array_filter($itens, function($v){
    return isset($v) && trim((string)$v) !== '';
});

if (!empty($itens_validos)) {
?>
    <div class="row">
        <?= implode('', $itens_validos) ?>
    </div>
<?php } ?>
<?php
$apps = array_filter([
    $dados_vnt_7,
    $dados_vnt_8,
    $dados_vnt_9,
    $dados_vnt_10,
    $dados_vnt_11
], function($v){
    return !empty($v) && $v !== 'N' && $v !== false;
});

if (!empty($apps)) {
?>
    <div class="pln-li-app-img">
        <a href="<?= $url_list ?>" class="pln-li-app-titulo">Apps inclusos</a>
        <?= implode('', $apps); ?>
    </div>
<?php } ?><?php if($dados_valor == true) { ?>
			            	<div class="row">
								<?php echo $dados_valor ?>
                            </div>
<?php } ?>
                        </li>
<?php } ?>

                    </ul>
                </div>
            	<div class="row">
                	<?php echo $dados_categoria_obs ?>
                </div>
			</div>
		</header>
	</section>

<?php } ?>
<?php endif; ?>