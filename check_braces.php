<?php
$file = 'inc/funcoes.php';
$code = file_get_contents($file);
$tokens = token_get_all($code);
$stack = []; // store line numbers of open braces
foreach ($tokens as $token) {
    if (is_array($token)) {
        if ($token[0] == T_CURLY_OPEN || $token[1] == '{') {
            $stack[] = $token[2];
        } else if ($token[1] == '}') {
            array_pop($stack);
        }
    } else {
        if ($token == '{') {
            // Find approximate line number by counting newlines up to this point
            // This is just a rough fallback since single char tokens don't have line numbers in token_get_all
            $stack[] = "unknown"; 
        } else if ($token == '}') {
            array_pop($stack);
        }
    }
}
if (!empty($stack)) {
    echo "Unclosed braces opened at lines: " . implode(", ", $stack) . "\n";
} else {
    echo "No unclosed braces!\n";
}
?>
