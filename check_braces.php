<?php
$file = 'inc/funcoes.php';
$code = file_get_contents($file);
$tokens = token_get_all($code);
$braces = 0;
$line = 0;
foreach ($tokens as $token) {
    if (is_array($token)) {
        $line = $token[2];
        if ($token[0] == T_CURLY_OPEN || $token[1] == '{') $braces++;
        if ($token[1] == '}') $braces--;
    } else {
        if ($token == '{') $braces++;
        if ($token == '}') $braces--;
    }
    if ($braces < 0) {
        echo "Extra closing brace at line $line\n";
        break;
    }
}
if ($braces > 0) {
    echo "Unclosed brace! Total open: $braces. Last line seen: $line\n";
} elseif ($braces == 0) {
    echo "Braces are balanced according to token_get_all.\n";
}
?>
