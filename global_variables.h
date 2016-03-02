// Created by Travis 
#include "std_lib_facilities_3.h"
#include <ios>
#include <iostream>
#include <fstream>



extern string ext_val;
extern const string ext[];
extern string image_name;
extern string check_tags[];
extern ofstream ofs1;
extern ifstream ist1;
extern ofstream ofs2;
extern ifstream ist2;
extern vector<string> family_list;
extern vector<string> friends_list;
extern vector<string> aggie_list;
extern vector<string> pets_list;
extern vector<string> vacation_list;
extern vector<string> active_p_list;
extern vector<string> active_t_list;
extern vector<string> t_list;
extern vector<string> p_list;
extern vector<string> ch_t;
extern int list_count;
extern int num_com;			//number of commas
extern vector<string> store;

extern void add_pic(string p,string t);
extern void set_tags(string t, string p);
extern void sync_file();
extern string find_tag(string s);
extern void find_picture(string s);
extern void delete_from_index(string p);
extern void view_all();