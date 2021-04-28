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


class DtoWrapBase
{
	public:
	DtoWrapBase()
	{
	}
	virtual void create(void * & v)
	{
	}
	virtual void erase(void * & v)
	{
	}
	virtual void set(void *& v1, void *& v2)
	{
	}
	virtual mbool equals (void *& v1, void *& v2)
	{
		return false;
	}
	virtual mbool less (void *& v1, void *& v2)
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
	virtual void datain(DataIn & in, void *& v)
	{
		
	}
	
};

template<class N>
class DtoWrap: public DtoWrapBase
{
	public:
	DtoWrap()
	{
	}
	virtual void create(void * & v)
	{
		v = new N;
	}
	virtual void erase(void * & v)
	{
		delete((N*)v);
	}
	virtual void set(void *& v1, void *& v2)
	{
		(*((N*)v1)) = (*((N*)v2));
	}
	virtual mbool equals (void *& v1, void *& v2)
	{
		return (*((N*)v1)) == (*((N*)v2));;
	}
	virtual mbool less (void *& v1, void *& v2)
	{
		return (*((N*)v1)) < (*((N*)v2));;
	}
	virtual mbool greater(void *& v1, void *& v2)
	{
		return (*((N*)v1)) > (*((N*)v2));;
	}
	virtual mbool lessequal(void *& v1, void *& v2)
	{
		return (*((N*)v1)) <= (*((N*)v2));;
	}
	virtual mbool greaterequal(void *& v1, void *& v2)
	{
		return (*((N*)v1)) >= (*((N*)v2));;
	}
	
	virtual void outstream(ostream & out, void *& v)
	{
		out << (*((N*)v));
	}
	virtual void dataout(DataOut & out, void *& v)
	{
		out << (*((N*)v));
	}
	virtual void datain(DataIn & in, void *& v)
	{
		in >> (*((N*)v));
	}
	
};

template<class N>
class DtoDataWrap: public DtoWrapBase
{
	public:
	DtoDataWrap()
	{
	}
	virtual void create(void * & v)
	{
		v = new N;
	}
	virtual void erase(void * & v)
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
	virtual void datain(DataIn & in, void *& v)
	{
		in >> (*((N*)v));
	}
};


class DtoData
{
	static Map<mulong, DtoWrapBase *> LookupWrapMap;
	public:
	
	template<class N>
	static void SetMapping()
	{
		static mulong id = GetClassId<N>();
		LookupWrapMap[id] = new DtoObjectWrap<N>;
	}
	
	template<class N>
	static void SetDataMapping()
	{
		static mulong id = GetClassId<N>();
		LookupWrapMap[id] = new DtoDataObjectWrap<N>;
	}
	
	
	mulong t = 0;;
	void * d = 0;
	DtoWrapBase * objwrap = 0;
	DtoData()
	{
	}
	
	~DtoData()
	{
		if(d!=0)
		{
			objwrap->erase(d);
			d= 0;
			t=0;
		}
	}
	
	
	template<class N>
	void set(const N & nn)
	{
		if(d!=0)
		{
			objwrap->erase(d);
		}
		t = GetClassId<N>();
		objwrap = LookupWrapMap[t];
		if(d == 0)
		{
			objwrap->create(d);
		}
		void * vn = (void*)&nn;
		objwrap->set(d, vn);
	}
	
	void setType(mulong tt)
	{
		if(d!=0)
		{
			objwrap->erase(d);
		}
		t =tt;
		objwrap = LookupWrapMap[t];
		if(d == 0)
		{
			objwrap->create(d);
		}
	}
	
	mbool equals(void *& v)
	{
		return objwrap->equals(d, v);
	}
	mbool less(void *& v)
	{
		return objwrap->less(d, v);
	}
	mbool greater(void *& v)
	{
		return objwrap->greater(d, v);
	}
	mbool lessequal(void *& v)
	{
		return objwrap->lessequal(d, v);
	}
	mbool greaterequal(void *& v)
	{
		return objwrap->greaterequal(d, v);
	}
	
	
	void outstream(ostream & out)
	{
		
		objwrap->outstream(out, d);
	}
	void dataout(DataOut & out)
	{
		out << t;
		objwrap->dataout(out, d);
	}
	void datain(DataIn & in)
	{
		mulong tt;
		in >> tt;
		if(d != 0)
		{
			objwrap->erase(d);
		}
		t =tt;
		objwrap = LookupWrapMap[t];
		objwrap->create(d);
		objwrap->datain(in, d);
	}
	
};
Map<mulong, DtoWrapBase *> DtoData::LookupWrapMap;

class Dto: CountingRef<Dto, DtoData>
{
	static mulong DtoType;
	static mulong CStrType;
	static mulong ConstCStrType;
	static mulong CstrArrayType;
	static mulong ConstCstrArrayType;
	typedef Dto CMPARENT;
	public:
	Dto()
	{
	}
	
	template<class N>
	Dto(const N & d)
	{
		mulong t = GetClassId<N>();
		if(t == CStrType || t == ConstCStrType || t == CstrArrayType || t == ConstCstrArrayType)
		{
			String str1 = d;
			n->set(str1);
		}
		
		else
		{
			n->set(d);
		}
	}
	
	template<class N>
	Dto & operator = (const N & d)
	{
		mulong t = GetClassId<N>();
		if(t == DtoType)
		{
			refequals(d);
		}
		else
		{
			n->set(d);
		}
		
		
		return (*this);
	}
	
	template<class N>
	mbool operator == (const N & n)
	{
		return n->equals(&n);
	}
	template<class N>
	mbool operator < (const N & n)
	{
		return n->less(&n);
	}
	template<class N>
	mbool operator > (const N & n)
	{
		return n->greater(&n);
	}
	template<class N>
	mbool operator <= (const N & n)
	{
		return n->lessequal(&n);
	}
	template<class N>
	mbool operator >= (const N & n)
	{
		return n->greaterequal(&n);
	}
	
	friend ostream & operator <<(ostream & out, const Dto & o)
	{
		o.n->outstream(out);
		return out;
	}
	
	$datastream(Dto,
	{
		
		
	},
	{
		
	});
	
};
mulong Dto::DtoType = GetClassId<Dto>();
mulong Dto::CStrType = GetClassId<char *>();
mulong Dto::ConstCStrType = GetClassId<const char *>();
mulong Dto::CstrArrayType = GetClassId<char[]>();
mulong Dto::ConstCstrArrayType = GetClassId<const char[]>();

int main()
{
	DtoData::SetMapping<mbool>();
	DtoData::SetMapping<muchar>();
	DtoData::SetMapping<mchar>();
	DtoData::SetMapping<muint>();
	DtoData::SetMapping<mint>();
	DtoData::SetMapping<mulong>();
	DtoData::SetMapping<mlong>();
	DtoData::SetMapping<mfloat>();
	DtoData::SetMapping<mdouble>();
	DtoData::SetMapping<String>();
	DtoData::SetDataMapping<Map<Dto, Dto>>();
	
	//Dto d1 = "hi there";
	//cout << d1;
	
	return 0;
}