<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/test.avi');
printf("ffmpeg getBitRate(): %s\n", $mov->getBitRate());
?>
