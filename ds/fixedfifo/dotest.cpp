#include <iostream>
#include <err.h>
#include "dotest.h"
#include "boolnode.h"
#include "fixedFifo.h"
/*
 *	try initilization copy and copy constructor
*/

/* all functions return 0 on success and non-zero otherwise */

/* t_ == test */
BoolNode<int> t_bnode;
FixedFifo t_ffifo(10);

/* m_ == magic */
const int m_bnode_data = 5;
const int m_ffo_nodata = -1;

void test_bnode_data(void)
{
	t_bnode.setValue(m_bnode_data);
	CU_ASSERT_EQUAL(t_bnode.getValue(), m_bnode_data);
}

void test_bnode_active(void)
{
	CU_ASSERT_EQUAL(t_bnode.getValue(), m_bnode_data);
}

void test_fixedfifo_pop(void)
{
	int i=1;
	t_ffifo.push(i++);
	t_ffifo.push(i++);
	t_ffifo.push(i++);
	CU_ASSERT_EQUAL(t_ffifo.getNumNodes(), i);
	i=1;
	/* in init we pushed 1, 2, 3 */
	CU_ASSERT_EQUAL(t_ffifo.pop(), i++);
	CU_ASSERT_EQUAL(t_ffifo.pop(), i++);
	CU_ASSERT_EQUAL(t_ffifo.pop(), i++);
	CU_ASSERT_EQUAL(t_ffifo.getNumNodes(), 0);
//	CU_ASSERT_EQUAL(t_ffifo.pop(), m_fo_nodata);
//	i++;
}

void test_fixedfifo_pushpop(void)
{
	t_ffifo.push(6);
	CU_ASSERT_EQUAL(t_ffifo.pop(), 6);
}


void test_fixedfifo_hasnext(void)
{
	CU_ASSERT_FALSE(t_ffifo.hasNext());
	t_ffifo.push(12);
	CU_ASSERT_TRUE(t_ffifo.hasNext());
	(void)t_ffifo.pop();
	CU_ASSERT_FALSE(t_ffifo.hasNext());
}

int fixedFifo_doTest()
{
	/* create the registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	CU_TestInfo test_array_node[] = {
		{ "\t accepts data correctly", test_bnode_data },
		{ "\t correctly reports active status", test_bnode_active },
	  	CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_fifo[] = {
		{ "\t pops data correctly", test_fixedfifo_pop },
		{ "\t pops data correctly after new push", test_fixedfifo_pushpop },
		{ "\t hasnext works", test_fixedfifo_hasnext },
	  	CU_TEST_INFO_NULL,
	};

	CU_SuiteInfo suites[] = {
	  { "Node", NULL, NULL, test_array_node },
	  { "Fifo", NULL, NULL, test_array_fifo },
	  CU_SUITE_INFO_NULL,
	};

    CU_ErrorCode error = CU_register_suites(suites);

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
