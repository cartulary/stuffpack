#include <sysexits.h>
#include "./string.h"
#include <stddef.h>
#include <stdio.h>
int main(void)
{
	const char* hello="hello";
	const char* bello="bello";
	const char* hello2="hello";
	char cArr[6], cArr2[6], cArr3[10];

	// This will be replaced with cunit soon.... a real unit testing system
	printf("Strcmp: %d\n", strcmp(hello,bello));
	printf("StrNcmp: %d\n", strncmp(hello,bello,3));
	printf("Strlen: %d\n", strlen(hello));
	//printf("StrNlen: %d\n", strnlen(hello,3));
	(void)strncpy(cArr, "12345", sizeof(cArr));
	(void)strncpy(cArr2, "1234567890", sizeof(cArr2));
	printf("StrNcpy: %s && %s\n", cArr, cArr2);
	return EX_OK;
}

int strcmp(const char* s1, const char* s2)
{
	int pos;
	// as long as we have not reached the end of the string continue moving
	for (pos = 0; s1[pos] != '\0' || s2[pos] != '\0'; ++pos)
	{
		if (s1[pos] != s2[pos])
		{
			return s1[pos] - s2[pos];
		}
	}
	// we got to the end of a string and they are equal
	return 0;
}

int strncmp(const char* s1, const char* s2, size_t len)
{
	int pos;
	for (pos = 0; s1[pos] != '\0' && s2[pos] != '\0' && pos < len; ++pos)
	{
		if (s1[pos] != s2[pos])
		{
			return s1[pos] - s2[pos];
		}
	}
	// we got to the end of a string and they are so far equal
	if (len == pos)
	{
		++pos;
	}
	//we can't use the optimization we used for strcmp as we may have differen
	// sized strings..
	return s1[pos] - s2[pos];
}

size_t strlen(const char* s)
{
	int i;
	for (i=0; s[i]!=0; ++i){}
	// Return the number of characters BEFORE the null
	return i;
}
/*
size_t strnlen(const char* s, size_t maxlen)
{
	int i;
	for (i=0; s[i]!=0; ++i){}
	/* Return the number of characters BEFORE the null
	   except if it greater than maxlen - if so return maxlen..
	*//*
	return (i > maxlen) ? maxlen : i;
}*/

char* strcpy(char* dst, const char* src)
{
	for (int i=0; src[i] != 0; ++i)
	{
		dst[i]=src[i];
	}
	return dst;
}

char* strncpy(char* dst, const char* src, size_t len)
{
	for (int i=0; src[i] != 0 && i < len; ++i)
	{
		dst[i]=src[i];
	}
	return dst;
}
