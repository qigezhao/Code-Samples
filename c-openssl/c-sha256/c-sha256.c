/*
 * c-sha256.c
 *
 *  Created on: Jul 24, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#include <stdio.h>
#include <string.h>

#include "qz-sha256.h"

int main(void)
{
	char enc[] = "Hello World!";
	unsigned char hash[128] = { 0 };

	qz_hmac_sha256(enc, strlen(enc), hash);
	printf("> SHA256(%s) = %s\n", enc, hash);

	return 0;
}

