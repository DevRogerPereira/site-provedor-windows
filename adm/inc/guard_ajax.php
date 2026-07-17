<?php
// Guard de autenticacao para os endpoints AJAX/form do painel (adm/js/cadastro/**).
// Esses .php sao servidos direto pelo FastCGI (nao passam pelo adm/index.php),
// entao SEM este guard qualquer visitante anonimo podia:
//   - abrir 1 conexao ao banco por chamada (estourando o limite de 30 da Locaweb);
//   - inserir/editar/excluir dados (INSERT/UPDATE/DELETE) sem estar logado.
// Este guard roda ANTES de incluir conexao.php: se nao houver sessao logada,
// devolve 403 e sai — nenhuma conexao ao banco chega a ser aberta.
//
// Usa exatamente o mesmo store de sessao do painel (adm/sess) e a mesma blindagem
// de cold-start do IIS, senao nao enxergaria o login e bloquearia admins legitimos.

if (session_status() == PHP_SESSION_NONE) {
    ini_set('session.gc_probability', 0);
    $sess_path = dirname(__DIR__) . '/sess'; // == adm/sess
    if (!is_dir($sess_path)) {
        @mkdir($sess_path, 0700, true);
    }
    session_save_path($sess_path);
    session_start();
}

if (!isset($_SESSION['usuarioID'])) {
    header('HTTP/1.1 403 Forbidden');
    exit('Forbidden');
}
