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


#define HAVE_LIBGD20
#ifdef HAVE_LIBGD20
#include "include/gd.h" 
#endif // HAVE_LIBGD20

#define RGBA_PIXELSTRIDE 4

static zend_class_entry *ffmpeg_frame_class_entry_ptr;
zend_class_entry ffmpeg_frame_class_entry;
 
static int le_ffmpeg_frame;
static int le_gd;

/* {{{ ffmpeg_frame methods[]
    Methods of the ffmpeg_frame class 
*/
zend_function_entry ffmpeg_frame_class_methods[] = {
   
    /* contructor */
    PHP_FE(ffmpeg_frame, NULL)

    /* methods */
    PHP_FALIAS(getwidth,       getWidth,      NULL)
    PHP_FALIAS(getheight,      getHeight,     NULL)
    PHP_FALIAS(resize,         resize,        NULL)
    PHP_FALIAS(crop,           crop,          NULL)
    PHP_FALIAS(togdimage,      toGDImage,     NULL)

	{NULL, NULL, NULL}
};
/* }}} */


/* {{{ _php_alloc_ff_frame()
 */
static ff_frame_context* _php_alloc_ff_frame()
{
    ff_frame_context *ff_frame = NULL;

    ff_frame = emalloc(sizeof(ff_frame_context));
    
    if (!ff_frame) {
        zend_error(E_ERROR, "Error allocating ffmpeg_frame");
    }

    ff_frame->av_frame = NULL;
    ff_frame->width = 0;
    ff_frame->height = 0;
    ff_frame->pixel_format = 0;

    return ff_frame;
}
/* }}} */


/* {{{ proto object ffmpeg_frame() 
   creates an ffmpeg_frame object, adds a ffmpeg_frame resource to the
   object, registers the resource and returns a direct pointer to the 
   resource.
 */
ff_frame_context* _php_create_ffmpeg_frame(INTERNAL_FUNCTION_PARAMETERS)
{
    int ret;
	ff_frame_context *ff_frame;
    
    ff_frame = _php_alloc_ff_frame();
    
	ret = ZEND_REGISTER_RESOURCE(NULL, ff_frame, le_ffmpeg_frame);
    
    object_init_ex(return_value, ffmpeg_frame_class_entry_ptr);
    add_property_resource(return_value, "ffmpeg_frame", ret);
    return ff_frame;
}
/* }}} */

static void _php_free_av_frame(AVFrame *av_frame)
{
    if (av_frame) {
        if (av_frame->data[0]) {
            av_free(av_frame->data[0]);
            av_frame->data[0] = NULL;
        }
        av_free(av_frame);
    }
}

/* {{{ _php_free_ffmpeg_frame
 */
static void _php_free_ffmpeg_frame(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    ff_frame_context *ff_frame = (ff_frame_context*)rsrc->ptr;    
    _php_free_av_frame(ff_frame->av_frame);
    efree(ff_frame);
}
/* }}} */


void register_ffmpeg_frame_class(int module_number) {
	TSRMLS_FETCH();
    ZEND_GET_RESOURCE_TYPE_ID(le_gd, "gd");

    le_ffmpeg_frame = zend_register_list_destructors_ex(_php_free_ffmpeg_frame,
            NULL, "ffmpeg_frame", module_number);

    INIT_CLASS_ENTRY(ffmpeg_frame_class_entry, "ffmpeg_frame", 
            ffmpeg_frame_class_methods);

    /* register ffmpeg frame class */
    ffmpeg_frame_class_entry_ptr = 
        zend_register_internal_class(&ffmpeg_frame_class_entry TSRMLS_CC);
}


/* {{{ _php_convert_frame()
 */
static int _php_convert_frame(ff_frame_context *ff_frame, int new_fmt) {
    AVFrame *new_fmt_frame;

    if (!ff_frame->av_frame) {
        return -1;
    }

    if (ff_frame->pixel_format == new_fmt) {
        return 0;
    }

    new_fmt_frame = avcodec_alloc_frame();
    avpicture_alloc((AVPicture*)new_fmt_frame, new_fmt, ff_frame->width,
                            ff_frame->height);
    if (img_convert((AVPicture*)new_fmt_frame, new_fmt, 
                (AVPicture *)ff_frame->av_frame, 
                ff_frame->pixel_format, ff_frame->width, 
                ff_frame->height) < 0) {
        zend_error(E_ERROR, "Error converting frame");
    }

    _php_free_av_frame(ff_frame->av_frame);

    ff_frame->av_frame = new_fmt_frame;
    ff_frame->pixel_format = new_fmt;
    return 0;
}
/* }}} */


/* {{{ _php_crop_frame()
 */
static int _php_crop_frame(ff_frame_context *ff_frame, 
        int crop_top, int crop_bottom, int crop_left, int crop_right) {
    AVFrame *cropped_frame, *tmp_src;
    AVFrame crop_temp;
    int cropped_width, cropped_height;

    if (!ff_frame->av_frame) {
        return -1;
    }

    tmp_src =ff_frame->av_frame;
    
    crop_temp.data[0] = tmp_src->data[0] +
        (crop_top * tmp_src->linesize[0]) + crop_left;

    crop_temp.data[1] = tmp_src->data[1] +
        ((crop_top >> 1) * tmp_src->linesize[1]) +
        (crop_left >> 1);

    crop_temp.data[2] = tmp_src->data[2] +
        ((crop_top >> 1) * tmp_src->linesize[2]) +
        (crop_left >> 1);

    crop_temp.linesize[0] = tmp_src->linesize[0];
    crop_temp.linesize[1] = tmp_src->linesize[1];
    crop_temp.linesize[2] = tmp_src->linesize[2];

    cropped_frame = avcodec_alloc_frame();

    cropped_width = ff_frame->width - (crop_left + crop_right);
    cropped_height = ff_frame->height - (crop_top + crop_bottom);
    
    avpicture_alloc((AVPicture*)cropped_frame, ff_frame->pixel_format,
            cropped_width, cropped_height);
    
    img_copy((AVPicture*)cropped_frame, 
                (AVPicture *)&crop_temp, ff_frame->pixel_format, 
                cropped_width, cropped_height);

    /* free non cropped frame */
    _php_free_av_frame(ff_frame->av_frame);

    ff_frame->av_frame = cropped_frame;
    ff_frame->width = cropped_width;
    ff_frame->height = cropped_height;
    return 0;
}
/* }}} */


