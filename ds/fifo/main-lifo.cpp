#include <iostream>
#include "lifo.cpp"
#include "fifo.cpp"
#include "node.cpp"
#include "fo.cpp"
int main(void)
{
	std::cout << "---- LIFO ----\n\n";

	Lifo mylifo;

	mylifo.push(1);
	mylifo.push(2);
	mylifo.push(3);
	std::cout << mylifo.pop() << mylifo.pop() << mylifo.pop() << '\n';
	mylifo.push(4);
	std::cout << mylifo.pop() << '\n';
	mylifo.push(9);
	mylifo.push(10);
	mylifo.push(11);
	mylifo.printAll();

	std::cout << "\n\n---- FIFO ----\n\n";

    Fifo myfifo;

    myfifo.push(1);
    myfifo.push(2);
    myfifo.push(3);
    std::cout << myfifo.pop() << myfifo.pop() << myfifo.pop() << '\n';
    myfifo.push(4);
    std::cout << myfifo.pop() << '\n';
    return 0;

}
