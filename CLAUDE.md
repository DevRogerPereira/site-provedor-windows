# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Site institucional de provedor de internet hospedado em **Windows IIS na Locaweb**. PHP procedural puro (sem framework), MySQL via MySQLi, jQuery no frontend. O site suporta múltiplas cidades/localidades e tem um painel administrativo completo.

## Deployment

Push para `main` dispara deploy automático via GitHub Actions (FTP para `web/` no servidor). Após o FTP, o workflow chama `reset.php` para limpar OPcache/APCu.

Secrets necessários no GitHub: `HOST`, `USER`, `PASS`.

## Architecture

### Dual Entry Points
- **Site público**: `index.php` → inclui `adm/conexao.php` (DB + sessão) → `inc/funcoes.php` (routing + lógica) → monta página com 3 includes (`$include_cabecalho`, `$include_centro`, `$include_rodape`)
- **Admin**: `adm/index.php` → `adm/conexao.php` → `adm/inc/funcoes.php` (extrai GET params, define defaults) → `adm/inc/funcoes_seguranca.php` (auth + routing via switch) → monta mesma estrutura de 3 includes

### URL Routing
Routing duplicado em `.htaccess` (Apache/Helicon) e `web.config` (IIS nativo). Ambos devem ser mantidos em sincronia.

- **Site público**: `/{cidade}/{pagina}/{url}/{id}` → `index.php?cidade=...&pagina=...&url=...&id=...`
- **Admin**: `/adm/{pagina}/{url}/{id}` → `adm/index.php?pagina=...&url=...&id=...`
- **Imagens dinâmicas**: `/{hash}/{largura}x{altura}/{caminho}` → `img.php?w=...&h=...&img=...`

### Two Separate Databases
- **Site/Admin principal**: `linknet_2026` em `linknet_2026.mysql.dbaas.com.br` (conexão em `adm/conexao.php`)
- **Autenticação admin**: `dribletelecom2` em `dribletelecom2.mysql.dbaas.com.br` (conexão em `adm/inc/inicial_seguranca.php`)

### Caching Layers
1. **Full-page HTML cache** (`cache/`): chave = MD5(URL + device type), TTL 10 min. Implementado no `index.php` público.
2. **Image cache** (`images/cache/`): imagens redimensionadas por `img.php`, cache 1 ano no browser.
3. **OPcache/APCu**: limpos via `reset.php` no deploy.

### Mobile vs Desktop
Device detection via `Mobile_Detect.php` (`libs/`). CSS separados (`modulos.css` / `modulos-m.css`). Templates `.inc` renderizam condicionalmente com `$disp_detect == "PC"` ou `"MV"`. Cache de página é separado por device.

## Windows IIS Constraints

Este servidor **não pode ser migrado**. Otimizações específicas:

- `session_save_path(__DIR__ . '/sess')` — isola sessões do diretório compartilhado lento da Locaweb
- `session.gc_probability = 0` — evita cold-start de 60s por garbage collection do IIS
- `gethostbyname($server)` antes de `new mysqli()` — resolve DNS para IPv4, evitando tentativa IPv6 que adiciona +1s de latência
- `max_execution_time = 30` e `memory_limit = 128M` em `.user.ini`
- Compressão zlib ativa (nível 6)

## Key Files

| Arquivo | Papel |
|---------|-------|
| `adm/conexao.php` | Sessão, conexão DB principal, carrega `tb_config` |
| `inc/funcoes.php` | Routing público, queries de planos/cidades/blog, funções utilitárias |
| `adm/inc/funcoes_seguranca.php` | Auth check + routing admin (switch por `$pagina`) |
| `adm/inc/inicial_seguranca.php` | `validaUsuario()`, `protegePagina()`, `expulsaVisitante()` |
| `adm/inc/funcoes.php` | Extrai `$pagina`/`$ht_url`/`$id` de GET, define página padrão, utilitários admin |
| `.user.ini` | Config PHP (errors off, zlib on, limites) |

## Conventions

- Páginas são arquivos `.inc` dentro de `inc/` (público) ou `adm/inc/` (admin)
- Nomes de página admin seguem padrão: `{feature}.inc` (listagem), `{feature}_add.inc` (formulário)
- Variáveis de routing: `$pagina`, `$ht_url`, `$id`, `$cidade`
- Queries usam MySQLi procedural com `addslashes()` para sanitização
- Credenciais DB estão hardcoded nos arquivos PHP (não usa `.env`)
- Imagens de upload admin vão para `adm/img/` (ignorado pelo git)
- Sessões admin em `adm/sess/` (ignorado pelo git, criado automaticamente)
