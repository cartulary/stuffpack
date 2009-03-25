// classes.cxx (example 3a)

#include <iostream>
#include <stdlib.h>
#include "../hanoi.cpp"
#include "inputWindow.cpp"
int main(int argc, char ** argv)
{
	SliderWindow window1("Pick a number");
	window1.show(argc,argv);
	return run();
}
