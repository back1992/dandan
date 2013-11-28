<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/test.avi');
printf("ffmpeg getFrameHeight(): %d\n", $mov->getFrameHeight());
?>
