#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Types.hpp"
#include "DataIO.hpp"
#include "SmtPtr.hpp"

template<class N>
class ArrayData
{
	public:
	N * d = 0;
	mint size = 0;
	~ArrayData()
	{
		if(d!=0)
		{
			delete(d);
			d = 0;
			size = 0;
		}
	}
	
	void setSize(mint s)
	{
		if(d!= 0)
		{
			d = (N*)realloc(d, s * sizeof(N));
		}
		else
		{
			d = (N*)malloc(s * sizeof(N));
		}
		size = s;
	}
	void erase()
	{
		if(d!=0)
		{
			delete(d);
			d = 0;
			size = 0;
		}
	}
	void Copy(const ArrayData<N> & a)
	{
		
		if(a.d == d)
		{
			d = 0;
			size = 0;
		}
		setSize(a.size);
		
		for(mint i = 0; i < size; i++)
		{
			d[i] = a.d[i];
		}
		
	}
};

template<class N>
class Array
{
	typedef Array CMPARENT;
	SmtPtr<ArrayData<N>> ref;
	
	public:
	
	
	$cm(mint, Size, 
	{
		return ref->size;
	},
	{
		ref->setSize(v);
	});
	
	N & operator[](mint index)
	{
		return ref->d[index];
	}
	
	void Copy(Array<N> & a)
	{
		ref.Release();
		ref->Copy( (*(a.ref))   );
	}
	
	typedef N * iterator;
	typedef const N * const_iterator;
	
	iterator begin()
	{
		return &(ref->d[0]);
	}
	iterator end()
	{
		mint s= Size();
		return &(ref->d[s]);
	}
	
	$datastream(Array<N>, 
	{
		
		out << o.Size();
		for(auto i: o)
		{
			out << i;
		}
	},
	{
		mint s;
		in >> s;
		o.Size(s);
		for(auto i: o)
		{
			in >> i;
		}
		
	});
	
	friend ostream & operator << (ostream & out, Array<N> & o)
	{
		out <<"Size: " << o.Size() << "\r\n";
		for(auto i: o)
		{
			out << i << "\r\n";
		}
		
		return out;
	}
};



#endif