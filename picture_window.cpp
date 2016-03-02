#include "std_lib_facilities_3.h"
#include "picture_window.h"
#include "input_window.h"
#include "image_window.h"
#include "global_variables.h"
#include <vector>
// MW CHANGES ----------------------------------
#include <iostream>
#include <string>
// ---------------------------------------------

using namespace Graph_lib;

//------------------------------------------------------------------------------

picture_window::picture_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
	back_button(Point(0,0), 70, 20, "Previous", cb_back),
	// MW Changes to add tags: -----------------------------------------
	find_button(Point(505,50), 50, 25, "View", cb_find),
	all_button(Point(505,80),40,25, "All", cb_all),
	pic_tags(Point(150,110),300,25,""),
	tags(Point(150,50),300,25,"Tags"),
	//enter_tags(Point(455,160),50,25,"Enter",cb_tag),
	clr(Point(455,50),50,25,"Clear",cb_clr),		//Button for manually clearing the tags, 2.0!
	
	family_button(Point(150,80),50,20, "Family", cb_family),
	friends_button(Point(210,80),50,20, "Friends", cb_friends),
	aggieland_button(Point(270,80),70,20, "Aggieland", cb_aggieland),
	pets_button(Point(350,80),40,20, "Pets", cb_pets),
	vacation_button(Point(400,80),60,20, "Vacation", cb_vacation),
	
	// -----------------------------------------------------------------

   button_pushed(false)
{
    //attach(next_button);
	//attach(back_button);
	
	// MW CHANGE ------------------------------------------------
	attach(find_button);
	attach(all_button);
	//attach(pic_tags);
	attach(tags);
	attach(clr);		// change 2.0!
	// attach(enter_tags);
	
	attach(family_button);
	attach(friends_button);
	attach(aggieland_button);
	attach(pets_button);
	attach(vacation_button);
	
	// ----------------------------------------------------------

}


//------------------------------------------------------------------------------

bool picture_window::wait_for_button()
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

void picture_window::cb_next(Address, Address pw)
{  
    reference_to<picture_window>(pw).next();    
}

//------------------------------------------------------------------------------

void picture_window::cb_back(Address, Address pw)
{  
    reference_to<picture_window>(pw).back();    
}

//------------------------------------------------------------------------------

void picture_window::next()
{
    button_pushed = true;
    //hide();
	
}

//------------------------------------------------------------------------------

void picture_window::back()
{
    button_pushed = true;
   // hide();
}


// MW CHANGES -------------------------------------------------------
// To find changes
void picture_window::cb_clr(Address, Address pw)	// CHANGE 2.0!
{  
    reference_to<picture_window>(pw).clear();    
}

void picture_window::cb_find(Address, Address pw)
{
	reference_to<picture_window>(pw).find();
}

void picture_window::cb_all(Address, Address pw)
{  
    reference_to<picture_window>(pw).all();    
}

// To change tags
/*
void picture_window::cb_tag(Address, Address pw)
{  
    reference_to<picture_window>(pw).in_tag();    
}
*/
void picture_window::cb_family(Address, Address pw)
{  
    reference_to<picture_window>(pw).family();    
}

void picture_window::cb_friends(Address, Address pw)
{  
    reference_to<picture_window>(pw).friends();    
}

void picture_window::cb_aggieland(Address, Address pw)
{  
    reference_to<picture_window>(pw).aggieland();    
}

void picture_window::cb_pets(Address, Address pw)
{  
    reference_to<picture_window>(pw).pets();    
}

void picture_window::cb_vacation(Address, Address pw)
{  
    reference_to<picture_window>(pw).vacation();    
}

// END MW CHANGE ------------------
// MW CHANGE ------------------------------------------------------------------------------
/*
void picture_window::in_tag()	// function to read tag inputs
{
	button_pushed = true;
}	
*/
void picture_window::family()	// function to print tag
{
	if (Tagsname.find("Family,") != string::npos)	// reads to see if Family is in outbox
	{	
		
		Tagsname.replace(Tagsname.find("Family,"), 7, "");	// erases Family
		tags.put(Tagsname);	// removes Family from tags outbox
		--num_com;
		
	}
	else
	{	
		Tagsname = Tagsname + "Family,";	// else, adds Family to tags
		tags.put(Tagsname);
		++num_com;
		
	}
	button_pushed = true;
}	

void picture_window::friends()	// function to print tag
{
	if (Tagsname.find("Friends,") != string::npos)
	{	
		Tagsname.replace(Tagsname.find("Friends,"), 8, "");
		tags.put(Tagsname);
		--num_com;
	}
	else
	{	
		Tagsname = Tagsname + "Friends,";
		tags.put(Tagsname);
		++num_com;
	}
	button_pushed = true;
}	

void picture_window::aggieland()	// function to print tag
{
	if (Tagsname.find("Aggieland,") != string::npos)
	{	
		Tagsname.replace(Tagsname.find("Aggieland,"), 10, "");
		tags.put(Tagsname);
		--num_com;
	}
	else
	{	
		Tagsname = Tagsname + "Aggieland,";
		tags.put(Tagsname);
		++num_com;
	}
	button_pushed = true;
}	

void picture_window::pets()	// function to print tag
{
	if (Tagsname.find("Pets,") != string::npos)
	{	
		Tagsname.replace(Tagsname.find("Pets,"), 5, "");
		tags.put(Tagsname);
		--num_com;
	}
	else
	{	
		Tagsname = Tagsname + "Pets,";
		tags.put(Tagsname);
		++num_com;
	}
	button_pushed = true;
}	

void picture_window::vacation()	// function to print tag
{
	if (Tagsname.find("Vacation,") != string::npos)
	{	
		Tagsname.replace(Tagsname.find("Vacation,"), 9, "");
		tags.put(Tagsname);
		--num_com;
	}
	else
	{	
		Tagsname = Tagsname + "Vacation,";
		tags.put(Tagsname);
		++num_com;
	}
	button_pushed = true;
}	

void picture_window::find()
{	
	
	find_picture(Tagsname);
	list_count=0;
	image_window win(Point(200,200),800,300,p_list[list_count]+": "+t_list[list_count]);
	win.wait_for_button();
	button_pushed = true;
}

void picture_window::all()
{	
	view_all();
	list_count=0;
	image_window win(Point(200,200),800,300,p_list[list_count]+": "+t_list[list_count]);
	win.wait_for_button();
	button_pushed = true;
}

void picture_window::clear()		//this allows the tags to be cleared 
{
	// MW CHANGE 2.0 -----------------------
	Tagsname = "";
	num_com=0;
	tags.put("");
	// END MW CHANGE -------------------
	button_pushed = true;
}
//------------------------------------------------------------------------------
// END MW CHANGE ---------------------

