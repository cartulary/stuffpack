#include <iostream>
#include "dotest.h"
#include "lifo.h"
#include "fifo.h"
#include "ll.h"
#include "sorted.h"
#include "OutOfBoundsException.h"
#include "DuplicateEntry.h"

/*
 *	try initilization copy and copy constructor
*/

/* all functions return 0 on success and non-zero otherwise */

/* t_ == test */
Node<int>* t_node;
Fifo<int> t_fifo;
Lifo<int> t_lifo;
LinkedList<int> myll;
Sorted<int> t_sorted;

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

void test_node_f_data(void)
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
	myll.remove(0);
	//LL now looks like 4 12
	CU_ASSERT_EQUAL(myll.read(0),4);
	CU_ASSERT_EQUAL(myll.read(1),12);
	CU_ASSERT_EQUAL(myll.getNumNodes(),2);
}

//This gets run after works();
void test_ll_operators(void)
{
	//The [] operator assumes we are sane so don't bother testing undefuned values
	CU_ASSERT_EQUAL(myll[0],4);
	CU_ASSERT_EQUAL(myll[1],12);
	//Test both sane and insane values
	CU_ASSERT_EQUAL(myll(0),4);
	CU_ASSERT_EQUAL(myll(1),12);
	bool did_catch_outofbounds_exception = false;
	try {
		CU_ASSERT_EQUAL(myll(myll.getNumNodes()+1),4);
	}
	catch (OutOfBoundsException e){
		did_catch_outofbounds_exception = true;
	}
	CU_ASSERT_TRUE(did_catch_outofbounds_exception);
}


void test_ll_clear(void)
{
	myll.clear();
	CU_ASSERT_EQUAL(myll.getNumNodes(),0);
}

void test_ll_except(void)
{
	bool did_catch_read_exception = false;
	try
	{
		myll.read(0);
	}
	catch(OutOfBoundsException& e)
	{
		did_catch_read_exception = true;
	}
	CU_ASSERT_TRUE(did_catch_read_exception);

	did_catch_read_exception = false;
	try
	{
		myll.read(10);
	}
	catch(OutOfBoundsException& e)
	{
		did_catch_read_exception = true;
	}
	CU_ASSERT_TRUE(did_catch_read_exception);

	myll.push(1);
	myll.push(2);
	myll.push(3);
	bool did_catch_push_exception = false;
	try
	{
		myll.push(10,500);
	}
	catch(OutOfBoundsException& e)
	{
		did_catch_push_exception = true;
	}
	CU_ASSERT_TRUE(did_catch_push_exception);

	bool did_catch_swap_exception = false;
	try
	{
		myll.swap(0,45);
	}
	catch(OutOfBoundsException& e)
	{
		did_catch_swap_exception = true;
	}
	CU_ASSERT_TRUE(did_catch_swap_exception)

	did_catch_swap_exception = false;
	try
	{
		myll.swap(45,0);
	}
	catch(OutOfBoundsException& e)
	{
		did_catch_swap_exception = true;
	}
	CU_ASSERT_TRUE(did_catch_swap_exception)

	/*
		Create test for swap bound exceptions
	*/
}

