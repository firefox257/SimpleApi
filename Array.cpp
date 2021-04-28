#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Types.hpp"
#include "DataIO.hpp"
#include "SmtPtr.hpp"

template<class N>
class List;


template<class N>
class ArrayArg
{
	public:
	const N * data = 0;
	mint size = 0;
	
	template<class A>
	ArrayArg(const A & n)
	{
		TypeInfo t(n);
		if(t.isArray)
		{
			data = n;
			size = t.arraySize;
		}
	}
	
};


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
	
	Array()
	{
	}
	
	
	Array(ArrayArg<N> n)
	{
		mint s = n.size;
		Size(s);
		for(mint i = 0; i < s; i++)
		{
			ref->d[i] = n.data[i];
		}
		
	}
	
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
	
	Array<N> & operator = (ArrayArg<N> & a)
	{
		ref.Release();
		mint s = a.size;
		Size(s);
		for(mint i = 0; i < s; i++)
		{
			ref->d[i] = a.data[i];
		}
	}
	
	operator List<N>()
	{
		List<N> ret;
		for(auto i: (*this))
		{
			ret.PushBack(i);
		}
		return ret;
	}		
	
	N * begin()
	{
		return &(ref->d[0]);
	}
	N * end()
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