/* {{{ _php_convert_frame()
 */
static int _php_resample_frame(ff_frame_context *ff_frame,
        int wanted_width, int wanted_height, int crop_top, int crop_bottom,
        int crop_left, int crop_right)
{
    AVFrame *resampled_frame;
    ImgReSampleContext *img_resample_ctx = NULL;
 
    if (!ff_frame->av_frame) {
        return -1;
    }

    /* just crop if wanted dimensions - crop bands = zero resampling */
    if (wanted_width == ff_frame->width - (crop_left + crop_right) && 
            wanted_height == ff_frame->height - (crop_left + crop_right)) {
        _php_crop_frame(ff_frame, crop_top, crop_bottom, crop_left, crop_right);
        return 0;
    } 
    
    /* convert to PIX_FMT_YUV420P required for resampling */
    _php_convert_frame(ff_frame, PIX_FMT_YUV420P);

    img_resample_ctx = img_resample_full_init(
            wanted_width, wanted_height,
            ff_frame->width, ff_frame->height,
            crop_top, crop_bottom, crop_left, crop_right,
            0, 0, 0, 0);
    if (!img_resample_ctx) {
        return -1;
    }

    resampled_frame = avcodec_alloc_frame();
    avpicture_alloc((AVPicture*)resampled_frame, PIX_FMT_YUV420P, 
            ff_frame->width, ff_frame->height);

    img_resample(img_resample_ctx, (AVPicture*)resampled_frame, 
            (AVPicture*)ff_frame->av_frame);

    _php_free_av_frame(ff_frame->av_frame);

    img_resample_close(img_resample_ctx);

    ff_frame->av_frame = resampled_frame;
    ff_frame->width = wanted_width;
    ff_frame->height = wanted_height;

    return 0;
}
/* }}} */

#ifdef HAVE_LIBGD20

/* {{{ _php_get_gd_image()
 */
int _php_get_gd_image(int w, int h)
{
    zval *function_name, *width, *height;
    zval **argv[2];
    zend_function *func;
    zval *retval;
    char *function_cname = "imagecreatetruecolor";
    int ret;
	TSRMLS_FETCH();   
    if (zend_hash_find(EG(function_table), function_cname, 
                strlen(function_cname) + 1, (void **)&func) == FAILURE) {
        zend_error(E_ERROR, "Error can't find %s function", function_cname);
    }

    MAKE_STD_ZVAL(function_name);
    MAKE_STD_ZVAL(width);
    MAKE_STD_ZVAL(height);

    ZVAL_STRING(function_name, function_cname, 0);
    ZVAL_LONG(width, w);
    ZVAL_LONG(height, h);

    argv[0] = &width;
    argv[1] = &height;

    if (call_user_function_ex(EG(function_table), NULL, function_name, 
                &retval, 2, argv, 0, NULL TSRMLS_CC) == FAILURE) {
        zend_error(E_ERROR, "Error calling %s function", function_cname);
    }
    
    FREE_ZVAL(function_name); 
    FREE_ZVAL(width); 
    FREE_ZVAL(height); 
    
    if (!retval || retval->type != IS_RESOURCE) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR,
                "Error creating GD Image");
    }

    ret = retval->value.lval;
    zend_list_addref(ret); 
    if (retval) {
        zval_ptr_dtor(&retval);
    }

    return ret;
}
/* }}} */


/* {{{ _php_avframe_to_gd_image()
 */
int _php_avframe_to_gd_image(AVFrame *frame, gdImage *dest, int width, int height)
{
    int x, y;
    int *src = (int*)frame->data[0];

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
		
			// FIXME: don't do bounds check until we fix the gd.h incompatiblity problem 
			//if (gdImageBoundsSafe(dest, x, y)) {
                /* copy pixel to gdimage buffer zeroing the alpha channel */
                dest->tpixels[y][x] = src[x] & 0x00ffffff;
            //} else {
            //    return -1;
            //}
        }
        src += width;
    }
    return 0;
}

int _php_gd_image_to_avframe(gdImage *src, AVFrame *frame, int width, int height) 
{
    int x, y;
    int *dest = (int*)frame->data[0];

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            //if (gdImageBoundsSafe(src, x, y)) {
                dest[x] = src->tpixels[y][x];
            /*} else {
                return -1;
            }*/
        }
        dest += width;
    }
    return 0;
}
/* }}} */

/* {{{ proto resource toGDImage()
 */
PHP_FUNCTION(toGDImage)
{
    ff_frame_context *ff_frame;
    gdImage *gd_img;

    GET_FRAME_RESOURCE(ff_frame);

    _php_convert_frame(ff_frame, PIX_FMT_RGBA32);

    return_value->value.lval = _php_get_gd_image(ff_frame->width, 
            ff_frame->height);

    return_value->type = IS_RESOURCE;

    ZEND_FETCH_RESOURCE(gd_img, gdImagePtr, &return_value, -1, "Image", le_gd);

    if (_php_avframe_to_gd_image(ff_frame->av_frame, gd_img,
            ff_frame->width, ff_frame->height)) {
        // don't error until we fix the gdImageBounds problem with older GD
        //zend_error(E_ERROR, "failed to convert frame to gd image");
    }
}
/* }}} */

#endif /* HAVE_LIBGD20 */


