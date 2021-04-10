#ifndef STRING_CPP
#define STRING_CPP


#include <string>
#include <stdio.h>
#include <string.h>
#include "types.cpp"
using namespace std;


class StringBuffer;

class String
{
	mchar * d= 0;
	mulong _size= 0;
	mulong getsize(char * str)
	{
		mulong l = 0;
		while(str[l] != 0) l++;
		return l;
	}
	
	public:
	String()
	{
		
	}
	String (const char * str)
	{
		mulong size = getsize((char*)str);
		setsize(size);
		memcpy(d, str, size);
	}
	String(const String & str)
	{
		setsize(str._size);
		memcpy(d, str.d, str._size);
	}
	template<class N>
	String(N n)
	{
		string str = to_string(n);
		setsize(str.size());
		memcpy(d, str.c_str(), _size);
	}
	String (StringBuffer & sb);
	
	inline mulong size()
	{
		return _size;
	}
	String & operator = (const char * str)
	{
		mulong size = getsize((char*)str);
		setsize(size);
		memcpy(d, str, size);
		return (*this);
	}
	
	mchar * cstr()
	{
		if(_size == 0)
		{
			return (mchar*)"";
		}
		return d;
	}
	
	template<class N>
	String & operator = (N n)
	{
		string str = to_string(n);
		setsize(str.size());
		memcpy(d, str.c_str(), _size);
		return (*this);
	}
	
	void setsize(mulong size)
	{
		if(_size == 0)
		{
			d = (mchar*)malloc(size +1);
		}
		else if(_size != size)
		{
			d = (mchar*)realloc(d, size + 1);
		}
		_size = size;
		d[size] = 0;
	}
	
	friend ostream & operator << (ostream & out , const String & str)
	{
		out << str.d;
		return out;
	}
	
	
	mbool operator <= (const String & str) const
	{
		mulong minsize = _size;
		if(str._size < minsize) minsize = str._size;
		for(mulong i = 0; i < minsize; i++)
		{
			if(d[i] > str.d[i]) return false;
		}
		if(_size > str._size) return false;
		return true;
		
	}
	mbool operator >= (const String & str) const
	{
		mulong minsize = _size;
		if(str._size < minsize) minsize = str._size;
		for(mulong i = 0; i < minsize; i++)
		{
			if(d[i] < str.d[i]) return false;
		}
		if(_size < str._size) return false;
		return true;
		
	}
	
	mbool operator < (const String & str) const
	{
		return !((*this) >= str);
	}
	mbool operator > (const String & str) const
	{
		return !((*this) <= str);
	}
	mbool operator == (const String & str) const
	{
		if(_size != str._size) return false;
		for(mulong i = 0; i < _size; i++)
		{
			if(d[i] != str.d[i]) return false;
		}
		return true;
	}
	mbool operator != (const String & str) const
	{
		return !((*this) == str);
	}
	
	void operator = (StringBuffer & sb);
	
	
};

class StringBuffer
{
	list<String> _list;
	public:
	StringBuffer()
	{
		
	}
	
	template<class N>
	StringBuffer(N n)
	{
		_list.push_back((String)n);
	}
	
	template<class N>
	StringBuffer & operator + (N n)
	{
		_list.push_back((String)n);
		return (*this);
	}
	
	void toString(String & str)
	{
		mulong size = 0;
		for(auto i: _list)
		{
			size += i.size();
		}
		str.setsize(size);
		mchar * ptr = str.cstr();
		
		mulong at = 0;
		for(auto i: _list)
		{
			mchar * ptr1 = i.cstr();
			mulong size1 = i.size();
			mchar * ptr2 = (mchar*)((mulong)ptr + at);
			memcpy(ptr2, ptr1, size1);
			at+= size1;
		}
		
	}
	
	
};


void String::operator = (StringBuffer & sb)
{
	sb.toString((*this));
}

String::String(StringBuffer & sb)
{
	sb.toString((*this));
}


#endif
