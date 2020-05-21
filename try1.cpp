#include <iostream>

#include "testlib.cpp"
#include "windowLib.cpp"
using namespace std;


int main()
{
	
	window::LoadLib();
	
	window w1 = window(800, 600, "hi there", "myWindow");
	
	w1.MessageLoop();
	
	return 0;
}