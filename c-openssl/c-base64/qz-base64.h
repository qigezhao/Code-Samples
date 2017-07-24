/*
 * qz-base64.h
 *
 *  Created on: Jul 24, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#ifndef QZ_BASE64_H_
#define QZ_BASE64_H_

int base64_encode(char *inbuf, int inlen, char *outbuf, int outlen);
int base64_decode(char *inbuf, int inlen, char *outbuf, int outlen);

#endif /* QZ_BASE64_H_ */

