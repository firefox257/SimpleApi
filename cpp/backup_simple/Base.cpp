#ifndef BASE_CPP
#define BASE_CPP

#include <list>
#include <map>
#include "DataIO.cpp"
#define el << "\r\n"

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
	
	
	
	friend dataout & operator << (dataout & out, List<N> & ar)
	{
		out << (mulong)ar.size();
		for(auto i: ar)
		{
			out << i;
		}
		return out;
	}
	
	friend datain & operator >> (datain & in, List<N> & ar)
	{
		unsigned long long size;
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
			out << i el;
		}
		return out;
	}
};
	

template <class K, class N>
class Map: public map<K, N>
{
	public:
	
	
	friend dataout & operator << (dataout & out, Map<K, N> & ar)
	{
		out << (mulong)ar.size();
		for(auto i: ar)
		{
			out << i.first;
			out << i.second;
		}
		return out;
	}
	
	friend datain & operator >> (datain & in, Map<K, N> & ar)
	{
		unsigned long long size;
		in >> size;
		
		for(int i = 0; i < size; i++)
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
			out << "key: " <<(K)i.first el;
			out <<i.second el;
		}
		return out;
	}
	
};

template<class N>
class Array
{
	unsigned long long _size = 0;
	N * n = 0;
	public:
	Array()
	{
	}
	Array(unsigned long long size)
	{
		setSize(size);
	}
	Array(unsigned long long size, N setn)
	{
		setSize(size);
		setAll(setn);
	}
	Array(list<N> items)
	{
		setSize(items.size());
		mulong count = 0;
		for(auto i: items)
		{
			n[count] = i;
			count++;
		}
	}
	~Array()
	{
		if(n != 0)
		{
			delete(n);
			n =0;
			_size = 0;
		}
	}
	void setSize(mulong size)
	{
		if(_size != 0)
		{
			delete(n);
			
		}
		
		n = new N[size];
		_size = size;
		
	}
		
	void setAll(N data)
	{
		for(int i = 0; i < _size; i++)
		{
			n[i] = data;
		}
	}
	
	inline N & operator [](mint index)
	{
		return n[index];
	}
	
	inline Array<N> operator = (list<N> items)
	{
		setSize(items.size());
		mulong count = 0;
		for(auto i: items)
		{
			n[count] = i;
			count++;
		}
		return (*this);
	}
	
	inline mulong size()
	{
		return _size;
	}
	
	
	friend dataout & operator << (dataout & out, Array<N> & ar)
	{
		out << ar._size;
		for(int i = 0; i < ar._size; i++)
		{
			out << ar[i];
		}
		return out;
	}
	
	friend datain & operator >> (datain & in, Array<N> & ar)
	{
		unsigned long long size;
		in >> size;
		ar.setSize(size);
		
		for(int i = 0; i < ar.size(); i++)
		{
			in >> ar[i];
		}
		return in;
	}
	
	
	
	
	friend ostream & operator << (ostream & out , Array<N> & n)
	{
		for(int i = 0; i< n._size; i++)
		{
			out << n[i] el;
		}
		return out;
	}
	
};

template<class N>
class PrimitiveArray
{
	unsigned long long _size = 0;
	N * n = 0;
	public:
	PrimitiveArray()
	{
	}
	PrimitiveArray(unsigned long long size)
	{
		setSize(size);
	}
	PrimitiveArray(unsigned long long size, N setn)
	{
		setSize(size);
		setAll(setn);
	}
	PrimitiveArray(list<N> items)
	{
		setSize(items.size());
		mulong count = 0;
		for(auto i: items)
		{
			n[count] = i;
			count++;
		}
	}
	~PrimitiveArray()
	{
		if(n != 0)
		{
			delete(n);
			n =0;
			_size = 0;
		}
	}
	void setSize(mulong size)
	{
		if(_size != 0)
		{
			delete(n);
			
		}
		
		n = new N[size];
		_size = size;
		
	}
		
	void setAll(N data)
	{
		for(int i = 0; i < _size; i++)
		{
			n[i] = data;
		}
	}
	
	N & operator [](mulong index)
	{
		return n[index];
	}
	inline PrimitiveArray<N> operator = (list<N> items)
	{
		setSize(items.size());
		mulong count = 0;
		for(auto i: items)
		{
			n[count] = i;
			count++;
		}
		return (*this);
	}
	inline mulong size()
	{
		return _size;
	}
	
	
	friend dataout & operator << (dataout & out, PrimitiveArray<N> & ar)
	{
		mulong size = ar._size * sizeof(N);
		out << size;
		out.write((muchar*)ar.n,size); 
		return out;
	}
	
	friend datain & operator >> (datain & in, PrimitiveArray<N> & ar)
	{
		unsigned long long size;
		in >> size;
		ar.setSize(size/sizeof(N));
		in.read((muchar*)ar.n, size);
		return in;
	}
	
	friend ostream & operator << (ostream & out , PrimitiveArray<N> & ar)
	{
		for(int i = 0; i< ar._size; i++)
		{
			out << ar[i] el;
		}
		return out;
	}
	
};

class Buffer
{
	muchar * d = 0;
	mulong _size = 0;
	public:
	Buffer()
	{
	}
	Buffer(mulong size)
	{
		setSize(size);
		
	}
	Buffer(List<muchar> items)
	{
		(*this) = items;
	}
	inline mulong size()
	{
		return _size;
	}
	void setSize(mulong size)
	{
		if(_size == 0)
		{
			d = (muchar*)malloc(size);
		}
		else
		{
			d = (muchar*)realloc(d, size);
		}
		_size = size;
	}
	inline Buffer & operator = (List<muchar> items)
	{
		setSize(items.size());
		mulong count = 0;
		for(auto i: items)
		{
			d[i] = i;
			count++;
		}
		return (*this);
	}
	operator muchar*()
	{
		return d;
	}
	
	
	friend dataout & operator << (dataout & out, Buffer & o)
	{
		out.write(o.d,o._size);
		return out;
	}
	friend datain & operator >> (datain & in, Buffer & o)
	{
		mulong size;
		in >> size;
		o.setSize(size);
		in.read(o.d, size);
		return in;
	}
	
	friend ostream & operator << (ostream & out, Buffer & o)
	{
		cout <<"Buffer size " << o.size() el;
		return out;
	}
};




#endif
