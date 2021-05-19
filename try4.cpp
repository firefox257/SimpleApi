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
	
	
	
	
	/*const mfloat FLOATCONST[] = {
	1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9,	
	1e10, 1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19,
	1e20, 1e21, 1e22, 1e23, 1e24, 1e25, 1e26, 1e27, 1e28, 1e29, 
	1e30, 1e31, 1e32, 1e33, 1e34, 1e35, 1e36, 1e37, 1e38};
	*/
	
	const mfloat FLOATPOWCONST[] = {1e38,1e37,1e36,1e35,1e34,1e33,1e32,1e31,1e30,1e29,
		1e28,1e27,1e26,1e25,1e24,1e23,1e22,1e21,1e20,1e19,
		1e18,1e17,1e16,1e15,1e14,1e13,1e12,1e11,1e10,1e9,
		1e8,1e7,1e6,1e5,1e4,1e3,1e2,1e1,1e0,1e-1,
		1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10,1e-11,
		1e-12,1e-13,1e-14,1e-15,1e-16,1e-17,1e-18,1e-19,1e-20,1e-21,
		1e-22,1e-23,1e-24,1e-25,1e-26,1e-27,1e-28,1e-29,1e-30,1e-31,
		1e-32,1e-33,1e-34,1e-35,1e-36,1e-37,1e-38};

	
	const mdouble DOUBLEPOWCONST[] = {1e308,1e307,1e306,1e305,1e304,1e303,1e302,1e301,1e300,1e299,
		1e298,1e297,1e296,1e295,1e294,1e293,1e292,1e291,1e290,1e289,
		1e288,1e287,1e286,1e285,1e284,1e283,1e282,1e281,1e280,1e279,
		1e278,1e277,1e276,1e275,1e274,1e273,1e272,1e271,1e270,1e269,
		1e268,1e267,1e266,1e265,1e264,1e263,1e262,1e261,1e260,1e259,
		1e258,1e257,1e256,1e255,1e254,1e253,1e252,1e251,1e250,1e249,
		1e248,1e247,1e246,1e245,1e244,1e243,1e242,1e241,1e240,1e239,
		1e238,1e237,1e236,1e235,1e234,1e233,1e232,1e231,1e230,1e229,
		1e228,1e227,1e226,1e225,1e224,1e223,1e222,1e221,1e220,1e219,
		1e218,1e217,1e216,1e215,1e214,1e213,1e212,1e211,1e210,1e209,
		1e208,1e207,1e206,1e205,1e204,1e203,1e202,1e201,1e200,1e199,
		1e198,1e197,1e196,1e195,1e194,1e193,1e192,1e191,1e190,1e189,
		1e188,1e187,1e186,1e185,1e184,1e183,1e182,1e181,1e180,1e179,
		1e178,1e177,1e176,1e175,1e174,1e173,1e172,1e171,1e170,1e169,
		1e168,1e167,1e166,1e165,1e164,1e163,1e162,1e161,1e160,1e159,
		1e158,1e157,1e156,1e155,1e154,1e153,1e152,1e151,1e150,1e149,
		1e148,1e147,1e146,1e145,1e144,1e143,1e142,1e141,1e140,1e139,
		1e138,1e137,1e136,1e135,1e134,1e133,1e132,1e131,1e130,1e129,
		1e128,1e127,1e126,1e125,1e124,1e123,1e122,1e121,1e120,1e119,
		1e118,1e117,1e116,1e115,1e114,1e113,1e112,1e111,1e110,1e109,
		1e108,1e107,1e106,1e105,1e104,1e103,1e102,1e101,1e100,1e99,
		1e98,1e97,1e96,1e95,1e94,1e93,1e92,1e91,1e90,1e89,
		1e88,1e87,1e86,1e85,1e84,1e83,1e82,1e81,1e80,1e79,
		1e78,1e77,1e76,1e75,1e74,1e73,1e72,1e71,1e70,1e69,
		1e68,1e67,1e66,1e65,1e64,1e63,1e62,1e61,1e60,1e59,
		1e58,1e57,1e56,1e55,1e54,1e53,1e52,1e51,1e50,1e49,
		1e48,1e47,1e46,1e45,1e44,1e43,1e42,1e41,1e40,1e39,
		1e38,1e37,1e36,1e35,1e34,1e33,1e32,1e31,1e30,1e29,
		1e28,1e27,1e26,1e25,1e24,1e23,1e22,1e21,1e20,1e19,
		1e18,1e17,1e16,1e15,1e14,1e13,1e12,1e11,1e10,1e9,
		1e8,1e7,1e6,1e5,1e4,1e3,1e2,1e1,1e0,1e-1,
		1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10,1e-11,
		1e-12,1e-13,1e-14,1e-15,1e-16,1e-17,1e-18,1e-19,1e-20,1e-21,
		1e-22,1e-23,1e-24,1e-25,1e-26,1e-27,1e-28,1e-29,1e-30,1e-31,
		1e-32,1e-33,1e-34,1e-35,1e-36,1e-37,1e-38,1e-39,1e-40,1e-41,
		1e-42,1e-43,1e-44,1e-45,1e-46,1e-47,1e-48,1e-49,1e-50,1e-51,
		1e-52,1e-53,1e-54,1e-55,1e-56,1e-57,1e-58,1e-59,1e-60,1e-61,
		1e-62,1e-63,1e-64,1e-65,1e-66,1e-67,1e-68,1e-69,1e-70,1e-71,
		1e-72,1e-73,1e-74,1e-75,1e-76,1e-77,1e-78,1e-79,1e-80,1e-81,
		1e-82,1e-83,1e-84,1e-85,1e-86,1e-87,1e-88,1e-89,1e-90,1e-91,
		1e-92,1e-93,1e-94,1e-95,1e-96,1e-97,1e-98,1e-99,1e-100,1e-101,
		1e-102,1e-103,1e-104,1e-105,1e-106,1e-107,1e-108,1e-109,1e-110,1e-111,
		1e-112,1e-113,1e-114,1e-115,1e-116,1e-117,1e-118,1e-119,1e-120,1e-121,
		1e-122,1e-123,1e-124,1e-125,1e-126,1e-127,1e-128,1e-129,1e-130,1e-131,
		1e-132,1e-133,1e-134,1e-135,1e-136,1e-137,1e-138,1e-139,1e-140,1e-141,
		1e-142,1e-143,1e-144,1e-145,1e-146,1e-147,1e-148,1e-149,1e-150,1e-151,
		1e-152,1e-153,1e-154,1e-155,1e-156,1e-157,1e-158,1e-159,1e-160,1e-161,
		1e-162,1e-163,1e-164,1e-165,1e-166,1e-167,1e-168,1e-169,1e-170,1e-171,
		1e-172,1e-173,1e-174,1e-175,1e-176,1e-177,1e-178,1e-179,1e-180,1e-181,
		1e-182,1e-183,1e-184,1e-185,1e-186,1e-187,1e-188,1e-189,1e-190,1e-191,
		1e-192,1e-193,1e-194,1e-195,1e-196,1e-197,1e-198,1e-199,1e-200,1e-201,
		1e-202,1e-203,1e-204,1e-205,1e-206,1e-207,1e-208,1e-209,1e-210,1e-211,
		1e-212,1e-213,1e-214,1e-215,1e-216,1e-217,1e-218,1e-219,1e-220,1e-221,
		1e-222,1e-223,1e-224,1e-225,1e-226,1e-227,1e-228,1e-229,1e-230,1e-231,
		1e-232,1e-233,1e-234,1e-235,1e-236,1e-237,1e-238,1e-239,1e-240,1e-241,
		1e-242,1e-243,1e-244,1e-245,1e-246,1e-247,1e-248,1e-249,1e-250,1e-251,
		1e-252,1e-253,1e-254,1e-255,1e-256,1e-257,1e-258,1e-259,1e-260,1e-261,
		1e-262,1e-263,1e-264,1e-265,1e-266,1e-267,1e-268,1e-269,1e-270,1e-271,
		1e-272,1e-273,1e-274,1e-275,1e-276,1e-277,1e-278,1e-279,1e-280,1e-281,
		1e-282,1e-283,1e-284,1e-285,1e-286,1e-287,1e-288,1e-289,1e-290,1e-291,
		1e-292,1e-293,1e-294,1e-295,1e-296,1e-297,1e-298,1e-299,1e-300,1e-301,
		1e-302,1e-303,1e-304,1e-305,1e-306,1e-307,1e-308};

	
	void ToCstr(mchar * d, mint & size, mfloat dd)
	{
		const int ss = sizeof(FLOATPOWCONST) / sizeof(mfloat);
		
		size = 0;
		mbool isneg = false;
		if(dd < 0) 
		{
			isneg = true;
			dd *=-1;
			d[size] = '-';
			size++;
		}
		
		
		int at1 = 0;
		int at2 = ss;
		int mid = (at2 - at1)/2;
		while((at2 - at1) > 1)
		{
			
			if(dd > FLOATPOWCONST[mid])
			{
				at2 = mid;
			}
			else
			{
				at1 = mid;
			}
			mid = ((at2 - at1)/2) + at1;
		}
		int digi = 38 - at2;
		
		
		
		if(digi >= 19)
		{
			dd /= FLOATPOWCONST[at2];
			muchar c = (muchar)dd;
			d[size] = getNumChar(c);
			dd -= c;
			dd *=10;
			size++;
			d[size] = '.';
			size++;
			
			for(mint i = 0; i < 4 && dd != 0; i++)
			{
				muchar c = (muchar)dd;
				d[size] = getNumChar(c);
				dd -= c;
				dd *=10;
				size++;
			}
			if(dd != 0)
			{
				muchar c1 = (muchar)dd;
				dd -= c1;
				dd *= 10;
				
				muchar c2 = (muchar)dd;
				dd -= c2;
				dd *= 10;
				if(c2 >=5) c1++;
				d[size] = getNumChar(c1);
				size++;
			}
			
			d[size] = 'e';
			size++;
			
			mint size1 = 0;
			ToCstr(d +  size, size1, digi);
			size += size1;
			d[size] = 0;
		}
		else if (digi <= -6)
		{
			dd /= FLOATPOWCONST[at2];
			muchar c = (muchar)dd;
			d[size] = getNumChar(c);
			dd -= c;
			dd *=10;
			size++;
			d[size] = '.';
			size++;
			
			for(mint i = 0; i < 4 && dd != 0; i++)
			{
				muchar c = (muchar)dd;
				d[size] = getNumChar(c);
				dd -= c;
				dd *=10;
				size++;
			}
			if(dd != 0)
			{
				muchar c1 = (muchar)dd;
				dd -= c1;
				dd *= 10;
				
				muchar c2 = (muchar)dd;
				dd -= c2;
				dd *= 10;
				if(c2 >=5) c1++;
				d[size] = getNumChar(c1);
				size++;
			}
			
			d[size] = 'e';
			size++;
			
			d[size] = '-';
			size++;
			
			digi *= -1;
			mint size1 = 0;
			ToCstr(d +  size, size1, digi);
			size += size1;
			d[size] = 0;
			
			
		}
		else
		{
			
			mulong n = (mulong) dd;
			mint size1; 
			ToCstr(d + size, size1, n);
			size += size1;
			dd -= n;
			dd *=10;
			
			if(dd != 0) 
			{
				d[size] = '.';
				size++;
			}
			
			for(mint i = 0; i < 4 && dd != 0; i++)//while(dd != 0)
			{
				muchar c = (muchar)dd;
				d[size] = getNumChar(c);
				dd -= c;
				dd *=10;
				size++;
			}
			if(dd != 0)
			{
				muchar c1 = (muchar)dd;
				dd -= c1;
				dd *= 10;
				muchar c2 = (muchar)dd;
				if(c2 >= 5) c1++;
				d[size] = getNumChar(c1);
				size++;
			}
			
			
			d[size] = 0;
		}
		
	}
	
	
	void ToCstr(mchar * d, mint & size, mdouble dd)
	{
		const int ss = sizeof(DOUBLEPOWCONST) / sizeof(mdouble);
		
		size = 0;
		mbool isneg = false;
		if(dd < 0) 
		{
			isneg = true;
			dd *=-1;
			d[size] = '-';
			size++;
		}
		
		
		int at1 = 0;
		int at2 = ss;
		int mid = (at2 - at1)/2;
		while((at2 - at1) > 1)
		{
			
			if(dd > DOUBLEPOWCONST[mid])
			{
				at2 = mid;
			}
			else
			{
				at1 = mid;
			}
			mid = ((at2 - at1)/2) + at1;
		}
		int digi = 308 - at2;
		
		
		
		if(digi >= 19)
		{
			dd /= DOUBLEPOWCONST[at2];
			muchar c = (muchar)dd;
			d[size] = getNumChar(c);
			dd -= c;
			dd *=10;
			size++;
			d[size] = '.';
			size++;
			
			for(mint i = 0; i < 4 && dd != 0; i++)
			{
				muchar c = (muchar)dd;
				d[size] = getNumChar(c);
				dd -= c;
				dd *=10;
				size++;
			}
			if(dd != 0)
			{
				muchar c1 = (muchar)dd;
				dd -= c1;
				dd *= 10;
				
				muchar c2 = (muchar)dd;
				dd -= c2;
				dd *= 10;
				if(c2 >=5) c1++;
				d[size] = getNumChar(c1);
				size++;
			}
			
			d[size] = 'e';
			size++;
			
			mint size1 = 0;
			ToCstr(d +  size, size1, digi);
			size += size1;
			d[size] = 0;
		}
		else if (digi <= -6)
		{
			dd /= DOUBLEPOWCONST[at2];
			muchar c = (muchar)dd;
			d[size] = getNumChar(c);
			dd -= c;
			dd *=10;
			size++;
			d[size] = '.';
			size++;
			
			for(mint i = 0; i < 4 && dd != 0; i++)
			{
				muchar c = (muchar)dd;
				d[size] = getNumChar(c);
				dd -= c;
				dd *=10;
				size++;
			}
			if(dd != 0)
			{
				muchar c1 = (muchar)dd;
				dd -= c1;
				dd *= 10;
				
				muchar c2 = (muchar)dd;
				dd -= c2;
				dd *= 10;
				if(c2 >=5) c1++;
				d[size] = getNumChar(c1);
				size++;
			}
			
			d[size] = 'e';
			size++;
			
			d[size] = '-';
			size++;
			
			digi *= -1;
			mint size1 = 0;
			ToCstr(d +  size, size1, digi);
			size += size1;
			d[size] = 0;
			
			
		}
		else
		{
			
			mulong n = (mulong) dd;
			mint size1; 
			ToCstr(d + size, size1, n);
			size += size1;
			dd -= n;
			dd *=10;
			
			if(dd != 0) 
			{
				d[size] = '.';
				size++;
			}
			
			for(mint i = 0; i < 4 && dd != 0; i++)//while(dd != 0)
			{
				muchar c = (muchar)dd;
				d[size] = getNumChar(c);
				dd -= c;
				dd *=10;
				size++;
			}
			if(dd != 0)
			{
				muchar c1 = (muchar)dd;
				dd -= c1;
				dd *= 10;
				muchar c2 = (muchar)dd;
				if(c2 >= 5) c1++;
				d[size] = getNumChar(c1);
				size++;
			}
			
			
			d[size] = 0;
		}
		
	}
	
	




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
	
	mchar buff[1000];
	
	mdouble f1 = -1.23456789e19;
	mint size;
	ToCstr(buff, size, f1);
	cout << buff << "\r\n";
	
	/*
	
	mint size;
	mchar buff[1000];
	mulong t1, t2;
	
	
	mfloat f1 = -1234.12345;
	
	ToCstr(buff, size, f1);
	cout << buff << "\r\n";
			
	t1 = time();
	for (mfloat i = 0; i < 1000000; i++)
	{
		ToCstr(buff, size,  i);
		//stringConvert::Mint(buff, size, i);
	}
	t2 = time();
	cout << "time: "  << (t2 - t1) << "\r\n";
	cout << buff << "\r\n";
	/*
	mfloat f1 = 123456.123;
	mchar buff[100];
	int size = 0;
	ToCstr(buff, size,  f1);
	cout << buff;
	
	/*
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