/* {{{ proto object _php_read_frame_from_file(mixed)
 */
/*_php_read_frame_from_file(ff_frame_context *ff_frame, char* filename)
{
    AVFrame *frame = NULL;
    AVFormatContext *ic;
    AVFormatParameters *ap;
    int err;

    // open the input file with generic libav function
    err = av_open_input_file(&ic, filename, NULL, 0, ap);
    if (err < 0) {
        zend_error(E_ERROR, "Can't open image file %d, %d", err, AVERROR_NOFMT);
    }

    
}*/
/* }}} */


/* {{{ proto object ffmpeg_frame(mixed)
 */
PHP_FUNCTION(ffmpeg_frame)
{
    zval **argv[1];
    AVFrame *frame;
    gdImage *gd_img;
    ff_frame_context *ff_frame;
    int width, height, ret;

    if (ZEND_NUM_ARGS() != 1) {
        WRONG_PARAM_COUNT;
    }

    /* retrieve argument */
    if (zend_get_parameters_array_ex(ZEND_NUM_ARGS(), argv) != SUCCESS) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR,
                "Error parsing arguments");
    }

    ff_frame = _php_alloc_ff_frame();
    
	ret = ZEND_REGISTER_RESOURCE(NULL, ff_frame, le_ffmpeg_frame);
    
    object_init_ex(getThis(), ffmpeg_frame_class_entry_ptr);
    add_property_resource(getThis(), "ffmpeg_frame", ret);
    
    switch (Z_TYPE_PP(argv[0])) {
        case IS_STRING:
            /* TODO: test for resource or string */
            convert_to_string_ex(argv[0]);
            zend_error(E_ERROR, "Creating an ffmpeg_frame from a file is not implemented yet\n");
            //_php_read_frame_from_file(ff_frame, Z_STRVAL_PP(argv[0]));
            break;
        case IS_RESOURCE:
            ZEND_FETCH_RESOURCE(gd_img, gdImagePtr, argv[0], -1, "Image", le_gd);

            if (!gd_img->trueColor) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "First parameter must be a truecolor gd image.");
            }

            width = gdImageSX(gd_img);
            height = gdImageSY(gd_img);

            frame = avcodec_alloc_frame();
            avpicture_alloc((AVPicture*)frame, PIX_FMT_RGBA32, width, height);
            _php_gd_image_to_avframe(gd_img, frame, width, height);
            
            ff_frame->av_frame = frame;
            ff_frame->width = width;
            ff_frame->height = height;
            ff_frame->pixel_format = PIX_FMT_RGBA32;
            break;
        default:
            zend_error(E_ERROR, "Invalid argument\n");
            
    }
}
/* }}} */


/* {{{ proto int getWidth()
 */
PHP_FUNCTION(getWidth)
{
    ff_frame_context *ff_frame;

    GET_FRAME_RESOURCE(ff_frame);
    
    RETURN_LONG(ff_frame->width);
}
/* }}} */


/* {{{ proto int getHeight()
 */
PHP_FUNCTION(getHeight)
{
    ff_frame_context *ff_frame;

    GET_FRAME_RESOURCE(ff_frame);
    
    RETURN_LONG(ff_frame->height);
}
/* }}} */


/* {{{ proto boolean crop([, int crop_top [, int crop_bottom [, int crop_left [, int crop_right ]]]])
*/
PHP_FUNCTION(crop)
{
    zval ***argv;
    ff_frame_context *ff_frame;
    int crop_top = 0, crop_bottom = 0, crop_left = 0, crop_right = 0;

    GET_FRAME_RESOURCE(ff_frame);

    /* retrieve arguments */ 
    argv = (zval ***) emalloc(sizeof(zval **) * ZEND_NUM_ARGS());

    if (zend_get_parameters_array_ex(ZEND_NUM_ARGS(), argv) != SUCCESS) {
        efree(argv);
        php_error_docref(NULL TSRMLS_CC, E_ERROR,
                "Error parsing arguments");
    }

    switch (ZEND_NUM_ARGS()) {
        case 4:
            convert_to_long_ex(argv[3]);
            crop_right = Z_LVAL_PP(argv[3]);

            /* crop right must be even number for lavc cropping */
            if (crop_right % 2) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Crop right must be an even number");
            }
            /* fallthru */
        case 3:
            convert_to_long_ex(argv[2]);
            crop_left = Z_LVAL_PP(argv[2]);

            /*  crop left must be even number for lavc cropping */
            if (crop_left % 2) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Crop left must be an even number");
            }

            /* fallthru */
        case 2:
            convert_to_long_ex(argv[1]);
            crop_bottom = Z_LVAL_PP(argv[1]);

            /*  crop bottom must be even number for lavc cropping */
            if (crop_bottom % 2) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Crop bottom must be an even number");
            }

            /* fallthru */
        case 1:
            convert_to_long_ex(argv[0]);
            crop_top = Z_LVAL_PP(argv[0]);

            /*  crop top  must be even number for lavc cropping */
            if (crop_top % 2) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Crop top must be an even number");
            }
            break;
        default:
            WRONG_PARAM_COUNT;
    } 

    efree(argv);

    /* crop frame */
    _php_crop_frame(ff_frame, crop_top, crop_bottom, crop_left, crop_right);

    RETURN_TRUE;
}
/* }}} */


