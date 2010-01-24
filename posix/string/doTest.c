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

/* This is the initilization function for testing strlen*/
int suite_strlen_init(void)
{
	return 0;
}

int suite_strlen_clean(void)
{
	return 0;
}

void test_strlen_strings(void)
{
	const char* s = "abcd";
	const int s_size = 4;
	CU_ASSERT_EQUAL(1, strlen("A"));
	CU_ASSERT_EQUAL(s_size, s);
}

void test_strlen_emptystring(void)
{
	const char* s="";
	CU_ASSERT_EQUAL(0, strlen(""));
	CU_ASSERT_EQUAL(0, strlen(s));
}

int main(void)
{
	CU_pSuite pSuite = NULL;

	/* create the registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	/* add the strlen suite */
	pSuite = CU_add_suite("strlen",suite_strlen_init, suite_strlen_clean);
	if (NULL == pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(pSuite, "test of strlen", test_strlen_strings))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	if (NULL == CU_add_test(pSuite, "test of strlen-empty", test_strlen_emptystring))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}