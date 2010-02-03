#include <iostream>
#include "fifo/lifo.cpp"
#include "fifo/fifo.cpp"
#include "fifo/node.cpp"
#include "fifo/fo.cpp"
#include "fifo/printit.cpp"
#include "fifo/ll.cpp"
#include "dotest.cpp"
#include "fifo/OutOfBoundsException.cpp"

int main(int argc, char* argv[])
{
	std::cout << "Test results return code is: " << doTest() << "\n";
}
