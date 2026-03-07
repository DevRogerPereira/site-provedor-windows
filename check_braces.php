<?php
$file = 'inc/funcoes.php';
$code = file_get_contents($file);
$tokens = token_get_all($code);
$stack = [];
$line = 1;

foreach ($tokens as $token) {
    if (is_array($token)) {
        $line = $token[2];
        if ($token[0] == T_CURLY_OPEN || $token[1] == '{') {
            $stack[] = "line $line";
        } else if ($token[1] == '}') {
            array_pop($stack);
        }
    } else {
        if ($token == '{') {
            $stack[] = "line $line"; 
        } else if ($token == '}') {
            array_pop($stack);
        }
    }
}
if (!empty($stack)) {
    echo "Unclosed braces opened at: " . implode(", ", $stack) . "\n";
} else {
    echo "No unclosed braces!\n";
}
?>
