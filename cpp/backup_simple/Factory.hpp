#ifndef FACTORY_CPP
#define FACTORY_CPP

#include"Utils.hpp"



template<class N>
class FObj
{
	public:
	N * n = 0;
	int * count = 0;
	FObj()
	{
		n = new N;
		count = new int;
		(*count) = 1;
	}
	FObj(const FObj<N> & p)
	{
		n = p.n;
		count = p.count;
		(*count)++;
	}
	~FObj()
	{
		(*count)--;
		if((*count) <=0)
		{
			delete(n);
			delete(count);
		}
	}
	FObj<N> & operator=(const FObj<N> & p)
	{
		(*count)--;
		if((*count)<=0)
		{
			delete(n);
			delete(count);
		}
		n = p.n;
		count = p.count;
		(*count)++;
		return (*this);
	}
	N* operator->()
	{
		return n;
	}
	
	N& operator *()
	{
		return (*n);
	}
	
	
	void Release()
	{
		(*count)--;
		if((*count) <=0)
		{
			delete(n);
			delete(count);
		}
		n = new N;
		count = new int;
		(*count) = 1;
	}
};

template<class A>
FObj<A> FactoryStatic()
{
    static FObj<A> obj;
    return obj;
}

template<class A>
FObj<A> FactoryInstance()
{
    FObj<A> obj;
    return obj;
}


uint32_t ___FactoryCounter = 0;

void FactoryScopeReset()
{
	___FactoryCounter++;
}

template<class A>
class Factory
{
    protected:

	static FObj<A> FactoryStatic()
	{
		static FObj<A> obj;
		return obj;
	}

	static FObj<A> FactoryInstance()
	{
		FObj<A> obj;
		return obj;
	}

	static uint32_t Count;
	static FObj<A> FactoryScope()
	{
		static FObj<A> obj;
		static uint32_t count = 0;
		if(___FactoryCounter != count)
		{
			obj = FObj<A>();
			count = ___FactoryCounter;
		}

		return obj;
	}


    static FObj<A> (*Fptr)();




    public:

    static void Static()
    {
        Fptr = FactoryStatic;

    }

    static void Instance()
    {
        Fptr = FactoryInstance;
    }

	static void Scope()
	{
		Fptr = FactoryScope;
	}

    static FObj<A> Get()
    {
        return Fptr();
    }

	

};
template<class A>
FObj<A> (*Factory<A>::Fptr)();



#endif