/* {{{ proto boolean resize(int width, int height [, int crop_top [, int crop_bottom [, int crop_left [, int crop_right ]]]])
*/
PHP_FUNCTION(resize)
{
    zval ***argv;
    ff_frame_context *ff_frame;
    int wanted_width = 0, wanted_height = 0;
    int crop_top = 0, crop_bottom = 0, crop_left = 0, crop_right = 0;

    GET_FRAME_RESOURCE(ff_frame);

    /* retrieve arguments */ 
    argv = (zval ***) emalloc(sizeof(zval **) * ZEND_NUM_ARGS());

    if (zend_get_parameters_array_ex(ZEND_NUM_ARGS(), argv) != SUCCESS) {
        efree(argv);
        php_error_docref(NULL TSRMLS_CC, E_ERROR,
                "Error parsing arguments");
    }

    switch (ZEND_NUM_ARGS()) {
        case 6:
            convert_to_long_ex(argv[5]);
            crop_right = Z_LVAL_PP(argv[5]);

            /* crop right must be even number for lavc cropping */
            if (crop_right % 2) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Crop right must be an even number");
            }
            /* fallthru */
        case 5:
            convert_to_long_ex(argv[4]);
            crop_left = Z_LVAL_PP(argv[4]);

            /*  crop left must be even number for lavc cropping */
            if (crop_left % 2) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Crop left must be an even number");
            }

            /* fallthru */
        case 4:
            convert_to_long_ex(argv[3]);
            crop_bottom = Z_LVAL_PP(argv[3]);

            /*  crop bottom must be even number for lavc cropping */
            if (crop_bottom % 2) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Crop bottom must be an even number");
            }

            /* fallthru */
        case 3:
            convert_to_long_ex(argv[2]);
            crop_top = Z_LVAL_PP(argv[2]);

            /*  crop top must be even number for lavc cropping */
            if (crop_top % 2) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Crop top must be an even number");
            }

            /* fallthru */
        case 2:
            /* height arg */
            convert_to_long_ex(argv[1]);
            wanted_height = Z_LVAL_PP(argv[1]);

            /* bounds check wanted height */
            if (wanted_height < 1) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Frame height must be greater than zero");
            }

            /* wanted height must be even number for lavc resample */
            if (wanted_height % 2) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Frame height must be an even number");
            }
        case 1:
            /* width arg */
            convert_to_long_ex(argv[0]);
            wanted_width = Z_LVAL_PP(argv[0]);

            /* bounds check wanted width */
            if (wanted_width < 1) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Frame width must be greater than zero");
            }

            /* wanted width must be even number for lavc resample */
            if (wanted_width % 2) {
                php_error_docref(NULL TSRMLS_CC, E_ERROR,
                        "Frame width must be an even number");
            }
            break;
        default:
            WRONG_PARAM_COUNT;
    } 

    efree(argv);

        /* resize frame */
    _php_resample_frame(ff_frame, wanted_width, wanted_height, 
            crop_top, crop_bottom, crop_left, crop_right);

    RETURN_TRUE;
}

//----------------------------------------------------------------------------------

#define lrint floor

static zend_class_entry *ffmpeg_movie_class_entry_ptr;
zend_class_entry ffmpeg_movie_class_entry;

static int le_ffmpeg_movie;

/* {{{ ffmpeg_movie methods[]
    Methods of the ffmpeg_movie class 
*/
zend_function_entry ffmpeg_movie_class_methods[] = {
   
    /* contructor */
    PHP_FE(ffmpeg_movie, NULL)

    /* methods */
	PHP_FALIAS(getduration,         getDuration,        NULL)
	PHP_FALIAS(getframecount,       getFrameCount,      NULL)
	PHP_FALIAS(getframerate,        getFrameRate,       NULL)
	PHP_FALIAS(getfilename,         getFileName,        NULL)
	PHP_FALIAS(getcomment,          getComment,         NULL)
	PHP_FALIAS(gettitle,            getTitle,           NULL)
    PHP_FALIAS(getauthor,           getAuthor,          NULL)
	PHP_FALIAS(getcopyright,        getCopyright,       NULL)
    PHP_FALIAS(getframewidth,       getFrameWidth,      NULL)
    PHP_FALIAS(getframeheight,      getFrameHeight,     NULL)
    PHP_FALIAS(getframenumber,      getFrameNumber,     NULL)
    PHP_FALIAS(getpixelformat,      getPixelFormat,     NULL)
    PHP_FALIAS(getbitrate,          getBitRate,         NULL)
    PHP_FALIAS(hasaudio,            hasAudio,           NULL)
    PHP_FALIAS(getframe,            getFrame,           NULL)
    PHP_FALIAS(getvideocodec,       getVideoCodec,      NULL)
    PHP_FALIAS(getaudiocodec,       getAudioCodec,      NULL)
    PHP_FALIAS(getaudiochannels,    getAudioChannels,   NULL)
	{NULL, NULL, NULL}
};
/* }}} */


/* {{{ _php_get_stream_index()
 */
static int _php_get_stream_index(AVFormatContext *fmt_ctx, int type)
{
    int i;
    
    for (i = 0; i < fmt_ctx->nb_streams; i++) {
        if (fmt_ctx->streams[i] && 
                fmt_ctx->streams[i]->codec.codec_type == type) {
            return i;
        }
    }
    /* stream not found */
    return -1;
}
/* }}} */


/* {{{ _php_get_video_stream()
 */
static AVStream *_php_get_video_stream(AVFormatContext *fmt_ctx)
{
    int i = _php_get_stream_index(fmt_ctx, CODEC_TYPE_VIDEO);
    
    return i < 0 ? NULL : fmt_ctx->streams[i];
}
/* }}} */


/* {{{ _php_get_audio_stream()
 */
static AVStream *_php_get_audio_stream(AVFormatContext *fmt_ctx)
{
    int i = _php_get_stream_index(fmt_ctx, CODEC_TYPE_AUDIO);
    
    return i < 0 ? NULL : fmt_ctx->streams[i];
}
/* }}} */


/* {{{ _php_get_filename()
 */
static char* _php_get_filename(ff_movie_context *ffmovie_ctx)
{
    return ffmovie_ctx->fmt_ctx->filename;
}
/* }}} */


/* {{{ _php_alloc_ffmovie_ctx()
 */
