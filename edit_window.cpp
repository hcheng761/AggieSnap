#include "std_lib_facilities_3.h"
#include "edit_window.h"
#include "input_window.h"
#include "global_variables.h"
#include <fstream>
// MW CHANGES ----------------------------------
#include <iostream>
#include <string>
// ---------------------------------------------

using namespace Graph_lib;


//------------------------------------------------------------------------------

edit_window::edit_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
	back_button(Point(0,0), 70, 20, "Previous", cb_back),
	
	// MW Changes to add tags: -----------------------------------------
	save_button(Point(x_max()-140,0), 70, 20, "Save", cb_save),
	
	tags(Point(150,160),300,25,"Tags"),
	//enter_tags(Point(455,160),50,25,"Enter",cb_tag),
	clr(Point(455,160),50,25,"Clear",cb_clr),		//Button for manually clearing the tags, 2.0!
	family_button(Point(150,190),50,20, "Family", cb_family),
	friends_button(Point(210,190),50,20, "Friends", cb_friends),
	aggieland_button(Point(270,190),70,20, "Aggieland", cb_aggieland),
	pets_button(Point(350,190),40,20, "Pets", cb_pets),
	vacation_button(Point(400,190),60,20, "Vacation", cb_vacation),
	// -----------------------------------------------------------------
	inbox(Point(150,100),300,25,"Enter Picture to Edit"),
	outbox(Point(150,75),300,25,""),	//used for conformation
	outbox2(Point(150,75),300,25,"Error"),	//used for errors
	edit_pic(Point(175,130), 100, 20, "Edit", cb_edit),
	delete_pic(Point(335,130), 100, 20, "Delete", cb_delete),
	
    button_pushed(false)
{
    //attach(next_button);
	//attach(back_button);
	
	// MW CHANGE ------------------------------------------------
	//attach(save_button);
	attach(tags);
	attach(clr);		// change 2.0!
	// attach(enter_tags);
	
	attach(family_button);
	attach(friends_button);
	attach(aggieland_button);
	attach(pets_button);
	attach(vacation_button);
	// ----------------------------------------------------------
	attach(inbox);
	attach(outbox);
	attach(outbox2);
	attach(edit_pic);
	attach(delete_pic);
	outbox.hide();
	outbox2.hide();
}


//------------------------------------------------------------------------------

bool edit_window::wait_for_button()
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

void edit_window::cb_next(Address, Address pw)
{  
    reference_to<edit_window>(pw).next();    
}

//------------------------------------------------------------------------------

void edit_window::cb_back(Address, Address pw)
{  
    reference_to<edit_window>(pw).back();    
}

//------------------------------------------------------------------------------

void edit_window::next()
{
    button_pushed = true;
    //hide();
	
}

//------------------------------------------------------------------------------

void edit_window::back()
{
    button_pushed = true;
    //hide();
   
}

// MW CHANGES -------------------------------------------------------
// To save changes
void edit_window::cb_clr(Address, Address pw)	// CHANGE 2.0!
{  
    reference_to<edit_window>(pw).clear();    
}

void edit_window::cb_save(Address, Address pw)
{
	reference_to<edit_window>(pw).save();
}

void edit_window::cb_delete(Address, Address pw)
{  
    reference_to<edit_window>(pw).del_pic();    
}

void edit_window::cb_edit(Address, Address pw)
{  
    reference_to<edit_window>(pw).edit();    
}

// To change tags
/*
void edit_window::cb_tag(Address, Address pw)
{  
    reference_to<edit_window>(pw).in_tag();    
}
*/
void edit_window::cb_family(Address, Address pw)
{  
    reference_to<edit_window>(pw).family();    
}

void edit_window::cb_friends(Address, Address pw)
{  
    reference_to<edit_window>(pw).friends();    
}

void edit_window::cb_aggieland(Address, Address pw)
{  
    reference_to<edit_window>(pw).aggieland();    
}

void edit_window::cb_pets(Address, Address pw)
{  
    reference_to<edit_window>(pw).pets();    
}

void edit_window::cb_vacation(Address, Address pw)
{  
    reference_to<edit_window>(pw).vacation();    
}

// END MW CHANGE ------------------
// MW CHANGE ------------------------------------------------------------------------------
/*
void edit_window::in_tag()	// function to read tag inputs
{
	button_pushed = true;
}	
*/
void edit_window::family()	// function to print tag
{
	if (Tagsname.find("Family,") != string::npos)	// reads to see if Family is in outbox
	{	
		// ATTN: HOWARD CHENG!
		/*
			For problems where you browse by tag, you can
			use this format.
			
			(Tagsname.find("stuff")!=string::npos means "stuff"
			is found in the output box. Make sure to include
			iostream and string up top.
		*/
		Tagsname.replace(Tagsname.find("Family,"), 7, "");	// erases Family
		tags.put(Tagsname);	// removes Family from tags outbox
	}
	else
	{	
		Tagsname = Tagsname + "Family,";	// else, adds Family to tags
		tags.put(Tagsname);
	}
	button_pushed = true;
}	

