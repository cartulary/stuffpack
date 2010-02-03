#include "dotest.h"

MultiNode* t_mn;

void test_node_ptrs(void)
{
	t_mn = new MultiNode(0,2);
	CU_ASSERT_PTR_NULL(t_mn->ptrs[0]);
	CU_ASSERT_PTR_NULL(t_mn->ptrs[1]);
}

void test_node_data(void)
{
	CU_ASSERT_EQUAL(t_mn->data,0);
	t_mn->data = 1;
	CU_ASSERT_EQUAL(t_mn->data,1);
}


int doTest(void)
{
	/* create the registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	CU_TestInfo test_array_node[] = {
		{ "node accepts multiple pointers correctly", test_node_ptrs },
		{ "node accepts data correctly", test_node_data },
	  	CU_TEST_INFO_NULL,
	};

	CU_SuiteInfo suites[] = {
	  { "node", NULL, NULL, test_array_node },
	  CU_SUITE_INFO_NULL,
	};

	CU_ErrorCode error = CU_register_suites(suites);

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
