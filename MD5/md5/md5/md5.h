
#ifndef MD5_H
#define MD5_H


typedef struct
{
	unsigned int count[2];
	unsigned int state[4];
	unsigned char buffer[64];
}MD5;


void initMd5(MD5 *context);
void updateMd5(MD5 *context, unsigned char *input, unsigned int inputlen);
void finalMd5(MD5 *context, unsigned char digest[16]);


#endif

