#include <iostream>
#include "lifo.cpp"
int main(void)
{
	Lifo mylifo;

	mylifo.push(1);
	mylifo.push(2);
	mylifo.push(3);
	std::cout << mylifo.pop() << mylifo.pop() << mylifo.pop() << '\n';
	mylifo.push(4);
	std::cout << mylifo.pop() << '\n';
	return 0;
}
