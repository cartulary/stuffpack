// classes.cxx (example 3a)

#include <fltk/run.h>
#include <fltk/Window.h>
#include <fltk/Slider.h>
#include <fltk/Button.h>
#include <fltk/IntInput.h>
#include <iostream>
#include <stdlib.h>
#include "../hanoi.cpp"
using namespace fltk;

class SliderWindow : public Window
{
	IntInput intinput;
	Button copy_button;
	Slider slider;
	Button down_button;
	Button up_button;
	Button exit_button;

	inline void copy_callback_i()
	{
		slider.value(intinput.ivalue());
	}

	static void copy_callback(Widget*, void* v)
	{
		((SliderWindow*)v)->copy_callback_i();
	}

	inline void down_callback_i()
	{
		slider.value(slider.value()-1);
		intinput.value(slider.value());
	}

	static void down_callback(Widget*, void* v)
	{
		((SliderWindow*)v)->down_callback_i();
  	}

	inline void up_callback_i()
	{
		slider.value(slider.value()+1);
		intinput.value(slider.value());
	}

	static void up_callback(Widget*, void* v)
	{
		((SliderWindow*)v)->up_callback_i();
	}

	inline void slider_callback_i(Slider* slider)
	{
		intinput.value(slider->value());
		std::cout << slider->value();
	}

	static void slider_callback(Widget* w, void* v)
	{
		((SliderWindow*)v)->slider_callback_i((Slider*)w);
  	}

	inline void exit_callback_i(Widget* widget)
	{
	//	std::cout << slider.value();
            Hanoi(slider.value(),'a','b','c');
		//((Window*)widget)->hide();
		//exit(0);
	}
	static void exit_callback(Widget* w, void* v)
	{
            ((SliderWindow*)v)->exit_callback_i(w);
	}


	public:

	SliderWindow(const char* label=0) :
	Window(USEDEFAULT,USEDEFAULT,320,90,label,true),
	intinput(10,10,100,20),
	copy_button(110,10,100,20,"copy to slider"),
	slider(10,35,300,20),
	down_button(50,60,50,20,"down"),
	up_button(150,60,50,20,"up"),
	exit_button(250,60,50,20,"done")
	{
		copy_button.callback(copy_callback,this);
		down_button.callback(down_callback,this);
		up_button.callback(up_callback,this);
		slider.callback(slider_callback,this);
		slider.set_horizontal(); slider.type(Slider::TICK_ABOVE);
		slider.range(0,10);
		slider.step(1);
		slider.value(0);
		exit_button.callback(exit_callback,this);
		end();
	}

	~SliderWindow() {}

};

int main(int argc, char ** argv)
{
	SliderWindow window1("Pick a number");
	window1.show(argc,argv);
	return run();
}
