#include <iostream>
#include <windows.h>
using namespace std;


class test
{
	private:	
	static void (*testInit)(test *);
	static void (*testDestroy)(test*);
	static void (*testSet)(test *, int, int, int ,int);
	static void (*testPrint)(test*);
	
	public:
	
	int x;
	int y;
	int w;
	int h;
	
	
	static void LoadLib()
	{
			HINSTANCE lib = LoadLibrary("./test.dll");
			
			if (!lib) 
			{
				cout << "could not load the dynamic library" << std::endl;
				return;
			}

			// resolve function address here
			testInit = (void(*)(test *))GetProcAddress(lib, "testInit");
			if (!testInit) 
			{
				cout << "could not locate the function" << endl;
				return;
			}
			
			testDestroy= (void(*)(test *))GetProcAddress(lib, "testDestroy");
			if (!testDestroy) 
			{
				cout << "could not locate the function" << endl;
				return;
			}
			
			
			testSet= (void(*)(test*, int, int, int, int))GetProcAddress(lib, "testSet");
			if (!testSet) 
			{
				cout << "could not locate the function" << endl;
				return;
			}
			
			testPrint= (void(*)(test *))GetProcAddress(lib, "testPrint");
			if (!testPrint) 
			{
				cout << "could not locate the function" << endl;
				return;
			}
			

	}
	
	inline test()
	{
		testInit(this);
	}
	inline ~test()
	{
		testDestroy(this);
	}
	inline void set(int xx, int yy, int ww, int hh)
	{
		testSet(this, xx, yy, ww, hh);
	}
	inline void print()
	{
		testPrint(this);
	}
	
	
};	
void(*test::testInit)(test*);
void(*test::testDestroy)(test*) ;
void(*test::testSet)(test*, int, int , int, int) ; 
void(*test::testPrint)(test*);








