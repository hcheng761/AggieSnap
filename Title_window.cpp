#include "std_lib_facilities_3.h"
#include "Title_window.h"
#include "Instruction_window.h"

using namespace Graph_lib;


//------------------------------------------------------------------------------

const string t1 = "AggieSnap Project";
const string t2 = "ENGR 112-507";
const string t3 = "Howard Cheng";
const string t4 = "Connor Collins";
const string t5 = "Travis Stewart";
const string t6 = "Minda Wei";


Title_window::Title_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
	//back_button(Point(0,0), 70, 20, "Previous", cb_back),
	p1(Point(300,100),t1),
	p2(Point(315,130),t2),
	p3(Point(315,170),t3),
	p4(Point(315,200),t4),
	p5(Point(315,230),t5),
	p6(Point(315,260),t6),
    button_pushed(false)
{
	p1.set_font_size(30);
	attach(p1);
	p2.set_font_size(30);
	attach(p2);
	p3.set_font_size(28);
	attach(p3);
	p4.set_font_size(28);
	attach(p4);
	p5.set_font_size(28);
	attach(p5);
	p6.set_font_size(28);
	attach(p6);
    attach(next_button);
	//attach(back_button);
}


//------------------------------------------------------------------------------

bool Title_window::wait_for_button()
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

void Title_window::cb_next(Address, Address pw)
{  
    reference_to<Title_window>(pw).next();    
}

//------------------------------------------------------------------------------
/*
void Title_window::cb_back(Address, Address pw)
{  
    reference_to<Title_window>(pw).back();    
}
*/
//------------------------------------------------------------------------------

void Title_window::next()
{
    button_pushed = true;
    hide();
	Instruction_window win(Point(100,50),1000,600,"Instructions");
	win.wait_for_button();
}

//------------------------------------------------------------------------------
/*
void Title_window::back()
{
    button_pushed = true;
   // hide();
}
*/