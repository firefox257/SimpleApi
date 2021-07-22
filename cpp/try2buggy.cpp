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

//std map is buggy proff is here. it is doing some copy constructor with out initilizing. 
//have to make own Map class. 
mint getCounter()
{
	static mint count = -1;
	count++;
	return count;
}

class DtoWrapBase
{
	public:
	virtual void create(void *& v)
	{
	}
	virtual void erase(void *& v)
	{
	}
	virtual void set(void *& v1, void *& v2)
	{
	}
	
	virtual mbool equal(void *& v1, void *& v2)
	{
		return false;
	}
	virtual mbool less(void *& v1, void *& v2)
	{
		return false;
	}
	virtual mbool greater(void *& v1, void *& v2)
	{
		return false;
	}
	virtual mbool lessequal(void *& v1, void *& v2)
	{
		return false;
	}
	virtual mbool greaterequal(void *& v1, void *& v2)
	{
		return false;
	}
	
	virtual void outstream(ostream & out, void *& v)
	{
	}
	virtual void dataout(DataOut & out, void *& v)
	{
	}
	virtual void datain(DataIn & in , void *& v)
	{
	}
	
};

template<class N>
class DtoWrap: public DtoWrapBase 
{
	virtual void create(void *& v)
	{
		v = new N;
	}
	virtual void erase(void *& v)
	{
		delete((N*)v);
	}
	virtual void set(void *& v1, void *& v2)
	{
		(*((N*)v1)) = (*((N*)v2));
	}
	
	virtual mbool equal(void *& v1, void *& v2)
	{
		return (*((N*)v1)) == (*((N*)v2));
	}
	virtual mbool less(void *& v1, void *& v2)
	{
		return (*((N*)v1)) < (*((N*)v2));
	}
	virtual mbool greater(void *& v1, void *& v2)
	{
		return (*((N*)v1)) > (*((N*)v2));
	}
	virtual mbool lessequal(void *& v1, void *& v2)
	{
		return (*((N*)v1)) <= (*((N*)v2));
	}
	virtual mbool greaterequal(void *& v1, void *& v2)
	{
		return (*((N*)v1)) >= (*((N*)v2));
	}
	
	virtual void outstream(ostream & out, void *& v)
	{
		out << (*((N*)v));
	}
	virtual void dataout(DataOut & out, void *& v)
	{
		out << (*((N*)v));
	}
	virtual void datain(DataIn & in , void *& v)
	{
		in >> (*((N*)v));
	}
};

template<class N>
class DtoDataWrap: public DtoWrapBase 
{
	virtual void create(void *& v)
	{
		v = new N;
	}
	virtual void erase(void *& v)
	{
		delete((N*)v);
	}
	virtual void set(void *& v1, void *& v2)
	{
		(*((N*)v1)) = (*((N*)v2));
	}
	
	
	virtual void outstream(ostream & out, void *& v)
	{
		out << (*((N*)v));
	}
	virtual void dataout(DataOut & out, void *& v)
	{
		out << (*((N*)v));
	}
	virtual void datain(DataIn & in , void *& v)
	{
		in >> (*((N*)v));
	}
};

template<class N>
class DtoMapWrap: public DtoWrapBase 
{
	virtual void create(void *& v)
	{
		v = new N;
	}
	virtual void erase(void *& v)
	{
		delete((N*)v);
	}
	virtual void set(void *& v1, void *& v2)
	{
		(*((N*)v1)) = (*((N*)v2));
	}
};

class DtoData
{
	public:
	static Map<mulong, DtoWrapBase *> wrapmap;
	mulong t = 0;
	void * d = 0;
	DtoWrapBase * wrap = 0;
	mint counter = getCounter();
	
	
	static void RegisterDefualt()
	{
		wrapmap[0] = new DtoWrapBase;
	}
	
