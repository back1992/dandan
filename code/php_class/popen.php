<?php
error_reporting(E_ALL);

/* 加入重定向以得到标准错误输出 stderr。 */
$handle = popen('/bin/ls 2>&1', 'r');
echo "'$handle'; " . gettype($handle) . "\n";
$read = fread($handle, 2096);
echo $read;
pclose($handle);
?>