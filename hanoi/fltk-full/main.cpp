// classes.cxx (example 3a)

#include <fltk/run.h>
#include <fltk/Window.h>
#include <fltk/Slider.h>
#include <fltk/Button.h>
#include <fltk/IntInput.h>
#include <fltk/ask.h>
#include <fltk/TextDisplay.h>

#include <iostream>
#include <stdlib.h>

using namespace fltk;

int main(int argc, char* argv[])
{
	TextDisplay* text = new TextDisplay(10,10,10,10,"hi");
	text->begin();
	text->show();
  	return fltk::run();

	return 0;
}