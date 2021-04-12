#ifndef DTO_CPP
#define DTO_CPP
#include<string>
#include "Base.cpp"
#include "DataIO.cpp"



class dto
{
	static hash<string> mhash;
	static dto dtonull;
	
	template<class N>
	static mulong getid()
	{
		return mhash(typeid(N).name());
	}
	static mulong maptype;
	static mulong dtotype;
	static mulong charstrtype;
	static mulong constcharstrtype;
	static mulong stringtype;
	
	static Map<mulong,function<mbool(void*, void*)>> lcomp;
	static Map<mulong,function<mbool(void*, void*)>> scomp;
	static Map<mulong,function<mbool(void*, void*)>> ecomp;
	static Map<mulong, function<void*()>> create;
	static Map<mulong,function<void(void *&)>> erase;
	
	static Map<mulong, function<void(ostream &, void *)>> ostreamoutmap;
	static Map<mulong, function<void(dataout &, void *)>> dataoutmap;
	static Map<mulong, function<void(datain &, dto&)>> datainmap;
	static Map<mulong, function<void(void *, void *)>> setmap;
	
	void * o;
	mulong t = 0;
	int * count;
	
	public:
	
	template<class N>
	static bool setup()
	{
		mulong id = mhash(typeid(N).name());
		
		lcomp[id] = [](void* v1, void * v2)
		{
			return (*((N*)v1)) > (*((N*)v2));
		};
		scomp[id] = [](void* v1, void * v2)
		{
			return (*((N*)v1)) < (*((N*)v2));
		};
		ecomp[id] = [](void* v1, void * v2)
		{
			return (*((N*)v1)) == (*((N*)v2));
		};
		create[id] = []()
		{
			return new N;
		};
		erase[id] = [](void *& v1)
		{
			delete((N*)v1);
		};
		ostreamoutmap[id] = [](ostream & out, void * v1)
		{
			out << (*((N*)v1));
			
		};
		dataoutmap[id] = [](dataout & out , void * v1)
		{
			out << (*((N*)v1));
		};
		
		
		datainmap[id] = [](datain & in , dto& v1)
		{
			N n;
			in >> n;
			v1 = n;
		};
		
		setmap[id] = [](void * v1, void * v2)
		{
			(*((N*)v1))=(*((N*)v2));
		};
		
		return true;
		
	}
	template<class N>
	static bool setupDataOnly()
	{
		mulong id = mhash(typeid(N).name());
		
		create[id] = []()
		{
			return new N;
		};
		erase[id] = [](void *& v1)
		{
			delete((N*)v1);
		};
		/*ostreamoutmap[id] = [](ostream & out, void * v1)
		{
			out << (*((N*)v1));
			
		};*/
		dataoutmap[id] = [](dataout & out , void * v1)
		{
			out << (*((N*)v1));
		};
		
		
		datainmap[id] = [](datain & in , dto& v1)
		{
			N n;
			in >> n;
			v1 = n;
		};
		
		setmap[id] = [](void * v1, void * v2)
		{
			(*((N*)v1))=(*((N*)v2));
		};
		
		return true;
	}
	
	dto()
	{
		o = 0;
		t = 0;
		count = new int;
		(*count) = 1;
	}
	~dto()
	{
		(*count)--;
		if((*count) <=0)
		{
			if(t !=0)
			{
				erase[t](o);
				t = 0;
				o = 0;
			}
			delete(count);
		}
	}

	dto(const dto  & n)
	{
		o = n.o;
		t = n.t;
		count = n.count;
		(*count)++;
		
	}
	template<class N>
	dto(N n)
	{
		//checksetup<N>();
		t = getid<N>();
		if(t == charstrtype || t == constcharstrtype)
		{	
			t = stringtype;		
			o = create[t]();
			(*((String*)o)) = n;
		}
		else
		{
			o = create[t]();
			(*((N*)o)) = n;
		}
		count = new int;
		(*count) = 1;
	}
	dto(const char * n)
	{
		t = stringtype;
		o = create[t]();
		(*((String*)o)) = n;
		count = new int;
		(*count) = 1;
	}
	
	template<class N>
	dto & operator = (N n)
	{
		//checksetup<N>();
		mulong tt = getid<N>();
		
		(*count)--;
		if((*count) <=0)
		{
			if(t != 0)
			{
				erase[t](o);
				t = 0;
				o = 0;
			}
			(*count) = 1;
		}
		
		t = tt;
		
		o = create[t]();
		setmap[t](o, &n);
		
		return (*this);
	}
	
