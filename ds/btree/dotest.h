#ifndef DOTEST_H
#define DOTEST_H
#include <sysexits.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <iostream>
#include "node.h"

int doTest(void);
void test_node_ptrs(void);
void test_node_data(void);
#endif
