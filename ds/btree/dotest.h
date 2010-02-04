#ifndef DOTEST_H
#define DOTEST_H
#include <sysexits.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <iostream>
#include "node.h"
#include "btree.h"

int doTest(void);
int suite_node_init(void);
int suite_node_clean(void);
int suite_btree_init(void);
int suite_btree_clean(void);
void test_node_ptrs(void);
void test_node_data(void);
void test_btree_add(void);
void test_btree_remove(void);
void test_btree_numnodes(void);
void test_btree_clear(void);
#endif
