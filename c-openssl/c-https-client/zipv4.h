/*
 * qz-ipv4.h
 *
 *  Created on: Jul 21, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#ifndef QZ_IPV4_H_
#define QZ_IPV4_H_

#define FALSE			NULL
#define QZ_DEBUG(str)	perror(str)

char *qz_gethostbyname(const char *name);

#endif /* QZ_IPV4_H_ */

