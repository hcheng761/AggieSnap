// Created by Travis 
#include "global_variables.h"
#include "std_lib_facilities_3.h"
#include <string>
#include <iostream>
#include <vector>

const string ext[]={"gif","jpg","JPG","GIF","jpeg","JPEG","png","PNG","bmp","BMP"}; 	//accepted file extensions 
string ext_val="";
string image_name;
string check_tags[5] = {"Family","Friends","Aggieland","Pets","Vacation"};
ofstream ofs1("picture_index.txt", ios::out | ios::app);
ifstream ist1("picture_index.txt");
ofstream ofs2("temp_index.txt", ios::out | ios::app);
ifstream ist2("temp_index.txt");

	vector<string> family_list;
	vector<string> friends_list;
	vector<string> aggie_list;
	vector<string> pets_list;
	vector<string> vacation_list;
	vector<string> active_p_list;
	vector<string> active_t_list;
	vector<string> t_list;
	vector<string> p_list;
	vector<string> ch_t;
	int list_count;
	int num_com;
	vector<string> store;

void add_pic(string p,string t)		//adds the picture along with tags to the picture_index
{
	ofs1.open("picture_index.txt", ios::out | ios::app);
	ofs1<<p<<","<<t;
	ofs1<<"\r\n";
	ofs1.close();
}

void set_tags(string t, string p)	//assigns a new picture to its tag vectors
{
	for(int i=0;i<5;++i)
	{	
		
		
			switch(i)
			{
				case 0: if(t.find("Family")!=string::npos) family_list.push_back(p);
				case 1: if(t.find("Friends")!=string::npos) friends_list.push_back(p);
				case 2: if(t.find("Aggieland")!=string::npos) aggie_list.push_back(p);
				case 3: if(t.find("Pets")!=string::npos) pets_list.push_back(p);
				case 4: if(t.find("Vacation")!=string::npos) vacation_list.push_back(p);
			}
	}
}

void sync_file()		//syncs up the picture_index and the tag vectors
{
	// string temp="";
	// string p="",t="";
	// while(ist1.peek()!= char_traits<char>::eof())
	// {
	// getline(ist1,temp);
	// unsigned pos = temp.find(",");
	// p=temp.substr(0,pos);
	// pos+=1;
	// t=temp.substr(pos);
	
	// set_tags(t,p);
	//ofs1.flush();
	
	
}

void delete_from_index(string p)
{	
	
	int pos=0;
	string temp="";
	store.begin();
	while(ist1.peek()!= char_traits<char>::eof())
	{
	getline(ist1,temp);
	if(temp.find(p)==string::npos){
		store.push_back(temp);
		}
	}
	ofstream ofs3("picture_index.txt", ios::out | ios::trunc);
	for(int n=0;n<store.size();++n){
	ofs3<<store[n];
	ofs3<<"\r\n";
	}
	ofs3.close();
}

string find_tag(string s)		// finds the tags for the given picture
{
	string temp="";
	for(int n=0;n<5;++n)
	{
	switch(n)
	{
		case 0: for(int i=0;i<family_list.size();++i) if(family_list[i] == s)  temp+="Family";
		case 1: for(int i=0;i<friends_list.size();++i) if(friends_list[i] == s)  temp+="Friends";
		case 2: for(int i=0;i<aggie_list.size();++i) if(aggie_list[i] == s)  temp+="Aggieland";
		case 3: for(int i=0;i<pets_list.size();++i) if(pets_list[i] == s)  temp+="Pets";
		case 4: for(int i=0;i<vacation_list.size();++i) if(vacation_list[i] == s)  temp+="Vacation";
	}
	}
	return temp;
}

void find_picture(string s)	  // finds the pictures for the given tags
{   
	p_list.begin();
	t_list.begin();
	string t1="";
	string t2="";
	int n1=0,n2=0;
	string temp="";
	string p="",t="";
	
	switch(num_com)
	{
	case 1:{n1=s.find(","); t1=s.substr(0,n1); ch_t.push_back(t1);}
	case 2:{n1=s.find(","); t1=s.substr(0,n1); ch_t.push_back(t1);   t2=s.substr(n1); n1=t2.find(","); t1=t2.substr(0,n1); ch_t.push_back(t1);}
	case 3:{n1=s.find(","); t1=s.substr(0,n1); ch_t.push_back(t1);   t2=s.substr(n1); n1=t2.find(","); t1=t2.substr(0,n1); ch_t.push_back(t1);   t2=s.substr(n1); n1=t2.find(","); t1=t2.substr(0,n1); ch_t.push_back(t1);}
	case 4:{n1=s.find(","); t1=s.substr(0,n1); ch_t.push_back(t1);   t2=s.substr(n1); n1=t2.find(","); t1=t2.substr(0,n1); ch_t.push_back(t1);   t2=s.substr(n1); n1=t2.find(","); t1=t2.substr(0,n1); ch_t.push_back(t1);    t2=s.substr(n1); n1=t2.find(","); t1=t2.substr(0,n1); ch_t.push_back(t1);}
	case 5:{n1=s.find(","); t1=s.substr(0,n1); ch_t.push_back(t1);   t2=s.substr(n1); n1=t2.find(","); t1=t2.substr(0,n1); ch_t.push_back(t1);   t2=s.substr(n1); n1=t2.find(","); t1=t2.substr(0,n1); ch_t.push_back(t1);    t2=s.substr(n1); n1=t2.find(","); t1=t2.substr(0,n1); ch_t.push_back(t1);    t2=s.substr(n1); n1=t2.find(","); t1=t2.substr(0,n1); ch_t.push_back(t1);}
	}
	
	while(ist1.peek()!= char_traits<char>::eof())
	{
	getline(ist1,temp);
	unsigned pos = temp.find(",");
	p=temp.substr(0,pos);
	pos+=1;
	t=temp.substr(pos);
	//p_list.push_back(p);
	//t_list.push_back(t);
	
	string tt = temp;
	switch(num_com)
	{
		case 1: if(tt.find(ch_t[0])!=string::npos){ t_list.push_back(t); p_list.push_back(p);}
		case 2: if(tt.find(ch_t[0])!=string::npos && tt.find(ch_t[1])!=string::npos){ t_list.push_back(t); p_list.push_back(p);}
		case 3: if(tt.find(ch_t[0])!=string::npos && tt.find(ch_t[1])!=string::npos && tt.find(ch_t[2])!=string::npos){ t_list.push_back(t); p_list.push_back(p);}
		case 4: if(tt.find(ch_t[0])!=string::npos && tt.find(ch_t[1])!=string::npos && tt.find(ch_t[2])!=string::npos && tt.find(ch_t[3])!=string::npos){ t_list.push_back(t); p_list.push_back(p);}
		case 5: if(tt.find(ch_t[0])!=string::npos && tt.find(ch_t[1])!=string::npos && tt.find(ch_t[2])!=string::npos && tt.find(ch_t[3])!=string::npos && tt.find(ch_t[4])!=string::npos){ t_list.push_back(t); p_list.push_back(p);}
	}
	
	}
}

void view_all()
{
	p_list.begin();
	t_list.begin();
	string temp="";
	string p="",t="";
	while(ist1.peek()!= char_traits<char>::eof())
	{
	getline(ist1,temp);
	unsigned pos = temp.find(",");
	p=temp.substr(0,pos);
	pos+=1;
	t=temp.substr(pos);
	p_list.push_back(p);
	t_list.push_back(t);
	}
	
	
	
}