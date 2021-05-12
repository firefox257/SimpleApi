#include <iostream>

using namespace std;


#define P1(I) << i[I + 1]
#define P2(I) << i [I + 1] P1(I + 1)
#define P3(I) << i[I] P2(I)



int main()
{
	int i[3];
	i[0] = 123;
	i[1] = 124;
	i[2] = 125;
	
	cout P2(-1);
	
	return 0;
}