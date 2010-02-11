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
	const char *a = {0,"a",0,0,0};
	const char *b = {0,0,0,0,0};
	const char *c = {"a",0,0,0,0};

	CU_ASSERT_EQUAL(strlen(a), 0);
//	CU_ASSERT_EQUAL(strlen(b), 0);
//	CU_ASSERT_EQUAL(strlen(c), 1);
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

	CU_SuiteInfo suites[] = {
		{"strlen", NULL, NULL, test_array_strlen },
		CU_SUITE_INFO_NULL
	};

	CU_ErrorCode error = CU_register_suites(suites);

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
