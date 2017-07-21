/*
 * gethostname.c
 *
 *  Created on: Jul 21, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#include <stdio.h>
#include <string.h>

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//#define CONF_CLI_INPUT

int main(int argc, char *argv[])
{
	int ret = 0;

	struct hostent *hp;
	struct in_addr in;
	struct sockaddr_in local_addr;

	do
	{
#ifndef CONF_CLI_INPUT
		const char host[] = "www.baidu.com";
#else
		char host[32] = { 0 };
		if (argc < 2)
		{
			perror("err> need parameter.\n");
			ret = -1;
			break;
		}
		snprintf(host, sizeof(host), "%s", argv[1]);
#endif
		hp = gethostbyname(host);
		if (!hp)
		{
			perror("err> cannot solve host.\n");
			ret = -2;
			break;
		}

		memset(&local_addr, 0, sizeof(local_addr));
		memcpy(&local_addr.sin_addr.s_addr, hp->h_addr, 4);
		in.s_addr = local_addr.sin_addr.s_addr;

		printf("Domain Name: %s\n", host);
		printf("IP address: %s\n", inet_ntoa(in));

	} while(0);

	return ret;
}

