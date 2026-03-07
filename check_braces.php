<?php
$file = 'inc/funcoes.php';
$code = file_get_contents($file);
$tokens = token_get_all($code);
$out = "";
$stack = [];
$line = 1;
foreach ($tokens as $token) {
    if (is_array($token)) {
        $line = $token[2];
        if ($token[0] == T_CURLY_OPEN || $token[1] == '{') {
            $stack[] = $line;
            $out .= "OPEN at $line (depth " . count($stack) . ")\n";
        } else if ($token[1] == '}') {
            array_pop($stack);
            $out .= "CLOSE at $line (depth " . count($stack) . ")\n";
        }
    } else {
        if ($token == '{') {
            $stack[] = $line;
            $out .= "OPEN at $line (depth " . count($stack) . ")\n";
        } else if ($token == '}') {
            array_pop($stack);
            $out .= "CLOSE at $line (depth " . count($stack) . ")\n";
        }
    }
}
file_put_contents('tokens_log.txt', $out);
echo "Log generated.";
?>
