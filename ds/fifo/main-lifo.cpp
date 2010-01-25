#include <iostream>
#include "fifo.cpp"
int main(void)
{
	Fifo myfifo;

	myfifo.push(1);
	myfifo.push(2);
	myfifo.push(3);
	std::cout << myfifo.pop() << myfifo.pop() << myfifo.pop() << '\n';
	myfifo.push(4);
	std::cout << myfifo.pop() << '\n';
	return 0;
}
