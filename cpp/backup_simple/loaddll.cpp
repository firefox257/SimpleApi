#include <stdio.h>
#include <windows.h>

char * printIfError(char * msg)
{
	if(msg != 0) printf(msg);
	return msg;
}

class Dll
{
	private:
	HINSTANCE lib;
	int errorCode;
	
	
	void _init(char * name)
	{
		errorCode = 0;
		lib = LoadLibrary(name);
		if (!lib) 
		{
			errorCode = 1;
			return;
		}
	}
	
	void * _get(char * name)
	{
		errorCode = 0;
		void * ret = (void*)GetProcAddress(lib,name);
		if (!ret) 
		{
			errorCode = 2;
		}
		return ret;	
	}
	
	public:

	
	Dll(char * name)
	{
		_init(name);
	}
	Dll(const char * name)
	{
		_init((char*)name);
	}
	~Dll()
	{
		CloseHandle(lib);
	}
	char * errorMsg()
	{
		switch(errorCode)
		{
			case 1:
			return  (char*)"could not load the dynamic library\r\n" ;
			case 2:
			return (char*)"could not locate the function windowInit\r\n";
			default:
			break;
		}
		return 0;
	}
	void * get(char * name)
	{
		return _get(name);
	}
	void * get(const char * name)
	{
		return _get((char*)name);
	}
};
/*
int main()
{
	
	Dll dl =Dll("printout.dll333");
	if(printIfError(dl.errorMsg()) != 0)
	{
		printf("here15454\r\n");
	}
	//void(*ptr)() = (void(*)())dl.get("printout");
	//printIfError(dl.errorMsg());
	//ptr();
	
	return 0;
}*/