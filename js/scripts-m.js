function scrollToDiv(div){ $('#nav ul li a').removeClass('act');  $('#nav ul li a.opC'+div).addClass('act'); $('html, body').animate({scrollTop: $("#"+div).offset().top-60}, 1000); }

var liAnt = '';
function perfil_li(li){ 
			
	$('.prf_li').hide(300);
	$('.tlp span').html('+');
	
	if(li!=liAnt){ 
		
		$('.rli'+li).show(300); 
		$('.tlp.li'+li+' span').html('-');
		
		console.info(li);
		
		liAnt=li; 
	
	} else { 
		
		liAnt=''; 
	
	}
}