static ff_movie_context* _php_alloc_ffmovie_ctx()
{
    int i;
    ff_movie_context *ffmovie_ctx;
    
    ffmovie_ctx = emalloc(sizeof(ff_movie_context));
    ffmovie_ctx->fmt_ctx = NULL;


    for (i = 0; i < MAX_STREAMS; i++) {
        ffmovie_ctx->codec_ctx[i] = NULL;
    }

    return ffmovie_ctx;
}
/* }}} */


/* {{{ _php_open_movie_file()
 */
static void _php_open_movie_file(ff_movie_context *ffmovie_ctx, 
        char* filename)
{
    AVFormatParameters params;

    /* open the file with generic libav function */
    if (av_open_input_file(&(ffmovie_ctx->fmt_ctx), filename, NULL, 0, 
                &params)) {
        zend_error(E_ERROR, "Can't open movie file %s", filename);
    }
    
    /* If not enough info to get the stream parameters, we decode the
       first frames to get it. */
    if (av_find_stream_info(ffmovie_ctx->fmt_ctx)) {
        /* This is not a problem for some formats like .mov */
        /*zend_error(E_WARNING, "Can't find codec parameters for %s", filename); */
    }
}
/* }}} */


/* {{{ proto object ffmpeg_movie(string filename) 
   Constructor for ffmpeg_movie objects
 */
PHP_FUNCTION(ffmpeg_movie)
{
    int argc, ret;
    zval **argv[1];
    ff_movie_context *ffmovie_ctx;
    
    /* get the number of arguments */
    argc = ZEND_NUM_ARGS();

    if (argc != 1) {
        WRONG_PARAM_COUNT;
    }

    /* argument count is correct, now retrieve arguments */
    if (zend_get_parameters_array_ex(argc, argv) != SUCCESS) {
        WRONG_PARAM_COUNT;
    }
  
	ffmovie_ctx = _php_alloc_ffmovie_ctx();
    
    convert_to_string_ex(argv[0]);
    
    _php_open_movie_file(ffmovie_ctx, Z_STRVAL_PP(argv[0]));

    /* pass NULL for resource result since we're not returning the resource
     directly, but adding it to the returned object. */
	ret = ZEND_REGISTER_RESOURCE(NULL, ffmovie_ctx, le_ffmpeg_movie);
    
    object_init_ex(getThis(), ffmpeg_movie_class_entry_ptr);
    add_property_resource(getThis(), "ffmpeg_movie", ret);
}
/* }}} */


/* {{{ _php_free_ffmpeg_movie
 */
static void _php_free_ffmpeg_movie(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    int i;
    ff_movie_context *ffmovie_ctx = (ff_movie_context*)rsrc->ptr;    

    if (ffmovie_ctx->codec_ctx) {
        for (i = 0; i < MAX_STREAMS; i++) {
            if(ffmovie_ctx->codec_ctx[i]) {
                avcodec_close(ffmovie_ctx->codec_ctx[i]);
            }
            ffmovie_ctx->codec_ctx[i] = NULL;
        }
    }

    av_close_input_file(ffmovie_ctx->fmt_ctx);

    efree(ffmovie_ctx);
}
/* }}} */


/* {{{ register_ffmpeg_movie_class()
 */
void register_ffmpeg_movie_class(int module_number) {
	TSRMLS_FETCH();
    le_ffmpeg_movie = zend_register_list_destructors_ex(_php_free_ffmpeg_movie,
            NULL, "ffmpeg_movie", module_number);

   
    INIT_CLASS_ENTRY(ffmpeg_movie_class_entry, "ffmpeg_movie", 
            ffmpeg_movie_class_methods);
    
    /* register ffmpeg movie class */
    ffmpeg_movie_class_entry_ptr = 
        zend_register_internal_class(&ffmpeg_movie_class_entry TSRMLS_CC);
}
/* }}} */


/* {{{ _php_get_decoder_context() 
   Opens codecs and gets codec context. Always call this to get a pointer to 
   the codec context. This allows to postpone codec init until a function
   that requires it is called.
 */
static AVCodecContext* _php_get_decoder_context(ff_movie_context *ffmovie_ctx,
        int stream_type, int reload_codec)
{
    AVCodec *decoder;
    int stream_index;

    stream_index = _php_get_stream_index(ffmovie_ctx->fmt_ctx, stream_type);
    if (stream_index < 0) {
        // FIXME: Find a way to do this without the if statement
        if (stream_type == CODEC_TYPE_VIDEO) {
            zend_error(E_WARNING, "Can't find video stream in %s", 
                    _php_get_filename(ffmovie_ctx));
            return NULL;
        } else {
            zend_error(E_WARNING, "Can't find audio stream in %s", 
                    _php_get_filename(ffmovie_ctx));
            return NULL;
        }
    }
    
    if (reload_codec && ffmovie_ctx->codec_ctx[stream_index]) {
        /* close decoder */
        avcodec_close(ffmovie_ctx->codec_ctx[stream_index]);
        ffmovie_ctx->codec_ctx[stream_index] = NULL;
    }

    if (!ffmovie_ctx->codec_ctx[stream_index]) {
   
        ffmovie_ctx->codec_ctx[stream_index] = 
            &ffmovie_ctx->fmt_ctx->streams[stream_index]->codec;
        
        /* find the decoder */
        decoder = avcodec_find_decoder(ffmovie_ctx->codec_ctx[stream_index]->codec_id);
        if (!decoder) {
            zend_error(E_ERROR, "Could not find decoder for %s", 
                    _php_get_filename(ffmovie_ctx));
        }

        /* open the decoder */
        if (avcodec_open(ffmovie_ctx->codec_ctx[stream_index], decoder) < 0) {
            zend_error(E_ERROR, "Could not open codec for %s",
                    _php_get_filename(ffmovie_ctx));
        }
    }
    return ffmovie_ctx->codec_ctx[stream_index];
}
/* }}} */


/* {{{ proto string getComment()
 */
