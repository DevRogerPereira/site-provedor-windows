<?php

// Invalida o Full Page Cache do site publico (cache/*.html gerado pelo index.php).
// Chamado automaticamente apos qualquer gravacao feita pelo painel adm — assim
// toda alteracao entra em vigor na hora, sem esperar o TTL de 10 minutos.
function limparCacheSite() {

	$cache_dir = dirname(__DIR__, 2) . '/cache/';

	$arquivos = @glob($cache_dir . '*.html');
	if (!is_array($arquivos)) {
		return 0;
	}

	$apagados = 0;
	foreach ($arquivos as $arquivo) {
		if (@unlink($arquivo)) {
			$apagados++;
		}
	}

	return $apagados;
}

?>
