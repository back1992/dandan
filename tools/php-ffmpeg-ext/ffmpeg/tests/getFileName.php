<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/test.avi');
printf("ffmpeg getFileName(): %s\n", $mov->getFileName());
?>
