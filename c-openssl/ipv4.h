/*
 * ipv4.h
 *
 *  Created on: Jul 21, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#ifndef IPV4_H_
#define IPV4_H_

#define FALSE			NULL
#define QZ_DEBUG(str)	perror(str)

char *qz_ipstring(void *ip_bytes);
char *qz_gethostbyname(const char *name);

#endif /* IPV4_H_ */

