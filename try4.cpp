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




class stringConvert
{
	
	public:
	
	static mchar getNumChar(muchar i)
	{
		return (mchar) i + '0';
	}
	
	static void Mbool(mchar * d, mint & size, mbool dd)
	{
		size = 1;
		d[1] = 0;
		if(dd) d[0] = '1';
		else d[0] = '0';
	}
	// end mbool
	
	static void Muchar (mchar * d, mint & size, muchar dd)
	{
		muchar dd1;
		if(dd >= 100)
		{
			size = 3;
			d[3] = 0;
			
			dd1 = dd/100;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[2] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 10)
		{
			size = 2;
			d[2] = 0;
			
			dd1 = dd/10;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[1] = getNumChar((muchar)dd);
		}
		else
		{
			size = 1;
			d[1] = 0;
			
			d[0] = getNumChar((muchar)dd);
		}
	}
	//end muchar
	
	static void Mchar(mchar * d, mint & size, mchar dd)
	{
		size = 1;
		d[1] = 0;
		d[0] = dd;
	}
	//end mchar
	
	static void Mushort(mchar * d, mint & size, mushort dd)
	{
		//65536
		mushort dd1;
		if(dd >= 10000)
		{
			size = 5;
			d[5] = 0;
			
			dd1 = dd/10000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[4] = getNumChar((muchar)dd);
			
			
		}
		else if(dd >= 1000)
		{
			size = 4;
			d[4] = 0;
			
			dd1 = dd/1000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[3] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 100)
		{
			size = 3;
			d[3] = 0;
			
			dd1 = dd/100;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[2] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 10)
		{
			size = 2;
			d[2] = 0;
			
			dd1 = dd/10;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[1] = getNumChar((muchar)dd);
		}
		else
		{
			size = 1;
			d[1] = 0;
			
			d[0] = getNumChar((muchar)dd);
		}
	}
	//end mushort
	
	static void Mshort(mchar * d, mint & size, mshort dd)
	{
		//65536
		mshort dd1;
		if(dd >= 0)
		{
			if(dd >= 10000)
			{
				size = 5;
				d[5] = 0;
				
				dd1 = dd/10000;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[4] = getNumChar((muchar)dd);
				
				
			}
			else if(dd >= 1000)
			{
				size = 4;
				d[4] = 0;
				
				dd1 = dd/1000;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[3] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 100)
			{
				size = 3;
				d[3] = 0;
				
				dd1 = dd/100;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[2] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 10)
			{
				size = 2;
				d[2] = 0;
				
				dd1 = dd/10;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[1] = getNumChar((muchar)dd);
			}
			else
			{
				size = 1;
				d[1] = 0;
				
				d[0] = getNumChar((muchar)dd);
			}
		}
		else // do the negative_sign
		{
			d[0] = '-';
			dd *=-1;
			if(dd >= 10000)
			{
				size = 6;
				d[6] = 0;
				
				dd1 = dd/10000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[5] = getNumChar((muchar)dd);
				
				
			}
			else if(dd >= 1000)
			{
				size = 5;
				d[5] = 0;
				
				dd1 = dd/1000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[4] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 100)
			{
				size = 4;
				d[4] = 0;
				
				dd1 = dd/100;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[3] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 10)
			{
				size = 3;
				d[3] = 0;
				
				dd1 = dd/10;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[2] = getNumChar((muchar)dd);
			}
			else
			{
				size = 2;
				d[2] = 0;
				
				d[1] = getNumChar((muchar)dd);
			}
		}
	}// end of short conversion.
	//end mshort
	
	static void Muint(mchar * d, mint & size, muint dd)
	{
		//4,294,967,295
		muint dd1;
		if(dd >= 1000000000)
		{
			size = 10;
			d[10] = 0;
			
			dd1 = dd/1000000000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000000);
			
			dd1 = dd/100000000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000000);
			
