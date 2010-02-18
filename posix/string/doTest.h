#ifdef REAL_STRING
    #include <string.h>
#else
    #include "./string.c"
#endif

#include <sysexits.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>


void test_strlen_strings(void);
void test_strlen_emptystring(void);
void test_strlen_multinull(void);

void test_strnlen_greater(void);
void test_strnlen_equeal(void);
void test_strnlen_lesser(void);
void test_strnlen_zero(void);
void test_strnlen_neg(void);

void test_strcmp_match(void);
void test_strcmp_match(void);
void test_strncmp_nomatch(void);
void test_strncmp_nomatch(void);

void test_strcasecmp_match(void);
void test_strcasecmp_mismatch(void);
void test_strcasecmp_matchcase(void);

void test_strncasecmp_match(void);
void test_strncasecmp_mismatch(void);
void test_strncasecmp_matchcase(void);

