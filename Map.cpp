#ifndef MAP_CPP
#define MAP_CPP

#include <map>
#include "Types.hpp"
#include "DataIO.hpp"

template <class K, class N>
class Map: public map<K, N>
{
	public:
	
	
	friend DataOut & operator << (DataOut & out, Map<K, N> & ar)
	{
		out << (mulong)ar.size();
		for(auto i: ar)
		{
			out << i.first;
			out << i.second;
		}
		return out;
	}
	
	friend DataIn & operator >> (DataIn & in, Map<K, N> & ar)
	{
		mulong size;
		in >> size;
		
		for(mint i = 0; i < size; i++)
		{
			K k;
			in >> k;
			N n;
			in >> n;
			ar[k] =n;
		}
		return in;
	}
	
	friend ostream & operator << (ostream & out , const Map<K, N> & n)
	{
		for(auto i: n)
		{
			out << "key: " <<(K)i.first << "\r\n";
			out <<i.second << "\r\n";
		}
		return out;
	}
	
};
#endif