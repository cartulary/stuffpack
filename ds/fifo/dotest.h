#ifndef DOTEST_H
#define DOTEST_H
#include <sysexits.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <iostream>
#include "fifo.h"
#include "lifo.h"
#include "node.h"
#include "fo.h"
#include "ll.h"

int doTest(void);
int suite_node_init(void);
int suite_node_clean(void);
int suite_fifo_init(void);
int suite_fifo_clean(void);
int suite_lifo_init(void);
int suite_lifo_clean(void);
int suite_ll_init(void);
int suite_ll_clean(void);
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
//TODO
void test_ll_clear(void);
#endif
