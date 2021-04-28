#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct try1Def try1;





typedef struct try1Def
{
	double x, y, z;
	
	double (*getX)(try1 * at);
	
} try1;

void try1Init(try1 * at)
{
	
	
}

double try1GetX(try1 * at)
{
	return at->x;
	
}

int main()
{
	
	return 0;
}





