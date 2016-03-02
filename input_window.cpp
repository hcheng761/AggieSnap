#include "std_lib_facilities_3.h"
#include "input_window.h"
#include "Instruction_window.h"
#include "picture_window.h"
#include "edit_window.h"
#include <iostream>
#include <fstream>
#include <string>
#include "global_variables.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

	

input_window::input_window(Point xy, int w, int h, const string& title) 
    :Window(xy,w,h,title),
	//next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
	back_button(Point(0,0), 70, 20, "Previous", cb_back),
	inbox(Point(150,100),300,25,"Enter File or URL"),
	newPicname(Point(150,75),300,25,"Save as"),
	outbox(Point(150,50),300,25,"Saved as"),	//used for conformation
	outbox2(Point(150,50),300,25,"Error"),	//used for errors
	clr(Point(455,100),50,25,"Clear",cb_clr),		//Button for manually clearing the In_box and Out_box fields
    file_button(Point(175,130), 100, 20, "File", cb_file),
	url_button(Point(335,130), 100, 20, "URL", cb_url),
	save_button(Point(270,215),60,20, "Save", cb_save),
	view_pic(Point(175,280), 100, 20, "View Pictures", cb_view),
	edit_pic(Point(335,280), 100, 20, "Edit Pictures", cb_edit),
	
	// MW Changes to add tags: -----------------------------------------
	tags(Point(150,160),300,25,"Tags"),
	//enter_tags(Point(455,160),50,25,"Enter",cb_tag),
	
	family_button(Point(150,190),50,20, "Family", cb_family),
	friends_button(Point(210,190),50,20, "Friends", cb_friends),
	aggieland_button(Point(270,190),70,20, "Aggieland", cb_aggieland),
	pets_button(Point(350,190),40,20, "Pets", cb_pets),
	vacation_button(Point(400,190),60,20, "Vacation", cb_vacation),
	
	// -----------------------------------------------------------------

	
    button_pushed(false)
{
	attach(clr);
    attach(file_button);
	attach(url_button);
	attach(inbox);
	attach(outbox);
	attach(outbox2);
	attach(newPicname);
	attach(save_button);
	attach(back_button);
	attach(view_pic);
	attach(edit_pic);
	outbox.hide();
	outbox2.hide();
		
	// MW CHANGE ------------------------------------------------
	attach(tags);
	// attach(enter_tags);
	
	attach(family_button);
	attach(friends_button);
	attach(aggieland_button);
	attach(pets_button);
	attach(vacation_button);
	
}
 

//------------------------------------------------



//------------------------------------------------------------------------------

bool input_window::wait_for_button()
{
    show();
    button_pushed = false;
#if 0
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
       Fl::run();
#endif
    return button_pushed;
}

//---------------Call_Back Functions---------------------------------------------------------------

void input_window::cb_file(Address, Address pw)
{  
    reference_to<input_window>(pw).in_file();    
}

void input_window::cb_url(Address, Address pw)
{  
    reference_to<input_window>(pw).in_url();    
}

void input_window::cb_clr(Address, Address pw)
{  
    reference_to<input_window>(pw).clear();    
}

void input_window::cb_save(Address, Address pw)
{  
    reference_to<input_window>(pw).save();    
}

void input_window::cb_back(Address, Address pw)
{  
    reference_to<input_window>(pw).back();    
}
void input_window::cb_view(Address, Address pw)
{  
    reference_to<input_window>(pw).view();    
}
void input_window::cb_edit(Address, Address pw)
{  
    reference_to<input_window>(pw).edit();    
}

// MW CHANGES -------------------------------------------------------
/*
void input_window::cb_tag(Address, Address pw)
{  
    reference_to<input_window>(pw).in_tag();    
}
*/
void input_window::cb_family(Address, Address pw)
{  
    reference_to<input_window>(pw).family();    
}

void input_window::cb_friends(Address, Address pw)
{  
    reference_to<input_window>(pw).friends();    
}

void input_window::cb_aggieland(Address, Address pw)
{  
    reference_to<input_window>(pw).aggieland();    
}

void input_window::cb_pets(Address, Address pw)
{  
    reference_to<input_window>(pw).pets();    
}

void input_window::cb_vacation(Address, Address pw)
{  
    reference_to<input_window>(pw).vacation();    
}

// END MW CHANGE ------------------

//------------------------------------------------------------------------------

