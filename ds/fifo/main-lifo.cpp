#include <iostream>
#include "lifo.cpp"
#include "node.cpp"
#include "fo.cpp"
int main(void)
{
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
	return 0;
}
