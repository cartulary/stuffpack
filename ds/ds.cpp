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
#include "fixedfifo/fixedFifo.cpp"
#include "fixedfifo/dotest.cpp"
#include "fixedfifo/boolnode.cpp"

#include "btree/DataNotExistException.cpp"

int main(void)
{
	std::cout << "Test results return code is: " << btree_doTest() << "\n";
	std::cout << "Test results return code is: " << fifo_doTest() << "\n";
	std::cout << "Test results return code is: " << fixedFifo_doTest() << "\n";
	return 0;
}
