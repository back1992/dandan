<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/robot.avi');
printf("ffmpeg getAudioCodec(): %s\n", $mov->getAudioCodec());
?>
