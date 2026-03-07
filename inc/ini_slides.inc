<?php if($dados_rows_slides > 0) { ?>
<?php if ($detect->isMobile()) : ?>
	<section id="ini-slides">
		<header id="wrap">
			<main class="main-content">
				<section class="slideshow">
					<div class="slideshow-inner">
						<div class="slides">
<?php
                    
	$sql_slides = mysqli_query($conexao,"SELECT * FROM slides WHERE del = 'N' ORDER BY RAND() LIMIT 3");
	$sql_slides_tr = mysqli_num_rows($sql_slides);

	$key_valor = 0;

	while ($dados_slides = mysqli_fetch_object($sql_slides)) {
                    
	$key_valor++;

	$url_list = $urlsite . "/" . $cidade . "/assine/";
                    
	if ($dados_slides->foto == true && file_exists("images/".$dados_slides->foto."")) { 
                    
		$sld_dados_foto = $urlsite."/63596/1920x824/".$dados_slides->foto."";
                    
	} else {
                    
		$sld_dados_foto = $urlsite."/62956/1920x824/slide.jpg";
                    
	}
                    
	if ($key_valor == 1) { 
	
	   $dados_key_valor = " is-active";
	   
	} else {
		
	   $dados_key_valor = "";
	   
	}

?>
							<div class="slide<?php echo $dados_key_valor ?>">
                            
								<div class="slide-content">
									<div class="container caption">
                                        <a href="<?php echo $url_list ?>" style="display:block;height:600px;"></a>
                                    </div>
								</div>

								<div class="image-container"> 
									<img src="<?php echo $sld_dados_foto ?>" alt="<?php echo $tsite ?>" class="image" />
								</div>
							</div>
<?php } ?>
						</div>
<?php if($sql_slides_tr > 1) { ?>
                        <div class="pagination">
<?php
                    
	$sql_slides = mysqli_query($conexao,"SELECT * FROM slides WHERE del = 'N' ORDER BY RAND() LIMIT 3");
	$sql_slides_tr = mysqli_num_rows($sql_slides);

	$key_valor = 0;

	while ($dados_slides = mysqli_fetch_object($sql_slides)) {
                    
	$key_valor++;
                    
	if ($key_valor == 1) { 
	
	   $dados_key_valor = " is-active";
	   
	} else {
		
	   $dados_key_valor = "";
	   
	}

?>
							<div class="item<?php echo $dados_key_valor ?>"> 
                            	<span class="icon"><?php echo $key_valor ?></span>
                            </div>
<?php } ?>
                        </div>
                        
                        <div class="arrows">
                        	<div class="arrow prev">
                        		<span class="svg svg-arrow-left">
                        		<svg version="1.1" id="svg4-Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="14px" height="26px" viewBox="0 0 14 26" enable-background="new 0 0 14 26" xml:space="preserve"> <path d="M13,26c-0.256,0-0.512-0.098-0.707-0.293l-12-12c-0.391-0.391-0.391-1.023,0-1.414l12-12c0.391-0.391,1.023-0.391,1.414,0s0.391,1.023,0,1.414L2.414,13l11.293,11.293c0.391,0.391,0.391,1.023,0,1.414C13.512,25.902,13.256,26,13,26z"/> </svg>
                        		<span class="alt sr-only"></span>
                        		</span>
                        	</div>
                        	<div class="arrow next">
                        		<span class="svg svg-arrow-right">
                        		<svg version="1.1" id="svg5-Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="14px" height="26px" viewBox="0 0 14 26" enable-background="new 0 0 14 26" xml:space="preserve"> <path d="M1,0c0.256,0,0.512,0.098,0.707,0.293l12,12c0.391,0.391,0.391,1.023,0,1.414l-12,12c-0.391,0.391-1.023,0.391-1.414,0s-0.391-1.023,0-1.414L11.586,13L0.293,1.707c-0.391-0.391-0.391-1.023,0-1.414C0.488,0.098,0.744,0,1,0z"/> </svg>
                        		<span class="alt sr-only"></span>
                        		</span>
                        	</div>
                        </div>
<?php } ?>
					</div> 
				</section>
			</main>
		</header>
	</section>
<?php else : ?>
	<section id="ini-slides">
		<header id="wrap">
			<main class="main-content">
				<section class="slideshow">
					<div class="slideshow-inner">
						<div class="slides">

<?php
                    
	$sql_slides = mysqli_query($conexao,"SELECT * FROM slides WHERE del = 'N' ".$dados_cidade_flt." ORDER BY RAND() LIMIT 3");
	$sql_slides_tr = mysqli_num_rows($sql_slides);

	$key_valor = 0;

	while ($dados_slides = mysqli_fetch_object($sql_slides)) {
                    
	$key_valor++;

	$url_list = $urlsite . "/" . $cidade . "/assine/";
                    
	if ($dados_slides->foto == true && file_exists("images/".$dados_slides->foto."")) { 
                    
		$sld_dados_foto = $urlsite."/63596/1920x824/".$dados_slides->foto."";
                    
	} else {
                    
		$sld_dados_foto = $urlsite."/62956/1920x824/slide.jpg";
                    
	}
                    
	if ($key_valor == 1) { 
	
	   $dados_key_valor = " is-active";
	   
	} else {
		
	   $dados_key_valor = "";
	   
	}

?>
							<div class="slide<?php echo $dados_key_valor ?>">
                            
								<div class="slide-content">
									<div class="container caption">
                                        <a href="<?php echo $url_list ?>" style="display:block;height:600px;"></a>
                                    </div>
								</div>

								<div class="image-container"> 
									<img src="<?php echo $sld_dados_foto ?>" alt="<?php echo $tsite ?>" class="image" />
								</div>
							</div>
<?php } ?>
						</div>
<?php if($sql_slides_tr > 1) { ?>
                        <div class="pagination">
<?php
                    
	$sql_slides = mysqli_query($conexao,"SELECT * FROM slides WHERE del = 'N' ".$dados_cidade_flt." ORDER BY RAND() LIMIT 3");
	$sql_slides_tr = mysqli_num_rows($sql_slides);

	$key_valor = 0;

	while ($dados_slides = mysqli_fetch_object($sql_slides)) {
                    
	$key_valor++;
                    
	if ($key_valor == 1) { 
	
	   $dados_key_valor = " is-active";
	   
	} else {
		
	   $dados_key_valor = "";
	   
	}

?>
							<div class="item<?php echo $dados_key_valor ?>"> 
                            	<span class="icon"><?php echo $key_valor ?></span>
                            </div>
<?php } ?>
                        </div>
                        
                        <div class="arrows">
                        	<div class="arrow prev">
                        		<span class="svg svg-arrow-left">
                        		<svg version="1.1" id="svg4-Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="14px" height="26px" viewBox="0 0 14 26" enable-background="new 0 0 14 26" xml:space="preserve"> <path d="M13,26c-0.256,0-0.512-0.098-0.707-0.293l-12-12c-0.391-0.391-0.391-1.023,0-1.414l12-12c0.391-0.391,1.023-0.391,1.414,0s0.391,1.023,0,1.414L2.414,13l11.293,11.293c0.391,0.391,0.391,1.023,0,1.414C13.512,25.902,13.256,26,13,26z"/> </svg>
                        		<span class="alt sr-only"></span>
                        		</span>
                        	</div>
                        	<div class="arrow next">
                        		<span class="svg svg-arrow-right">
                        		<svg version="1.1" id="svg5-Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="14px" height="26px" viewBox="0 0 14 26" enable-background="new 0 0 14 26" xml:space="preserve"> <path d="M1,0c0.256,0,0.512,0.098,0.707,0.293l12,12c0.391,0.391,0.391,1.023,0,1.414l-12,12c-0.391,0.391-1.023,0.391-1.414,0s-0.391-1.023,0-1.414L11.586,13L0.293,1.707c-0.391-0.391-0.391-1.023,0-1.414C0.488,0.098,0.744,0,1,0z"/> </svg>
                        		<span class="alt sr-only"></span>
                        		</span>
                        	</div>
                        </div>
<?php } ?>
					</div> 
				</section>
			</main>
		</header>
	</section>
<?php endif; ?>
<?php } ?>