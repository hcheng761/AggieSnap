#include "std_lib_facilities_3.h"
#include "Instruction_window.h"
#include "Title_window.h"
#include "input_window.h"
#include "global_variables.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

const string i1 = "Instructions for use of AggieSnap";
const string i2 = "Enter a URL that begins with http:// and ends with one of the accepted extensions ie. .jpg .gif ";
const string i3 = "To open a picture from your library just type the name of the photo you want to open followed by the extension ie. tamu.jpg";
const string i4 = "To retrieve your picture click either File or URL";
const string i5 = "If you would like to Tag using any of the accompanied tags just click on which relate to your photo";
const string i6 = "The program will automatically save in your library as whatever you put in the save as spot when you click File or URL";
const string i7 = "After picking the tags you want on your picture be sure to select the save button so they save to the picture";
const string i8 = "";

Instruction_window::Instruction_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
	back_button(Point(0,0), 70, 20, "Previous", cb_back),
	p1(Point(300,100),i1),
	p2(Point(100,150),i2),
	p3(Point(100,200),i3),
	p4(Point(100,250),i4),
	p5(Point(100,300),i5),
	p6(Point(100,350),i6),
	p7(Point(100,400),i7),
	p8(Point(100,450),i8),
	
	
    button_pushed(false)
{
	p1.set_font_size(30);
	p1.set_color(Color::blue);
	attach(p1);
	p2.set_font_size(15);
	p2.set_color(Color::blue);
	attach(p2);
	p3.set_font_size(15);
	p3.set_color(Color::blue);
	attach(p3);
	p4.set_font_size(15);
	p4.set_color(Color::blue);
	attach(p4);
	p5.set_font_size(15);
	p5.set_color(Color::blue);
	attach(p5);
	p6.set_font_size(15);
	p6.set_color(Color::blue);
	attach(p6);
	p7.set_font_size(15);
	p7.set_color(Color::blue);
	attach(p7);
	p8.set_font_size(15);
	p8.set_color(Color::blue);
	attach(p8);
	
	
	
	
	
    attach(next_button);
	attach(back_button);
}


//------------------------------------------------------------------------------

bool Instruction_window::wait_for_button()
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

void Instruction_window::cb_next(Address, Address pw)
{  
    reference_to<Instruction_window>(pw).next();    
}

//------------------------------------------------------------------------------

void Instruction_window::cb_back(Address, Address pw)
{  
    reference_to<Instruction_window>(pw).back();    
}

//------------------------------------------------------------------------------

void Instruction_window::next()
{
	
    button_pushed = true;
    hide();
	input_window win(Point(200,200),600,400,"Options");
	win.wait_for_button();
	
}

//------------------------------------------------------------------------------

void Instruction_window::back()
{
    button_pushed = true;
    hide();
    Title_window win(Point(100,50),800,600,"Title");
	win.wait_for_button();
}