bool check_file(string s)		//checks if the input file name is a valid name
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

//------------------------------------------------------------------------------

bool check_url(string s)		//checks if the input url is a valid url
{	
	ext_val="";
	string h="http://";
	int a = s.size()-3;
	int b = s.size()-4;
	if(s.find(h)==0)
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

//----------------Button Functions--------------------------------------------------------------

void input_window::in_file()	//File button's functions
{
	outbox.put("");
	outbox.hide();
	outbox2.put("");
	outbox2.hide();
	file_val="";
	Picname="";
	file_val=inbox.get_string();		//retrieves the file name of the picture to be copied
	Picname=newPicname.get_string();	//retrieves the new user defined name for the new picture
	if(Picname=="")
	Picname="New_Picture";
	if(check_file(file_val)==true)		//checks if the input file name is a valid name
	{
		outbox.show();
		Picname = Picname + "." + ext_val;		//adds the extension of the retrieved picture to the new picture name
		outbox.put(Picname);
		string command = "cp -u " + file_val + " " + Picname;
			system(command.c_str());
		//string display = "display " + Picname;
		//	system(display.c_str());
	}
	else
	{
		outbox2.show();
		outbox2.put("Invalid File");
	}
	button_pushed = true;
}

//------------------------------------------------------------------------------

void input_window::in_url()		//URL button's functions
{	
	outbox.put("");
	outbox.hide();
	outbox2.put("");
	outbox2.hide();
	url_val="";
	Picname="";
	url_val=inbox.get_string();			//retrieves the url of the picture to be copied
	Picname=newPicname.get_string();	//retrieves the new user defined name for the new picture
	if(Picname=="")
	Picname="New_Picture";
	if(check_url(url_val)==true)		//checks if the input url is a valid url
	{
		outbox.show();
		Picname = Picname + "." + ext_val;		//adds the extension of the retrieved picture to the new picture name
		outbox.put(Picname);
		string command = "wget " + url_val + " -O " + Picname;		//Linux command for retrieving a file from a url
		system(command.c_str());
		//string display = "display " + Picname;		//displays the picture so the user can verify whether it is the right picture
		//system(display.c_str());
	}
	else 
	{
		outbox2.show();
		outbox2.put("Invalid URL");	
	}
    button_pushed = true;
}

//------------------------------------------------------------------------------

// MW CHANGE ------------------------------------------------------------------------------
/*
void input_window::in_tag()	// function to read tag inputs
{
	button_pushed = true;
}	
*/
void input_window::family()	// function to print tag
{
	if (Tagsname.find("Family,") != string::npos)	// reads to see if Family is in outbox
	{	
		// ATTN: HOWARD CHENG!
		/*
			For problems where you browse by tag, you can
			use this format.
			
			(Tagsname.find("stuff")!=string::npos means "stuff"
			is found in the output box. Make sure to attach
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
void input_window::friends()	// function to print tag
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
void input_window::aggieland()	// function to print tag
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
void input_window::pets()	// function to print tag
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
void input_window::vacation()	// function to print tag
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

// END MW CHANGE ---------------------

void input_window::save()
{  
	
	add_pic(Picname, Tagsname);
	sync_file();
	set_tags(Tagsname, Picname);
	tags.put("Saved");
	button_pushed = true;
}

void input_window::clear()		//had to modify the GUI.h and GUI.cpp
{								//this allows the In_box(s) and Out_box(s) to be cleared 
	outbox.put("");
	outbox.hide();
	outbox2.put("");
	outbox2.hide();
	url_val="";
	file_val="";
	Picname="";
	inbox.put("");				//I added the put() function for an In_box. Found in GUI.h and GUI.cpp
	newPicname.put("");
	
	// MW CHANGE -----------------------
	tags.put("");
	Tagsname="";
	// END MW CHANGE -------------------
	button_pushed = true;
}
//------------------------------------------------------------------------------

void input_window::back()
{
    button_pushed = true;
    hide();
	Instruction_window win(Point(100,50),800,600,"Instructions");
	win.wait_for_button();
}

void input_window::view()
{
    button_pushed = true;
   // hide();
	picture_window win(Point(200,200),600,250,"Library");
	win.wait_for_button();
}

void input_window::edit()
{
    button_pushed = true;
    //hide();
	edit_window win(Point(200,200),600,250,"Edit Pictures");
	win.wait_for_button();
}
