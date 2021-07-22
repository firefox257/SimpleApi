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

#include <fstream>
#include "Types.cpp"
#include "String.cpp"
#include "DataIO.cpp"
#include "Array.cpp"
#include "List.cpp"
#include "Map.cpp"
#include "Async.cpp"
#include "CountingRef.cpp"

using namespace std;
#define el << "\r\n"



struct windowStruct
{
	String title= "";
	mint x= 0;
	mint y= 0;
	mint w= 0;
	mint h= 0;
};

class window: public CountingRef<window, windowStruct>
{
	typedef window CMPARENT;
	public:
	
	$cm(String, title, 
	{
		
		return n->title;
	},
	{
		n->title = v;
		//do stuff to set window
	});
	$scm(mint, x, n->x);
	$scm(mint, y, n->y);
	$scm(mint, w, n->w);
	$scm(mint, h, n->h);
	
	$datastream(window, 
	{
		out 
		<< o.n->title 
		<< o.n->x 
		<< o.n->y 
		<< o.n->w 
		<< o.n->h;
	
	},
	{
		in 
		>> o.n->title 
		>> o.n->x 
		>> o.n->y 
		>> o.n->w 
		>> o.n->h;
	});
	
	friend ostream & operator << (ostream & out, window & o)
	{
		out << o.title() el << o.x() el << o.y() el << o.w() el << o.h() el;
		return out;
	}
	
};




/*

template<int S>
class dbConstString
{
	
	
	static mbool equals(const mchar * str1, const mchar * str2)
	{
		mint at = 0;
		while(str1[at] != 0 && str2[at] != 0)
		{
			if(str1[at] != str2[at]) return false;
			at++;
		}
		if(str1[at] != str2[at]) return false;
		return true;
	}
	
	static mbool less(const mchar * str1, const mchar * str2)
	{
		mint at = 0;
		while(str1[at] != 0 && str2[at] != 0)
		{
			if(str1[at] < str2[at])return true;
			else if(str1[at] > str2[at]) return false;
			at++;
		}
		if(str1[at] < str2[at]) return true;
		return false;
		
	}
	
	static mbool more(const mchar * str1, const mchar * str2)
	{
		mint at = 0;
		while(str1[at] != 0 && str2[at] != 0)
		{
			if(str1[at] > str2[at])return true;
			else if(str1[at] < str2[at]) return false;
			at++;
		}
		if(str1[at] > str2[at]) return true;
		return false;
	}
	
	char v[S];
	public:
	
	dbConstString()
	{
		v[0] = 0;
	}
	
	void Set(const mchar * str)
	{
		mint at = 0;
		while(str[at] != 0)
		{
			v[at] = str[at];
			at++;
		}
		v[at] = 0;
	}
	operator mchar*()
	{
		return v;
	}
	
	
	
	
	mbool operator == (const mchar * str)
	{
		return equals(v, str);
	}
	friend mbool operator == (const mchar * str, const dbConstString<S> & o)
	{
		return equals(str, o.v);
	}
	mbool operator == (const dbConstString & str)
	{
		return equals(v, str.v);
	}
	
	mbool operator < (const mchar * str)
	{
		return less(v, str);
	}
	friend mbool operator < (const mchar * str, const dbConstString<S> & o)
	{
		return less(str, o.v);
	}
	mbool operator < (const dbConstString & str)
	{
		return less(v, str.v);
	}
	
	mbool operator > (const mchar * str)
	{
		return more(v, str);
	}
	friend mbool operator > (const mchar * str, const dbConstString<S> & o)
	{
		return more(str, o.v);
	}
	mbool operator > (const dbConstString & str)
	{
		return more(v, str.v);
	}
	
	mbool operator <= (const mchar * str)
	{
		return !more(v, str);
	}
	friend mbool operator <= (const mchar * str, const dbConstString<S> & o)
	{
		return !more(str, o.v);
	}
	mbool operator <= (const dbConstString & str)
	{
		return !more(v, str.v);
	}
	
	mbool operator >= (const mchar * str)
	{
		return !less(v, str);
	}
	friend mbool operator >= (const mchar * str, const dbConstString<S> & o)
	{
		return !less(str, o.v);
	}
	mbool operator >= (const dbConstString & str)
	{
		return !less(v, str.v);
	}
	
	
	
};
#define dbConstStringHeader(T)\
	T()\
	{\
	}\
	T(const mchar * str)\
	{\
		Set(str);\
	}\
	T(mchar * str)\
	{\
		Set(str);\
	}\
	T & operator = (const mchar * str)\
	{\
		Set(str);\
		return (*this);\
	}\
	T & operator = (mchar * str)\
	{\
		Set(str);\
		return (*this);\
	}

class dbBool
{
	mbool b;
	public:
	dbBool()
	{
		
	}
	
	void Set(const mbool & bb)
	{
		b = bb;
	}
	operator mbool &()
	{
		return b;
	}
};
#define dbBoolHeader(T)\
	T()\
	{\
	}\
	T( mbool bb)\
	{\
		Set(bb);\
	}\
	T & operator =(mbool bb)\
	{\
		Set(bb);\
		return (*this);\
	}

class dbInt
{
	mint b;
	public:
	dbInt()
	{
		
	}
	
	void Set(const mint & bb)
	{
		b = bb;
	}
	operator mint &()
	{
		return b;
	}
	
	dbBool & operator = (const mint & bb)
	{
		b = bb;
		return (*this);
	}
};
#define dbIntHeader(T)\
	T()\
	{\
	}\
	T( mint bb)\
	{\
		Set(bb);\
	}\
	T & operator =(mint bb)\
	{\
		Set(bb);\
		return (*this);\
	}


class Person
{
	public:
	
	class Name: public dbConstString<30>
	{
		public:
		dbConstStringHeader(Name);
		static mbool indexed()
		{
			return true;
		}
	};
	
	class IsActive: public dbBool
	{
		public:
		dbBoolHeader(IsActive);
		static mbool indexed()
		{
			return false;
		}
	};
	class Count
	{
		
	
	private:
	Name firstNameField;
	Name lastNameField;
	IsActive isActiveField;
	public:
	
	typedef Person CMPARENT;
	$scm(Name, firstName, firstNameField);
	$scm(Name, lastName, lastNameField);
	$scm(IsActive, isActive, isActiveField);
	
	void func()
	{
		cout << typeid(Name).name() el;
	}
	
};

//*/


class Indexed
{
	public:
	static const mbool Indexed = true;
};
class NotIndexed
{
	public:
	static const mbool Indexed = false;
};

class dbBool
{
	
	
};



int main()
{
	
	
	
	cout << sizeof(Person) el;
	
	Person::Name n1;
	n1 = " asdf";
	Person p;
	p.func();
	
	
	
	
	
	/*window w1;
	
	w1.x(1).y(1).title("Main title").w(1000).h(700);
	DataFileWriter dw("try1.bin");
	dw << w1;
	dw.Close();*/
	
	/*
	DoneState done1;
	
	window w2;
	AsyncRun([&w2]()
	{
		DataFileReader dr("try1.bin");
		dr >> w2;
		dr.Close();
	}, done1);
	
	
	WaitFor(done1);
	
	cout << w2;
	*/

	return 0;
}