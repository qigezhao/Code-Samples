/*
 * qz-ipv4.c
 *
 *  Created on: Jul 21, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#include <stdio.h>
#include <string.h>

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "zipv4.h"

char *qz_gethostbyname(const char *hostname)
{
	static char ip[16] = { 0 };

	struct hostent *hp = NULL;
	struct in_addr in;
	struct sockaddr_in local_addr;

	do
	{
		if (hostname == NULL || strlen(hostname) < 1)
		{
			QZ_DEBUG("ipv4> (error) bad host.\n");
			break;
		}

		hp = gethostbyname(hostname);
		if (! hp)
		{
			QZ_DEBUG("ipv4> (error) cannot solve hostname.\n");
			break;
		}

		memset(&local_addr, 0, sizeof(local_addr));
		memcpy(&local_addr.sin_addr.s_addr, hp->h_addr, 4);
		in.s_addr = local_addr.sin_addr.s_addr;

		snprintf(ip, sizeof(ip), "%s", inet_ntoa(in));
	} while(NULL);

	return ip;
}
