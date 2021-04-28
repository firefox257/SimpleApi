#include <stdio.h>
#include <windows.h>





typedef struct threadDef thread;
typedef struct threadDef
{
	
	
	DWORD id;
	HANDLE handel; 
	char reserved[24];
	
} thread;

void initThread(thread * at)
{
	at->id = 0;
}
void destroyThread(thread * at)
{
	CloseHandle(at->handel);
}

void (*HelperFunc)(void*);
DWORD WINAPI myThread(LPVOID ptr)
{
	HelperFunc(ptr);
	return 0;
}


void startThread(thread * at)
{
	at->handel = CreateThread(0, 0, myThread, at, 0, &at->id);
}

void setHelperFunc(void(*func)(void *))
{
	HelperFunc = func;
	
}


void func1(void * ptr)
{
		printf("here1\r\n");
	
}

int main()
{
	setHelperFunc(func1);
	printf("%d %d\r\n", sizeof(DWORD), sizeof(HANDLE));
	thread th;
	initThread(&th);
	startThread(&th);
	
	destroyThread(&th);
	sleep(2);
	return 0;
}

/*

MIPI DSI display port

*/