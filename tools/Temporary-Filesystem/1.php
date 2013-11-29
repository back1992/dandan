<?php
ini_set('display_errors', '1');
require 'vendor/autoload.php';
use Neutron\TemporaryFilesystem\TemporaryFilesystem;

$fs = TemporaryFilesystem::create();
$tempDir = $fs->createTemporaryDirectory($mode = 0755);

$fs->createTemporaryFile();

// return an empty temporary files with a "thumb-"
// prefix, '.dcm' as suffix and 'jpg' as extension
// $tf = $fs->createTemporaryFile('thumb-', '.dcm', 'jpg');
// $tf = $fs->createTemporaryFiles(5);



// return an array of 5 path to empty temporary files with a "thumb-"
// prefix, '.dcm' as suffix and 'jpg' as extension
// $tf = $fs->createTemporaryFiles(20, 'thumb-', '.dcm', 'jpg');
// $tf = $fs->createEmptyFile(getcwd());
$tf = $fs->createEmptyFile('~/back1992/tmp', 'original.', '.raw', 'CR2');

var_dump($tf);
?>