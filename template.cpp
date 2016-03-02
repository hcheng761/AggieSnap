#include "std_lib_facilities_3.h"
#include "input_window.h"
#include "Title_window.h"
#include "Graph.h"
#include "global_variables.h"

int main()
try {
  if(H112 != 201206L)error("Error: incorrect std_lib_facilities_3.h version ",
		  	   H112);
			   
  Title_window win(Point(100,50),800,600,"Title");
  win.wait_for_button();
  
  
 
   return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
