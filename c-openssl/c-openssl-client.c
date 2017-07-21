/*
 * https-client.c
 *
 *  Created on: Jul 17, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <openssl/err.h>
#include <openssl/ssl.h>

#include "ipv4.h"

#define DST_URL "www.baidu.com"
//#define DST_URL "192.168.1.2"
#define DST_PORT 443

int main(void)
{
	int ret = 0, bytes_tx = 0, bytes_rx = 0;

	int socket_fd;
	struct sockaddr_in sa_server;

	SSL_CTX *ctx = NULL;
	SSL *ssl = NULL;
	X509 *cert = NULL;

	char buffer[1024], data[128] = { 0 };
	snprintf(data, sizeof(data), "GET / HTTP/1.1\nHost: %s\n\n", DST_URL);

	do
	{
		socket_fd = socket(AF_INET, SOCK_STREAM, 0);
		if (socket_fd < 0)
		{
			perror("err> bind local socket failed.\n");
			ret = -1;
			break;
		}

		memset(&sa_server, 0, sizeof(sa_server));
		sa_server.sin_family = AF_INET;
		sa_server.sin_port = htons(DST_PORT);
		sa_server.sin_addr.s_addr = inet_addr(qz_gethostbyname(DST_URL));

		if (connect(socket_fd, (struct sockaddr *) &sa_server, sizeof(struct sockaddr)) < 0)
		{
			perror("err> connect to peer failed.\n");
			ret = -2;
			break;
		}

		printf("> Connected.\n");

		// SSL take over
		SSL_load_error_strings();
		SSL_library_init();

		ctx = SSL_CTX_new(SSLv23_client_method());
		if (ctx == NULL)
		{
			perror("err> cannot init SSL handshake.\n");
			ret = -3;
			break;
		}

		ssl = SSL_new(ctx);
		SSL_set_fd(ssl, socket_fd);
		if (SSL_connect(ssl) < 0)
		{
			perror("err> cannot start SSL comm.\n");
			ret = -4;
			break;
		}

		cert = SSL_get_peer_certificate(ssl);
		if (cert == NULL)
		{
			perror("err> unknown certificate.\n");
			ret = -5;
			break;
		}

		printf("> SSL encrypted. Line is secure.\n");

		bytes_tx = SSL_write(ssl, data, strlen(data));
		if (bytes_tx < 1)
		{
			printf("err> cannot send request.\n");
			ret = -6;
			break;
		}

		printf("> SSL_write (%d bytes sent).\n", bytes_tx);

		memset(buffer, 0, sizeof(buffer));
		bytes_rx = SSL_read(ssl, buffer, sizeof(buffer));

		printf("> SSL_read (%d bytes received).\n", bytes_rx);

		/*
		int ssl_err = SSL_get_error(ssl, bytes_rx);
		int ssl_bytes_rx_left = SSL_pending(bytes_rx);
		*/

	} while(FALSE);

	SSL_shutdown(ssl);
	SSL_free(ssl);
	SSL_CTX_free(ctx);
	close(socket_fd);

	return ret;
}

