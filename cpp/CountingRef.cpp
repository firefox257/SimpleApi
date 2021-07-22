///Do not use use smart pointers wrapper. 


#ifndef COUNTINGREF_CPP
#define COUTNIGNREF_CPP
#include "Types.hpp"


template<class PARENT, class NODE>
class CountingRef
{
	protected:
	NODE * ref =0;
	mint * count =0;
	public:
	
	
	CountingRef()
	{
		ref = new NODE;
		count = new mint;
		(*count) = 1;
	}
	CountingRef(const PARENT & p)
	{
		ref = p.ref;
		count = p.count;
		(*count)++;
	}
	~CountingRef()
	{
		(*count)--;
		if((*count) <=0)
		{
			delete(count);
			delete(ref);
			count = 0;
			ref = 0;
		}
	}
	
	void refequals(const PARENT & p)
	{
		(*count)--;
		if((*count) <=0)
		{
			delete(ref);
			delete(count);
			
		}
		ref = p.ref;
		count = p.count;
		(*count)++;
	}
	
	
};

//This is method cascading. 
//Exapmle obj.x(123).title("hi there"); 

//create cascading method with a getter and setter. 
#define $cm(T, NA, G, S) T & NA() G CMPARENT & NA(const T & v) {S  return (*((CMPARENT*)this));}

//create a cascading methode that is simple for a getter setter, pointing to the backer variable. 
#define $scm(T, NA, B) T & NA(){ return B;} CMPARENT & NA(const T & v) { B = v; return (*((CMPARENT*)this));}


/*

only stright classes can be used. 
Templetes with CountingRef currently don't work. 

example: 
struct crtry1data
{
	int x;
	int y;
};
class crtry1: public countingref<crtry1, crtry1data>
{
	public:
	typedef crtry1 CMPARENT;
	$cm(int, x,
	{
		
		return ref->x;
	}, 
	{
		
		ref->x = v;
	});
	$scm(int, y, ref->y);
	
	crtry1()
	{
		
	}
	crtry1(int xx, int yy)
	{
		x(xx).y(yy);
	}
	//**** must implement in other class to over ride default copy functionality. 
	crtry1 & operator = (const crtry1 & n)
	{
		refequals(n);
		return (*this);
	}
	datastream(crtry1,
	{
		out << o.x() << o.y();
	},
	{
		in >> o.x() >> o.y();
	});
};
*/

#endif