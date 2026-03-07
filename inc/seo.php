<?php if ($detect->isMobile()) : ?>
	<meta charset="utf-8" />
    <title><?php echo $dados_seo_title_format ?></title>

	<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
	<meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="robots" content="index, follow">
    <meta name="googlebot" content="index, follow">
	<meta http-equiv="Cache-control" content="public">
    <meta http-equiv="Cache-control" content="private">
    <meta http-equiv="Cache-control" content="no-cache">
    <meta http-equiv="Cache-control" content="no-store">
	<meta name="description" content="<?php echo $dados_seo_description_format ?>"/>
    <meta name="keywords" content="provedor internet fibra"/>
    <link rel="shortcut icon" href="<?php echo $urlsite . "/favicon.ico" ?>" type="image/png"/>
    <link rel="apple-touch-icon" href="<?php echo $urlsite . "/favicon.ico" ?>" type="image/png"/>
    <link rel="alternate" type="application/rss+xml" title="<?php echo $dados_seo_title_format ?>" href="<?php echo $urlsite ?>/feed.xml">

    <link rel="canonical" href="<?php echo $urlsite ?>" />
	<meta property="og:locale" content="pt_BR" />
	<meta property="og:type" content="article" />
    
    <meta property="og:title" content="<?php echo $dados_seo_og_title ?>" />
    <meta property="og:description" content="<?php echo $dados_seo_description_format ?>" />
	<meta property="og:url" content="<?php echo $urlsite_full ?>" />
	<meta property="og:site_name" content="<?php echo $dados_seo_og_title ?>" />
	<meta property="article:publisher" content="https://www.facebook.com/<?php echo $social_facebook ?>" />
	<meta property="article:section" content="Geral" />
    <meta property="article:published_time" content="<?php echo $feed_data_pg ?>" />
    <meta property="article:modified_time" content="<?php echo $feed_data_pg ?>" />
    <meta property="og:updated_time" content="<?php echo $feed_data_pg ?>" />

	<meta itemprop="image" content="<?php echo $feed_foto_social ?>" />
	<meta property="og:image" content="<?php echo $feed_foto_social ?>" />
    <meta property="og:image:width" content="800">
    <meta property="og:image:height" content="511">

    <link rel="apple-touch-icon" sizes="57x57" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="apple-touch-icon" sizes="60x60" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="apple-touch-icon" sizes="72x72" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="apple-touch-icon" sizes="76x76" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="apple-touch-icon" sizes="114x114" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="apple-touch-icon" sizes="120x120" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="apple-touch-icon" sizes="144x144" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="apple-touch-icon" sizes="152x152" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="apple-touch-icon" sizes="180x180" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="icon" type="image/png" sizes="192x192"  href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="icon" type="image/png" sizes="32x32" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="icon" type="image/png" sizes="96x96" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="icon" type="image/png" sizes="16x16" href="<?php echo $urlsite . "/favicon.ico" ?>">
    <link rel="manifest" href="/manifest.json">
    <meta name="msapplication-TileImage" content="<?php echo $urlsite . "/favicon.ico" ?>">
    <meta name="msapplication-TileColor" content="#ffffff">
    <meta name="theme-color" content="#ffffff">
    <meta name="msapplication-navbutton-color" content="#ffffff">
    <meta name="apple-mobile-web-app-status-bar-style" content="#ffffff">
	<style><?php include("css/modulos-m.css"); ?></style>
<?php else : ?>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="format-detection" content="telephone=no">
    <title><?php echo $dados_seo_title_format ?></title>
	<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <meta http-equiv="Content-type" content="text/html; charset=utf-8" />
	<meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="robots" content="index, follow">
    <meta name="googlebot" content="index, follow">
	<meta http-equiv="Cache-control" content="public">
    <meta http-equiv="Cache-control" content="private">
    <meta http-equiv="Cache-control" content="no-cache">
    <meta http-equiv="Cache-control" content="no-store">
    <base href="<?php echo $urlsite ?>" />
	<meta name="description" content="<?php echo $dados_seo_description_format ?>"/>
    <meta name="keywords" content="provedor internet fibra"/>
    <link rel="canonical" href="<?php echo $urlsite ?>" />
    <meta http-equiv="content-language" content="pt-br" />
    <meta http-equiv="cache-control" content="no-cache, no-store, max-age=0, s-maxage=0, must-revalidate, proxy-revalidate" />
    <meta name="author" content="<?php echo $dados_seo_title_format ?>" />
    <meta name="generator" content="<?php echo $dados_seo_title_format ?>" />
    <meta name="copyright" content="2020, <?php echo $urlsite ?>/" />
    <link id="page_favicon" href="<?php echo $urlsite . "/favicon.ico" ?>" rel="icon" type="image/x-icon" />
    <link rel="shortcut icon" href="<?php echo $urlsite . "/favicon.ico" ?>" type="image/png"/>
    <link rel="apple-touch-icon" href="<?php echo $urlsite . "/favicon.ico" ?>" type="image/png"/>
    <link rel="alternate" type="application/rss+xml" title="<?php echo $urlsite ?>" href="<?php echo $urlsite ?>/feed.xml">

    <meta property="og:title" content="<?php echo $dados_seo_og_title ?>" />
    <meta property="og:description" content="<?php echo $dados_seo_description_format ?>" />
	<meta property="og:url" content="<?php //echo PegaUrl($url_full) ?>" />
	<meta itemprop="image" content="<?php echo $feed_foto_social ?>" />
	<meta property="og:image" content="<?php echo $feed_foto_social ?>" />
    <meta property="og:image:type" content="image/jpeg">
    <meta property="og:image:width" content="800">
    <meta property="og:image:height" content="511">
    <meta property="og:type" content="website" />
    <meta property="og:site_name" content="<?php echo $dados_seo_og_title ?>" />
	<meta property="article:publisher" content="https://www.facebook.com/<?php echo $social_facebook ?>" />
	<meta property="article:section" content="Geral" />
    <meta property="article:published_time" content="<?php echo $feed_data_pg ?>" />
    <meta property="article:modified_time" content="<?php echo $feed_data_pg ?>" />
    <meta property="og:updated_time" content="<?php echo $feed_data_pg ?>" />
    <link rel="icon" href="<?php echo $urlsite ?>/favicon.ico" type="image/x-icon">
    
	<style><?php include("css/modulos.css"); ?></style>
    
<?php endif; ?>
<?php if(isset($pixel_head)) { echo $pixel_head; } ?>