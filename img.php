<?php
/*
 * Crop-to-fit PHP-GD
 * http://salman-w.blogspot.com/2009/04/crop-to-fit-image-using-aspphp.html
 *
 * Resize and center crop an arbitrary size image to fixed width and height
 * e.g. convert a large portrait/landscape image to a small square thumbnail
 */

define('DESIRED_IMAGE_WIDTH', $_GET['w']);
define('DESIRED_IMAGE_HEIGHT', $_GET['h']);

$source_path = $_GET['img'];
/*
 * Add file validation code here
 */

// ==== INÍCIO CACHE SYSTEM ====
$cache_dir = 'images/cache/';
if (!file_exists($cache_dir)) {
    @mkdir($cache_dir, 0777, true);
}

// Criar um nome único e seguro para a imagem cache baseada no arquivo e nas dimensões
$md5_filename = md5($source_path) . '_' . DESIRED_IMAGE_WIDTH . 'x' . DESIRED_IMAGE_HEIGHT . '.jpg';
$cache_path = $cache_dir . $md5_filename;

// Se o cache já existe, servimos direto e paramos o processamento aqui!
if (file_exists($cache_path)) {
    header('Content-Type: image/jpeg');
    header('Cache-Control: public, max-age=31536000'); // 1 ano cache de brower tb
    readfile($cache_path);
    exit;
}
// ==== FIM CACHE SYSTEM VERIFICATION ====

if(!file_exists($source_path)) {
	die("Image not found");
}

list($source_width, $source_height, $source_type) = getimagesize($source_path);

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

// ==== SALVA NO CACHE FÍSICO ====
imagejpeg($desired_gdim, $cache_path, 92);

// Exibe a imagem salva
header('Content-Type: image/jpeg');
header('Cache-Control: public, max-age=31536000');
readfile($cache_path);

/*
 * Add clean-up code here
 */
if(isset($source_gdim) && $source_gdim) { @imagedestroy($source_gdim); unset($source_gdim); }
if(isset($temp_gdim) && $temp_gdim) { @imagedestroy($temp_gdim); unset($temp_gdim); }
if(isset($desired_gdim) && $desired_gdim) { @imagedestroy($desired_gdim); unset($desired_gdim); }
?>