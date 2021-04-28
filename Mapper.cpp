#ifndef MAPPER_CPP
#define MAPPER_CPP
#include <functional>
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








#endif