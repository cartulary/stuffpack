// classes.cxx (example 3a)

#include <iostream>
#include <stdlib.h>
#include "../hanoi.cpp"
#include "inputWindow.cpp"
int main(int argc, char* argv[])
{
	SliderWindow pickNumberWindow("Pick a number");
	pickNumberWindow.resetHanoi();
	pickNumberWindow.show(argc,argv);
	int hanoiVal = 0;
	while (Window::first())
	{
		wait();
		hanoiVal = pickNumberWindow.getHanoi();
		if (hanoiVal > 0)
		{
			Hanoi(hanoiVal,'a','b','c');
	            std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
			pickNumberWindow.resetHanoi();

		}
	}
	return 0;
}
