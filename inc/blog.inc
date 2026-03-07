        <section class="section-blog">
            <div class="section-header">
                <div class="container">
                    <h1 class="title">Avisos</h1>
                </div>
            </div>

            <div class="section-content">
                <div class="container">
                    <div class="box-blog-menu">
                        <ul>
                            <li<?php echo $css_pg_format ?>>
                                <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>">Tudo</a>
                            </li>
<?php

$sql_blog_categorias = mysqli_query($conexao,"SELECT * FROM blog WHERE del = 'N' GROUP BY cat_id_1");

while ($dados_blog_categorias = mysqli_fetch_object($sql_blog_categorias)) {

if($dados_blog_categorias->cat_id_1 == true) {

	$dados_blog_categorias = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM blog_categorias WHERE del = 'N' && id = '". $dados_blog_categorias->cat_id_1 ."'"));
	$dados_nome = $dados_blog_categorias->nome;

} else {

	$dados_nome = "";

}

if($dados_blog_categorias->url == $url) {

	$css_format = " class=\"active\"";

} else {

	$css_format = "";

}

?>
                                <li<?php echo $css_format ?>>
                                    <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" . $dados_blog_categorias->url . "/" ?>"><?php echo $dados_nome ?></a>
                                </li>
<?php } ?>
                        </ul>
                    </div>

                    <div id="accordion-blog" class="box-accordion-blog">
<?php

$sql_blog = mysqli_query($conexao,"SELECT * FROM blog WHERE del = 'N' && status = 'S' ". $dados_flt ." ORDER BY data_ini DESC");

while ($dados_blog = mysqli_fetch_object($sql_blog)) {

if($dados_blog->data_ini <> "0000-00-00 00:00:00") {

	$dados_data_ini = date('d/m/Y', strtotime($dados_blog->data_ini)) . " às " . date('H:i', strtotime($dados_blog->data_ini));

} else {

	$dados_data_ini = "";

}

if($dados_blog->cat_id_1 == true) {

	$dados_cat_id_1 = $dados_blog->cat_id_1;

} else {

	$dados_cat_id_1 = "";

}

if($dados_blog->tag == true) {

	$dados_tag = "<h5 class=\"category\">". $dados_blog->tag ."</h5>";

} else {

	$dados_tag = "";

}

if($dados_blog->titulo == true) {

	$dados_titulo = "<span>". $dados_blog->titulo. "</span>";

} else {

	$dados_titulo = "";

}

if($dados_blog->detalhes == true) {

	$dados_detalhes = nl2br($dados_blog->detalhes);

} else {

	$dados_detalhes = "";

}

if($dados_blog->foto == true && file_exists("images/". $dados_blog->foto ."")) {

	list($width, $height) = getimagesize("images/". $dados_blog->foto ."");

	$newWidth = 600;
	$x = ($newWidth*$height)/$width;
	$x1 = number_format($x, 0, '.', '');
	$url_ft = md5(uniqid(time()));

	$dados_foto = "<img src=\"".$urlsite."/".$url_ft."/600x".$x1."/". $dados_blog->foto ."\">";

} else {

	$dados_foto = "";

}

?>
                            <div class="card">
                                <div class="card-header">
                                    <?php echo $dados_tag ?>
                                    <h2 class="title" data-toggle="collapse" data-target="#collapese-blog-<?php echo $dados_blog->id ?>">
                                        <?php echo $dados_titulo ?>
                                    </h2>
                                    <p class="date"><?php echo $dados_data_ini ?></p>

                                    <button type="button" class="button" data-toggle="collapse" data-target="#collapese-blog-<?php echo $dados_blog->id ?>">Ver mais</button>
                                </div>

                                <div id="collapese-blog-<?php echo $dados_blog->id ?>" class="collapse" data-parent="#accordion-blog">
                                    <div class="card-body">
<?php if($tmp == true) { ?>
                                        <div class="content-header">
                                            <p><strong>Serviço afetado:</strong> Internet</p>
                                            <p><strong>Motivo:</strong> Manutenção</p>
                                        </div>
<?php } ?>
                                        <figure>
                                            <?php echo $dados_foto ?>
                                        </figure>

                                        <div class="box-text">
                                            <p><?php echo $dados_detalhes ?></p>
                                        </div>
                                    </div>
                                </div>
                            </div>
<?php } ?>
                    </div>

                    <div class="box-blog-list">
                        <h2 class="box-blog-title">Blog e avisos</h2>

                        <div class="box-blog-menu -center">
                            <ul>
                                <li<?php echo $css_pg_format ?>>
                                    <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>">Tudo</a>
                                </li>
<?php

$sql_blog_categorias = mysqli_query($conexao,"SELECT * FROM blog WHERE del = 'N' GROUP BY cat_id_1");

while ($dados_blog_categorias = mysqli_fetch_object($sql_blog_categorias)) {

if($dados_blog_categorias->cat_id_1 == true) {

	$dados_blog_categorias = mysqli_fetch_object(mysqli_query($conexao,"SELECT * FROM blog_categorias WHERE del = 'N' && id = '". $dados_blog_categorias->cat_id_1 ."'"));
	$dados_nome = $dados_blog_categorias->nome;

} else {

	$dados_nome = "";

}

if($dados_blog_categorias->url == $url) {

	$css_format = " class=\"active\"";

} else {

	$css_format = "";

}

?>
                                <li<?php echo $css_format ?>>
                                    <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" . $dados_blog_categorias->url . "/" ?>"><?php echo $dados_nome ?></a>
                                </li>
<?php } ?>
                            </ul>
                        </div>

                        <div class="items">
                            <div class="row">
<?php

$sql_blog = mysqli_query($conexao,"SELECT * FROM blog WHERE del = 'N' && status = 'S' ORDER BY data_ini DESC");

while ($dados_blog = mysqli_fetch_object($sql_blog)) {

if($dados_blog->data_ini <> "0000-00-00 00:00:00") {

	$dados_data_ini = date('d/m/Y', strtotime($dados_blog->data_ini)) . " às " . date('H:i', strtotime($dados_blog->data_ini));

} else {

	$dados_data_ini = "";

}

if($dados_blog->tag == true) {

	$dados_tag = "<h5 class=\"category\">". $dados_blog->tag ."</h5>";

} else {

	$dados_tag = "";

}

if($dados_blog->titulo == true) {

	$dados_titulo = $dados_blog->titulo;

} else {

	$dados_titulo = "";

}

?>
                                    <div class="item col-lg-4">
                                        <div class="card">
                                            <div class="card-header">
                                                <?php echo $dados_tag ?>
                                                <h2 class="title">
                                                    <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>"><?php echo $dados_titulo ?></a>
                                                </h2>

                                                <p class="date"><?php echo $dados_data_ini ?></p>

                                                <a href="<?php echo $urlsite . "/" . $cidade . "/blog/" ?>" class="button">Ver mais</a>
                                            </div>
                                        </div>
                                    </div>
<?php } ?>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </section>

<?php include("inc/pg_assine.inc") ?>