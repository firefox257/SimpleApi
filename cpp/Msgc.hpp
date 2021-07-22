#ifndef MSGC_HPP
#define MSGC_HPP




Map<mulong, Map<void *, void* > > msgcentermap;


template<class N>
class MsgcHandler
{
	
	static mulong classid;
	function <void(N&)> func;
	public:

	MsgcHandler()
	{
	}
	MsgcHandler(function<void(N&)> f)
	{
		func = f;
		msgcentermap[classid][&func] = &func;
	}
	~MsgcHandler()
	{
		if(func)
		{
			msgcentermap[classid].erase(&func);
		}
	}
	
	
	MsgcHandler<N> & operator = (function<void(N&)> f)
	{
		if(func)
		{
			msgcentermap[classid].erase(&func);
		}
		func = f;
		msgcentermap[classid][&func] = &func;
		
		return (*this);
	}
	
};

template<class N>
mulong MsgcHandler<N>::classid =  GetClassId<N>();


template<class N>
void MsgcSend(N & n)
{
	const static mulong id = GetClassId<N>();
	for(auto i : msgcentermap[id])
	{
		function<void (N&)> * ptr = (function <void(N&)>*)i.second;
		(*ptr)(n);
	}
	
}


/*
example
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
#include "Msgc.cpp"
using namespace std;
#define el << "\r\n"




struct msg1Data
{
	String title;
};
class msg1: public CountingRef<msg1, msg1Data>
{
	typedef msg1 CMPARENT;
	public:
	
	$scm(String, title, n->title);
	
};




int main()
{
	MsgcHandler<msg1> h1;
	h1 = [&](msg1 & m)
	{
		cout << m.title() el;
		
	};
	msg1 m;
	m.title("hi there");
	{
		MsgcHandler<msg1> h2;
		h2 = [&](msg1 & m)
		{
			cout << "at h2" el;
			
		};
	
		MsgcSend(m);
	}
	cout << "===============" el;
	MsgcSend(m);
	
	return 0;
}






*/


#endif
