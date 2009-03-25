#include <fltk/run.h>
#include <fltk/Window.h>
#include <fltk/Slider.h>
#include <fltk/Button.h>
#include <fltk/IntInput.h>
#include <fltk/ask.h>
#include <iostream>
#include <stdlib.h>
using namespace fltk;

class SliderWindow : public Window
{
	IntInput intinput;
	Button copy_button;
	Slider slider;
	Button down_button;
	Button up_button;
	Button done_button;

	static const int min_rings = 1;
	static const int max_rings = 10;

	inline void copy_callback_i()
	{
		int new_val = intinput.ivalue();
		if (new_val >= min_rings && new_val <= max_rings)
		{
			if (new_val == min_rings)
                  {
                        down_button.hide();
                  }
			else
			{
                        down_button.show();
                  }
                  if (new_val == max_rings)
                  {
                        up_button.hide();
                  }
			else
                  {
                        up_button.show();
                  }
			slider.value(intinput.ivalue());
		}
		else
		{
			alert("Please choose a number between %d and %d", min_rings, max_rings);
		}
	}

	static void copy_callback(Widget*, void* v)
	{
		((SliderWindow*)v)->copy_callback_i();
	}

	inline void down_callback_i()
	{
		int new_val = slider.value()-1;
		if (new_val >= min_rings)
		{
			slider.value(new_val);
			intinput.value(new_val);
			up_button.show();
			if (new_val == min_rings)
			{
				down_button.hide();
			}
		}
	}

	static void down_callback(Widget*, void* v)
	{
		((SliderWindow*)v)->down_callback_i();
  	}

	inline void up_callback_i()
	{
            int new_val = slider.value() + 1;
            if (new_val <= max_rings)
            {
                  slider.value(new_val);
                  intinput.value(new_val);
                  down_button.show();
                  if (new_val == max_rings)
                  {
                        up_button.hide();
                  }
            }
	}

	static void up_callback(Widget*, void* v)
	{
		((SliderWindow*)v)->up_callback_i();
	}

	inline void slider_callback_i(Slider* slider)
	{
		int new_val = slider->value();
            if (new_val == min_rings)
            {
			down_button.hide();
            }
            else
            {
			down_button.show();
            }
            if (new_val == max_rings)
            {
            	up_button.hide();
            }
            else
            {
			up_button.show();
            }
		if (new_val >= min_rings && new_val <= max_rings)
		{
			intinput.value(slider->value());
		}
		else
		{
			alert("Please choose a number between %d and %d", min_rings, max_rings);
		}
	}

	static void slider_callback(Widget* w, void* v)
	{
		((SliderWindow*)v)->slider_callback_i((Slider*)w);
  	}

	inline void done_callback_i(Widget* widget)
	{
            Hanoi(slider.value(),'a','b','c');
		std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-" << std::endl;
	}
	static void done_callback(Widget* w, void* v)
	{
            ((SliderWindow*)v)->done_callback_i(w);
	}


	public:

	SliderWindow(const char* label=0) :
	Window(USEDEFAULT,USEDEFAULT,320,90,label,true),
	intinput(10,10,100,20),
	copy_button(110,10,100,20,"copy to slider"),
	slider(10,35,300,20),
	down_button(50,60,50,20,"@270->"),
	up_button(150,60,50,20,"@90->"),
	done_button(250,60,50,20,"@>")
	{
		copy_button.callback(copy_callback,this);
		down_button.callback(down_callback,this);
		up_button.callback(up_callback,this);
		slider.callback(slider_callback,this);
		slider.set_horizontal(); slider.type(Slider::TICK_ABOVE);
		//create the slider with correct range and defaults
		slider.range(min_rings,max_rings);
		slider.step(1);
		slider.value(3);
		intinput.value(3);
		done_button.callback(done_callback,this);
		end();
	}

	~SliderWindow() {}

};
