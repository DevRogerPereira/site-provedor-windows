<?php
/*
 * Crop-to-fit PHP-GD
 * http://salman-w.blogspot.com/2009/04/crop-to-fit-image-using-aspphp.html
 *
 * Resize and center crop an arbitrary size image to fixed width and height
 * e.g. convert a large portrait/landscape image to a small square thumbnail
 */

define('DESIRED_IMAGE_WIDTH', (int) $_GET['w']);
define('DESIRED_IMAGE_HEIGHT', (int) $_GET['h']);

$source_path = $_GET['img'];

// Só processa imagens locais (evita ler caminhos arbitrarios / remotos)
if (!is_string($source_path) || preg_match('#^[a-z]+://#i', $source_path) || strpos($source_path, "\0") !== false) {
    header("HTTP/1.1 400 Bad Request");
    exit;
}

// ==== CACHE EM DISCO: serve direto se ja foi gerada, sem reprocessar GD ====
$cache_dir = __DIR__ . '/img/cache/';
if (!is_dir($cache_dir)) { @mkdir($cache_dir, 0777, true); }
$cache_path = $cache_dir . md5($source_path) . '_' . DESIRED_IMAGE_WIDTH . 'x' . DESIRED_IMAGE_HEIGHT . '.jpg';
if (is_file($cache_path)) {
    header('Content-Type: image/jpeg');
    header('Cache-Control: public, max-age=31536000');
    readfile($cache_path);
    exit;
}

if (!is_file($source_path)) {
    header("HTTP/1.1 404 Not Found");
    exit;
}

list($source_width, $source_height, $source_type) = getimagesize($source_path);
if (!$source_width || !$source_height) {
    header("HTTP/1.1 404 Not Found");
    exit;
}

switch ($source_type) {
    case IMAGETYPE_GIF:
        $source_gdim = imagecreatefromgif($source_path);
        break;
    case IMAGETYPE_JPEG:
        $source_gdim = imagecreatefromjpeg($source_path);
        break;
    case IMAGETYPE_PNG:
        $source_gdim = imagecreatefrompng($source_path);
        break;
}

$source_aspect_ratio = $source_width / $source_height;
$desired_aspect_ratio = DESIRED_IMAGE_WIDTH / DESIRED_IMAGE_HEIGHT;

if ($source_aspect_ratio > $desired_aspect_ratio) {
    /*
     * Triggered when source image is wider
     */
    $temp_height = DESIRED_IMAGE_HEIGHT;
    $temp_width = ( int ) (DESIRED_IMAGE_HEIGHT * $source_aspect_ratio);
} else {
    /*
     * Triggered otherwise (i.e. source image is similar or taller)
     */
    $temp_width = DESIRED_IMAGE_WIDTH;
    $temp_height = ( int ) (DESIRED_IMAGE_WIDTH / $source_aspect_ratio);
}

/*
 * Resize the image into a temporary GD image
 */

$temp_gdim = imagecreatetruecolor($temp_width, $temp_height);
imagecopyresampled(
    $temp_gdim,
    $source_gdim,
    0, 0,
    0, 0,
    $temp_width, $temp_height,
    $source_width, $source_height
);

/*
 * Copy cropped region from temporary image into the desired GD image
 */

$x0 = ($temp_width - DESIRED_IMAGE_WIDTH) / 2;
$y0 = ($temp_height - DESIRED_IMAGE_HEIGHT) / 2;
$desired_gdim = imagecreatetruecolor(DESIRED_IMAGE_WIDTH, DESIRED_IMAGE_HEIGHT);
imagecopy(
    $desired_gdim,
    $temp_gdim,
    0, 0,
    $x0, $y0,
    DESIRED_IMAGE_WIDTH, DESIRED_IMAGE_HEIGHT
);

/*
 * Render the image
 * Alternatively, you can save the image in file-system or database
 */

// Salva no cache de disco e serve (proximas requisicoes nao reprocessam GD)
imagejpeg($desired_gdim, $cache_path, 84);
header('Content-type: image/jpeg');
header('Cache-Control: public, max-age=31536000');
readfile($cache_path);

/*
 * Add clean-up code here
 */
if (isset($source_gdim) && $source_gdim) { @imagedestroy($source_gdim); }
if (isset($temp_gdim) && $temp_gdim) { @imagedestroy($temp_gdim); }
if (isset($desired_gdim) && $desired_gdim) { @imagedestroy($desired_gdim); }
?>