<?php if($disp_detect == "PC") {?>
	<meta charset="utf-8" />
    <title><?php echo $dados_seo_title_format ?></title>

	<meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name='robots' content='index, follow'>
    <meta name='googlebot' content='index, follow'>

    <link rel="shortcut icon" href="<?php echo $urlsite. "/favicon.ico"; ?>" type="image/png"/>
    <link rel="apple-touch-icon" href="<?php echo $urlsite. "/favicon.ico"; ?>" type="image/png"/>
    <link rel="alternate" type="application/rss+xml" title="vipnet" href="<?php echo $urlsite ?>/feed.xml">

    <link rel="canonical" href="<?php echo $urlsite ?>" />
    
	<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
    
	<style><?php include('css/reset.css'); ?></style>
    <style><?php include('css/text.min.css'); ?></style>
    <style><?php include('css/grid_12_1040'.$entrar_css.'.css'); ?></style>
    <style><?php include('css/modulos.css'); ?></style>
<?php } ?>
<?php if($disp_detect == "MV") {?>
	<meta charset="utf-8" />
    <title><?php echo $dados_seo_title_format ?></title>

	<meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name='robots' content='index, follow'>
    <meta name='googlebot' content='index, follow'>

	<meta name="description" content="<?php echo $dados_seo_description_format ?>"/>
    <meta name="keywords" content=""/>
    <link rel="shortcut icon" href="<?php echo $urlsite. "/".$url_seo_ft."/favicon/16x16/favicon.png"; ?>" type="image/png"/>
    <link rel="apple-touch-icon" href="<?php echo $urlsite. "/".$url_seo_ft."/favicon/76x76/favicon.png"; ?>" type="image/png"/>
    <link rel="alternate" type="application/rss+xml" title="" href="<?php echo $urlsite ?>/feed.xml">

    <link rel="canonical" href="<?php echo $urlsite ?>" />
    
	<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
<?php } ?>