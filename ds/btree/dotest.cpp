#include "dotest.h"

MultiNode* t_mn;
BinaryTree* t_bt;

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

int suite_btree_init(void)
{
	t_bt = new BinaryTree();
	return 0;
}

int suite_btree_clean(void)
{
	delete t_bt;
	return 0;
}

void test_btree_add(void)
{
}

void test_btree_remove(void)
{
}

void test_btree_numnodes(void)
{
}

void test_btree_clear(void)
{
}

int doTest(void)
{
	/* create the registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	CU_TestInfo test_array_node[] = {
		{ "MultiNode accepts multiple pointers correctly", test_node_ptrs },
		{ "MultiNode accepts data correctly", test_node_data },
	  	CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_btree[] = {
		{ "Binary Tree adds data correctly", test_btree_add },
		{ "Binary Tree removes data correctly", test_btree_remove },
		{ "Binary Tree reports the correct number of nodes", test_btree_numnodes },
		{ "Binary Tree clears the tree on command", test_btree_clear },
	  	CU_TEST_INFO_NULL,
	};

	CU_SuiteInfo suites[] = {
	  { "MultiNode", NULL, NULL, test_array_node },
	  { "BinaryTree", suite_btree_init, suite_btree_clean, test_array_btree },
	  CU_SUITE_INFO_NULL,
	};

	CU_ErrorCode error = CU_register_suites(suites);

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
