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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <assert.h>
#include <avcodec.h>
#include <avformat.h>
//#include <inttypes.h>
#include <math.h>

#include "php.h"
#include "php_ini.h"
#include "php_globals.h"
#include "ext/standard/info.h"
#include "php_ffmpeg.h"

/* If you declare any globals in php_ffmpeg.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(ffmpeg)
*/

/* True global resources - no need for thread safety here */
static int le_ffmpeg;

/* {{{ ffmpeg_functions[]
 *
 * Every user visible function must have an entry in ffmpeg_functions[].
 */
function_entry ffmpeg_functions[] = {
	PHP_FE(confirm_ffmpeg_compiled,	NULL)		/* For testing, remove later. */
	{NULL, NULL, NULL}	/* Must be the last line in ffmpeg_functions[] */
};
/* }}} */

/* {{{ ffmpeg_module_entry
 */
zend_module_entry ffmpeg_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"ffmpeg",
	ffmpeg_functions,
	//NULL;
	PHP_MINIT(ffmpeg),
	PHP_MSHUTDOWN(ffmpeg),
	PHP_RINIT(ffmpeg),		/* Replace with NULL if there's nothing to do at request start */
	//NULL;
	PHP_RSHUTDOWN(ffmpeg),	/* Replace with NULL if there's nothing to do at request end */
	//NULL;
	PHP_MINFO(ffmpeg),
#if ZEND_MODULE_API_NO >= 20010901
	"0.4.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_FFMPEG
ZEND_GET_MODULE(ffmpeg)
#endif

extern void register_ffmpeg_movie_class(int);
//extern void register_ffmpeg_output_movie_class(int);
extern void register_ffmpeg_frame_class(int);

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("ffmpeg.global_value",      "42", PHP_INI_ALL, OnUpdateInt, global_value, zend_ffmpeg_globals, ffmpeg_globals)
    STD_PHP_INI_ENTRY("ffmpeg.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_ffmpeg_globals, ffmpeg_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_ffmpeg_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_ffmpeg_init_globals(zend_ffmpeg_globals *ffmpeg_globals)
{
	ffmpeg_globals->global_value = 0;
	ffmpeg_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(ffmpeg)
{
	/* If you have INI entries, uncomment these lines 
	ZEND_INIT_MODULE_GLOBALS(ffmpeg, php_ffmpeg_init_globals, NULL);
	REGISTER_INI_ENTRIES();
	*/
    /* must be called before using avcodec libraries. */ 
    avcodec_init();

    /* register all codecs */
    av_register_all();

    register_ffmpeg_movie_class(module_number);
    //register_ffmpeg_output_movie_class(module_number);
    register_ffmpeg_frame_class(module_number);

    REGISTER_LONG_CONSTANT("LIBAVCODEC_VERSION_NUMBER", avcodec_version(), CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("LIBAVCODEC_BUILD_NUMBER", avcodec_build(), CONST_CS | CONST_PERSISTENT);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(ffmpeg)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	av_free_static();
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(ffmpeg)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(ffmpeg)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(ffmpeg)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "ffmpeg support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_ffmpeg_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_ffmpeg_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char string[256];

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = sprintf(string, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "ffmpeg", arg);
	RETURN_STRINGL(string, len, 1);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
