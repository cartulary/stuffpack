#ifdef REAL_STRING
	#include <string.h>
#else
	#include "./string.c"
#endif
#include <sysexits.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int suite_strlen_init(void);
int suite_strlen_clean(void);
void test_strlen_strings(void);
void test_strlen_emptystring(void);
/* all functions return 0 on success and non-zero otherwise */

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
