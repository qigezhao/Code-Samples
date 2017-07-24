/*
 * c-base64.c
 *
 *  Created on: Jul 24, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */
#include <stdio.h>
#include <string.h>

#include "qz-base64.h"

int main(void)
{
	char *b64 = "SGVsbG8gV29ybGQhAA==\n";
	char enc[] = "Hello World!", buf[128] = { 0 };

	int b64_len = strlen(b64);
	int enc_len = sizeof(enc);
	int buf_len = sizeof(buf);

	if (base64_decode(b64, b64_len, buf, buf_len) < 0)
	{
		printf("> (error) decode failed.\n");
	} else {
		printf("decode: [%s] > [%s]\n--------\n", b64, buf);
	}

	if (base64_encode(enc, enc_len, buf, buf_len) < 0)
	{
		printf("> (error) encode failed.\n");
	} else {
		printf("encode: [%s] > [%s]\n--------\n", enc, buf);
	}

	return 0;
}