void edit_window::friends()	// function to print tag
{
	if (Tagsname.find("Friends,") != string::npos)
	{	
		Tagsname.replace(Tagsname.find("Friends,"), 8, "");
		tags.put(Tagsname);
	}
	else
	{	
		Tagsname = Tagsname + "Friends,";
		tags.put(Tagsname);
	}
	button_pushed = true;
}	

void edit_window::aggieland()	// function to print tag
{
	if (Tagsname.find("Aggieland,") != string::npos)
	{	
		Tagsname.replace(Tagsname.find("Aggieland,"), 10, "");
		tags.put(Tagsname);
	}
	else
	{	
		Tagsname = Tagsname + "Aggieland,";
		tags.put(Tagsname);
	}
	button_pushed = true;
}	

void edit_window::pets()	// function to print tag
{
	if (Tagsname.find("Pets,") != string::npos)
	{	
		Tagsname.replace(Tagsname.find("Pets,"), 5, "");
		tags.put(Tagsname);
	}
	else
	{	
		Tagsname = Tagsname + "Pets,";
		tags.put(Tagsname);
	}
	button_pushed = true;
}	

void edit_window::vacation()	// function to print tag
{
	if (Tagsname.find("Vacation,") != string::npos)
	{	
		Tagsname.replace(Tagsname.find("Vacation,"), 9, "");
		tags.put(Tagsname);
	}
	else
	{	
		Tagsname = Tagsname + "Vacation,";
		tags.put(Tagsname);
	}
	button_pushed = true;
}	

bool check_file2(string s)		//checks if the input file name is a valid name
{
	ext_val="";
	ifstream ist(s.c_str());
	int a = s.size()-3;
	int b = s.size()-4;
	if (ist) 
		for(int i =0;i<10;++i)
		{
			ext_val=ext[i];			//stores the extension of the picture for later use
			switch(i)
			{
			case 0: if(s.find(ext[i])==a) return true;
			case 1: if(s.find(ext[i])==a) return true;
			case 2: if(s.find(ext[i])==a) return true;
			case 3: if(s.find(ext[i])==a) return true;
			case 4: if(s.find(ext[i])==b) return true;
			case 5: if(s.find(ext[i])==b) return true;
			case 6: if(s.find(ext[i])==a) return true;
			case 7: if(s.find(ext[i])==a) return true;
			case 8: if(s.find(ext[i])==a) return true;
			case 9: if(s.find(ext[i])==a) return true;
			}
		}
	else 
		return false;
		
}



void edit_window::edit()	
{
	outbox.put("");
	outbox.hide();
	outbox2.put("");
	outbox2.hide();
	file_val="";
	Picname="";
	file_val=inbox.get_string();		//retrieves the file name of the picture to be copied
	Picname=file_val;	
	if(Picname=="")
	Picname="New_Picture";
	if(check_file2(file_val)==true)		//checks if the input file name is a valid name
	{
		outbox.show();
		//Picname = Picname + "." + ext_val;		//adds the extension of the retrieved picture to the new picture name
		outbox.put(Picname+" has been changed");
		//string command = "cp -u " + file_val + " " + Picname;
			//system(command.c_str());
		delete_from_index(Picname);
		add_pic(Picname,Tagsname);
		
		
	}
	else
	{
		outbox2.show();
		outbox2.put("Invalid File");
	}
	button_pushed = true;
}

void edit_window::del_pic()	
{
	outbox.put("");
	outbox.hide();
	outbox2.put("");
	outbox2.hide();
	file_val="";
	Picname="";
	file_val=inbox.get_string();		//retrieves the file name of the picture to be copied
	Picname=file_val;	
	if(Picname=="")
	Picname="New_Picture";
	if(check_file2(file_val)==true)		//checks if the input file name is a valid name
	{
		outbox.show();
		outbox.put("Deleted");
		delete_from_index(Picname);
		
		
	}
	else
	{
		outbox2.show();
		outbox2.put("Invalid File");
	}
	button_pushed = true;
}

void edit_window::save()
{
	
	button_pushed = true;
}

void edit_window::clear()		//this allows the tags to be cleared 
{
	outbox.put("");
	outbox.hide();
	outbox2.put("");
	outbox2.hide();
	file_val="";
	Picname="";
	inbox.put("");
	// MW CHANGE 2.0 -----------------------
	Tagsname = "";
	tags.put(Tagsname);
	// END MW CHANGE -------------------
	button_pushed = true;
}
//------------------------------------------------------------------------------
// END MW CHANGE ---------------------

