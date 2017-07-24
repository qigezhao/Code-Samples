/*
 * main.c
 *
 *  Created on: Jul 24, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#include <stdio.h>
#include <string.h>

#include "qz-iconv.h"

int main(void)
{
	char *url = "https://git.io/vMoco/";
	char *gb = "正在安装";
	char buf[128] = { 0 };

	int url_len = strlen(url);
	int gb_len = strlen(gb);
	int buf_len = sizeof(buf);

	if (ascii_to_utf8(url, url_len, buf, buf_len) < 0)
	{
		printf("1> charset convert failed.\n");
	} else {
		printf("1> charset convert successfully.\n");
	}

	if (utf8_to_gb(gb, gb_len, buf, buf_len) < 0)
	{
		printf("2> charset convert failed.\n");
	} else {
		printf("2> charset convert successfully.\n");
	}
	return 0;
}

