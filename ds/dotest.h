#ifndef DOTEST_H
#define DOTEST_H
#include <sysexits.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <iostream>
#include "fifo/fifo.h"
#include "fifo/lifo.h"
#include "fifo/node.h"
#include "fifo/fo.h"
#include "fifo/ll.h"
#include "fifo/OutOfBoundsException.h"

int doTest(void);
int suite_node_init(void);
int suite_node_clean(void);
void test_node_data(void);
void test_fifo_pop(void);
void test_lifo_pop(void);
void test_fifo_pushpop(void);
void test_lifo_pushpop(void);
void test_fifo_hasnext(void);
void test_lifo_hasnext(void);
void test_fifo_numnodes(void);
void test_lifo_numnodes(void);
void test_ll_works(void);
void test_ll_operators(void);
void test_ll_clear(void);
void test_ll_except(void);
void test_ll_swap(void);
void test_ll_copy(void);
#endif