
#ifndef LIST_CPP
#define LIST_CPP
#include <list>
#include "Types.hpp"
#include "DataIO.hpp"

template <class N>	
class List: public list<N>
{
	public:
	List()
	{
	}
	List(list<N> items)
	{
		for(auto i: items)
		{
			(*this).push_back(i);
		}
	}
	
	List<N> & operator = (list<N> items)
	{
		(*this).clear();
		for(auto i: items)
		{
			(*this).push_back(i);
		}
		return (*this);
	}
	
	
	
	friend DataOut & operator << (DataOut & out, List<N> & ar)
	{
		out << (mulong)ar.size();
		for(auto i: ar)
		{
			out << i;
		}
		return out;
	}
	
	friend DataIn & operator >> (DataIn & in, List<N> & ar)
	{
		mulong size;
		in >> size;
		for(int i = 0; i < size; i++)
		{
			N n;
			in >> n;
			ar.push_back(n);
		}
		return in;
	}
	
	friend ostream & operator << (ostream & out , const List<N> & n)
	{
		for(auto i: n)
		{
			out << i << "\r\n";
		}
		return out;
	}
};
	

#endif
