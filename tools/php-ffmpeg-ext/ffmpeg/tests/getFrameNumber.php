<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/test.avi');

/* move frame point to frame 5 */
$mov->getFrame(5);
printf("ffmpeg getFrameNumber(): %d\n", $mov->getFrameNumber());
?>
