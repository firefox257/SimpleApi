#include <iostream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <functional>
#include <utility>
#include <tuple>
#include <typeinfo>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#include <fstream>

#include <unordered_map>
#include <vector>
#include <chrono>

#include "Types.cpp"
//#include "SmtPtr.hpp"
//#include "Array.cpp"
//#include "List.cpp"
/*#include "String.cpp"
#include "DataIO.cpp"
#include "Array.cpp"


#include "Async.cpp"
#include "SmtPtr.hpp"
#include "Mapper.cpp"
#include "Factory.cpp"*/



using namespace std;
#define el << "\r\n"


mulong  time()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}



//unsigned longs
#define D10P19 1e19
//longs
#define D10P18 1e18
#define D10P17 100000000000000000L
#define D10P16 10000000000000000L
#define D10P15 1000000000000000L
#define D10P14 100000000000000L
#define D10P13 10000000000000L
#define D10P12 1000000000000L
#define D10P11 100000000000L
#define D10P10 10000000000L
//integers
#define D10P9 1000000000  
#define D10P8 100000000
#define D10P7 10000000
#define D10P6 1000000
#define D10P5 100000
//shorts
#define D10P4 10000
#define D10P3 1000
//chars
#define D10P2 100
#define D10P1 10
#define D10P0 1


#define _PROD0(I) \
d[I + 1] = getNumChar((muchar)dd);

#define _PROD1(I) \
dd1 = dd/1e1; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * 1e1); \
_PROD0(I + 1)
			
#define _PROD2(I) \
dd1 = dd/D10P2; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P2); \
_PROD1(I + 1)

#define _PROD3(I) \
dd1 = dd/D10P3; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P3); \
_PROD2(I + 1)

#define _PROD4(I) \
dd1 = dd/D10P4; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P4); \
_PROD3(I + 1)

#define _PROD5(I) \
dd1 = dd/D10P5; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P5); \
_PROD4(I + 1)

#define _PROD6(I) \
dd1 = dd/D10P6; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P6); \
_PROD5(I + 1)

#define _PROD7(I) \
dd1 = dd/D10P7; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P7); \
_PROD6(I + 1)

#define _PROD8(I) \
dd1 = dd/D10P8; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P8); \
_PROD7(I + 1)

#define _PROD8(I) \
dd1 = dd/D10P8; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P8); \
_PROD7(I + 1)

#define _PROD9(I) \
dd1 = dd/D10P9; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P9); \
_PROD8(I + 1)

#define _PROD10(I) \
dd1 = dd/D10P10; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P10); \
_PROD9(I + 1)

#define _PROD11(I) \
dd1 = dd/D10P11; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P11); \
_PROD10(I + 1)

#define _PROD12(I) \
dd1 = dd/D10P12; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P12); \
_PROD11(I + 1)

#define _PROD13(I) \
dd1 = dd/D10P13; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P13); \
_PROD12(I + 1)

#define _PROD14(I) \
dd1 = dd/D10P14; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P14); \
_PROD13(I + 1)

#define _PROD15(I) \
dd1 = dd/D10P15; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P15); \
_PROD14(I + 1)

#define _PROD16(I) \
dd1 = dd/D10P16; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P16); \
_PROD15(I + 1)

#define _PROD17(I) \
dd1 = dd/D10P17; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P17); \
_PROD16(I + 1)

#define _PROD18(I) \
dd1 = dd/D10P18; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P18); \
_PROD17(I + 1)

#define _PROD19(I) \
dd1 = dd/D10P19; \
d[I+1] = getNumChar((muchar)dd1); \
dd -= (dd1 * D10P19); \
_PROD18(I + 1)


