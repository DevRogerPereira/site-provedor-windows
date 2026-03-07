<?php if($dados_rows_plano_3 > 0) { ?>
	<section id="ini-planos">
		<header id="wrap">
			<div class="container">
            	<div class="row">
                    <a class="pln-tag">Conheça nossos</a>
                    <a class="pln-titulo">planos <strong>cabo residenciais</strong></a>
                </div>
            	<div class="row">

					<ul>
<?php

$sql = mysqli_query($conexao,"SELECT * FROM planos WHERE del = 'N' && cat_id = '3' ".$dados_cidade_flt." ORDER BY valor ASC");

while ($dados_planos = mysqli_fetch_object($sql)) {

$dados_categoria = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM planos_categorias WHERE del = 'N' && id = '".$dados_planos->cat_id."'"));

$url_list = $urlsite . "/" . $dados_cidade['url'] . "/assine/". $pagina ."/" . $dados_planos->url . "";

if (isset($dados_categoria->intro)) { 

	$dados_categoria_obs = "<span class=\"pln-obs\">". nl2br($dados_categoria->intro) ."</span>";
 
} else {
	
	$dados_categoria_obs = "";
   
}

if ($dados_planos->download == true) { 

	$dados_titulo = "<a href=\"".$url_list."\" class=\"pln-li-num\">" . $dados_planos->download . "</a><a href=\"".$url_list."\" class=\"pln-li-mega\">MEGA</a><a href=\"".$url_list."\" class=\"pln-li-tag\"><strong>Ultra</strong> Cabo</a>";
	$dados_titulo_alt = $dados_planos->download;
                                 
 
} else {
	
	$dados_titulo = "";
	$dados_titulo_alt = "Plano - " . $tsite;
   
}

if ($dados_planos->valor <> 0.00) {

	$dados_valor = "<a href=\"".$url_list."\" class=\"pln-li-apenas\">Por apenas</a><a href=\"".$url_list."\" class=\"pln-li-valor\"><strong>R$ ". substr($dados_planos->valor, 0, -3) ."". substr(number_format($dados_planos->valor, 2, ',', '.'), -3) ."</strong>/mês</a><a href=\"".$url_list."\" class=\"pln-li-assine\">Eu quero!</a>";
	$dados_valor_assine = "S";

} else {
	
	$dados_valor = "";
	$dados_valor_assine = "";
   
}
										
if ($dados_planos->vnt_1 == true) {

	$dados_vnt_1 = "<a href=\"".$url_list."\" class=\"pln-li-vnt\">".$dados_planos->vnt_1 ."</a>";
   
} else {
	
	$dados_vnt_1 = "";
   
}

if ($dados_planos->vnt_2 == true) {

	$dados_vnt_2 = "<a href=\"".$url_list."\" class=\"pln-li-vnt\">".$dados_planos->vnt_2 ."</a>";
   
} else {
	
	$dados_vnt_2 = "";
   
}

if ($dados_planos->vnt_3 == true) {

	$dados_vnt_3 = "<a href=\"".$url_list."\" class=\"pln-li-vnt\">".$dados_planos->vnt_3 ."</a>";
   
} else {
	
	$dados_vnt_3 = "";
   
}

if ($dados_planos->vnt_7 == true) {

	$dados_vnt_7 = "<a href=\"".$url_list."\" class=\"pln-li-serv-icone\"><img src=\"".$urlsite."/images/planos-li-srv-noggin.jpg\" /></a>";
   
} else {
	
	$dados_vnt_7 = "";
   
}

if ($dados_planos->vnt_8 == true) {

	$dados_vnt_8 = "<a href=\"".$url_list."\" class=\"pln-li-serv-icone\"><img src=\"".$urlsite."/images/planos-li-srv-nordesde-fc.jpg\" /></a>";
   
} else {
	
	$dados_vnt_8 = "";
   
}

if ($dados_planos->vnt_9 == true) {

	$dados_vnt_9 = "<a href=\"".$url_list."\" class=\"pln-li-serv-icone\"><img src=\"".$urlsite."/images/planos-li-srv-paramount.jpg\" /></a>";
   
} else {
	
	$dados_vnt_9 = "";
   
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
<?php if($dados_titulo == true) { ?>
                            <div class="pln-ul-num">
                                <?php echo $dados_titulo ?>
                            </div>
<?php } ?>
<?php if($dados_vnt_7 == true || $dados_vnt_8 == true || $dados_vnt_9 == true) { ?>
                            <div class="pln-ul-serv">
                                <a href="<?php echo $url_list ?>" class="pln-li-serv">Serviços inclusos</a>
								<?php echo $dados_vnt_7 . $dados_vnt_8 . $dados_vnt_9 ?>
                            </div>
<?php } ?>
                            <div class="pln-ul-vnt">
<?php if($dados_vnt_1 == true || $dados_vnt_2 == true || $dados_vnt_3 == true) { ?>
								<?php echo $dados_vnt_1 . $dados_vnt_2 . $dados_vnt_3 ?>
                                <hr>
<?php } ?>
                                <?php echo $dados_valor ?>
                            </div>
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