	template<class N>
	static void Register()
	{
		mulong id = GetClassId<N>();
		wrapmap[id] = new DtoWrap<N>;
		
	}
	template<class N>
	static void RegisterData()
	{
		mulong id = GetClassId<N>();
		wrapmap[id] = new DtoDataWrap<N>;
	}
	template<class N>
	static void RegisterMap()
	{
		mulong id = GetClassId<N>();
		wrapmap[id] = new DtoMapWrap<N>;
	}
	
	DtoData()
	{
		cout << "new DtoData " << counter el;
		wrap = wrapmap[t];
		d = 0;
		t = 0;
		//wrap->create(d);
	}
	
	template<class N>
	DtoData(const N & n)
	{
		cout << "new DtoData n " << counter el;
		
		t = GetClassId<N>();
		cout << "t is " << t el;
		cout << t el;
		wrap = wrapmap[t];
		wrap->create(d);
		void * vv = (void*)&n;
		wrap->set(d, vv);
	}
	
	
	~DtoData()
	{
		if(d != 0)
		{
			cout << "delete data " << counter el;
			cout << t el;
			wrap->erase(d);
			d = 0;
			t = 0;
			wrap = 0;
		}
	}
	
	template<class N>
	void makeNew()
	{
		if(d != 0)
		{
			wrap->erase(d);
			d = 0;
			t = 0;
			wrap = 0;
		}
		t = GetClassId<N>();
		wrap = wrapmap[t];
		wrap->create(d);
	}
	
	template<class N>
	void operator = (const N & n)
	{
		mulong tt = GetClassId<N>();
		wrap->erase(d);
		d = 0;
		t = tt;
		wrap = wrapmap[t];
		wrap->create(d);
	}
	
	mbool equal(void *& v)
	{
		return wrap->equal(d, v);
	}
	mbool less (void *& v)
	{
		return wrap->less(d, v);
	}
	mbool greater(void *& v)
	{
		return wrap->greater(d, v);
	}
	mbool lessequal(void *& v)
	{
		return wrap->lessequal(d, v);
	}
	mbool greaterequal(void *& v)
	{
		return wrap->greaterequal(d, v);
	}
	
	void outstream(ostream & out)
	{
		wrap->outstream(out, d);
	}
	void dataout(DataOut & out)
	{
		wrap->dataout(out, d);
	}
	void datain(DataIn & in)
	{
		wrap->datain(in, d);
	}
};
Map<mulong, DtoWrapBase *> DtoData::wrapmap;

class Dto
{
	static mulong dtotype;
	static mulong charstrtype;
	static mulong constcharstrtype;
	static mulong chararraystrtype;
	static mulong constchararraystrtype;
	static mulong dtomaptype;
	
	DtoData * d = 0;
	mint * count = 0;
	
	mint counter = getCounter();
	public:
	Dto()
	{
		cout << "create dto " << counter el;
		d = new DtoData;
		count = new int;
		(*count) = 1;
	}
	
	
	Dto(mchar * n)
	{
		cout << "create char * dto " << counter el;
		mulong t = GetClassId<String>();
		String str1 = n;
		
		d = new DtoData(str1);
		count = new int;
		(*count) = 1;
	}
	Dto(const mchar * n)
	{
		cout << "create const char * dto " << counter el;
		mulong t = GetClassId<String>();
		String str1 = n;
		
		d = new DtoData(str1);
		count = new int;
		(*count) = 1;
	}
	template<class N>
	Dto(const N & n)
	{
		cout << "create n dto " << counter el;
		mulong t = GetClassId<N>();
		
		if(t == dtotype)
		{
			Dto * dd = (Dto *)&n;
			d = dd->d;
			count = dd->count;
			(*count)++;
		}
		/*else if(t == charstrtype 
		|| t == constcharstrtype 
		|| t == chararraystrtype 
		|| t == constchararraystrtype)
		{
			String str1 = n;
			d = new DtoData(str1);
			count = new int;
			(*count) = 1;
		}*/
		else
		{
			d = new DtoData(n);
			count = new int;
			(*count) = 1;
		}
		
		
	}
	~Dto()
	{
		if(count !=0)
		{
			cout << "count is " << (*count) el;
			(*count)--;
			if((*count) <=0)
			{
				cout << "delete dto " << counter el;
				delete(d);
				delete(count);
				d = 0;
				count = 0;
			}
		}
	}
	