void test_ll_swap(void)
{
//	myll.clear();
	myll.push(1);
	myll.push(2);
	myll.push(3);
	myll.push(4);
	myll.push(5);
	/* Array now looks like 1 2 3 4 5*/
	myll.swap(0,2);
	/* Array now looks like 3 2 1 4 5*/
	CU_ASSERT_EQUAL(myll.read(0), 3);
	CU_ASSERT_EQUAL(myll.read(1), 2);
	CU_ASSERT_EQUAL(myll.read(2), 1);
	CU_ASSERT_EQUAL(myll.read(3), 4);
	CU_ASSERT_EQUAL(myll.read(4), 5);
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

void test_sorted_read(void)
{
	/* perhaps we should also warn when data is out of order on a (data,location) push ?*/
	t_sorted.push(2);
	t_sorted.push(1);
	t_sorted.push(3);
	t_sorted.push(7);
	t_sorted.push(5);
	t_sorted.push(6);
	t_sorted.push(4);

	CU_ASSERT_EQUAL(t_sorted.read(0), 1);
	CU_ASSERT_EQUAL(t_sorted.read(1), 2);
	CU_ASSERT_EQUAL(t_sorted.read(2), 3);
	CU_ASSERT_EQUAL(t_sorted.read(3), 4);
	CU_ASSERT_EQUAL(t_sorted.read(4), 5);
	CU_ASSERT_EQUAL(t_sorted.read(5), 6);
	CU_ASSERT_EQUAL(t_sorted.read(6), 7);
}

void test_sorted_duplicate(void)
{
	/* test high number */
	bool did_catch_duplicate_exception = false;
	try
	{
		t_sorted.push(1000);
		t_sorted.push(1000);
	}
	catch(DuplicateEntryException& e)
	{
		did_catch_duplicate_exception = true;
	}
	CU_ASSERT_TRUE(did_catch_duplicate_exception);

	/* test head */
	did_catch_duplicate_exception = false;
	try
	{
		t_sorted.push(1);
	}
	catch(DuplicateEntryException& e)
	{
		did_catch_duplicate_exception = true;
	}
	CU_ASSERT_TRUE(did_catch_duplicate_exception);
}

void test_ll_copy(void)
{
	myll.clear();
	myll.push(1);
	CU_ASSERT_EQUAL(1,myll.read(0));
	LinkedList<int> icopyll = myll;
	CU_ASSERT_EQUAL(1,myll.read(0));
	CU_ASSERT_EQUAL(1,icopyll.read(0));

	icopyll.remove(0);
	CU_ASSERT_TRUE(myll.has(1));
	CU_ASSERT_FALSE(icopyll.has(1));

	LinkedList<int> copyll;
	copyll = myll;
	CU_ASSERT_EQUAL(1,myll.read(0));
	CU_ASSERT_EQUAL(1,copyll.read(0));

	copyll.remove(0);
	CU_ASSERT_TRUE(myll.has(1));
	CU_ASSERT_FALSE(copyll.has(1));


}

int fifo_doTest(void)
{
	/* create the registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	CU_TestInfo test_array_node[] = {
		{ "\t accepts data correctly", test_node_f_data },
	  	CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_fifo[] = {
		{ "\t pops data correctly", test_fifo_pop },
		{ "\t pops data correctly after new push", test_fifo_pushpop },
		{ "\t hasnext works", test_fifo_hasnext },
	  	CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_lifo[] = {
		{ "\t pops data correctly", test_lifo_pop },
		{ "\t pops data correctly after new push", test_lifo_pushpop },
		{ "\t hasnext works", test_lifo_hasnext },
	  	CU_TEST_INFO_NULL,
	};
	CU_TestInfo test_array_ll[] = {
		{ "\t can accept data and get data from any point", test_ll_works},
		{ "\t operators work as expected", test_ll_operators },
		{ "\t clear() clears all elements", test_ll_clear },
		{ "\t exceptions work", test_ll_except },
		{ "\t swapping works", test_ll_swap },
		{ "\t copying array works; modifying new data does not affect old data", test_ll_copy },
	  	CU_TEST_INFO_NULL,
	};

	CU_TestInfo test_array_sorted[] = {
		{ "\t pushes data in correct order", test_sorted_read },
		{ "\t returns exception on duplicate entry", test_sorted_duplicate },
	  	CU_TEST_INFO_NULL,
	};

	CU_SuiteInfo suites[] = {
	  { "Node", suite_node_init, suite_node_clean, test_array_node },
	  { "Fifo", NULL, NULL, test_array_fifo },
	  { "Lifo", NULL, NULL, test_array_lifo },
	  { "LinkedList", NULL, NULL, test_array_ll },
	  { "Sorted LinkedLink", NULL, NULL, test_array_sorted },
	  CU_SUITE_INFO_NULL,
	};


	CU_ErrorCode error = CU_register_suites(suites);

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
