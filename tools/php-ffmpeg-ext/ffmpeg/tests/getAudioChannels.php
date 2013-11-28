<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/robot.avi');
printf("ffmpeg getAudioChannels(): %s\n", $mov->getAudioChannels());
?>
