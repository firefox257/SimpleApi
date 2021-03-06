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

#include "Async.cpp"
#include "SmtPtr.hpp"
#include "Mapper.cpp"
#include "Factory.cpp"

using namespace std;
#define el << "\r\n"



/*

template<class ...Args>
class MapperObject
{
	static function<void(Args & ...)>  * mapfunc;
	public:
	static void set(function<void (Args & ...)> func)
	{
		if(mapfunc != 0)
		{
			delete(mapfunc);
		}
		mapfunc = new function<void (Args & ...)>;
		(*mapfunc) = func;
	}
	static void call(Args & ... args)
	{
		(*mapfunc)(args...);
	}
	static mbool has()
	{
		return mapfunc != 0;
	}
	
};
template<class ... Args>
function<void(Args & ...)> * MapperObject<Args...>::mapfunc = 0;

template<class A, class B>
void mapper(function<void(A & a, B & b)> func)
{
	MapperObject<A, B>::set(func);
}


template<class A, class B, class C>
void mapper(function<void(A & a, B & b, C & c)> func)
{
	MapperObject<A, B, C>::set(func);
}

template<class A, class B, class C, class D>
void mapper(function<void(A & a, B & b, C & c, D & d)> func)
{
	MapperObject<A, B, C, D>::set(func);
}


template<class A, class B>
void mapper(A & a, B & b)
{
	if(MapperObject<A, B>::has())
	{
		MapperObject<A, B>::call(a, b);
	}
}

template<class A, class B, class C>
void mapper(A & a, B & b, C & c)
{
	if(MapperObject<A, B, C>::has())
	{
		MapperObject<A, B, C>::call(a, b, c);
	}
	else if(MapperObject<A, C, B>::has())
	{
		MapperObject<A, C, B>::call(a, c, b);
	}
	else
	{
		//cout << "no mapper" el;
	}
}


template<class A, class B, class C, class D>
void mapper(A & a, B & b, C & c, D & d)
{
	if(MapperObject<A, B, C, D>::has())
	{
		MapperObject<A, B, C, D>::call(a, b, c, d);
	}
	else if(MapperObject<A, B, D, C>::has())
	{
		MapperObject<A, B, D, C>::call(a, b, d, c);
	}
	else if(MapperObject<A, C, B, D>::has())
	{
		MapperObject<A, C, B, D>::call(a, c, b, d);
	}
	else if(MapperObject<A, C, D, B>::has())
	{
		MapperObject<A, C, D, B>::call(a, c, d, b);
	}
	else if(MapperObject<A, D, C, B>::has())
	{
		MapperObject<A, D, C, B>::call(a, d, c, b);
	}
	
}

template<class ... Args>
void mapperhas()
{
	return MapperObject<Args ...>::has();
}



class try1
{
	public:
	String title = "hi there";
	
	void func()
	{
		cout << title el;
	}
};

*/

template<class ...Args>
struct MapperObject
{
	void * callout = 0;
};

map<mulong, MapperObject> mapperObjectMap;




template<class A, class B>
void mapper(function<void(A & a, B & b)> func)
{
	static mulong id = GetClassId<MapperObject<A, B>>();
	mapperObjectMap[id] = &func;
	//MapperObject<A, B>::set(func);
}


template<class A, class B, class C>
void mapper(function<void(A & a, B & b, C & c)> func)
{
	static mulong id = GetClassId<MapperObject<A, B, C>>();
	mapperObjectMap[id] = &func;
	//MapperObject<A, B, C>::set(func);
}

template<class A, class B, class C, class D>
void mapper(function<void(A & a, B & b, C & c, D & d)> func)
{
	static mulong id = GetClassId<MapperObject<A, B, C, D>>();
	mapperObjectMap[id] = &func;
	//MapperObject<A, B, C, D>::set(func);
}


template<class A, class B>
void mapper(A & a, B & b)
{
	static mulong id = GetClassId<MapperObject<A, B>>();
	if(mapperObjectMap[id].callout != 0)
	{
		(*(function<void(A &, B &)>*)mapperObjectMap[id].callout)(a, b);
		//MapperObject<A, B>::call(a, b);
	}
}

template<class A, class B, class C>
void mapper(A & a, B & b, C & c)
{
	static mulong id1 = GetClassId<MapperObject<A, B, C>>();
	static mulong id2 = GetClassId<MapperObject<A, C, B>>();
	if(mapperObjectMap[id1].callout != 0)
	{
		//MapperObject<A, B, C>::call(a, b, c);
		(*(function<void(A &, B &, C &)>*)mapperObjectMap[id].callout)(a, b, c);
	}
	else if(mapperObjectMap[id2].callout != 0)//MapperObject<A, C, B>::has())
	{
		//MapperObject<A, C, B>::call(a, c, b);
		(*(function<void(A &, C &, B &)>*)mapperObjectMap[id].callout)(a, c, b);
	}
	else
	{
		//cout << "no mapper" el;
	}
}


template<class A, class B, class C, class D>
void mapper(A & a, B & b, C & c, D & d)
{
	static mulong id1 = GetClassId<MapperObject<A, B, C, D>>();
	static mulong id2 = GetClassId<MapperObject<A, B, D, C>>();
	static mulong id3 = GetClassId<MapperObject<A, C, B, D>>();
	static mulong id4 = GetClassId<MapperObject<A, C, D, B>>();
	static mulong id5 = GetClassId<MapperObject<A, D, B, C>>();
	static mulong id6 = GetClassId<MapperObject<A, D, C, B>>();
	
	if(MapperObject<A, B, C, D>::has())
	{
		MapperObject<A, B, C, D>::call(a, b, c, d);
	}
	else if(MapperObject<A, B, D, C>::has())
	{
		MapperObject<A, B, D, C>::call(a, b, d, c);
	}
	else if(MapperObject<A, C, B, D>::has())
	{
		MapperObject<A, C, B, D>::call(a, c, b, d);
	}
	else if(MapperObject<A, C, D, B>::has())
	{
		MapperObject<A, C, D, B>::call(a, c, d, b);
	}
	else if(MapperObject<A, D, B, C>::has())
	{
		MapperObject<A, D, B, C>::call(a, d, b, c);
	}
	else if(MapperObject<A, D, C, B>::has())
	{
		MapperObject<A, D, C, B>::call(a, d, c, b);
	}
	
}

template<class ... Args>
void mapperhas()
{
	return MapperObject<Args ...>::has();
}




int main()
{
	
	
	return 0;
}


