<?php
ini_set('display_errors', '1');

function _image_imagemagick_exec($command) {
  $descriptors = array(
    0 => array('pipe', 'r'), // stdin
    1 => array('pipe', 'w'), // stdout
    2 => array('pipe', 'w')  // stderr
  );
  if ($h = proc_open($command, $descriptors, $pipes)) {
    $output = fgets($pipes[1]);
    $errors = fgets($pipes[2]);
    fclose($pipes[0]);
    fclose($pipes[1]);
    fclose($pipes[2]);
    return proc_close($h);
  }
  return FALSE;
}
 
  $flag=_image_imagemagick_exec('convert -resize 418x106 2.jpg ');
  echo $flag;
?>