
#ifndef TITLE_WINDOW_GUARD
#define TITLE_WINDOW_GUARD 1

#include "GUI.h"    
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------
struct Title_window : Graph_lib::Window {
    Title_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop
	

private:
    Button next_button;     
	//Button back_button;
    bool button_pushed;     
	Text p1;
	Text p2;
	Text p3;
	Text p4;
	Text p5;
	Text p6;
	
	

    static void cb_next(Address, Address);
    void next();       
	//static void cb_back(Address, Address);
    //void back();           

};

//------------------------------------------------------------------------------

#endif // TITLE_WINDOW_GUARD
