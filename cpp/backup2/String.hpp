#ifndef STRING_HPP
#define STRING_HPP
#include <ostream>
#include <list>
#include <string>
#include <stdio.h>
#include <string.h>
#include "Types.hpp"
using namespace std;


class StringBuffer;

class String
{
	mchar * d= 0;
	mulong _size= 0;
	mulong getsize(mchar * str);
	
	public:
	String();
	String (mchar * str);
	String (const mchar * str);
	String(const String & str);
	template<class N>
	String(N n);
	String (StringBuffer & sb);
	
	inline mulong Size();
	String & operator = (const mchar * str);
	
	mchar * cstr();
	
	template<class N>
	String & operator = (const N & n);
	
	void setsize(mulong size);
	
	mbool operator <= (const String & str) const;
	mbool operator >= (const String & str) const;
	
	mbool operator < (const String & str) const;
	mbool operator > (const String & str) const;
	mbool operator == (const String & str) const;
	mbool operator != (const String & str) const;
	
	void operator = (StringBuffer & sb);
	
	friend ostream & operator << (ostream & out , const String & str)
	{
		out << str.d;
		return out;
	}
	
};

class StringBuffer
{
	list<String> _list;
	public:
	StringBuffer();
	
	template<class N>
	StringBuffer(N n);
	
	template<class N>
	StringBuffer & operator + (N n);
	
	void ToString(String & str);
};





#endif