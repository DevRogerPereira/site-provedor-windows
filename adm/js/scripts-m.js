function gotopo(){ $('html, body').animate({scrollTop: $("#header.headerTopo").offset().top-18}, 1000); }

function scrollToDiv(div){ $('#nav ul li a').removeClass('act');  $('#nav ul li a.opC'+div).addClass('act'); $('html, body').animate({scrollTop: $("#"+div).offset().top-0}, 1000); }

window.onscroll = scrollAnimation;

function scrollAnimation(){

	if(window.pageYOffset > 400){ $('#topoAll').addClass('scroll'); $('.btTopo').addClass('scroll');  } else { $('#topoAll').removeClass('scroll'); $('.btTopo').removeClass('scroll'); }

}
