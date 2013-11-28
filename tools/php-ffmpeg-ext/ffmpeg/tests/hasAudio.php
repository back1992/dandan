<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/test.avi');
printf("ffmpeg hasAudio(): %s\n", $mov->hasAudio() ? 'Yes' : 'No');
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/robot.avi');
printf("ffmpeg hasAudio(): %s\n", $mov->hasAudio() ? 'Yes' : 'No');
?>
