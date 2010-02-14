#include "doTest.h"
#ifdef REAL_STRING
	#include <string.h>
#else
	#include "./string.c"
#endif
#include <sysexits.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_strnlen_greater(void);
void test_strnlen_equeal(void);
void test_strnlen_lesser(void);
void test_strnlen_zero(void);
void test_strnlen_neg(void);

void test_strcmp_works(void);

void test_strlen_strings(void)
{
	const char* s = "abcd";
	const int s_size = 4;
	CU_ASSERT_EQUAL(1, strlen("A"));
	CU_ASSERT_EQUAL(s_size, strlen(s));
}

void test_strlen_emptystring(void)
{
	const char* s="";
	CU_ASSERT_EQUAL(0, strlen(""));
	CU_ASSERT_EQUAL(0, strlen(s));
}

void test_strlen_multinull(void)
{
	const char a[5] = {0,'a',0,0,0};
	const char b[5] = {0,0,0,0,0};
	const char c[5] = {'a',0,0,0,0};

	CU_ASSERT_EQUAL(strlen(a), 0);
	CU_ASSERT_EQUAL(strlen(b), 0);
	CU_ASSERT_EQUAL(strlen(c), 1);
}

void test_strnlen_greater(void)
{
	const char* s = "abcd";
	const int s_size = 4;
	CU_ASSERT_EQUAL(1, strnlen("A", 10));
	CU_ASSERT_EQUAL(s_size, strnlen(s, 10));
}

void test_strnlen_lesser(void)
{
	const char* s = "abcd";
	const int s_size = 4;
	const int max_size = 3;
	CU_ASSERT_EQUAL(0, strnlen("A", 0));
	CU_ASSERT_EQUAL(max_size, strnlen(s, max_size));
}

void test_strnlen_equal(void)
{
	const char* s = "abcd";
	const int s_size = 4;
	CU_ASSERT_EQUAL(1, strnlen("A", 1));
	CU_ASSERT_EQUAL(s_size, strnlen(s, s_size));
}

void test_strnlen_zero(void)
{
	const char* s = "abcd";
	const int s_size = 4;
	CU_ASSERT_EQUAL(0, strnlen("A", 0));
	CU_ASSERT_EQUAL(0, strnlen(s, 0));
}

void test_strnlen_neg(void)
{
	const char* s = "abcd";
	const int s_size = 4;
	CU_ASSERT_EQUAL(1, strnlen("A", -1));
	CU_ASSERT_EQUAL(s_size, strnlen(s, -1));
}

void test_strcmp_match(void)
{
	const char* s = "abcd";
	const char* x = "abcd";
	CU_ASSERT_EQUAL(0, strcmp(s,x));
}

void test_strcmp_nomatch(void)
{
	const char* s = "abcd";
	const char* x = "defg";
	CU_ASSERT(strcmp(s,x) < 0);
	CU_ASSERT(strcmp(x,s) > 0);
}

int main(void)
{
#ifdef REAL_STRING == 1
	printf("We are testing for realz");
#endif

	/* create the registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	CU_TestInfo test_array_strlen[] = {
		{ "test of strlen", test_strlen_strings },
		{ "strlen reports empty strings correctly", test_strlen_emptystring},
		{ "strlen correctly finds the FIRST null", test_strlen_multinull },
		CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_strnlen[] = {
		{ "test of strnlen when N > strlen(s)", test_strnlen_greater },
		{ "test of strnlen when N < strlen(s)", test_strnlen_lesser },
		{ "test of strnlen when N == strlen(s)", test_strnlen_equal },
		{ "test of strnlen when N == 0", test_strnlen_zero },
		{ "test of strnlen when N < 0",  test_strnlen_neg },
		CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_strcmp[] = {
		{ "strcmp finds patterns that match", test_strcmp_match },
		{ "strcmp returns correct value with patterns don't match", test_strcmp_nomatch },
		CU_TEST_INFO_NULL,
	};

	CU_SuiteInfo suites[] = {
		{"strlen", NULL, NULL, test_array_strlen },
		{"strnlen", NULL, NULL, test_array_strnlen },
		{"strcmp", NULL, NULL, test_array_strcmp },
		CU_SUITE_INFO_NULL
	};

	CU_ErrorCode error = CU_register_suites(suites);

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
