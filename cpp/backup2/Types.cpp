#ifndef TYPES_CPP
#define TYPES_CPP

#include "Types.hpp"

	mbool TypeInfo::isnum(mchar c)
	{
		if(c>='0' && c<='9' || c=='.') return true;
		return false;
	}
	template<class N>
	void TypeInfo::setInfo()
	{
		string n = typeid(N).name();
		
		
		if(n[0] =='A')
		{
			isArray = true;
			mint i= 0;
			mint at= 1;
			while(isnum(n[at]))
			{
				i = i * 10 + ((mint)n[at]-(mint)'0');
				at++;
			}
			arraySize = i;
			at++;
			baseName = n.substr(at, n.size()).c_str();
			//name = n.c_str();
			name = "A_" + baseName;
			typeSize = sizeof(N)/arraySize;
			
		}
		else
		{
			name = n.c_str();
			typeSize=sizeof(N);
		}
		if(name[0] == 'P') isPointer = true;
	}
	template<class N>
	TypeInfo::TypeInfo()
	{
		setInfo<N>();
	}
	template<class N>
	TypeInfo::TypeInfo(const N & a)
	{
		setInfo<N>();
	}
	


#endif