/*
 * qz-sha256.c
 *
 *  Created on: Jul 24, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#include <stdio.h>
#include <string.h>

#include <openssl/opensslconf.h>
//#include <openssh/crypto.h>
#include <openssl/sha.h>
#include <openssl/opensslv.h>

int qz_hmac_sha256(char *inbuf, int inlen, char *outbuf)
{
	int i = 0;
	unsigned char hash[SHA256_DIGEST_LENGTH] = { 0 };

	SHA256((unsigned char *) inbuf, inlen, hash);

	for(i = 0; i < SHA256_DIGEST_LENGTH; i ++)
	{
		sprintf(outbuf + (i * 2), "%02x", hash[i]);
	}

	printf("raw> [%s]\n", outbuf);
	return 0;
}

