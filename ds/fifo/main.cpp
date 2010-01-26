#include <iostream>
#include "lifo.cpp"
#include "fifo.cpp"
#include "node.cpp"
#include "fo.cpp"
#include "printit.cpp"
int main(void)
{
	std::cout << "---- LIFO ----\n\n";

	Lifo<int> mylifo;

	std::cout << "pushing 1,2,3\n";
	mylifo.push(1);
	mylifo.push(2);
	mylifo.push(3);
	std::cout << mylifo.pop() << mylifo.pop() << mylifo.pop() << '\n';
	mylifo.push(4);
	std::cout << mylifo.pop() << '\n';
	mylifo.push(9);
	mylifo.push(10);
	mylifo.push(11);
	std::cout << "==printall==\n";
	mylifo.printAll();
	std::cout << "==popprint==\n";
	mylifo.printAll(true);

	std::cout << "\n\n---- FIFO ----\n\n";

    Fifo myfifo;
	std::cout << "pushing 1,2,3\n";
    myfifo.push(1);
    myfifo.push(2);
    myfifo.push(3);
    std::cout << myfifo.pop() << myfifo.pop() << myfifo.pop() << '\n';
    myfifo.push(4);
    std::cout << myfifo.pop() << '\n';
	myfifo.push(9);
	myfifo.push(10);
	myfifo.push(11);
	std::cout << "==printall==\n";
	myfifo.printAll();
	std::cout << "==popprint==\n";
	myfifo.printAll(true);
    return 0;

}
