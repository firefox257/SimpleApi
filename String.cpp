#ifndef STRING_CPP
#define STRING_CPP
#include <ostream>
#include <list>
#include <string>
#include <stdio.h>
#include <string.h>
#include "Types.cpp"
#include "String.hpp"
using namespace std;


class StringBuffer;

	mulong String::getsize(mchar * str)
	{
		mulong l = 0;
		while(str[l] != 0) l++;
		return l;
	}
	
	
	String::String()
	{
		
	}
	String::String (mchar * str)
	{
		mulong size = getsize((mchar*)str);
		setsize(size);
		memcpy(d, str, size);
	}
	String::String (const mchar * str)
	{
		mulong size = getsize((mchar*)str);
		setsize(size);
		memcpy(d, str, size);
	}
	String::String(const String & str)
	{
		setsize(str._size);
		memcpy(d, str.d, str._size);
	}
	template<class N>
	String::String(N n)
	{
		string str = to_string(n);
		setsize(str.size());
		memcpy(d, str.c_str(), _size);
	}
	
	String::String(StringBuffer & sb)
	{
		sb.ToString((*this));
	}
	
	inline mulong String::Size()
	{
		return _size;
	}
	String & String::operator = (const mchar * str)
	{
		mulong size = getsize((mchar*)str);
		setsize(size);
		memcpy(d, str, size);
		return (*this);
	}
	
	mchar * String::cstr()
	{
		if(_size == 0)
		{
			return (mchar*)"";
		}
		return d;
	}
	
	template<class N>
	String & String::operator = (const N & n)
	{
		string str = to_string(n);
		setsize(str.size());
		memcpy(d, str.c_str(), _size);
		return (*this);
	}
	
	void String::setsize(mulong size)
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
	
	mbool String::operator <= (const String & str) const
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
	mbool String::operator >= (const String & str) const
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
	
	mbool String::operator < (const String & str) const
	{
		return !((*this) >= str);
	}
	mbool String::operator > (const String & str) const
	{
		return !((*this) <= str);
	}
	mbool String::operator == (const String & str) const
	{
		if(_size != str._size) return false;
		for(mulong i = 0; i < _size; i++)
		{
			if(d[i] != str.d[i]) return false;
		}
		return true;
	}
	mbool String::operator != (const String & str) const
	{
		return !((*this) == str);
	}
	void String::operator = (StringBuffer & sb)
	{
		sb.ToString((*this));
	}
	
	
	
	
	


	StringBuffer::StringBuffer()
	{
		
	}
	
	template<class N>
	StringBuffer::StringBuffer(N n)
	{
		_list.push_back((String)n);
	}
	
	template<class N>
	StringBuffer & StringBuffer::operator + (N n)
	{
		_list.push_back((String)n);
		return (*this);
	}
	
	void StringBuffer::ToString(String & str)
	{
		mulong size = 0;
		for(auto i: _list)
		{
			size += i.Size();
		}
		str.setsize(size);
		mchar * ptr = str.cstr();
		
		mulong at = 0;
		for(auto i: _list)
		{
			mchar * ptr1 = i.cstr();
			mulong size1 = i.Size();
			mchar * ptr2 = (mchar*)((mulong)ptr + at);
			memcpy(ptr2, ptr1, size1);
			at+= size1;
		}
		
	}
	
	







#endif