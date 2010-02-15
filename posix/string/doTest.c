#include "doTest.h"

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
	const char* s_extend = "abcdefg";
	const char* x = "defg";
	CU_ASSERT(strcmp(s,x) < 0);
	CU_ASSERT(strcmp(x,s) > 0);
	CU_ASSERT(strcmp(s,s_extend) < 0);
}

void test_strcmp_case(void)
{
	const char* s = "abcd";
	const char* x = "ABCD";
	CU_ASSERT(strcmp(s,x) > 0);
}


void test_strncmp_match(void)
{
	const char* s = "abcd";
	const char* s_extend = "abcdefg";
	const char* x = "abcd";
	CU_ASSERT_EQUAL(0, strncmp(s,x,4));
	CU_ASSERT_EQUAL(0, strncmp(s,s_extend,4));
	CU_ASSERT_EQUAL(0, strncmp(s,x,1));
}

void test_strncmp_nomatch(void)
{
	const char* s = "abcd";
	const char* s_extend = "abcdefg";
	const char* x = "defg";
	CU_ASSERT(strncmp(s,x,6) < 0);
	CU_ASSERT(strncmp(x,s,6) > 0);
	CU_ASSERT(strncmp(s,s_extend,5) < 0 );
}


void test_strcasecmp_match(void)
{
	const char* s = "abcd";
	const char* x = "abcd";
	CU_ASSERT_EQUAL(0, strcasecmp(s,x));
}

void test_strcasecmp_mismatch(void)
{
	const char* s = "abcd";
	const char* s_extend = "abcdefg";
	const char* x = "defg";
	CU_ASSERT(strcmp(s,x) < 0);
	CU_ASSERT(strcmp(x,s) > 0);
}

void test_strcasecmp_matchcase(void)
{
	const char* s = "abcd";
	const char* x = "ABCD";
	CU_ASSERT_EQUAL(0,strcasecmp(s,x));
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
		{ "\t works", test_strlen_strings },
		{ "\t reports empty strings correctly", test_strlen_emptystring},
		{ "\t correctly finds the FIRST null", test_strlen_multinull },
		CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_strnlen[] = {
		{ "\t when N > strlen(s)", test_strnlen_greater },
		{ "\t when N < strlen(s)", test_strnlen_lesser },
		{ "\t when N == strlen(s)", test_strnlen_equal },
		{ "\t when N == 0", test_strnlen_zero },
		{ "\t when N < 0",  test_strnlen_neg },
		CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_strcmp[] = {
		{ "\t finds patterns that match", test_strcmp_match },
		{ "\t returns correct value with patterns don't match", test_strcmp_nomatch },
		{ "\t does not ignore case", test_strcmp_case },
		CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_strncmp[] = {
		{ "\t finds patterns that match", test_strncmp_match },
		{ "\t returns correct value with patterns don't match", test_strncmp_nomatch },
		CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_strcasecmp[] = {
		{ "\t finds patterns that match", test_strcasecmp_match },
		{ "\t return correct value with patterns that don't match", test_strcasecmp_mismatch },
		{ "\t correctly ignores case", test_strcasecmp_matchcase },
		CU_TEST_INFO_NULL,
	};

	CU_SuiteInfo suites[] = {
		{"strlen", NULL, NULL, test_array_strlen },
		{"strnlen", NULL, NULL, test_array_strnlen },
		{"strcmp", NULL, NULL, test_array_strcmp },
		{"strncmp", NULL, NULL, test_array_strncmp },
		{"strcasecmp", NULL, NULL, test_array_strcasecmp },
		CU_SUITE_INFO_NULL
	};

	CU_ErrorCode error = CU_register_suites(suites);

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