	dto & operator = (const char * n)
	{
		(*count)--;
		if((*count) <=0)
		{
			if(t != 0)
			{
				erase[t](o);
				t = 0;
				o = 0;
			}
			(*count) = 1;
			
			
		}
		t = stringtype;
		o = create[t]();
		String n1 = n;
		setmap[t](o, &n1);
		
		
		return (*this);
	}
	
	
	dto & operator = (const dto & n)
	{
		(*count)--;
		if((*count) <=0)
		{
			if(t != 0)
			{
				erase[t](o);
				t = 0;
				o = 0;
			}
			delete(count);
		}
		
		o = n.o;
		t = n.t;
		count = n.count;
		(*count)++;
		return (*this);
	}
	
	template<class N, class K>
	dto & operator()(const N & n, const K  & k)
	{
		if(t != maptype && t != 0)
		{
			(*count)--;
			if((*count) <=0)
			{
				erase[t](o);
				t = 0;
				o = 0;
				(*count) = 1;
			}
			t  = maptype;
			o = create[t]();
		}
		else if(t == 0)
		{
			(*count)--;
			if((*count) <=0)
			{
				(*count) = 1;
			}
			t  = maptype;
			o = create[t]();
		}
		
		(*((Map<dto, dto>*)o))[n] = k;
		
		return (*this);
	}
	
	dto & operator[](const dto & n)
	{
		if(t != maptype)
		{
			return dtonull;
		}
		Map<dto, dto> * ptr = (Map<dto, dto>*)o;
		return (*ptr)[n];
	}
	template <class N>
	N & at()
	{
		return (*((N*)o));
	}
	
	mbool operator < (const dto & obj) const
	{
		if(t == obj.t)
		{
			return scomp[t](o, obj.o);
		}
		
		return t < obj.t;
	}
	mbool operator > (const dto & obj) const
	{
		if(t == obj.t)
		{
			return lcomp[t](o, obj.o);
		}
		
		return t > obj.t;
	}
	mbool operator == (const dto & obj) const
	{
		if(t == obj.t)
		{
			return ecomp[t](o, obj.o);
		}
		
		return t== obj.t;
	}
	mbool operator <=(const dto &obj) const
	{
		
		return !((*this) > obj);
	}
	mbool operator >=(const dto &obj) const
	{
		return !((*this) < obj);
	}
	
	friend ostream & operator << (ostream & out, const dto & obj)
	{
		if(obj.t == 0) return out;
		ostreamoutmap[obj.t](out, obj.o);
		return out;
		
	}
	friend dataout & operator << (dataout & out, const dto & obj)
	{
		if(obj.t == 0) return out;
		out << obj.t;
		dataoutmap[obj.t](out, obj.o);
		return out;
		
	}
	friend datain & operator >> (datain & in, dto & obj)
	{
		mulong t;
		in >> t;
		datainmap[t](in, obj);
		return in;
		
	}
};
hash<string> dto::mhash;
dto dto::dtonull;
mulong dto::maptype = dto::getid<Map<dto, dto>>();
mulong dto::dtotype = dto::getid<dto>();
mulong dto::charstrtype = dto::getid<char*>();
mulong dto::constcharstrtype = dto::getid<const char *>();
mulong dto::stringtype = dto::getid<String>();
Map<mulong,function<bool(void*, void*)>> dto::lcomp;
Map<mulong,function<bool(void*, void*)>> dto::scomp;
Map<mulong,function<bool(void*, void*)>> dto::ecomp;
Map<mulong, function<void*()>> dto::create;
Map<mulong,function<void(void *&)>> dto::erase;

Map<mulong, function<void(ostream &, void *)>> dto::ostreamoutmap;
Map<mulong, function<void(dataout &, void *)>> dto::dataoutmap;
Map<mulong, function<void(datain &, dto&)>> dto::datainmap;
Map<mulong, function<void(void *, void *)>> dto::setmap;


mbool SETUPDTOOBJECTS()
{
	dto::setup<mbool>();
	dto::setup<mchar>();
	dto::setup<muchar>();
	dto::setup<mshort>();
	dto::setup<mushort>();
	dto::setup<mint>();
	dto::setup<muint>();
	dto::setup<mlong>();
	dto::setup<mulong>();
	dto::setup<mfloat>();
	dto::setup<mdouble>();
	dto::setup<String>();
	dto::setup<dto>();
	dto::setup<Map<dto, dto>>();
	return true;
}
mbool ISSETUPDTOOBJECTS =SETUPDTOOBJECTS();




#endif
