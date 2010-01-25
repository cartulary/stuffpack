#include <sysexits.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "fifo.cpp"
#include "lifo.cpp"
#include "node.cpp"
#include "fo.cpp"

int suite_node_init(void);
int suite_node_clean(void);
int suite_fifo_init(void);
int suite_fifo_clean(void);
int suite_lifo_init(void);
int suite_lifo_clean(void);
void test_node_data(void);
void test_fifo_pop(void);
void test_lifo_pop(void);
void test_fifo_pushpop(void);
void test_lifo_pushpop(void);
void test_fifo_hasnext(void);
void test_lifo_hasnext(void);

/* all functions return 0 on success and non-zero otherwise */

Node* t_node;
Fifo* t_fifo;
Lifo* t_lifo;

int suite_node_init(void)
{
	return 0;
}

int suite_node_clean(void)
{
	return 0;
}

int suite_fifo_init(void)
{
	return 0;
}

int suite_fifo_clean(void)
{
	return 0;
}
int suite_lifo_init(void)
{
	return 0;
}

int suite_lifo_clean(void)
{
	return 0;
}


void test_node_data(void)
{
	CU_ASSERT_EQUAL(1, 1);
}

void test_fifo_pop(void)
{
}

void test_lifo_pop(void)
{
}

void test_fifo_pushpop(void)
{
}

void test_lifo_pushpop(void)
{
}

void test_fifo_hasnext(void)
{
}

void test_lifo_hasnext(void)
{
}



int main(void)
{
	CU_pSuite node_suite = NULL;
	CU_pSuite fifo_suite = NULL;
	CU_pSuite lifo_suite = NULL;

	/* create the registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	/* add the strlen suite */
	node_suite = CU_add_suite("node",suite_node_init, suite_node_clean);
	fifo_suite = CU_add_suite("fifo",suite_fifo_init, suite_fifo_clean);
	lifo_suite = CU_add_suite("lifo",suite_lifo_init, suite_lifo_clean);
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
	/*if (NULL == CU_add_test(lifo_suite, "push newdata and pop it", test_lifo_pushpop))
	{
		std::cout << "t5";
		CU_cleanup_registry();
		return CU_get_error();
	}*/

	if (NULL == CU_add_test(fifo_suite, "test of strlen", test_fifo_hasnext))
	{
		std::cout << "t6";
		CU_cleanup_registry();
		return CU_get_error();
	}
	if (NULL == CU_add_test(lifo_suite, "test of strlen", test_lifo_hasnext))
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