//class stringConvert
//{
	
	
	
	
	
	//public:
	
	inline mchar getNumChar(muchar i)
	{
		return (mchar) i + '0';
	}
	
	void ToCstr(mchar * d, mint & size, mbool dd)
	{
		size = 1;
		d[1] = 0;
		if(dd) d[0] = '1';
		else d[0] = '0';
	}
	// end mbool
	
	void ToCstr(mchar * d, mint & size, muchar dd)
	{
		muchar dd1;
		if(dd >= D10P2)
		{
			size = 3;
			d[3] = 0;
			
			_PROD2(-1);
			
		}
		else if(dd >= D10P1)
		{
			size = 2;
			d[2] = 0;
			
			_PROD1(-1);
		}
		else
		{
			size = 1;
			d[1] = 0;
			
			_PROD0(-1);
		}
	}
	//end muchar
	
	void ToCstr(mchar * d, mint & size, mchar dd)
	{
		size = 1;
		d[1] = 0;
		d[0] = dd;
	}
	//end mchar
	
	void ToCstr(mchar * d, mint & size, mushort dd)
	{
		//65536
		mushort dd1;
		if(dd >= D10P4)
		{
			size = 5;
			d[5] = 0;
			_PROD4(-1)
		}
		else if(dd >= D10P3)
		{
			size = 4;
			d[4] = 0;
			_PROD3(-1)
		}
		else if(dd >= D10P2)
		{
			size = 3;
			d[3] = 0;
			
			_PROD2(-1)
			
		}
		else if(dd >= D10P1)
		{
			size = 2;
			d[2] = 0;
			_PROD1(-1)
		}
		else
		{
			size = 1;
			d[1] = 0;
			_PROD0(-1)
		}
	}
	//end mushort
	
	void ToCstr(mchar * d, mint & size, mshort dd)
	{
		//65536
		mshort dd1;
		if(dd >= 0)
		{
			if(dd >= D10P4)
			{
				size = 5;
				d[5] = 0;
				_PROD4(-1)
			}
			else if(dd >= D10P3)
			{
				size = 4;
				d[4] = 0;
				_PROD3(-1)
			}
			else if(dd >= D10P2)
			{
				size = 3;
				d[3] = 0;
				
				_PROD2(-1)
				
			}
			else if(dd >= D10P1)
			{
				size = 2;
				d[2] = 0;
				_PROD1(-1)
			}
			else
			{
				size = 1;
				d[1] = 0;
				_PROD0(-1)
			}
		}
		else // do the negative_sign
		{
			d[0] = '-';
			dd *=-1;
			if(dd >= D10P4)
			{
				size = 6;
				d[6] = 0;
				_PROD4(-1)
			}
			else if(dd >= D10P3)
			{
				size = 5;
				d[5] = 0;
				_PROD3(-1)
			}
			else if(dd >= D10P2)
			{
				size = 4;
				d[4] = 0;
				_PROD2(-1)
			}
			else if(dd >= D10P1)
			{
				size = 3;
				d[3] = 0;
				_PROD1(-1)
			}
			else
			{
				size = 2;
				d[2] = 0;
				_PROD0(-1)
			}
		}
	}// end of short conversion.
	//end mshort
	
	void ToCstr(mchar * d, mint & size, muint dd)
	{
		//4,294,967,295
		muint dd1;
		
		
		if(dd >= D10P9)
		{
			size = 10;
			d[10] = 0;
			_PROD9(-1);
		}
		else if(dd >= D10P8)
		{
			size = 9;
			d[9] = 0;
			_PROD8(-1);
		}
		else if(dd >= D10P7)
		{
			size = 8;
			d[8] = 0;
			_PROD7(-1);
		}
		else if(dd >= D10P6)
		{
			size = 7;
			d[7] = 0;
			_PROD6(-1);
		}
		else if(dd >= D10P5)
		{
			size = 6;
			d[6] = 0;
			_PROD5(-1);
		}
		else if(dd >= D10P4)
		{
			size = 5;
			d[5] = 0;
			_PROD4(-1);
		}
		else if(dd >= D10P3)
		{
			size = 4;
			d[4] = 0;
			_PROD3(-1);
		}
		else if(dd >= D10P2)
		{
			size = 3;
			d[3] = 0;
			_PROD2(-1);
		}
		else if(dd >= D10P1)
		{
			size = 2;
			d[2] = 0;
			_PROD1(-1);
		}
		else 
		{
			size = 1;
			d[1] = 0;
			_PROD0(-1);
			
		}//*/
	}
	//end muint
	
	void ToCstr(mchar * d, mint & size, mint dd)
	{
		mint dd1;
		if(dd >= 0)
		{
			if(dd >= D10P9)
			{
				size = 10;
				d[10] = 0;
				_PROD9(-1);
			}
			else if(dd >= D10P8)
			{
				size = 9;
				d[9] = 0;
				_PROD8(-1);
			}
			else if(dd >= D10P7)
			{
				size = 8;
				d[8] = 0;
				_PROD7(-1);
			}
			else if(dd >= D10P6)
			{
				size = 7;
				d[7] = 0;
				_PROD6(-1);
			}
			else if(dd >= D10P5)
			{
				size = 6;
				d[6] = 0;
				_PROD5(-1);
			}
			else if(dd >= D10P4)
			{
				size = 5;
				d[5] = 0;
				_PROD4(-1);
			}
			else if(dd >= D10P3)
			{
				size = 4;
				d[4] = 0;
				_PROD3(-1);
			}
			else if(dd >= D10P2)
			{
				size = 3;
				d[3] = 0;
				_PROD2(-1);
			}
			else if(dd >= D10P1)
			{
				size = 2;
				d[2] = 0;
				_PROD1(-1);
			}
			else 
			{
				size = 1;
				d[1] = 0;
				_PROD0(-1);
				
			}//*/
			
		}
		else
		{
			dd *= -1;
			d[0] = '-';
			if(dd >= D10P9)
			{
				size = 11;
				d[11] = 0;
				_PROD9(0);
			}
			else if(dd >= D10P8)
			{
				size = 10;
				d[10] = 0;
				_PROD8(0);
			}
			else if(dd >= D10P7)
			{
				size = 9;
				d[9] = 0;
				_PROD7(0);
			}
			else if(dd >= D10P6)
			{
				size = 8;
				d[8] = 0;
				_PROD6(0);
			}
			else if(dd >= D10P5)
			{
				size = 7;
				d[7] = 0;
				_PROD5(0);
			}
			else if(dd >= D10P4)
			{
				size = 6;
				d[6] = 0;
				_PROD4(0);
			}
			else if(dd >= D10P3)
			{
				size = 5;
				d[5] = 0;
				_PROD3(0);
			}
			else if(dd >= D10P2)
			{
				size = 4;
				d[4] = 0;
				_PROD2(0);
			}
			else if(dd >= D10P1)
			{
				size = 3;
				d[3] = 0;
				_PROD1(0);
			}
			else 
			{
				size = 2;
				d[2] = 0;
				_PROD0(0);
				
			}//*/
			
		}
			
	}
	//end mint
	
	void ToCstr(mchar * d, mint & size, mulong dd)
	{
		//18,446,744,073,709,551,616
		mulong dd1;
		
		if(dd >= D10P15)
		{
			if(dd >= D10P19)
			{
				size = 20;
				d[20] = 0;
				_PROD19(-1);
			}
			else if(dd >= D10P18)
			{
				size = 19;
				d[19] = 0;
				_PROD18(-1);
			}
			else if(dd >= D10P17)
			{
				size = 18;
				d[18] = 0;
				_PROD17(-1);
			}
			else if(dd >= D10P16)
			{
				size = 17;
				d[17] = 0;
				_PROD16(-1);
			}
			else 
			{
				size = 16;
				d[16] = 0;
				_PROD15(-1);
			}
		}
		else if(dd >= D10P10)
		{
			if(dd >= D10P14)
			{
				size = 15;
				d[15] = 0;
				_PROD14(-1);
			}
			else if(dd >= D10P13)
			{
				size = 14;
				d[14] = 0;
				_PROD13(-1);
			}
			else if(dd >= D10P12)
			{
				size = 13;
				d[13] = 0;
				_PROD12(-1);
			}
			else if(dd >= D10P11)
			{
				size = 12;
				d[12] = 0;
				_PROD11(-1);
			}
			else
			{
				size = 11;
				d[11] = 0;
				_PROD10(-1);
			}
		}
		else if(dd >= D10P5)
		{
			if(dd >= D10P9)
			{
				size = 10;
				d[10] = 0;
				_PROD9(-1);
			}
			else if(dd >= D10P8)
			{
				size = 9;
				d[9] = 0;
				_PROD8(-1);
			}
			else if(dd >= D10P7)
			{
				size = 8;
				d[8] = 0;
				_PROD7(-1);
			}
			else if(dd >= D10P6)
			{
				size =7;
				d[7] = 0;
				_PROD6(-1);
			}
			else
			{
				size =6;
				d[6] = 0;
				_PROD5(-1);
			}
		}
		else
		{
			if(dd >= D10P4)
			{
				size =5;
				d[5] = 0;
				_PROD4(-1);
			}
			else if(dd >= D10P3)
			{
				size =4;
				d[4] = 0;
				_PROD3(-1);
			}
			else if(dd >= D10P2)
			{
				size =3;
				d[3] = 0;
				_PROD2(-1);
			}
			else if(dd >= D10P1)
			{
				size =2;
				d[2] = 0;
				_PROD1(-1);
			}
			else
			{
				size =1;
				d[1] = 0;
				_PROD0(-1);
			}
		}
		
		
		
	}
	//end mulong
	
	void ToCstr(mchar * d, mint & size, mlong dd)
	{
		
		mlong dd1;
		if(dd >= 0)
		{
			if(dd >= D10P15)
			{
				if(dd >= D10P19)
				{
					size = 20;
					d[20] = 0;
					_PROD19(-1);
				}
				else if(dd >= D10P18)
				{
					size = 19;
					d[19] = 0;
					_PROD18(-1);
				}
				else if(dd >= D10P17)
				{
					size = 18;
					d[18] = 0;
					_PROD17(-1);
				}
				else if(dd >= D10P16)
				{
					size = 17;
					d[17] = 0;
					_PROD16(-1);
				}
				else 
				{
					size = 16;
					d[16] = 0;
					_PROD15(-1);
				}
			}
			else if(dd >= D10P10)
			{
				if(dd >= D10P14)
				{
					size = 15;
					d[15] = 0;
					_PROD14(-1);
				}
				else if(dd >= D10P13)
				{
					size = 14;
					d[14] = 0;
					_PROD13(-1);
				}
				else if(dd >= D10P12)
				{
					size = 13;
					d[13] = 0;
					_PROD12(-1);
				}
				else if(dd >= D10P11)
				{
					size = 12;
					d[12] = 0;
					_PROD11(-1);
				}
				else
				{
					size = 11;
					d[11] = 0;
					_PROD10(-1);
				}
			}
			else if(dd >= D10P5)
			{
				if(dd >= D10P9)
				{
					size = 10;
					d[10] = 0;
					_PROD9(-1);
				}
				else if(dd >= D10P8)
				{
					size = 9;
					d[9] = 0;
					_PROD8(-1);
				}
				else if(dd >= D10P7)
				{
					size = 8;
					d[8] = 0;
					_PROD7(-1);
				}
				else if(dd >= D10P6)
				{
					size =7;
					d[7] = 0;
					_PROD6(-1);
				}
				else
				{
					size =6;
					d[6] = 0;
					_PROD5(-1);
				}
			}
			else
			{
				if(dd >= D10P4)
				{
					size =5;
					d[5] = 0;
					_PROD4(-1);
				}
				else if(dd >= D10P3)
				{
					size =4;
					d[4] = 0;
					_PROD3(-1);
				}
				else if(dd >= D10P2)
				{
					size =3;
					d[3] = 0;
					_PROD2(-1);
				}
				else if(dd >= D10P1)
				{
					size =2;
					d[2] = 0;
					_PROD1(-1);
				}
				else
				{
					size =1;
					d[1] = 0;
					_PROD0(-1);
				}
			}//
			
		}
		else
		{
			dd *= -1;
			d[0] = '-';
			
			
			if(dd >= D10P15)
			{
				if(dd >= D10P19)
				{
					size = 21;
					d[21] = 0;
					_PROD19(0);
				}
				else if(dd >= D10P18)
				{
					size = 20;
					d[20] = 0;
					_PROD18(0);
				}
				else if(dd >= D10P17)
				{
					size = 19;
					d[19] = 0;
					_PROD17(0);
				}
				else if(dd >= D10P16)
				{
					size = 18;
					d[18] = 0;
					_PROD16(0);
				}
				else 
				{
					size = 17;
					d[17] = 0;
					_PROD15(0);
				}
			}
			else if(dd >= D10P10)
			{
				if(dd >= D10P14)
				{
					size = 16;
					d[16] = 0;
					_PROD14(0);
				}
				else if(dd >= D10P13)
				{
					size = 15;
					d[15] = 0;
					_PROD13(0);
				}
				else if(dd >= D10P12)
				{
					size = 14;
					d[14] = 0;
					_PROD12(0);
				}
				else if(dd >= D10P11)
				{
					size = 13;
					d[13] = 0;
					_PROD11(0);
				}
				else
				{
					size = 12;
					d[12] = 0;
					_PROD10(0);
				}
			}
			else if(dd >= D10P5)
			{
				if(dd >= D10P9)
				{
					size = 11;
					d[11] = 0;
					_PROD9(0);
				}
				else if(dd >= D10P8)
				{
					size = 10;
					d[10] = 0;
					_PROD8(0);
				}
				else if(dd >= D10P7)
				{
					size = 9;
					d[9] = 0;
					_PROD7(0);
				}
				else if(dd >= D10P6)
				{
					size =8;
					d[8] = 0;
					_PROD6(0);
				}
				else
				{
					size =7;
					d[7] = 0;
					_PROD5(0);
				}
			}
			else
			{
				if(dd >= D10P4)
				{
					size =6;
					d[6] = 0;
					_PROD4(0);
				}
				else if(dd >= D10P3)
				{
					size =5;
					d[5] = 0;
					_PROD3(0);
				}
				else if(dd >= D10P2)
				{
					size =4;
					d[4] = 0;
					_PROD2(0);
				}
				else if(dd >= D10P1)
				{
					size =3;
					d[3] = 0;
					_PROD1(0);
				}
				else
				{
					size =2;
					d[2] = 0;
					_PROD0(0);
				}
			}//
			
		}
	}
	//end mlong
	
	void ToCstr(mchar * d, mint & size, mfloat dd)
	{
		
		
		
		//size = snprintf(d, 30, "%f", dd);
		/*
		Type	Minimum value				Maximum value
		float	1.175494351 E - 38			3.402823466 E + 38
		double	2.2250738585072014 E - 308	1.7976931348623158 E + 308
		*/
		
		/*
		38
		37
		36+
		35
		34
		33+
		32
		31
		30++
		29
		28
		27+
		26
		25
		24+
		23
		22
		21++
		20
		19
		18+
		17
		16
		15+
		14
		13
		12++
		11
		10
		9+
		8
		7
		6+
		5
		4
		3++
		2
		1
		0
		*/
		size = 0;
		if(dd < 0)
		{
			d[size] = '-';
			size++;
			dd *=-1;
		}
		
		mint exp  = 0;
		
		if(dd >=1)
		{
			if(dd >= 1e30)
			{
				if(dd >= 1e36)
				{
					if(dd >= 1e38)
					{
						exp = 38;
						dd /= 1e38;
						
					}
					else if(dd >= 1e37)
					{
						exp = 37;
						dd /= 1e37;
					}
					else
					{
						exp = 36;
						dd /= 1e36;
						//1e36
					}
				}
				else if(dd >= 1e33)
				{
					if(dd >= 1e35)
					{
						exp = 35;
						dd /= 1e35;
					}
					else if(dd >=1e34)
					{
						exp = 34;
						dd /= 1e34;
					}
					else
					{
						exp = 33;
						dd /= 1e33;
						//1e33
					}
				}
				else
				{
					if(dd >= 1e32)
					{
						exp = 32;
						dd /= 1e32;
					}
					else if( dd >= 1e31)
					{
						exp = 31;
						dd /= 1e31;
					}
					else 
					{
						exp = 30;
						dd /= 1e30;
						//1e30
					}
				}
				
			}
			else if(dd >= 1e21)
			{
				if(dd >= 1e27)
				{
					if(dd >= 1e29)
					{
						exp = 29;
						dd /= 1e29;
					}
					else if(dd >= 1e28)
					{
						exp = 28;
						dd /= 1e28;
					}
					else
					{
						exp = 27;
						dd /= 1e27;
						//1e27
					}
				}
				else if(dd >= 1e24)
				{
					if(dd >=1e26)
					{
						exp = 26;
						dd /= 1e26;
					}
					else if(dd >= 1e25)
					{
						exp = 25;
						dd /= 1e25;
					}
					else
					{
						exp = 24;
						dd /= 1e24;
						//1e24
					}
				}
				else
				{
					if(dd >= 1e23)
					{
						exp = 23;
						dd /= 1e23;
					}
					else if(dd >= 1e22)
					{
						exp = 22;
						dd /= 1e22;
					}
					else
					{
						exp = 21;
						dd /= 1e21;
						//1e21
					}
				}
			}
			else if(dd >= 1e12)
			{
				if(dd >= 1e18)
				{
					if(dd >= 1e20)
					{
						exp = 20;
						dd /= 1e20;
					}
					else if(dd >= 1e19)
					{
						exp = 19;
						dd /= 1e19;
					}
					else
					{
						exp = 18;
						dd /= 1e18;
						//1e18
					}
				}
				else if(dd >= 1e15)
				{
					if(dd >= 1e17)
					{
						exp = 17;
						dd /= 1e17;
					}
					else if( dd >= 1e16)
					{
						exp = 16;
						dd /= 1e16;
					}
					else
					{
						exp = 15;
						dd /= 1e15;
						//1e15
					}
				}
				else
				{
					if(dd >= 1e14)
					{
						exp = 14;
						dd /= 1e14;
					}
					else if(dd >= 1e13)
					{
						exp = 13;
						dd /= 1e13;
					}
					else
					{
						exp = 12;
						dd /= 1e12;
						//1e12
					}
				}
			}
			else
			{
				if(dd >= 1e8)
				{
					if(dd >= 1e11)
					{
						exp = 11;
						dd /= 1e11;
					}
					else if(dd >= 1e10)
					{
						exp = 10;
						dd /= 1e10;
					}
					else if(dd >= 1e9)
					{
						exp = 9;
						dd /= 1e9;
					}
					else
					{
						exp = 8;
						dd /= 1e8;
						//1e8
					}
				}
				else if(dd >= 1e4)
				{
					if(dd >= 1e7)
					{
						exp = 7;
						dd /= 1e7;
					}
					else if(dd >= 1e6)
					{
						exp = 6;
						dd /= 1e6;
					}
					else if(dd >= 1e5)
					{
						exp = 5;
						dd /= 1e5;
					}
					else
					{
						exp = 4;
						dd /= 1e4;
						//1e4
					}
				}
				else
				{
					if(dd >= 1e3)
					{
						exp = 3;
						dd /= 1e3;
					}
					else if(dd >= 1e2)
					{
						exp = 2;
						dd /= 1e2;
					}
					else if(dd >= 1e1)
					{
						exp = 1;
						dd /= 1e1;
					}
					//else
					//{
						//1e0
					//}
				}
			}
			
			//*/
			
			
			if(exp >15)
			{
				
			}
			else
			{
				
				
				for(mint i = 0; i <= exp; i++)
				{
					muchar n = (muchar)dd;
					d[size] = getNumChar(n);
					dd -= n;
					dd *=10;
					size++;
				}
				if(dd != 0 && size < 30)
				{
					
					d[size] = '.';
					size++;
					while(dd != 0)
					{
						muchar n = (muchar)dd;
						d[size] = getNumChar(n);
						dd -= n;
						dd *=10;
						size++;
					}
				}
				d[size] = 0;
			}
			
			
		}//end large number
		else
		{
			/*
			-1
			-2
			-3+
			-4
			-5
			-6+
			-7
			-8
			-9++
			-10
			-11
			-12+
			-13
			-14
			-15+
			-16
			-17
			-18++
			-19
			-20
			-21+
			-22
			-23
			-24+
			-25
			-26
			-27++
			-28
			-29
			-30+
			-31
			-32
			-33+
			-34
			-35
			-36++
			-37
			-38
			
			*/
			
			if(dd >= 1e-9)
			{
				if(dd >= 1e-3)
				{
					if(dd >= 1e-1)
					{
						
					}
					else if(dd >= 1e-2)
					{
						
					}
					else
					{
						//1e-3
					}
				}
				else if(dd >= 1e-6)
				{
					if(dd >= 1e-4)
					{
						
					}
					else if(dd >= 1e-5)
					{
						
					}
					else
					{
						//1e-6
					}
				}
				else
				{
					if(dd >= 1e-7)
					{
						
					}
					else if(dd >= 1e-8)
					{
						
					}
					else
					{
						//1e-9
					}
				}
			}
			else if(dd >= 1e-18)
			{
				if(dd >= 1e-12)
				{
					if(dd >= 1e-10)
					{
						
					}
					else if(dd >= 1e-11)
					{
						
					}
					else
					{
						//1e-12
					}
				}
				else if(dd >= 1e-15)
				{
					if(dd >= 1e-13)
					{
						
					}
					else if(dd >= 1e-14)
					{
						
					}
					else
					{
						//1e-15
					}
				}
				else
				{
					if(dd >= 1e-16)
					{
						
					}
					else if(dd >= 1e-17)
					{
						
					}
					else
					{
						//1e-18
					}
				}
				
			}
			else if(dd >= 1e-27)
			{
				if(dd >= 1e-21)
				{
					if(dd >= 1e-19)
					{
						
					}
					else if(dd >= 1e-20)
					{
						
					}
					else
					{
						//1e-21
					}
				}
				else if(dd >= 1e-24)
				{
					if(dd >= 1e-22)
					{
						
					}
					else if(dd >= 1e-23)
					{
						
					}
					else
					{
						//1e-24
					}
				}
				else
				{
					if(dd >= 1e-25)
					{
						
					}
					else if(dd >= 1e-26)
					{
						
					}
					else 
					{
						//1e-27
					}
				}
			}
			else 
			{
				
			}
		}
		
		
		
	}// end mfloat
