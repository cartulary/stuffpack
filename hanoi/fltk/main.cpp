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
			/*
				Since we are moving toward making this one unified system
				lets tru and get this to be like the other versions.
				Only ask once.  Once we have answer get out of the loop.
			*/
			break;
		}
	}
	Hanoi(hanoiVal,'a','b','c');
	pickNumberWindow.resetHanoi();

	return 0;
}
