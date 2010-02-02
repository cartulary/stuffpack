#include <iostream>
#include "lifo.cpp"
#include "fifo.cpp"
#include "node.cpp"
#include "fo.cpp"
#include "printit.cpp"
#include "ll.cpp"
#include "dotest.cpp"
#include "OutOfBoundsException.cpp"

int main(int argc, char* argv[])
{
//goto skiptests;
	std::cout << "Test results return code is: " << doTest() << "\n\n\n\n";
	if (argc > 1)
	{
		if (!strcmp("-y",argv[1]))
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
skiptests:
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
	std::cout << mylifo.getNumNodes() << " nodes left\n";
	std::cout << "==printall==\n";
	mylifo.printAll();
	std::cout << "==popprint==\n";
	mylifo.printAll(true);

	std::cout << "\n\n---- FIFO ----\n\n";

    Fifo<int> myfifo;
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
	std::cout << myfifo.getNumNodes() << " nodes left\n";
	std::cout << "==printall==\n";
	myfifo.printAll();
	std::cout << "==popprint==\n";
	myfifo.printAll(true);

	std::cout << "\n\n-=--LL----\n\n";
	Ll<int> myll;
	std::cout << "pushing 1\n";
	myll.push(1);
	std::cout << "pushing 2\n";
	myll.push(2);
	std::cout << "pushing 3\n";
	myll.push(3);
	std::cout << "popping - should be 1 2 3\n";
	std::cout << myll.read(0) << myll.read(1) << myll.read(2);
	std::cout << "\npushing 4 as new 2nd item\n";
	myll.push(4,1);
	std::cout << "\nreading 2nd item\n";
	std::cout << myll.read(1);
	std::cout << "\nreading 4nd item\n";
	std::cout << myll.read(3);
	std::cout << "\nreading all\n";\
	myll.printAll();
	std::cout << "removing 3rd item\n";
	myll.remove(2);
	std::cout << "\nreading all\n";
	myll.printAll();
	std::cout << '\n';
    return 0;

}
