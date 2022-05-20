#ifndef FACTORY_CPP
#define FACTORY_CPP




template<class N>
class Factory
{
	public:
	N * n = 0;
	mint * count = 0;
	mbool * isStatic = 0;
	
	
	Factory(N * atn, mbool isstatic = false)
	{
		n = atn;
		count = new mint;
		(*count) = 1;
		isStatic = new mbool;
		(*isStatic) = isstatic;
		//cout << "facotry init" el;
	}
	Factory(const Factory<N> & p)
	{
		n = p.n;
		count = p.count;
		(*count)++;
		isStatic = p.isStatic;
		//cout << "copy constructor factory" el;
	}
	~Factory()
	{
		(*count)--;
		if((*count) <=0)
		{
			//cout <<"delete facotry " el;
			if(!(*isStatic)) delete(n);
			delete(count);
			delete(isStatic);
		}
	}
	Factory<N> & operator=(const Factory<N> & p)
	{
		(*count)--;
		if((*count)<=0)
		{
			if(!(*isStatic)) delete(n);
			delete(count);
			delete(isStatic);
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
	
};

//Ctodo change out to Map.
struct FactoryNode
{
	function<void *()> callout;
	mbool isStatic = false;
	
};
map<mulong, FactoryNode> globalFactoryMap;


template<class A>
void factory(function<void*()> func, mbool isstatic)
{
	static const mulong id = GetClassId<A>();
	globalFactoryMap[id] = {func, isstatic};
}

template<class A>
Factory<A> factory()
{
	static const mulong id = GetClassId<A>();
	static function<void*()> func = globalFactoryMap[id].callout;
	static mbool isstatic = globalFactoryMap[id].isStatic;
	return Factory<A>((A*)func(), isstatic);
}





/*
//example
class try1
{
	public:
	String title = "hi there";
	
	void func()
	{
		cout << title el;
	}
};



int main()
{
	factory<try1>([]()->void *
	{
		static try1 t1;
		
		return & t1;
		
	}, true);
	
	
	
	auto t1 = factory<try1>();
	
	t1->func();
	
	return 0;
}

*/

#endif