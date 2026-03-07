<?php if($disp_detect == "PC") {?>
	<section id="pf_rv_centro">
		<header id="wrap">
			<div class="container">
            	<div class="col grid-3">
<?php include("menu.inc")?>
                </div>
            	<div class="col grid-9">
<?php echo "resumo"; //include("lt_equipamentos.inc") ?>
<?php if($user_nivel == "3") {?>
<?php } else { ?>
<?php } ?>
                </div>
			</div>
		</header>
	</section>
<?php } ?>
<?php if($disp_detect == "MV") { ?>
<?php } ?>