<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/test.avi');
printf("ffmpeg getVideoCodec(): %s\n", $mov->getVideoCodec());
?>
