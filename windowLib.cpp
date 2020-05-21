#include <iostream>
#include <windows.h>
using namespace std;


class window
{
	private:	
	static void (*windowInit)(window *);
	static void (*windowInitFull)(window * at, int w, int h, const char * name, const char * className);
	static void (*windowDestroy)(window*);
	static void (*windowMessageLoop)(window *);
	
	public:
	
	int x;
	int y;
	int w;
	int h;
	char * name;
	char * className;
	
	///////////////reserved
	char reserved[100];
	
	
	static void LoadLib()
	{
			HINSTANCE lib = LoadLibrary("./window.dll");
			
			if (!lib) 
			{
				cout << "could not load the dynamic library" << std::endl;
				return;
			}
			
			// resolve function address here
			windowInit = (void(*)(window *))GetProcAddress(lib, "windowInit");
			if (!windowInit) 
			{
				cout << "could not locate the function windowInit" << endl;
				return;
			}
			
			windowInitFull= (void(*)(window *, int, int, const char *, const char *))GetProcAddress(lib, "windowInitFull");
			if (!windowInitFull) 
			{
				cout << "could not locate the function windowInitFull" << endl;
				return;
			}
			
			windowDestroy= (void(*)(window *))GetProcAddress(lib, "windowDestory");
			if (!windowDestroy) 
			{
				cout << "could not locate the function windowDestroy" << endl;
				return;
			}
			
			windowMessageLoop= (void(*)(window*))GetProcAddress(lib, "windowMessageLoop");
			if (!windowMessageLoop) 
			{
				cout << "could not locate the function windowMessageLoop" << endl;
				return;
			}

	}
	
	inline window()
	{
		windowInit(this);
	}
	inline window(int w, int h, const char * name, const char * className)
	{
		windowInitFull(this, w, h, name, className);
	}
	inline ~window()
	{
		windowDestroy(this);
	}
	inline void MessageLoop()
	{
		windowMessageLoop(this);
	}
	
	
	
};	
void(*window::windowInit)(window*);
void(*window::windowInitFull)(window*, int, int , const char * , const char *);
void(*window::windowDestroy)(window*) ;
void(*window::windowMessageLoop)(window*);
