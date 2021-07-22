#include <iostream>

#include <windows.h>


using namespace std;

int main()
{
	HANDLE h = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 100000000, 200000000);
	
	int * i1 = (int*)HeapAlloc(h, 0, sizeof(int));
	
	
	return 0;
}



///duo
