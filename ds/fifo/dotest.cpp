#include <iostream>
#include "dotest.h"
#include "OutOfBoundsException.h"

/* all functions return 0 on success and non-zero otherwise */

/* t_ == test */
Node<int>* t_node;
Fifo<int> t_fifo;
Lifo<int> t_lifo;
Ll<int> myll;

/* m_ == magic */
const int m_node_data = 5;
const int m_fo_nodata = -1;

int suite_node_init(void)
{
	t_node = new Node<int>(m_node_data);
	return 0;
}

int suite_node_clean(void)
{
	delete t_node;
	return 0;
}

void test_node_data(void)
{
	CU_ASSERT_EQUAL(t_node->data, m_node_data);
}

void test_fifo_pop(void)
{
	int i=1;
	t_fifo.push(i++);
	t_fifo.push(i++);
	t_fifo.push(i++);
	i=1;
	/* in init we pushed 1, 2, 3 */
	CU_ASSERT_EQUAL(t_fifo.pop(), i++);
	CU_ASSERT_EQUAL(t_fifo.pop(), i++);
	CU_ASSERT_EQUAL(t_fifo.pop(), i++);
//	CU_ASSERT_EQUAL(t_fifo.pop(), m_fo_nodata);
//	i++;
}

void test_fifo_pushpop(void)
{
	t_fifo.push(6);
	CU_ASSERT_EQUAL(t_fifo.pop(), 6);
}


void test_fifo_hasnext(void)
{
	CU_ASSERT_FALSE(t_fifo.hasNext());
	t_fifo.push(12);
	CU_ASSERT_TRUE(t_fifo.hasNext());
	(void)t_fifo.pop();
	CU_ASSERT_FALSE(t_fifo.hasNext());
}

void test_lifo_pop(void)
{
	t_lifo.push(1);
    t_lifo.push(2);
    t_lifo.push(3);
	CU_ASSERT_EQUAL(t_lifo.pop(), 3);
	CU_ASSERT_EQUAL(t_lifo.pop(), 2);
	CU_ASSERT_EQUAL(t_lifo.pop(), 1);
}

void test_ll_works(void)
{
	//myll.clear();
    myll.push(10);
    myll.push(11);
    myll.push(12);
	//LL now looks like 10 11 12
	CU_ASSERT_EQUAL(myll.read(0),10);
	CU_ASSERT_EQUAL(myll.read(1),11);
	CU_ASSERT_EQUAL(myll.read(2),12);
	CU_ASSERT_EQUAL(myll.getNumNodes(),3);
    myll.push(4,1);
	//LL now looks like 10 4 11 12
	CU_ASSERT_EQUAL(myll.read(0),10);
	CU_ASSERT_EQUAL(myll.read(1),4);
	CU_ASSERT_EQUAL(myll.read(2),11);
	CU_ASSERT_EQUAL(myll.read(3),12);
	CU_ASSERT_EQUAL(myll.getNumNodes(),4);
	//LL now looks like 10 4 11 12
	//                  0  1 2  3
    myll.remove(2);
	//LL now looks like 10 4 12
	CU_ASSERT_EQUAL(myll.read(0),10);
	CU_ASSERT_EQUAL(myll.read(1),4);
	CU_ASSERT_EQUAL(myll.read(2),12);
	CU_ASSERT_EQUAL(myll.getNumNodes(),3);
}

//This gets run after works();
void test_ll_operators(void)
{
	//The [] operator assumes we are sane so don't bother testing undefuned values
	CU_ASSERT_EQUAL(myll[0],10);
	CU_ASSERT_EQUAL(myll[1],4);
	CU_ASSERT_EQUAL(myll[2],12);
}


void test_ll_clear(void)
{
	myll.clear();
	CU_ASSERT_EQUAL(myll.getNumNodes(),0);
}

void test_ll_except(void)
{
	myll.push(1);
	myll.push(2);
	myll.push(3);
	bool did_catch_exception = false;
	try
	{
		myll.push(10,500);
	}
	catch(OutOfBoundsException& e)
	{
		did_catch_exception = true;
	}
	CU_ASSERT_TRUE(did_catch_exception);
}

void test_lifo_pushpop(void)
{
    t_lifo.push(4);
	CU_ASSERT_EQUAL(t_lifo.pop(),4);
}

void test_lifo_hasnext(void)
{
	CU_ASSERT_FALSE(t_lifo.hasNext());
	t_lifo.push(12);
	CU_ASSERT_TRUE(t_lifo.hasNext());
	(void)t_lifo.pop();
	CU_ASSERT_FALSE(t_lifo.hasNext());
}

void test_lifo_numnodes(void)
{
    t_lifo.push(9);
    t_lifo.push(10);
    t_lifo.push(11);
	CU_ASSERT_EQUAL(t_lifo.getNumNodes(),3);
}


int doTest(void)
{
	/* create the registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	CU_TestInfo test_array_node[] = {
		{ "node accepts data correctly", test_node_data },
	  	CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_fifo[] = {
		{ "fifo pops data correctly", test_fifo_pop },
		{ "fifo pops data correctly after new push", test_fifo_pushpop },
		{ "fifo hasnext works", test_fifo_hasnext },
	  	CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_lifo[] = {
		{ "lifo pops data correctly", test_lifo_pop },
		{ "lifo pops data correctly after new push", test_lifo_pushpop },
		{ "lifo hasnext works", test_lifo_hasnext },
	  	CU_TEST_INFO_NULL,
	};
	CU_TestInfo test_array_ll[] = {
		{ "linked list can accept data and get data from any point", test_ll_works},
		{ "linklist operators work as expected", test_ll_operators },
		{ "linklist.clear() clears all elements", test_ll_clear },
		{ "linklist exceptions work", test_ll_except },
	  	CU_TEST_INFO_NULL,
	};

	CU_SuiteInfo suites[] = {
	  { "node", suite_node_init, suite_node_clean, test_array_node },
	  { "fifo", NULL, NULL, test_array_fifo },
	  { "lifo", NULL, NULL, test_array_lifo },
	  { "linkedlist", NULL, NULL, test_array_ll },
	  CU_SUITE_INFO_NULL,
	};

	CU_ErrorCode error = CU_register_suites(suites);

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
