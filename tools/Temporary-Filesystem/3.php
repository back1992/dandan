<?php
$tmpfname = tempnam("/back1992/tmp", "FOO");

$handle = fopen($tmpfname, "w");
fwrite($handle, "writing to tempfile");
fclose($handle);

var_dump($tmpfname);
// do here something

// unlink($tmpfname);
?>