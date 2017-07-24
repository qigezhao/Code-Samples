/*
 * qz-base64.c
 *
 *  Created on: Jul 24, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */
#include <string.h>

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

int base64_encode(char *inbuf, int inlen, char *outbuf, int outlen)
{
	int ret = 0;
	BIO *b64 = NULL, *bmem = NULL;
	BUF_MEM *bptr = NULL;

	b64 = BIO_new(BIO_f_base64());
	bmem = BIO_new(BIO_s_mem());
	b64 = BIO_push(b64, bmem);
	BIO_write(b64, inbuf, inlen); // encode
	BIO_flush(b64);
	BIO_get_mem_ptr(b64, &bptr);
	if (bptr->length > outlen)
	{
		printf("> (error) buffer is not enough\n");
		BIO_free_all(b64);
		ret = -1;
	} else {
		outlen = bptr->length;
		memcpy(outbuf, bptr->data, bptr->length);
	}

	BIO_free_all(b64);
	return ret;
}

int base64_decode(char *inbuf, int inlen, char *outbuf, int outlen)
{
	int ret = 0, len = 0;
	BIO *b64 = NULL, *bmem = NULL;
	b64 = BIO_new(BIO_f_base64());
	bmem = BIO_new_mem_buf(inbuf, inlen);
	bmem = BIO_push(b64, bmem);
	len = BIO_read(bmem, outbuf, outlen);
	if (len <= 0)
	{
		ret = -1;
	} else {
		outbuf[len] = 0;
	}
	BIO_free_all(bmem);
	return ret;
}

