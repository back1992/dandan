/*
  +----------------------------------------------------------------------+
  | PHP Version 4                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2003 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.02 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available at through the world-wide-web at                           |
  | http://www.php.net/license/2_02.txt.                                 |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+

  $Id: header,v 1.10.8.1 2003/07/14 15:59:18 sniper Exp $ 
*/

#ifndef PHP_FFMPEG_H
#define PHP_FFMPEG_H

#ifndef INIT_FUNC_ARGS
#include "zend_modules.h"
#endif

extern zend_module_entry ffmpeg_module_entry;
#define phpext_ffmpeg_ptr &ffmpeg_module_entry

#ifdef PHP_WIN32
#define PHP_FFMPEG_API __declspec(dllexport)
#else
#define PHP_FFMPEG_API
#endif
//#define ZTS
//#undef ZTS
#ifdef ZTS
#include "TSRM.h"
#endif

#include "include/gd.h"
#include "include/gd_io.h"


PHP_MINIT_FUNCTION(ffmpeg);
PHP_MSHUTDOWN_FUNCTION(ffmpeg);
PHP_RINIT_FUNCTION(ffmpeg);
PHP_RSHUTDOWN_FUNCTION(ffmpeg);
PHP_MINFO_FUNCTION(ffmpeg);

PHP_FUNCTION(confirm_ffmpeg_compiled);	/* For testing, remove later. */

#include "ffmpeg_frame.h"
#include "ffmpeg_movie.h"

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(ffmpeg)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(ffmpeg)
*/

/* In every utility function you add that needs to use variables 
   in php_ffmpeg_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as FFMPEG_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define FFMPEG_G(v) TSRMG(ffmpeg_globals_id, zend_ffmpeg_globals *, v)
#else
#define FFMPEG_G(v) (ffmpeg_globals.v)
#endif

#endif	/* PHP_FFMPEG_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
