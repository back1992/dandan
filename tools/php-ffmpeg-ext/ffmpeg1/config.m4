dnl $Id$
dnl config.m4 for extension ffmpeg

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(ffmpeg, for ffmpeg support,
dnl Make sure that the comment is aligned:
dnl [  --with-ffmpeg             Include ffmpeg support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(ffmpeg, whether to enable ffmpeg support,
dnl Make sure that the comment is aligned:
dnl [  --enable-ffmpeg           Enable ffmpeg support])

if test "$PHP_FFMPEG" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-ffmpeg -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/ffmpeg.h"  # you most likely want to change this
  dnl if test -r $PHP_FFMPEG/; then # path given as parameter
  dnl   FFMPEG_DIR=$PHP_FFMPEG
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for ffmpeg files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       FFMPEG_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$FFMPEG_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the ffmpeg distribution])
  dnl fi

  dnl # --with-ffmpeg -> add include path
  dnl PHP_ADD_INCLUDE($FFMPEG_DIR/include)

  dnl # --with-ffmpeg -> check for lib and symbol presence
  dnl LIBNAME=ffmpeg # you may want to change this
  dnl LIBSYMBOL=ffmpeg # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $FFMPEG_DIR/lib, FFMPEG_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_FFMPEGLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong ffmpeg lib version or lib not found])
  dnl ],[
  dnl   -L$FFMPEG_DIR/lib -lm -ldl
  dnl ])
  dnl
  dnl PHP_SUBST(FFMPEG_SHARED_LIBADD)

  PHP_NEW_EXTENSION(ffmpeg, ffmpeg.c, $ext_shared)
fi
