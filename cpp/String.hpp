#ifndef STRING_HPP
#define STRING_HPP

#include <list>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
using namespace std;


class StringBuffer;

class String
{
	char * d= 0;
	uint64_t _size= 0;
	uint64_t getsize(char * str)
	{
		uint64_t l = 0;
		while(str[l] != 0) l++;
		return l;
	}
	
	public:
	String()
	{
		
	}
	String (const char * str)
	{
		uint64_t size = getsize((char*)str);
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
	
	inline uint64_t size()
	{
		return _size;
	}
	String & operator = (const char * str)
	{
		uint64_t size = getsize((char*)str);
		setsize(size);
		memcpy(d, str, size);
		return (*this);
	}
	
	char * cstr()
	{
		if(_size == 0)
		{
			return (char*)"";
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
	
	void setsize(uint64_t size)
	{
		if(_size == 0)
		{
			d = (char*)malloc(size +1);
		}
		else if(_size != size)
		{
			d = (char*)realloc(d, size + 1);
		}
		_size = size;
		d[size] = 0;
	}
	
	friend ostream & operator << (ostream & out , const String & str)
	{
		out << str.d;
		return out;
	}
	
	
	bool operator <= (const String & str) const
	{
		uint64_t minsize = _size;
		if(str._size < minsize) minsize = str._size;
		for(uint64_t i = 0; i < minsize; i++)
		{
			if(d[i] > str.d[i]) return false;
		}
		if(_size > str._size) return false;
		return true;
		
	}
	bool operator >= (const String & str) const
	{
		uint64_t minsize = _size;
		if(str._size < minsize) minsize = str._size;
		for(uint64_t i = 0; i < minsize; i++)
		{
			if(d[i] < str.d[i]) return false;
		}
		if(_size < str._size) return false;
		return true;
		
	}
	
	bool operator < (const String & str) const
	{
		return !((*this) >= str);
	}
	bool operator > (const String & str) const
	{
		return !((*this) <= str);
	}
	bool operator == (const String & str) const
	{
		if(_size != str._size) return false;
		for(uint64_t i = 0; i < _size; i++)
		{
			if(d[i] != str.d[i]) return false;
		}
		return true;
	}
	bool operator != (const String & str) const
	{
		return !((*this) == str);
	}
	
	void operator = (StringBuffer & sb);
	
    friend ostream & operator  << (ostream & out, String & o)
    {
        out << o.cstr();
        return out;
    }
    friend istream & operator >> (istream & in, String & o)
    {
        throw "Not implemented";
        //return in;
    }
	
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
		uint64_t size = 0;
		for(auto i: _list)
		{
			size += i.size();
		}
		str.setsize(size);
		char * ptr = str.cstr();
		
		uint64_t at = 0;
		for(auto i: _list)
		{
			char * ptr1 = i.cstr();
			uint64_t size1 = i.size();
			char * ptr2 = (char*)((uint64_t)ptr + at);
			memcpy(ptr2, ptr1, size1);
			at+= size1;
		}
		
	}

    friend ostream & operator  << (ostream & out, StringBuffer & o)
    {
       for(auto i: o._list)
       {
           out << i.cstr();
       }
        return out;
    }
    friend istream & operator >> (istream & in, StringBuffer & o)
    {
        throw "Not implemented";
        //return in;
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