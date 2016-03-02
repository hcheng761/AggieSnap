#include "std_lib_facilities_3.h"
#include "image_window.h"
#include "picture_window.h"
#include "global_variables.h"

using namespace Graph_lib;


//------------------------------------------------------------------------------

image_window::image_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
	back_button(Point(0,0), 70, 20, "Previous", cb_back),
	i1(Point(50,50),p_list[list_count]),
    button_pushed(false)
{
	attach(i1);
    attach(next_button);
	attach(back_button);
}


//------------------------------------------------------------------------------

bool image_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;
#if 0
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void image_window::cb_next(Address, Address pw)
{  
    reference_to<image_window>(pw).next();    
}

//------------------------------------------------------------------------------

void image_window::cb_back(Address, Address pw)
{  
    reference_to<image_window>(pw).back();    
}

//------------------------------------------------------------------------------

void image_window::next()
{
    hide();
	++list_count;
	if(list_count<p_list.size()){
	image_window win(Point(200,200),800,300,p_list[list_count]+": "+t_list[list_count]);
	win.wait_for_button();
	}
	//else
	//hide();
	button_pushed = true;
   
}

//------------------------------------------------------------------------------

void image_window::back()
{
	hide();
	--list_count;
	if(list_count>=0){
	image_window win(Point(200,200),800,300,p_list[list_count]+": "+t_list[list_count]);
	win.wait_for_button();
	}
	//else
	//hide();
	button_pushed = true;
    
}
