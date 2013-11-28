<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/test.avi');
printf("ffmpeg getPixelFormat(): %s\n", $mov->getPixelFormat());
?>
