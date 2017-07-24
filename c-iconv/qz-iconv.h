/*
 * qz-iconv.h
 *
 *  Created on: Jul 24, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#ifndef QZ_ICONV_H_
#define QZ_ICONV_H_

int charset_convert(
		char *from_charset, char *to_charset,
		char *inbuf, int inlen,
		char *outbuf, int outlen
	);

int utf8_to_gb(char *inbuf, size_t inlen, char *outbuf, size_t outlen);
int gb_to_utf8(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

int utf8_to_ascii(char *inbuf, size_t inlen, char *outbuf, size_t outlen);
int ascii_to_utf8(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

int utf8_to_unicode(char *inbuf, size_t inlen, char *outbuf, size_t outlen);
int unicode_to_utf8(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

#endif /* QZ_ICONV_H_ */