PHP_FUNCTION(getComment)
{
    ff_movie_context *ffmovie_ctx;

    GET_MOVIE_RESOURCE(ffmovie_ctx);
    
    RETURN_STRINGL(ffmovie_ctx->fmt_ctx->comment,
            strlen(ffmovie_ctx->fmt_ctx->comment), 1);
}
/* }}} */


/* {{{ proto string getTitle()
 */
PHP_FUNCTION(getTitle)
{
    ff_movie_context *ffmovie_ctx;
    
    GET_MOVIE_RESOURCE(ffmovie_ctx);

    RETURN_STRINGL(ffmovie_ctx->fmt_ctx->title,
            strlen(ffmovie_ctx->fmt_ctx->title), 1);
}
/* }}} */


/* {{{ proto string getAuthor()
 */
PHP_FUNCTION(getAuthor)
{
    ff_movie_context *ffmovie_ctx;
    
    GET_MOVIE_RESOURCE(ffmovie_ctx);

    RETURN_STRINGL(ffmovie_ctx->fmt_ctx->author,
            strlen(ffmovie_ctx->fmt_ctx->author), 1);
}
/* }}} */


/* {{{ proto string getCopyright()
 */
PHP_FUNCTION(getCopyright)
{
    ff_movie_context *ffmovie_ctx;
    
    GET_MOVIE_RESOURCE(ffmovie_ctx);

    RETURN_STRINGL(ffmovie_ctx->fmt_ctx->copyright,
            strlen(ffmovie_ctx->fmt_ctx->copyright), 1);
}
/* }}} */


/* {{{ _php_get_duration()
 */
static float _php_get_duration(ff_movie_context *ffmovie_ctx)
{
    float duration;

    duration = (float)ffmovie_ctx->fmt_ctx->duration / AV_TIME_BASE;

    if (duration < 0) {
        duration = 0.0f;
    }
    return duration;
}
/* }}} */


/* {{{ proto int getDuration()
 */
PHP_FUNCTION(getDuration)
{
    ff_movie_context *ffmovie_ctx;
       
    GET_MOVIE_RESOURCE(ffmovie_ctx);
    
    RETURN_DOUBLE(_php_get_duration(ffmovie_ctx));
}
/* }}} */


/* {{{ _php_get_framecount()
 */
static long _php_get_framecount(ff_movie_context *ffmovie_ctx)
{
    float duration = 0.0, frame_rate = 0.0;
    AVStream *st = _php_get_video_stream(ffmovie_ctx->fmt_ctx);

    if (!st) {
      return 0;
    }
    
    duration = _php_get_duration(ffmovie_ctx);
    frame_rate = (float)st->codec.frame_rate / st->codec.frame_rate_base;

    return lrint(frame_rate * duration);

}
/* }}} */


/* {{{ proto int getFrameCount()
 */
PHP_FUNCTION(getFrameCount)
{
    ff_movie_context *ffmovie_ctx;
    GET_MOVIE_RESOURCE(ffmovie_ctx);
    RETURN_LONG(_php_get_framecount(ffmovie_ctx));
}
/* }}} */


/* {{{ _php_get_framerate()
 */
static float _php_get_framerate(ff_movie_context *ffmovie_ctx)
{
    AVStream *st = _php_get_video_stream(ffmovie_ctx->fmt_ctx);

    if (!st) {
      return 0.0f;
    }

    /*
    if (st->codec.frame_rate > 1000 && st->codec.frame_rate_base==1) {
        st->codec.frame_rate_base = 1000;
    }
     */

    return (float)st->codec.frame_rate / st->codec.frame_rate_base;
}
/* }}} */


/* {{{ proto int getFrameRate()
 */
PHP_FUNCTION(getFrameRate)
{
    ff_movie_context *ffmovie_ctx;
    
    GET_MOVIE_RESOURCE(ffmovie_ctx);

    RETURN_DOUBLE(_php_get_framerate(ffmovie_ctx));
}
/* }}} */


/* {{{ proto string getFileName()
 */
PHP_FUNCTION(getFileName)
{
    ff_movie_context *ffmovie_ctx;
    char* filename;
    
    GET_MOVIE_RESOURCE(ffmovie_ctx);

    filename = _php_get_filename(ffmovie_ctx);
    RETURN_STRINGL(filename, strlen(filename), 1);
}
/* }}} */


/* {{{ _php_get_framewidth()
 */
static int _php_get_framewidth(ff_movie_context *ffmovie_ctx)
{
    AVStream *st = _php_get_video_stream(ffmovie_ctx->fmt_ctx);

    if (!st) {
      return 0;
    }
 
    return st->codec.width;
}
/* }}} */


/* {{{ proto int getFrameWidth()
 */
PHP_FUNCTION(getFrameWidth)
{
    ff_movie_context *ffmovie_ctx;
    
    GET_MOVIE_RESOURCE(ffmovie_ctx);
    
    RETURN_LONG(_php_get_framewidth(ffmovie_ctx));
}
/* }}} */


/* {{{ _php_get_frameheight()
 */
static int _php_get_frameheight(ff_movie_context *ffmovie_ctx)
{
    AVStream *st = _php_get_video_stream(ffmovie_ctx->fmt_ctx);

    if (!st) {
      return 0;
    }
 
    return st->codec.height;
}
/* }}} */


/* {{{ proto int getFrameHeight()
 */
PHP_FUNCTION(getFrameHeight)
{
    ff_movie_context *ffmovie_ctx;

    GET_MOVIE_RESOURCE(ffmovie_ctx);

    RETURN_LONG(_php_get_frameheight(ffmovie_ctx));
}
/* }}} */


/* {{{ _php_get_framenumber()
 */
