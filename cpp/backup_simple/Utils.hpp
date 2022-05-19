#ifndef UTILS_HPP
#define UTILS_HPP
#include <stdio.h>
#include <stdint.h>
#include <string>
#include <functional>

using namespace std;


class TypeId
{
	static bool isnum(char c)
	{
		if(c>='0' && c<='9' || c=='.') return true;
		return false;
	}
	public:
	template<class N>
	static uint64_t GetId()
	{
		static hash<string> strhash;
		string n = typeid(N).name();
		
		string name;
		string baseName;
		if(n[0] =='A')
		{
			int32_t i= 0;
			int32_t at= 1;
			while(isnum(n[at]))
			{
				i = i * 10 + ((int32_t)n[at]-(int32_t)'0');
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
uint64_t GetClassId()
{
	static uint64_t id = TypeId::GetId<N>();
	return id;
}

#define MakeID(...) static uint64_t Id()\
{\
    static uint64_t id = GetClassId<__VA_ARGS__>();\
    return id;\
}\

template<class N>
class Ref
{
	public:
	N * n = 0;
	int * count = 0;
	Ref()
	{
		n = new N;
		count = new int;
		(*count) = 1;
	}
	Ref(const Ref<N> & p)
	{
		n = p.n;
		count = p.count;
		(*count)++;
	}
	template<class A>
	Ref(A * a)
	{
		n = a;
		count = new int;
		(*count) = 1;
	}

	~Ref()
	{
		(*count)--;
		if((*count) <=0)
		{
			delete(n);
			delete(count);
		}
	}
	Ref<N> & operator=(const Ref<N> & p)
	{
		(*count)--;
		if((*count)<=0)
		{
			delete(n);
			delete(count);
		}
		n = p.n;
		count = p.count;
		(*count)++;
		return (*this);
	}
	N* operator->()
	{
		return n;
	}
	
	N& operator *()
	{
		return (*n);
	}
	
	N* Ptr()
	{
		return n;
	}
	
	void Release()
	{
		(*count)--;
		if((*count) <=0)
		{
			delete(n);
			delete(count);
		}
		n = new N;
		count = new int;
		(*count) = 1;
	}
};

#endif