//};

/*
struct stringData
{
	mchar * data = 0;
	mint size = 0;
	mbool isConst = false;
};
class string
{
	stringData * ref;
	mint * count;
	
	
	void resizeData(mint size)
	{
		if(ref->data == 0)
		{
			ref->data = (mchar*)malloc(size);
		}
		else
		{
			ref->data = (mchar*)realloc(ref->data, size);
		}
	}
	
	
	
	
	
	public:
	string()
	{
		ref = new stringData;
		count = new mint;
		(*count) = 1;
	}
	
	string(const mchar * d)
	{
		ref = new stringData;
		count  = new mint;
		(*count) = 1;
		
		ref->data = (mchar*)d;
		ref->isConst = true;
	}
	
	//do not manage outside refs. 
	//
	//	Example if comes from list then list should manage menmory. 
	//
	string (mchar * d)
	{
		ref = new stringData;
		count  = new mint;
		(*count) = 1;
		
		ref->data = d;
		ref->isConst = true;
	}
	
	string(const mbool & d)
	{
		ref = new stringData;
		count  = new mint;
		(*count) = 1;
		resizeData(2);
		ref->data[1] = 0;
		if(d)
		{
			ref->data[0] = '1';
		}
		else
		{
			ref->data[1] = '0';
		}
		ref->size = 1;
		
	}
	
	string(const mchar & d)
	{
		ref = new stringData;
		count  = new mint;
		(*count) = 1;
		resizeData(2);
		ref->data[1] = 0;
		ref->data[0] = d;
		ref->size = 1;
	}
	
	string(const mushort & d)
	{
		ref = new stringData;
		count  = new mint;
		(*count) = 1;
		resizeData(6);
		
		
	}
	
	
};
*/


int main()
{
	
	
	
	
	mchar buff[30];
	
	mint size; 
	
	
	mfloat f1 = -123.123;
	
	
	ToCstr(buff, size, f1);
	cout << "buff: "<< buff << "\r\n";
	
	
	
	mulong t1, t2;
	t1 = time();
	for(mfloat i = 0; i < 1000000; i++)
	{
	
		ToCstr(buff, size, i);
	}
	t2 = time();
	cout << "time: " << (t2  - t1) << "\r\n";
	cout << "buff " << buff << "\r\n";
	
	/*
	t1 = time();
	for(mint i = 0; i < 1000000000; i++)
	{
	
		//int snprintf ( char * s, size_t n, const char * format, ... );
		size =  snprintf ( buff, 30, "%d");
	}
	t2 = time();
	cout << "time: " << (t2  - t1) << "\r\n";
	//*/
	
	return 0;
}


