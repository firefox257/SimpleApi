#ifndef TYPES_HPP
#define TYPES_HPP
#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;
typedef bool mbool;
typedef uint8_t muchar;
typedef char mchar;
typedef uint16_t mushort;
typedef int16_t mshort;
typedef uint32_t muint;
typedef int32_t mint;
typedef uint64_t mulong;
typedef int64_t mlong;
typedef float mfloat;
typedef double mdouble;


class TypeInfo
{
	mbool isnum(mchar c);
	
	template<class N>
	void setInfo();
	public:
	mbool isArray = false;
	mbool isPointer = false;
	string name = "";
	string baseName = "";
	mint arraySize=0;
	mint typeSize = 0;
	
	template<class N>
	TypeInfo();
	template<class N>
	TypeInfo(const N & a);
};


class TypeId
{
	static mbool isnum(mchar c)
	{
		if(c>='0' && c<='9' || c=='.') return true;
		return false;
	}
	public:
	template<class N>
	static mulong GetId()
	{
		static hash<string> strhash;
		string n = typeid(N).name();
		
		string name;
		string baseName;
		if(n[0] =='A')
		{
			mint i= 0;
			mint at= 1;
			while(isnum(n[at]))
			{
				i = i * 10 + ((mint)n[at]-(mint)'0');
				at++;
			}
			at++;
			baseName = n.substr(at, n.size()).c_str();
			name = "A_" + baseName;
			
		}
		else
		{
			name = n.c_str();
		}
		
		return strhash(name);
		
	}
};

template<class N>
mulong GetClassId()
{
	static mulong id = TypeId::GetId<N>();
	return id;
}

#endif