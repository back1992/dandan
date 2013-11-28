<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/test.avi');
printf("ffmpeg getFrameRate(): %0.2f\n", $mov->getFrameRate());
?>
