#ifndef STRING_H
#define STRING_H
#include <stddef.h>
char* stpcpy(char *dst, const char *src);
/* POSIX */
char* strcat(char *s, const char *append);
/* POSIX */
char* strncat(char *s, const char *append, size_t len);
/* POSIX */
char* strchr(const char *s, int c);
/* POSIX */
char* strrchr(const char *s, int c);
/* POSIX */
int strcmp(const char *s1, const char *s2);
/* POSIX */
int strncmp(const char *s1, const char *s2, size_t len);
int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t len);
/* POSIX */
char* strcpy(char *dst, const char *src);
/* POSIX */
char * strncpy(char *dst, const char *src, size_t len);
/* POSIX */
char * strerror(int errno);
/* POSIX */
size_t strlen(const char *s);
/* POSIX */
/* Will not be implemented for now */
char* strpbrk(const char *s, const char *charset);
char* strsep(char **stringp, const char *delim);
/* POSIX */
/* Will not be implemented for now */
size_t strspn(const char *s, const char *charset);
/* POSIX */
/* Will not be implemented for now */
size_t  strcspn(const char *s, const char *charset);
/* POSIX */
char * strstr(const char *s1, const char *s2);
/* POSIX */
char * strtok(char *s, const char *delim);
char * index(const char *s, int c);
char * rindex(const char *s, int c);
 
/* NOT_IN_BSD */
/*int strnlen(const char* s, size_t maxlen);*/
#endif