static long _php_get_framenumber(ff_movie_context *ffmovie_ctx) 
{
    AVCodecContext *decoder_ctx = NULL;

    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, CODEC_TYPE_VIDEO, 0);
    if (!decoder_ctx) {
        return 0;
    }

    if (decoder_ctx->frame_number <= 0) {
        return 1; /* no frames read yet so return the first */
    } else {
        return decoder_ctx->frame_number;
    }
}
/* }}} */


/* {{{ proto resource getFrameNumber()
 */
PHP_FUNCTION(getFrameNumber)
{
    ff_movie_context *ffmovie_ctx;
    int frame_number = 0;
    
    GET_MOVIE_RESOURCE(ffmovie_ctx);

    frame_number =_php_get_framenumber(ffmovie_ctx);
   
    if (frame_number) {
        RETURN_LONG(frame_number);
    } else {
        RETURN_FALSE;
    }
}
/* }}} */


/* {{{ _php_get_pixelformat()
 */
static int _php_get_pixelformat(ff_movie_context *ffmovie_ctx)
{
    AVCodecContext *decoder_ctx;
    
    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, CODEC_TYPE_VIDEO, 0);
    if (!decoder_ctx) {
        return 0;
    }

    return decoder_ctx->pix_fmt;
}
/* }}} */


/* {{{ proto int getPixelFormat()
 */
PHP_FUNCTION(getPixelFormat)
{
    int pix_fmt;
    const char *fmt;
    ff_movie_context *ffmovie_ctx;

    GET_MOVIE_RESOURCE(ffmovie_ctx);

    pix_fmt = _php_get_pixelformat(ffmovie_ctx);
    fmt = avcodec_get_pix_fmt_name(pix_fmt);
    
    if (fmt) {
        /* cast const to non-const to keep compiler from complaining, 
           RETURN_STRINGL just copies so the string won't get overwritten
           */
        RETURN_STRINGL((char *)fmt, strlen(fmt), 1);
    } else {
        RETURN_FALSE;
    }
}
/* }}} */


/* {{{ _php_get_bitrate()
 */
static int _php_get_bitrate(ff_movie_context *ffmovie_ctx)
{
    return ffmovie_ctx->fmt_ctx->bit_rate;
}
/* }}} */


/* {{{ proto int getBitrate()
 */
PHP_FUNCTION(getBitRate)
{
    int bitrate;
    ff_movie_context *ffmovie_ctx;
    
    GET_MOVIE_RESOURCE(ffmovie_ctx);
   
    /* convert to kb/s */
    bitrate = _php_get_bitrate(ffmovie_ctx) / 1000; 

    RETURN_LONG(bitrate);
}
/* }}} */


/* {{{ proto int hasAudio()
 */
PHP_FUNCTION(hasAudio)
{
    ff_movie_context *ffmovie_ctx;

    GET_MOVIE_RESOURCE(ffmovie_ctx);

    RETURN_BOOL(_php_get_audio_stream(ffmovie_ctx->fmt_ctx));
}
/* }}} */


/* {{{ _php_get_video_codec()
   Returns a frame from the movie.
 */
static const char* _php_get_codec_name(ff_movie_context *ffmovie_ctx, int type)
{
    AVCodecContext *decoder_ctx = NULL;
    AVCodec *p = NULL;
    const char *codec_name;
    char buf1[32];
    int stream;

    stream = _php_get_stream_index(ffmovie_ctx->fmt_ctx, type);
    if (stream < 0) {
        return NULL;
    }

    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, type, 0);
    if (!decoder_ctx) {
        return NULL;
    }

    p = avcodec_find_decoder(decoder_ctx->codec_id);

    /* Copied from libavcodec/utils.c::avcodec_string */
    if (p) {
        codec_name = p->name;
        if (decoder_ctx->codec_id == CODEC_ID_MP3) {
            if (decoder_ctx->sub_id == 2)
                codec_name = "mp2";
            else if (decoder_ctx->sub_id == 1)
                codec_name = "mp1";
        }
    } else if (decoder_ctx->codec_id == CODEC_ID_MPEG2TS) {
        /* fake mpeg2 transport stream codec (currently not registered) */
        codec_name = "mpeg2ts";
    } else if (decoder_ctx->codec_name[0] != '\0') {
        codec_name = decoder_ctx->codec_name;
    } else {
        /* output avi tags */
        if (decoder_ctx->codec_type == CODEC_TYPE_VIDEO) {
            snprintf(buf1, sizeof(buf1), "%c%c%c%c",
                    decoder_ctx->codec_tag & 0xff,
                    (decoder_ctx->codec_tag >> 8) & 0xff,
                    (decoder_ctx->codec_tag >> 16) & 0xff,
                    (decoder_ctx->codec_tag >> 24) & 0xff);
        } else {
            snprintf(buf1, sizeof(buf1), "0x%04x", decoder_ctx->codec_tag);
        }
        codec_name = buf1;
    }

    return codec_name;
} 


/* {{{ proto int getVideoCodec()
 */
PHP_FUNCTION(getVideoCodec)
{
    ff_movie_context *ffmovie_ctx;
    char *codec_name;

    GET_MOVIE_RESOURCE(ffmovie_ctx);

    codec_name = (char*)_php_get_codec_name(ffmovie_ctx, CODEC_TYPE_VIDEO);
 
    if (codec_name) {
        RETURN_STRINGL(codec_name, strlen(codec_name), 1);
    } else {
        RETURN_FALSE;
    }
}
/* }}} */


/* {{{ proto int getVideoCodec()
 */
PHP_FUNCTION(getAudioCodec)
{
    ff_movie_context *ffmovie_ctx;
    char *codec_name;

    GET_MOVIE_RESOURCE(ffmovie_ctx);

    codec_name = (char*)_php_get_codec_name(ffmovie_ctx, CODEC_TYPE_AUDIO);
 
    if (codec_name) {
        RETURN_STRINGL(codec_name, strlen(codec_name), 1);
    } else {
        RETURN_FALSE;
    }
}
/* }}} */