	Dto & operator = (const Dto & data)
	{
		(*count)--;
		if((*count) <=0)
		{
			cout << "delete = dto " << counter el;
			delete(d);
			delete(count);
			d = 0;
			count = 0;
		}//
		
		d = data.d;
		count = data.count;
		(*count)++;
		
		return (*this);
	}
	
	
	/*mbool operator == (const Dto & o)
	{
		if(d->t != o.d->t) return false;
		return d->equal(o.d->d);
	}
	
	mbool operator < (const Dto & o)
	{
		if(d->t < o.d->t) return true;
		else if(d->t == o.d->t)
		{
			return d->less(o.d->d);
		}
		return false;
	}
	mbool operator > (const Dto & o)
	{
		if(d->t > o.d->t) return true;
		else if(d->t == o.d->t)
		{
			return d->greater(o.d->d);
		}
		return false;
	}
	
	mbool operator <= (const Dto & o)
	{
		return ! Dto::operator>(o);
	}
	mbool operator >= (const Dto & o)
	{
		return ! Dto::operator<(o);
	}*/
	
	friend mbool operator == (const Dto & d1, const Dto & d2)
	{
		if(d1.d->t != d2.d->t) return false;
		return d1.d->equal(d2.d->d);
	}
	friend mbool operator < (const Dto & d1, const Dto & d2)
	{
		if(d1.d->t < d2.d->t) return true;
		else if(d1.d->t == d2.d->t)
		{
			return d1.d->less(d2.d->d);
		}
		return false;
	}
	friend mbool operator > (const Dto & d1, const Dto & d2)
	{
		if(d1.d->t > d2.d->t) return true;
		else if(d1.d->t == d2.d->t)
		{
			return d1.d->greater(d2.d->d);
		}
		return false;
	}
	friend mbool operator <= (const Dto & d1, const Dto & d2)
	{
		return !(d1 > d2);
	}
	friend mbool operator >= (const Dto & d1, const Dto & d2)
	{
		return !(d1 < d2);
	}
	
	
	template <class N>
	N & at()
	{
		return (*((N*)d->d));
	}
	
	/*Dto & operator ()(const Dto & d1, const Dto & d2)
	{
		if(d->t != dtomaptype)
		{
			(*count)--;
			if((*count) <=0)
			{
				delete(d);
				delete(count);
				d = 0;
				count = 0;
			}
			Map<Dto, Dto> map1;
			
			d = new DtoData(map1);
			count = new mint;
			(*count) = 1;
			//d = data.d;
			//count = data.count;
			//(*count)++;
		}
		
		
		//(*((Map<Dto, Dto>*)d->d))[d1] = d2;
		return (*this);
	}*/
	
	friend ostream & operator << (ostream & out , const Dto & o)
	{
		o.d->outstream(out);
		return out;
	}
	
	$datastream(Dto,
	{
		o.d->dataout(out);
	},
	{
		o.d->datain(in);
		
	});
};
mulong Dto::dtotype = GetClassId<Dto>();
mulong Dto::charstrtype = GetClassId<char*>() ;
mulong Dto::constcharstrtype = GetClassId<const char *>();
mulong Dto::chararraystrtype = GetClassId<char[]>();
mulong Dto::constchararraystrtype = GetClassId<const char[]>();
mulong Dto::dtomaptype = GetClassId<Map<Dto, Dto>>();

int main()
{
	DtoData::Register<int>();
	DtoData::Register<String>();
	DtoData::RegisterMap<Map<Dto, Dto>>();
	DtoData::RegisterMap<Map<Dto, mint>>();
	
	
	Map<Dto, Dto> m1;
	
	m1[1] = 123;
	
	cout << "ending " el;

	return 0;
}

