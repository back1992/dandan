--TEST--
ffmpeg get key frames test 
--SKIPIF--
<?php 
extension_loaded('ffmpeg') or die("skip ffmpeg extension not loaded"); 
extension_loaded('gd') or die("skip gd extension not avaliable.");
function_exists("imagecreatetruecolor") or die("skip function imagecreatetruecolor unavailable");
?>
--FILE--
<?php
$mov = new ffmpeg_movie(dirname(__FILE__) . '/test_media/robot.avi');
$img = dirname(__FILE__) . '/test-';

while (($frame = $mov->getNextKeyFrame()) != false) {
    $i = $mov->getFrameNumber();
    $filename = $img . $i . '.png';
    $gd_image = $frame->toGDImage();
    imagepng($gd_image, $filename);
    printf("ffmpeg getFrame($i): md5 = %s\n", md5(file_get_contents($filename)));
    imagedestroy($gd_image);
    unlink($filename);
}
?>
--EXPECT--
ffmpeg getFrame(1): md5 = abdf9f281de68cef4b77a5a7a899b60a
ffmpeg getFrame(2): md5 = abdf9f281de68cef4b77a5a7a899b60a
ffmpeg getFrame(3): md5 = abdf9f281de68cef4b77a5a7a899b60a
ffmpeg getFrame(4): md5 = 9770f3afe55297ea35c9f06a0e4334ea
ffmpeg getFrame(5): md5 = 9770f3afe55297ea35c9f06a0e4334ea
ffmpeg getFrame(6): md5 = 9770f3afe55297ea35c9f06a0e4334ea
ffmpeg getFrame(7): md5 = 157cf8c54851ee90bda8b2398b077c28
ffmpeg getFrame(8): md5 = 157cf8c54851ee90bda8b2398b077c28
ffmpeg getFrame(9): md5 = 157cf8c54851ee90bda8b2398b077c28
ffmpeg getFrame(10): md5 = 966a1fb1d649d8fdc6552ce6fa0e735f
ffmpeg getFrame(11): md5 = 966a1fb1d649d8fdc6552ce6fa0e735f
ffmpeg getFrame(12): md5 = 966a1fb1d649d8fdc6552ce6fa0e735f
ffmpeg getFrame(13): md5 = 5415f831017e32afa73e5ceb32344f4d
ffmpeg getFrame(14): md5 = 5415f831017e32afa73e5ceb32344f4d
ffmpeg getFrame(15): md5 = 5415f831017e32afa73e5ceb32344f4d
ffmpeg getFrame(16): md5 = 337873cd3a4b8529dae4da4aac38874c
ffmpeg getFrame(17): md5 = 337873cd3a4b8529dae4da4aac38874c
ffmpeg getFrame(18): md5 = 337873cd3a4b8529dae4da4aac38874c
ffmpeg getFrame(19): md5 = 3411d97fd52b27b7105a4cf91a7b181e
ffmpeg getFrame(20): md5 = 3411d97fd52b27b7105a4cf91a7b181e
ffmpeg getFrame(21): md5 = 3411d97fd52b27b7105a4cf91a7b181e
ffmpeg getFrame(22): md5 = 74c553e7c88fd2479610cd2093d75717
ffmpeg getFrame(23): md5 = 74c553e7c88fd2479610cd2093d75717
ffmpeg getFrame(24): md5 = 74c553e7c88fd2479610cd2093d75717
ffmpeg getFrame(25): md5 = c9ec47e51edb4a58c1c76a2202d7147f
ffmpeg getFrame(26): md5 = c9ec47e51edb4a58c1c76a2202d7147f
ffmpeg getFrame(27): md5 = c9ec47e51edb4a58c1c76a2202d7147f
ffmpeg getFrame(28): md5 = 0f54b4e8a9e3cbbc6c5e1729f4793b2f
ffmpeg getFrame(29): md5 = 0f54b4e8a9e3cbbc6c5e1729f4793b2f
ffmpeg getFrame(30): md5 = 0f54b4e8a9e3cbbc6c5e1729f4793b2f
ffmpeg getFrame(31): md5 = 30f0dff87230a9f3b1ebdc08b40aa0a7
ffmpeg getFrame(32): md5 = 30f0dff87230a9f3b1ebdc08b40aa0a7
ffmpeg getFrame(33): md5 = 30f0dff87230a9f3b1ebdc08b40aa0a7
ffmpeg getFrame(34): md5 = f614e07399921150044dfdaf880afa17
ffmpeg getFrame(35): md5 = f614e07399921150044dfdaf880afa17
ffmpeg getFrame(36): md5 = f614e07399921150044dfdaf880afa17
ffmpeg getFrame(37): md5 = ae68f48c14a76e4dc2f9c7f2183c7787
ffmpeg getFrame(38): md5 = ae68f48c14a76e4dc2f9c7f2183c7787
ffmpeg getFrame(39): md5 = ae68f48c14a76e4dc2f9c7f2183c7787
ffmpeg getFrame(40): md5 = b8ae52b0bd25ff1ccddfffd61c2aee5a
ffmpeg getFrame(41): md5 = b8ae52b0bd25ff1ccddfffd61c2aee5a
ffmpeg getFrame(42): md5 = b8ae52b0bd25ff1ccddfffd61c2aee5a
ffmpeg getFrame(43): md5 = 1560e32dc970140780155a3b9b8a5458
ffmpeg getFrame(44): md5 = 1560e32dc970140780155a3b9b8a5458
ffmpeg getFrame(45): md5 = 1560e32dc970140780155a3b9b8a5458
ffmpeg getFrame(46): md5 = 9d6241b89b0320d045c81564ae392df1
ffmpeg getFrame(47): md5 = 9d6241b89b0320d045c81564ae392df1
ffmpeg getFrame(48): md5 = 9d6241b89b0320d045c81564ae392df1
ffmpeg getFrame(49): md5 = ac35fe74cc8150970d6b8d6b6615ee7d
ffmpeg getFrame(50): md5 = ac35fe74cc8150970d6b8d6b6615ee7d
ffmpeg getFrame(51): md5 = ac35fe74cc8150970d6b8d6b6615ee7d
ffmpeg getFrame(52): md5 = e256491e34893b935d9a3839536d2587
ffmpeg getFrame(53): md5 = e256491e34893b935d9a3839536d2587
ffmpeg getFrame(54): md5 = e256491e34893b935d9a3839536d2587
ffmpeg getFrame(55): md5 = 1c72b33fd6f829b293a83acd9dd6ba3e
ffmpeg getFrame(56): md5 = 1c72b33fd6f829b293a83acd9dd6ba3e
ffmpeg getFrame(57): md5 = 1c72b33fd6f829b293a83acd9dd6ba3e
ffmpeg getFrame(58): md5 = 954c1013975c1fc29ab8bbaf9208069a
ffmpeg getFrame(59): md5 = 954c1013975c1fc29ab8bbaf9208069a
ffmpeg getFrame(60): md5 = 954c1013975c1fc29ab8bbaf9208069a
ffmpeg getFrame(61): md5 = 86d1330ec92bb2c672db8cfacef7c128
ffmpeg getFrame(62): md5 = 86d1330ec92bb2c672db8cfacef7c128
ffmpeg getFrame(63): md5 = 86d1330ec92bb2c672db8cfacef7c128
ffmpeg getFrame(64): md5 = 3b8248dcafbc02ecab8f5a3065e61f03
ffmpeg getFrame(65): md5 = 3b8248dcafbc02ecab8f5a3065e61f03
ffmpeg getFrame(66): md5 = 3b8248dcafbc02ecab8f5a3065e61f03
ffmpeg getFrame(67): md5 = db77eae1c1395ba1c794ae1281d68868
ffmpeg getFrame(68): md5 = db77eae1c1395ba1c794ae1281d68868
ffmpeg getFrame(69): md5 = db77eae1c1395ba1c794ae1281d68868
ffmpeg getFrame(70): md5 = afe384b15e07ea544fa7a1cdada288c0
ffmpeg getFrame(71): md5 = afe384b15e07ea544fa7a1cdada288c0
ffmpeg getFrame(72): md5 = afe384b15e07ea544fa7a1cdada288c0
ffmpeg getFrame(73): md5 = 8c9cbc1183504e1d1fee262e83775e01
ffmpeg getFrame(74): md5 = 8c9cbc1183504e1d1fee262e83775e01
ffmpeg getFrame(75): md5 = 8c9cbc1183504e1d1fee262e83775e01
ffmpeg getFrame(76): md5 = d502f1afe81ec69de3222d3b56b3d516
ffmpeg getFrame(77): md5 = d502f1afe81ec69de3222d3b56b3d516
ffmpeg getFrame(78): md5 = d502f1afe81ec69de3222d3b56b3d516
ffmpeg getFrame(79): md5 = 8004f62b065a0d55150220972821be96
ffmpeg getFrame(80): md5 = 8004f62b065a0d55150220972821be96
ffmpeg getFrame(81): md5 = 8004f62b065a0d55150220972821be96
ffmpeg getFrame(82): md5 = 92ecabfab41f2715a05f3847e2484b60
ffmpeg getFrame(83): md5 = 92ecabfab41f2715a05f3847e2484b60
ffmpeg getFrame(84): md5 = 92ecabfab41f2715a05f3847e2484b60
ffmpeg getFrame(85): md5 = ceafeaf93812d8f5fd48f6fa242d5e36
ffmpeg getFrame(86): md5 = ceafeaf93812d8f5fd48f6fa242d5e36
ffmpeg getFrame(87): md5 = ceafeaf93812d8f5fd48f6fa242d5e36
ffmpeg getFrame(88): md5 = 41b5423e725b29fdacc5ee40faa4776c
ffmpeg getFrame(89): md5 = 41b5423e725b29fdacc5ee40faa4776c
ffmpeg getFrame(90): md5 = 41b5423e725b29fdacc5ee40faa4776c
ffmpeg getFrame(91): md5 = afa2f0bab3ba2b34806b2a52aea98bce
ffmpeg getFrame(92): md5 = afa2f0bab3ba2b34806b2a52aea98bce
ffmpeg getFrame(93): md5 = afa2f0bab3ba2b34806b2a52aea98bce
ffmpeg getFrame(94): md5 = c8ed36df36fb8cea156212a5d5952d33
ffmpeg getFrame(95): md5 = c8ed36df36fb8cea156212a5d5952d33
ffmpeg getFrame(96): md5 = c8ed36df36fb8cea156212a5d5952d33
ffmpeg getFrame(97): md5 = c97ea8a480b98c52f8b726b811f9714d
ffmpeg getFrame(98): md5 = c97ea8a480b98c52f8b726b811f9714d
ffmpeg getFrame(99): md5 = c97ea8a480b98c52f8b726b811f9714d
ffmpeg getFrame(100): md5 = a98e967bbda4b6dcaa19fd52d9fdef12
ffmpeg getFrame(101): md5 = a98e967bbda4b6dcaa19fd52d9fdef12
ffmpeg getFrame(102): md5 = a98e967bbda4b6dcaa19fd52d9fdef12
ffmpeg getFrame(103): md5 = 395b50b5c8615cdb4b905aa0b3b2e669
ffmpeg getFrame(104): md5 = 395b50b5c8615cdb4b905aa0b3b2e669
ffmpeg getFrame(105): md5 = 395b50b5c8615cdb4b905aa0b3b2e669
ffmpeg getFrame(106): md5 = 86f50526473282524be5c092f77950a5
ffmpeg getFrame(107): md5 = 86f50526473282524be5c092f77950a5
ffmpeg getFrame(108): md5 = 86f50526473282524be5c092f77950a5
ffmpeg getFrame(109): md5 = 9e5e0b70bfc1c90f2c5092428bc384ee
ffmpeg getFrame(110): md5 = 9e5e0b70bfc1c90f2c5092428bc384ee
ffmpeg getFrame(111): md5 = 9e5e0b70bfc1c90f2c5092428bc384ee
ffmpeg getFrame(112): md5 = 5f9109436658f422ec1841247acf835e
ffmpeg getFrame(113): md5 = 5f9109436658f422ec1841247acf835e
ffmpeg getFrame(114): md5 = 5f9109436658f422ec1841247acf835e
ffmpeg getFrame(115): md5 = 80e13931ccc6ace3a5a7ae256e048a61
ffmpeg getFrame(116): md5 = 80e13931ccc6ace3a5a7ae256e048a61
ffmpeg getFrame(117): md5 = 80e13931ccc6ace3a5a7ae256e048a61
ffmpeg getFrame(118): md5 = 21f287b5f3334a7aaed0aeeb55230621
ffmpeg getFrame(119): md5 = 21f287b5f3334a7aaed0aeeb55230621
ffmpeg getFrame(120): md5 = 21f287b5f3334a7aaed0aeeb55230621
ffmpeg getFrame(121): md5 = 22caa03aaa35e0aed2f0a3d4a3375b24
ffmpeg getFrame(122): md5 = 22caa03aaa35e0aed2f0a3d4a3375b24
ffmpeg getFrame(123): md5 = 22caa03aaa35e0aed2f0a3d4a3375b24
ffmpeg getFrame(124): md5 = 36cbf250ecf8c5a5538bd0a5f2eb9333
ffmpeg getFrame(125): md5 = 36cbf250ecf8c5a5538bd0a5f2eb9333
ffmpeg getFrame(126): md5 = 36cbf250ecf8c5a5538bd0a5f2eb9333
ffmpeg getFrame(127): md5 = ffdc385768b0b1fcbb9908c9c9bffe21
ffmpeg getFrame(128): md5 = ffdc385768b0b1fcbb9908c9c9bffe21
ffmpeg getFrame(129): md5 = ffdc385768b0b1fcbb9908c9c9bffe21
ffmpeg getFrame(130): md5 = 3ead3c1a402a7e26ee248cd8f9c96647
ffmpeg getFrame(131): md5 = 3ead3c1a402a7e26ee248cd8f9c96647
ffmpeg getFrame(132): md5 = 3ead3c1a402a7e26ee248cd8f9c96647
ffmpeg getFrame(133): md5 = 3445a37f0effaef1a9c4e788f5ce54e5
ffmpeg getFrame(134): md5 = 3445a37f0effaef1a9c4e788f5ce54e5
ffmpeg getFrame(135): md5 = 3445a37f0effaef1a9c4e788f5ce54e5
ffmpeg getFrame(136): md5 = 948fd5fd379679006c2ca2ba3bc52048
ffmpeg getFrame(137): md5 = 948fd5fd379679006c2ca2ba3bc52048
ffmpeg getFrame(138): md5 = 948fd5fd379679006c2ca2ba3bc52048
ffmpeg getFrame(139): md5 = 814b8a64a6a08093b3a81063bffffed4
ffmpeg getFrame(140): md5 = 814b8a64a6a08093b3a81063bffffed4
ffmpeg getFrame(141): md5 = 814b8a64a6a08093b3a81063bffffed4
ffmpeg getFrame(142): md5 = 51a73cbaf315c9faf8263627455fd5d5
ffmpeg getFrame(143): md5 = 51a73cbaf315c9faf8263627455fd5d5
ffmpeg getFrame(144): md5 = 51a73cbaf315c9faf8263627455fd5d5
ffmpeg getFrame(145): md5 = 31038504cc4c1e664de89c257b1fa1b0
ffmpeg getFrame(146): md5 = 31038504cc4c1e664de89c257b1fa1b0
ffmpeg getFrame(147): md5 = 31038504cc4c1e664de89c257b1fa1b0
ffmpeg getFrame(148): md5 = c76afdadc9099d8bd173f0e08807ee3d
ffmpeg getFrame(149): md5 = c76afdadc9099d8bd173f0e08807ee3d
ffmpeg getFrame(150): md5 = c76afdadc9099d8bd173f0e08807ee3d
ffmpeg getFrame(151): md5 = cd42cff504053e23c5db378119a40b3f
ffmpeg getFrame(152): md5 = cd42cff504053e23c5db378119a40b3f
ffmpeg getFrame(153): md5 = cd42cff504053e23c5db378119a40b3f
ffmpeg getFrame(154): md5 = 7862bd022cc4e9c3976b2f4758e5cd30
ffmpeg getFrame(155): md5 = 7862bd022cc4e9c3976b2f4758e5cd30
ffmpeg getFrame(156): md5 = 7862bd022cc4e9c3976b2f4758e5cd30
ffmpeg getFrame(157): md5 = 7dee4d143138fce530917488cc337c8c
ffmpeg getFrame(158): md5 = 7dee4d143138fce530917488cc337c8c
ffmpeg getFrame(159): md5 = 7dee4d143138fce530917488cc337c8c
ffmpeg getFrame(160): md5 = 254d01500e3ec7f6ae402747761c0a95
ffmpeg getFrame(161): md5 = 254d01500e3ec7f6ae402747761c0a95
ffmpeg getFrame(162): md5 = 254d01500e3ec7f6ae402747761c0a95
ffmpeg getFrame(163): md5 = fe0cdb9314d1628af56e6c3662deb24f
ffmpeg getFrame(164): md5 = fe0cdb9314d1628af56e6c3662deb24f
ffmpeg getFrame(165): md5 = fe0cdb9314d1628af56e6c3662deb24f
ffmpeg getFrame(166): md5 = c790f8cc0f715ca0ec31845c9ef7397a
ffmpeg getFrame(167): md5 = c790f8cc0f715ca0ec31845c9ef7397a
ffmpeg getFrame(168): md5 = c790f8cc0f715ca0ec31845c9ef7397a
ffmpeg getFrame(169): md5 = bab883284018046ddfa2e638785615aa
ffmpeg getFrame(170): md5 = bab883284018046ddfa2e638785615aa
ffmpeg getFrame(171): md5 = bab883284018046ddfa2e638785615aa
ffmpeg getFrame(172): md5 = a469093f43c0fdd6016ee5ef932b7ca4
ffmpeg getFrame(173): md5 = a469093f43c0fdd6016ee5ef932b7ca4
ffmpeg getFrame(174): md5 = a469093f43c0fdd6016ee5ef932b7ca4
ffmpeg getFrame(175): md5 = 50d636deb9cdca5c88842653d3e62463
ffmpeg getFrame(176): md5 = 50d636deb9cdca5c88842653d3e62463
ffmpeg getFrame(177): md5 = 50d636deb9cdca5c88842653d3e62463
ffmpeg getFrame(178): md5 = 7def27ec8a2136e344b24b12337f3a0c
ffmpeg getFrame(179): md5 = 7def27ec8a2136e344b24b12337f3a0c
ffmpeg getFrame(180): md5 = 7def27ec8a2136e344b24b12337f3a0c
ffmpeg getFrame(181): md5 = 93bdda9b26422cf7791154d54667812e
ffmpeg getFrame(182): md5 = 93bdda9b26422cf7791154d54667812e
ffmpeg getFrame(183): md5 = 93bdda9b26422cf7791154d54667812e
ffmpeg getFrame(184): md5 = 965909c3829a19aa301ff7dc98f1ca90
ffmpeg getFrame(185): md5 = 965909c3829a19aa301ff7dc98f1ca90
ffmpeg getFrame(186): md5 = 965909c3829a19aa301ff7dc98f1ca90
ffmpeg getFrame(187): md5 = a53b0c4d2c023f1019b3190b35216c60
ffmpeg getFrame(188): md5 = a53b0c4d2c023f1019b3190b35216c60
ffmpeg getFrame(189): md5 = a53b0c4d2c023f1019b3190b35216c60
ffmpeg getFrame(190): md5 = b900f912fbe898801a4c8356638dcf54
ffmpeg getFrame(191): md5 = b900f912fbe898801a4c8356638dcf54
ffmpeg getFrame(192): md5 = b900f912fbe898801a4c8356638dcf54
ffmpeg getFrame(193): md5 = 5221475c9ea8970258feb9dab1392049
ffmpeg getFrame(194): md5 = 5221475c9ea8970258feb9dab1392049
ffmpeg getFrame(195): md5 = 5221475c9ea8970258feb9dab1392049
ffmpeg getFrame(196): md5 = 6851e0793856841f31acc6a5f704650c
ffmpeg getFrame(197): md5 = 6851e0793856841f31acc6a5f704650c
ffmpeg getFrame(198): md5 = 6851e0793856841f31acc6a5f704650c
ffmpeg getFrame(199): md5 = 35335bb3cbc1cb75aff8416a26df8f39
ffmpeg getFrame(200): md5 = 35335bb3cbc1cb75aff8416a26df8f39
ffmpeg getFrame(201): md5 = 35335bb3cbc1cb75aff8416a26df8f39
ffmpeg getFrame(202): md5 = c9584d3d2c2480fb480953e9bc317cb0
ffmpeg getFrame(203): md5 = c9584d3d2c2480fb480953e9bc317cb0
ffmpeg getFrame(204): md5 = c9584d3d2c2480fb480953e9bc317cb0
ffmpeg getFrame(205): md5 = 3081db2af3ff5bc76f938f9b80ec72bb
ffmpeg getFrame(206): md5 = 3081db2af3ff5bc76f938f9b80ec72bb
ffmpeg getFrame(207): md5 = 3081db2af3ff5bc76f938f9b80ec72bb
ffmpeg getFrame(208): md5 = 10230400f9cdb8a4785082ed133f4c40
ffmpeg getFrame(209): md5 = 10230400f9cdb8a4785082ed133f4c40
ffmpeg getFrame(210): md5 = 10230400f9cdb8a4785082ed133f4c40
ffmpeg getFrame(211): md5 = ccc8aa4b659a072ef3e94005e982e197
ffmpeg getFrame(212): md5 = ccc8aa4b659a072ef3e94005e982e197
ffmpeg getFrame(213): md5 = ccc8aa4b659a072ef3e94005e982e197
ffmpeg getFrame(214): md5 = 916130d3a9a0b5291dd80c3f905f3cfe
ffmpeg getFrame(215): md5 = 916130d3a9a0b5291dd80c3f905f3cfe
ffmpeg getFrame(216): md5 = 916130d3a9a0b5291dd80c3f905f3cfe
ffmpeg getFrame(217): md5 = c9b92c3b3043cadf83b634aaa9967af2
ffmpeg getFrame(218): md5 = c9b92c3b3043cadf83b634aaa9967af2
ffmpeg getFrame(219): md5 = c9b92c3b3043cadf83b634aaa9967af2
ffmpeg getFrame(220): md5 = d60ad82118cc3d82d61380e8c1c35821
ffmpeg getFrame(221): md5 = d60ad82118cc3d82d61380e8c1c35821
ffmpeg getFrame(222): md5 = d60ad82118cc3d82d61380e8c1c35821
ffmpeg getFrame(223): md5 = bb894534f0fbb93ae13effea4ae7778c
ffmpeg getFrame(224): md5 = bb894534f0fbb93ae13effea4ae7778c
ffmpeg getFrame(225): md5 = bb894534f0fbb93ae13effea4ae7778c
ffmpeg getFrame(226): md5 = 03fe855c91fbaabe9e260a23ca4fa6cd
ffmpeg getFrame(227): md5 = 03fe855c91fbaabe9e260a23ca4fa6cd
ffmpeg getFrame(228): md5 = 03fe855c91fbaabe9e260a23ca4fa6cd
ffmpeg getFrame(229): md5 = 92b0f153f17e6a387535ba873c245ef2
ffmpeg getFrame(230): md5 = 92b0f153f17e6a387535ba873c245ef2
ffmpeg getFrame(231): md5 = 92b0f153f17e6a387535ba873c245ef2
ffmpeg getFrame(232): md5 = f513c73faf87cbfe1fff854d97f8f492
ffmpeg getFrame(233): md5 = f513c73faf87cbfe1fff854d97f8f492
ffmpeg getFrame(234): md5 = f513c73faf87cbfe1fff854d97f8f492
ffmpeg getFrame(235): md5 = 972e660b84a02fb883809c93f1ffdbf8
ffmpeg getFrame(236): md5 = 972e660b84a02fb883809c93f1ffdbf8
ffmpeg getFrame(237): md5 = 972e660b84a02fb883809c93f1ffdbf8
ffmpeg getFrame(238): md5 = 7e80bfd9c95b8f46e4ffcc1acacd478d
ffmpeg getFrame(239): md5 = 7e80bfd9c95b8f46e4ffcc1acacd478d
ffmpeg getFrame(240): md5 = 7e80bfd9c95b8f46e4ffcc1acacd478d
ffmpeg getFrame(241): md5 = c3fca01d3ba84b05c18574615858e613
ffmpeg getFrame(242): md5 = c3fca01d3ba84b05c18574615858e613
