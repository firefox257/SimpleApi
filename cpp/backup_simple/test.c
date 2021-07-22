#include <stdio.h>


typedef struct testDef test;
typedef struct testDef
{
	int x;
	int y;
	int w;
	int h;
	
	
} test;

void testInit(test * at)
{
	at->x = 0;
	at->y = 0;
	at->w = 0;
	at->h = 0;
}
void testDestroy(test * at)
{
	
}

void testSet(test * at, int x, int y, int w, int h)
{
	at->x = x;
	at->y = y;
	at->w = w;
	at->h = h;
}

void testPrint(test*at)
{
	printf("valuse are %d, %d, %d, %d\r\n", at->x, at->y, at->w, at->h);
}








