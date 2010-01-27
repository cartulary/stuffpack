#include <iostream>
#include "dotest.h"

/* all functions return 0 on success and non-zero otherwise */

/* t_ == test */
Node<int>* t_node;
Node<int>* t_nodes[10];
Fifo<int> t_fifo;
Fifo<int>* t_fifos[10];
Lifo<int> t_lifo;
Lifo<int>* t_lifos[10];

/* m_ == magic */
const int m_node_data = 5;
const int m_fo_nodata = -1;

int suite_node_init(void)
{
	t_node = new Node<int>(m_node_data);
	t_node->next = NULL;
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

int suite_fifo_init(void)
{
	return 0;
}

int suite_fifo_clean(void)
{
	return 0;
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

int suite_lifo_init(void)
{
	return 0;
}

int suite_lifo_clean(void)
{
	return 0;

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
}

void test_lifo_pushpop(void)
{
    t_lifo.push(4);
	CU_ASSERT_EQUAL(t_lifo.pop(),4);
}

void test_lifo_hasnext(void)
{
	t_lifo.push(1);
	CU_ASSERT_TRUE(t_lifo.hasNext());
	(void)t_lifo.pop();
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
	CU_pSuite node_suite = NULL;
	CU_pSuite fifo_suite = NULL;
	CU_pSuite lifo_suite = NULL;
	CU_pSuite ll_suite = NULL;

	/* create the registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	node_suite = CU_add_suite("node",suite_node_init, suite_node_clean);
	fifo_suite = CU_add_suite("fifo",suite_fifo_init, suite_fifo_clean);
	lifo_suite = CU_add_suite("lifo",suite_lifo_init, suite_lifo_clean);
	ll_suite = CU_add_suite("linkedlist",suite_lifo_init, suite_lifo_clean);
	if (NULL == node_suite)
	{
		std::cout << "node";
		CU_cleanup_registry();
		return CU_get_error();
	}
	if (NULL == fifo_suite)
	{
		std::cout << "fifo";
		CU_cleanup_registry();
		return CU_get_error();
	}
	if (NULL == lifo_suite)
	{
		std::cout << "lifo";
		CU_cleanup_registry();
		return CU_get_error();
	}
	if (NULL == ll_suite)
	{
		std::cout << "linkedlist";
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(node_suite, "node accepts data correctly", test_node_data))
	{
		std::cout << "t1";
		CU_cleanup_registry();
		return CU_get_error();
	}
	if (NULL == CU_add_test(fifo_suite, "pop the data we pushed in init", test_fifo_pop))
	{
		std::cout << "t2";
		CU_cleanup_registry();
		return CU_get_error();
	}
	if (NULL == CU_add_test(fifo_suite, "push newdata and pop it", test_fifo_pushpop))
	{
		std::cout << "t3";
		CU_cleanup_registry();
		return CU_get_error();
	}
	if (NULL == CU_add_test(lifo_suite, "push newdata and pop it", test_lifo_pop))
	{
		std::cout << "t4";
		CU_cleanup_registry();
		return CU_get_error();
	}
	if (NULL == CU_add_test(ll_suite, "linked list can accept data and get data from any point", test_ll_works))
	{
		std::cout << "t4";
		CU_cleanup_registry();
		return CU_get_error();
	}
	/*if (NULL == CU_add_test(lifo_suite, "push newdata and pop it", test_lifo_pushpop))
	{
		std::cout << "t5";
		CU_cleanup_registry();
		return CU_get_error();
	}*/

	if (NULL == CU_add_test(fifo_suite, "fifo hasnext works ", test_fifo_hasnext))
	{
		std::cout << "t6";
		CU_cleanup_registry();
		return CU_get_error();
	}
	if (NULL == CU_add_test(ll_suite, "lifo hasnext works", test_lifo_hasnext))
	{
		std::cout << "t7";
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
