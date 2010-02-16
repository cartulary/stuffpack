#include <iostream>
#include "btree/dotest.cpp"
#include "btree/btree.cpp"
#include "btree/node.cpp"
#include "fifo/dotest.cpp"
#include "fifo/node.cpp"
#include "fifo/lifo.cpp"
#include "fifo/fifo.cpp"
#include "fifo/OutOfBoundsException.cpp"
#include "fifo/DuplicateEntry.cpp"
#include "fifo/fo.cpp"
#include "fifo/printit.cpp"
#include "fifo/ll.cpp"
#include "fifo/sorted.cpp"

int main(void)
{
	std::cout << "Test results return code is: " << btree_doTest() << "\n";
	return 0;
	std::cout << "Test results return code is: " << fifo_doTest() << "\n";
	return 0;
}
