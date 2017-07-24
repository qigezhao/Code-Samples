/*
 * qz-iconv.c
 *
 *  Created on: Jul 24, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#include <string.h>
#include <iconv.h>

int charset_convert(
		char *from_charset, char *to_charset,
		char *inbuf, size_t inlen,
		char *outbuf, size_t outlen
	)
{
	iconv_t cd;
	char **pin = &inbuf;
	char **pout = &outbuf;

	cd = iconv_open(to_charset, from_charset);
	if (cd == 0)
	{
		return -1;
	}

	memset(outbuf, 0, outlen);
	if (iconv(cd, pin, &inlen, pout, &outlen) == -1)
	{
		return -2;
	}

	iconv_close(cd);
	return 0;
}

int utf8_to_gb(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
	return charset_convert("utf-8", "gb2312",
			inbuf, inlen, outbuf, outlen);
}

int gb_to_utf8(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
	return charset_convert("gb2312", "utf-8",
			inbuf, inlen, outbuf, outlen);
}

int utf8_to_ascii(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
	return charset_convert("utf-8", "ascii//",
			inbuf, inlen, outbuf, outlen);
}

int ascii_to_utf8(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
	return charset_convert("ascii//", "utf-8",
			inbuf, inlen, outbuf, outlen);
}

int utf8_to_unicode(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
	return charset_convert("utf-8", "unicode",
			inbuf, inlen, outbuf, outlen);
}

int unicode_to_utf8(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
	return charset_convert("unicode", "utf-8",
			inbuf, inlen, outbuf, outlen);
}

