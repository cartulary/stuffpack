#include <sysexits.h>
#include "./string.h"
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

int strcasecmp(const char *s1, const char *s2)
{
	int pos;
	char c1;
	char c2;
	// as long as we have not reached the end of the string continue moving
	for (pos = 0; s1[pos] != '\0' || s2[pos] != '\0'; ++pos)
	{
		c1 = tolower(s1[pos]);
		c2 = tolower(s2[pos]);
		if (c1 != c2)
		{
			return c1 - c2;
		}
	}
	// we got to the end of a string and they are equal
	return 0;
}

int strncasecmp(const char *s1, const char *s2, size_t len)
{
	size_t pos;
	char c1;
	char c2;
	for (pos = 0; s1[pos] != '\0' && s2[pos] != '\0' && pos < len; ++pos)
	{
		c1 = tolower(s1[pos]);
		c2 = tolower(s2[pos]);
		if (c1 != c2)
		{
			// return at the end
			break;
		}
	}
	// we got to the end of a string and they are so far equal
	if (len == pos)
	{
		++pos;
	}
	//we can't use the optimization we used for strcmp as we may have differen
	// sized strings..
	//Instead we use a "break" optimization
	return c1 - c2;
}

int strcmp(const char* s1, const char* s2)
{
	unsigned int pos;
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
	size_t pos;
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

/*
	tested: true
*/
size_t strlen(const char* s)
{
	size_t i;
	for (i=0; s[i] != (char)0; ++i){}
	// Return the number of characters BEFORE the null
	return i;
}

size_t strnlen(const char* s, size_t maxlen)
{
	size_t i;
	for (i=0; s[i]!=0; ++i)
	{
		if (i == maxlen)
		{
			break;
		}
	}
	// Return the number of characters BEFORE the null
	// except if it greater than maxlen - if so return maxlen..
	return i;
}

// Use strcpy to do the copying then do my own return */
char* stpcpy(char* dst, const char* src)
{
	size_t len = strlen(dst);
	strcpy(dst, src);
	return &dst[len];
}

char* strcpy(char* dst, const char* src)
{
	int i;
	for (i=0; src[i] != 0; ++i)
	{
		dst[i]=src[i];
	}
	return dst;
}

char* strncpy(char* dst, const char* src, size_t len)
{
	size_t i;
	for (i=0; src[i] != 0 && i < len; ++i)
	{
		dst[i]=src[i];
	}
	return dst;
}

// FIX THIS CODE
char* index(const char *s, int c)
{
	int i;
	for (i=0; i != 0 && i!=(char)c; ++i)
	{
	}
	//return the matching character...
	//return NULL if not found
	if (s[i] == (char)c)
	{
		return &s[i];
	}
	return NULL;
}

// FIX THIS CODE
// start from end...
char* rindex(const char *s, int c)
{
	int i;
	for (i=strlen(s); i >=0 && i!=(char)c; --i)
	{
		//printf("(r) i=%d; strlen(s)=%d; s[i]=%c\n", i, strlen(s), s[i]);
	}
	//return the matching character...
	//return NULL if not found
	if (s[i] == (char)c)
	{
		//printf("(r) We found %d\n", i);
		return &s[i];
	}
	//printf("(r) null\n");
	return NULL;
}

char* strcat(char* restrict s, const char* restrict append)
{
	size_t sLen = strlen(s);
	for (size_t i=sLen; i < strlen(append); ++i)
	{
		s[sLen+i] = append[i];
	}
	return NULL;
}

char* strncat(char* restrict s, const char* restrict append, size_t len)
{
	size_t sLen = strlen(s);
	size_t i;
	for (i=sLen; i < strlen(append) && i<=len; ++i)
	{
		s[sLen+i] = append[i];
	}
	s[sLen+i+1] = 0;
	return NULL;
}

/* it seems from the man page that strchr==index and strrchr==index */
inline char* strchr(const char *s, int c)
{
	return index(s,c);
}

inline char* strrchr(const char *s, int c)
{
	return rindex(s,c);
}
