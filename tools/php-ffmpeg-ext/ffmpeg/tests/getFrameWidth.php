<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/test.avi');
printf("ffmpeg getFrameWidth(): %d\n", $mov->getFrameWidth());
?>
