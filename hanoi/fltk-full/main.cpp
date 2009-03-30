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

int main(int argc, char* argv[])
{
	fltk::TextDisplay* text = new fltk::TextDisplay(10,10,10,10,"hi");
	text->begin();
	text->show();
  	return fltk::run();
}