/* {{{ _php_get_audio_channels()
   Returns a frame from the movie.
 */
static int _php_get_audio_channels(ff_movie_context *ffmovie_ctx)
{
    AVCodecContext *decoder_ctx = NULL;
    int stream;

    stream = _php_get_stream_index(ffmovie_ctx->fmt_ctx, CODEC_TYPE_AUDIO);
    if (stream < 0) {
        return 0;
    }

    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, CODEC_TYPE_AUDIO, 0);
    if (!decoder_ctx) {
        return 0;
    }

    return decoder_ctx->channels;
} 



/* {{{ proto int getVideoCodec()
 */
PHP_FUNCTION(getAudioChannels)
{
    ff_movie_context *ffmovie_ctx;
    int channels;

    GET_MOVIE_RESOURCE(ffmovie_ctx);

    channels = _php_get_audio_channels(ffmovie_ctx);
 
    if (channels) {
        RETURN_LONG(channels);
    } else {
        RETURN_FALSE;
    }
}
/* }}} */


/* {{{ _php_getframe()
   Returns a frame from the movie.
 */
static AVFrame* _php_getframe(ff_movie_context *ffmovie_ctx, int wanted_frame)
{
    AVCodecContext *decoder_ctx = NULL;
    AVPacket packet;
    AVFrame *frame = NULL;
    int got_frame; 
    int video_stream;

    video_stream = _php_get_stream_index(ffmovie_ctx->fmt_ctx, CODEC_TYPE_VIDEO);
    if (video_stream < 0) {
        return NULL;
    }
 
    decoder_ctx = _php_get_decoder_context(ffmovie_ctx, CODEC_TYPE_VIDEO, 0);
    if (decoder_ctx == NULL) {
        return NULL;
    }

    /* Rewind to the beginning of the stream if wanted frame already passed */
    if (wanted_frame && wanted_frame <= decoder_ctx->frame_number) {
        if (
#if LIBAVFORMAT_BUILD >=  4619
                av_seek_frame(ffmovie_ctx->fmt_ctx, -1, 0, 0)
#else 
                av_seek_frame(ffmovie_ctx->fmt_ctx, -1, 0)
#endif
                < 0) {
            zend_error(E_ERROR, "Error seeking to beginning of video stream");
        }

#define RELOAD_CODEC 1

        /* re-open decoder */
        decoder_ctx = _php_get_decoder_context(ffmovie_ctx, CODEC_TYPE_VIDEO, RELOAD_CODEC);
        if (decoder_ctx == NULL) {
            //zend_printf("reload");
            return NULL;
        }
    }

    frame = avcodec_alloc_frame();
    
    /* read frames looking for wanted_frame */ 
    while (av_read_frame(ffmovie_ctx->fmt_ctx, &packet) >= 0) {

        if (packet.stream_index == video_stream) {
        
            avcodec_decode_video(decoder_ctx, frame, &got_frame,
                    packet.data, packet.size);

            if (got_frame) {
                if (!wanted_frame || decoder_ctx->frame_number == wanted_frame) {
                    /* free wanted frame packet */
                    av_free_packet(&packet);
                    break; 
                }
            }
        }

        /* free the packet allocated by av_read_frame */
        av_free_packet(&packet);
    }
    return frame;
}
/* }}} */


/* {{{ proto resource getFrame([int frame])
 */
PHP_FUNCTION(getFrame)
{
    zval **argv[1];
    int wanted_frame = 0; 
    AVFrame *frame = NULL;
    ff_frame_context *ff_frame;
    ff_movie_context *ffmovie_ctx;

    if (ZEND_NUM_ARGS() > 1) {
        WRONG_PARAM_COUNT;
    }
    
    GET_MOVIE_RESOURCE(ffmovie_ctx);

    if (ZEND_NUM_ARGS()) {

        /* retrieve arguments */ 
        if (zend_get_parameters_array_ex(ZEND_NUM_ARGS(), argv) != SUCCESS) {
            php_error_docref(NULL TSRMLS_CC, E_ERROR,
                    "Error parsing arguments");
        }

        convert_to_long_ex(argv[0]);
        wanted_frame = Z_LVAL_PP(argv[0]);

        /* bounds check wanted frame */
        if (wanted_frame < 1) {
            php_error_docref(NULL TSRMLS_CC, E_ERROR,
                    "Frame number must be greater than zero");
        }
    } 

    frame = _php_getframe(ffmovie_ctx, wanted_frame);
    if (frame) { 
        /* 
         * _php_create_ffmpeg_frame sets PHP return_value to a ffmpeg_frame 
         * object via INTERNAL_FUNCTION_PARAM_PASSTHRU, the returned ff_frame
         * is just for conveniently setting its fields. 
         */
        ff_frame = _php_create_ffmpeg_frame(INTERNAL_FUNCTION_PARAM_PASSTHRU);

        if (!ff_frame) {
            php_error_docref(NULL TSRMLS_CC, E_ERROR,
                    "Error allocating ffmpeg_frame resource");
        }

        /* TODO: Provide function(s) for setting these in ffmpeg_frame */
        ff_frame->width = _php_get_framewidth(ffmovie_ctx);
        ff_frame->height = _php_get_frameheight(ffmovie_ctx);
        ff_frame->pixel_format = _php_get_pixelformat(ffmovie_ctx);
        
        ff_frame->av_frame = avcodec_alloc_frame();
        avpicture_alloc((AVPicture*)ff_frame->av_frame, ff_frame->pixel_format,
            ff_frame->width, ff_frame->height);
 
        /* FIXME: temporary hack until I figure out how to pass new buffers to the decoder */
        img_copy((AVPicture*)ff_frame->av_frame, 
                (AVPicture *)frame, ff_frame->pixel_format, 
                ff_frame->width, ff_frame->height);

        //ff_frame->av_frame = frame;
    } else {
        RETURN_FALSE;
    }
}
/* }}} */

