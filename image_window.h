
#ifndef IMAGE_WINDOW_GUARD
#define IMAGE_WINDOW_GUARD 1

#include "GUI.h"    
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------
struct image_window : Graph_lib::Window {
    image_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop
	

private:
    Button next_button;     
	Button back_button;
    bool button_pushed;     
	Image i1;
	
	

    static void cb_next(Address, Address);
    void next();       
	static void cb_back(Address, Address);
    void back();           

};

//------------------------------------------------------------------------------

#endif // IMAGE_WINDOW_GUARD
