
#ifndef PICTURE_WINDOW_GUARD
#define PICTURE_WINDOW_GUARD 1

#include "GUI.h"    
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------
struct picture_window : Graph_lib::Window {
    picture_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop
	
	// MW EDIT ---------
	string Tagsname;		//finds previous tag input by user
	// END EDIT --------
	

private:
    Button next_button;     // the "next" button
	Button back_button;
	
	// MW CHANGE ---------------------------------------
	Button clr;				// clears tags	2.0!
	Button find_button;		// find button
	Button all_button;
	Out_box tags;
	Out_box pic_tags;
	// Button enter_tags;
	
	Button family_button;	// buttons for tags
	Button friends_button;
	Button aggieland_button;
	Button pets_button;
	Button vacation_button;
	
	// --------------------------------------------------
	
    bool button_pushed;     // implementation detail

    static void cb_next(Address, Address);
    void next();       
	static void cb_back(Address, Address);
    void back();           

	// MW CHANGES ------------------------------
	static void cb_find(Address, Address);	// find button
	void find();
	static void cb_all(Address, Address);	
	void all();
	static void cb_clr(Address, Address); 	// clear button 2.0!
	void clear();
	
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

#endif // PICTURE_WINDOW_GUARD
