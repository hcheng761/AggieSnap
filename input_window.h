
#ifndef INPUT_WINDOW_GUARD
#define INPUT_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"


	
	
	
	
using namespace Graph_lib;

//------------------------------------------------------------------------------

struct input_window : Graph_lib::Window {
    input_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop
	
//temporary user input values 
  //These can be accessed in main() by ex: [window_name].file_val, or [window_name].url_val, ...
	string file_val;		//saves file name input by user
	string url_val;			//saves url input by user
	string Picname;			//saves new picture name input by user
	
	
	
	
	
	// MW EDIT ---------
	string Tagsname;		//saves previous tag input by user
	// END EDIT --------
	
private:
	Button clr;
    Button file_button;
	Button url_button;
	//Button next_button;
	Button back_button;
	Button view_pic;
	Button edit_pic;
	Button save_button;
	In_box inbox;
	In_box newPicname;
	Out_box outbox;
	Out_box outbox2;
	//Text retrieve;
	
	// MW CHANGE ---------------------------------------
	Out_box tags;
	// Button enter_tags;
	
	Button family_button;
	Button friends_button;
	Button aggieland_button;
	Button pets_button;
	Button vacation_button;
	
	
	
	// --------------------------------------------------
	
    bool button_pushed;     // implementation detail

    static void cb_file(Address, Address); 
	void in_file();            
	static void cb_url(Address, Address); 
	void in_url();
	static void cb_clr(Address, Address); 
	void clear();
	//static void cb_next(Address, Address); 
	//void next();
	static void cb_back(Address, Address); 
	void back();
	static void cb_view(Address, Address); 
	void view();
	static void cb_edit(Address, Address); 
	void edit();
	static void cb_save(Address, Address); 
	void save();
	
	// MW CHANGES ------------------------------
	
	// static void cb_tag(Address, Address); 
	// void in_tag();      
	static void cb_family(Address, Address); 
	void family();      
	static void cb_friends(Address, Address); 
	void friends();      
	static void cb_aggieland(Address, Address); 
	void aggieland();      
	static void cb_pets(Address, Address); 
	void pets();      
	static void cb_vacation(Address, Address); 
	void vacation();      
	// -----------------------------------------

};

//------------------------------------------------------------------------------

#endif // INPUT_WINDOW_GUARD
