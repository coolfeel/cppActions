#pragma warning(disable:4996)£»

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "md5.h"

#ifndef bool
typedef enum
{
	false,
	true
}bool;
#endif

int main(int argc, char *argv[])
{
	bool is_file = false;
	unsigned char decrypt[16];
	MD5 md5;

	if (argc > 1 && strlen(argv[1]) == 2 && !memcmp(argv[1], "-f", 2))
	{
		is_file = true;
	}

	if (argc == 1 || (argc == 2 && is_file))
	{
		fprintf(stderr, "usage:\n    %s -f file ...\n    %s string ...\n", argv[0], argv[0]);
		return 1;
	}


	if (is_file)
	{
		FILE *fp;
		fp = fopen(argv[2], "rb");
		
		if (fp == NULL)
		{
			fprintf(stderr, "File %s not exists, errno = %d, error = %s\n", argv[2], errno, strerror(errno));
		}

		initMd5(&md5);
		
		do
		{
			unsigned char encrypt[1024];
			while (!feof(fp))
			{
				updateMd5(&md5, encrypt, fread(encrypt, 1, sizeof(encrypt), fp));
			}
			fclose(fp);
		} while (0);
		
		finalMd5(&md5, decrypt);

		for (int i = 0; i < 16; i++) 
		{
			printf("%02x", decrypt[i]);
		}

		printf("  %s\n", argv[2]);

		//d0b8c5f6473e0489edaaf939395395ed  F : \\study\\Projects\\cppProjects\\cppActions\\MD5\\md5\\x64\\Debug\\test.txt
	}
	
	return 0;
}