			dd1 = dd/10000000;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000000);
			
			dd1 = dd/1000000;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000);
			
			dd1 = dd/100000;
			d[4] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000);
			
			dd1 = dd/10000;
			d[5] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[6] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[7] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[8] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[9] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 100000000)
		{
			size = 9;
			d[9] = 0;
			
			dd1 = dd/100000000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000000);
			
			dd1 = dd/10000000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000000);
			
			dd1 = dd/1000000;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000);
			
			dd1 = dd/100000;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000);
			
			dd1 = dd/10000;
			d[4] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[5] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[6] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[7] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[8] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 10000000)
		{
			size = 8;
			d[8] = 0;
			
			dd1 = dd/10000000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000000);
			
			dd1 = dd/1000000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000);
			
			dd1 = dd/100000;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000);
			
			dd1 = dd/10000;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[4] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[5] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[6] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[7] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 1000000)
		{
			size = 7;
			d[7] = 0;
			
			dd1 = dd/1000000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000);
			
			dd1 = dd/100000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000);
			
			dd1 = dd/10000;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[4] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[5] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[6] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 100000)
		{
			size = 6;
			d[6] = 0;
			
			dd1 = dd/100000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000);
			
			dd1 = dd/10000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[4] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[5] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 10000)
		{
			size = 5;
			d[5] = 0;
			
			dd1 = dd/10000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[4] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 1000)
		{
			size = 4;
			d[4] = 0;
			
			dd1 = dd/1000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[3] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 100)
		{
			size = 3;
			d[3] = 0;
			
			dd1 = dd/100;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[2] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 10)
		{
			size = 2;
			d[2] = 0;
			
			dd1 = dd/10;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[1] = getNumChar((muchar)dd);
			
		}
		else 
		{
			size = 1;
			d[1] = 0;
			
			d[0] = getNumChar((muchar)dd);
			
		}
	}
	//end muint
	
	static void Mint(mchar * d, mint & size, mint dd)
	{
		mint dd1;
		if(dd >= 0)
		{
			if(dd >= 1000000000)
			{
				size = 10;
				d[10] = 0;
				
				dd1 = dd/1000000000;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000000000);
				
				dd1 = dd/100000000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000000);
				
				dd1 = dd/10000000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000000);
				
				dd1 = dd/1000000;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000000);
				
				dd1 = dd/100000;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000);
				
				dd1 = dd/10000;
				d[5] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[6] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[7] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[8] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[9] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 100000000)
			{
				size = 9;
				d[9] = 0;
				
				dd1 = dd/100000000;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000000);
				
				dd1 = dd/10000000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000000);
				
				dd1 = dd/1000000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000000);
				
				dd1 = dd/100000;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000);
				
				dd1 = dd/10000;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[5] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[6] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[7] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[8] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 10000000)
			{
				size = 8;
				d[8] = 0;
				
				dd1 = dd/10000000;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000000);
				
				dd1 = dd/1000000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000000);
				
				dd1 = dd/100000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000);
				
				dd1 = dd/10000;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[5] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[6] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[7] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 1000000)
			{
				size = 7;
				d[7] = 0;
				
				dd1 = dd/1000000;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000000);
				
				dd1 = dd/100000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000);
				
				dd1 = dd/10000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[5] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[6] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 100000)
			{
				size = 6;
				d[6] = 0;
				
				dd1 = dd/100000;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000);
				
				dd1 = dd/10000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[5] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 10000)
			{
				size = 5;
				d[5] = 0;
				
				dd1 = dd/10000;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[4] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 1000)
			{
				size = 4;
				d[4] = 0;
				
				dd1 = dd/1000;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[3] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 100)
			{
				size = 3;
				d[3] = 0;
				
				dd1 = dd/100;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[2] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 10)
			{
				size = 2;
				d[2] = 0;
				
				dd1 = dd/10;
				d[0] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[1] = getNumChar((muchar)dd);
				
			}
			else 
			{
				size = 1;
				d[1] = 0;
				
				d[0] = getNumChar((muchar)dd);
				
			}
			
		}
		else
		{
			dd *= -1;
			d[0] = '-';
			if(dd >= 1000000000)
			{
				size = 11;
				d[11] = 0;
				
				dd1 = dd/1000000000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000000000);
				
				dd1 = dd/100000000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000000);
				
				dd1 = dd/10000000;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000000);
				
				dd1 = dd/1000000;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000000);
				
				dd1 = dd/100000;
				d[5] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000);
				
				dd1 = dd/10000;
				d[6] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[7] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[8] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[9] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[10] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 100000000)
			{
				size = 10;
				d[10] = 0;
				
				dd1 = dd/100000000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000000);
				
				dd1 = dd/10000000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000000);
				
				dd1 = dd/1000000;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000000);
				
				dd1 = dd/100000;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000);
				
				dd1 = dd/10000;
				d[5] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[6] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[7] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[8] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[9] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 10000000)
			{
				size = 9;
				d[9] = 0;
				
				dd1 = dd/10000000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000000);
				
				dd1 = dd/1000000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000000);
				
				dd1 = dd/100000;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000);
				
				dd1 = dd/10000;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[5] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[6] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[7] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[8] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 1000000)
			{
				size = 8;
				d[8] = 0;
				
				dd1 = dd/1000000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000000);
				
				dd1 = dd/100000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000);
				
				dd1 = dd/10000;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[5] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[6] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[7] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 100000)
			{
				size = 7;
				d[7] = 0;
				
				dd1 = dd/100000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100000);
				
				dd1 = dd/10000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[5] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[6] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 10000)
			{
				size = 6;
				d[6] = 0;
				
				dd1 = dd/10000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10000);
				
				dd1 = dd/1000;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[4] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[5] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 1000)
			{
				size = 5;
				d[5] = 0;
				
				dd1 = dd/1000;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 1000);
				
				dd1 = dd/100;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[3] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[4] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 100)
			{
				size = 4;
				d[4] = 0;
				
				dd1 = dd/100;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 100);
				
				dd1 = dd/10;
				d[2] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[3] = getNumChar((muchar)dd);
				
			}
			else if(dd >= 10)
			{
				size = 3;
				d[3] = 0;
				
				dd1 = dd/10;
				d[1] = getNumChar((muchar)dd1);
				dd -= (dd1 * 10);
				
				d[2] = getNumChar((muchar)dd);
				
			}
			else 
			{
				size = 2;
				d[2] = 0;
				
				d[1] = getNumChar((muchar)dd);
				
			}
			
		}
			
	}
	//end mint
	
	static void Mulong(mchar * d, mint & size, mulong dd)
	{
		//18,446,744,073,709,551,616
		mulong dd1;
		if(dd >= 10000000000000000000UL)
		{
			size = 20;
			d[20] = 0;
			
			dd1 = dd/10000000000000000000UL;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000000000000000000UL);
			
			dd1 = dd/1000000000000000000UL;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000000000000000UL);
		}
		
		
		
		
		
		else if(dd >= 1000000000)
		{
			size = 10;
			d[10] = 0;
			
			dd1 = dd/1000000000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000000);
			
			dd1 = dd/100000000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000000);
			
			dd1 = dd/10000000;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000000);
			
			dd1 = dd/1000000;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000);
			
			dd1 = dd/100000;
			d[4] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000);
			
			dd1 = dd/10000;
			d[5] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[6] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[7] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[8] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[9] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 100000000)
		{
			size = 9;
			d[9] = 0;
			
			dd1 = dd/100000000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000000);
			
			dd1 = dd/10000000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000000);
			
			dd1 = dd/1000000;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000);
			
			dd1 = dd/100000;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000);
			
			dd1 = dd/10000;
			d[4] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[5] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[6] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[7] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[8] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 10000000)
		{
			size = 8;
			d[8] = 0;
			
			dd1 = dd/10000000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000000);
			
			dd1 = dd/1000000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000);
			
			dd1 = dd/100000;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000);
			
			dd1 = dd/10000;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[4] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[5] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[6] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[7] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 1000000)
		{
			size = 7;
			d[7] = 0;
			
			dd1 = dd/1000000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000000);
			
			dd1 = dd/100000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000);
			
			dd1 = dd/10000;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[4] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[5] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[6] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 100000)
		{
			size = 6;
			d[6] = 0;
			
			dd1 = dd/100000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100000);
			
			dd1 = dd/10000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[4] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[5] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 10000)
		{
			size = 5;
			d[5] = 0;
			
			dd1 = dd/10000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10000);
			
			dd1 = dd/1000;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[3] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[4] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 1000)
		{
			size = 4;
			d[4] = 0;
			
			dd1 = dd/1000;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 1000);
			
			dd1 = dd/100;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[2] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[3] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 100)
		{
			size = 3;
			d[3] = 0;
			
			dd1 = dd/100;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 100);
			
			dd1 = dd/10;
			d[1] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[2] = getNumChar((muchar)dd);
			
		}
		else if(dd >= 10)
		{
			size = 2;
			d[2] = 0;
			
			dd1 = dd/10;
			d[0] = getNumChar((muchar)dd1);
			dd -= (dd1 * 10);
			
			d[1] = getNumChar((muchar)dd);
			
		}
		else 
		{
			size = 1;
			d[1] = 0;
			
			d[0] = getNumChar((muchar)dd);
			
		}
	}
	//end muint
	
};

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
	
	mulong t1, t2;
	t1 = time();
	for(mint i = 0; i < 1000000000; i++)
	{
	
		stringConvert::Mint(buff, size, i);
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
	*/
	
	return 0;
}


