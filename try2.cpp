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

#include "Async.cpp"
#include "SmtPtr.hpp"
#include "Mapper.cpp"
using namespace std;
#define el << "\r\n"







#define where(C) whereDef([&]() -> mbool \
{\
	return C;\
})

template<class A>
class Query1List
{
	List<A> * l1;
	A ** ref;
	function<mbool()> wherefunc;
	
	public:
	Query1List(List<A>  & l, A *& a)
	{
		l1 = &l;
		ref = &a;
	}
	Query1List<A> whereDef(function<mbool()> func)
	{
		wherefunc = func;
		return (*this);
	}
	void select(function<void()> func)
	{
		for(auto i: (*l1))
		{
			(*ref) = &i;
			if( wherefunc())
			{
				func();
			}
		}
	}
	
	void select(List<A> & retlist)
	{
		for(auto i: (*l1))
		{
			(*ref) = &i;
			if( wherefunc())
			{
				retlist.PushBack(i);
			}
		}
	}
	
	
	template<class B>
	void select(List<B> & retlist)
	{
		
		for(auto i: (*l1))
		{
			(*ref) = &i;
			if( wherefunc())
			{
				B b;
				mapper(b, i);
				retlist.PushBack(b);
			}
		}
	}
	
	void selectFirst(function<void()> func)
	{
		
		for(auto i: (*l1))
		{
			(*ref) = &i;
			if( wherefunc())
			{
				func();
				return;
			}
		}
	}
	
	
	void selectFirst( A & ret)
	{
		for(auto i: (*l1))
		{
			(*ref) = &i;
			if( wherefunc())
			{
				ret = i;
				return;
			}
		}
	}
	
	template<class B>
	void selectFirst( B & ret)
	{
		for(auto i: (*l1))
		{
			(*ref) = &i;
			if( wherefunc())
			{
				mapper(ret, i);
				return;
			}
		}
	}
	
};


template<class A>
Query1List<A> from(List<A> & alist, A * & aref)
{
	return Query1List<A>(alist, aref);
}





template<class A, class B>
class Query2List
{
	List<A> * alist;
	A ** aref;
	
	List<B> * blist;
	B ** bref;
	
	function<mbool()> wherefunc;
	
	public:
	Query2List(List<A>  & al, A *& a, List<B> & bl, B*& b)
	{
		alist = &al;
		aref = &a;
		
		blist = &bl;
		bref = &b;
	}
	Query2List<A, B> whereDef(function<mbool()> func)
	{
		wherefunc = func;
		return (*this);
	}
	
	//=========start plain select function
	void selectManyToMany(function<void()> func)
	{
		for(auto aa: (*alist))
		{
			(*aref) = &aa;
			for(auto bb: (*blist))
			{
				(*bref) = &bb;
				if( wherefunc())
				{
					func();
				}
			}
		}
	}
	
	void selectOneToMany(function<void()> func)
	{
		for(auto bb: (*blist))
		{
			(*bref) = &bb;
			for(auto aa: (*alist))
			{
				(*aref) = &aa;
				if( wherefunc())
				{
					func();
					break;
				}
			}
		}
	}
	
	void selectManyToOne(function<void()> func)
	{
		for(auto aa: (*alist))
		{
			(*aref) = &aa;
			for(auto bb: (*blist))
			{
				(*bref) = &bb;
				if( wherefunc())
				{
					func();
					break;
				}
			}
		}
	}
	
	void selectOneToOne(function<void()> func)
	{
		//todo optimize by removing entries
		for(auto aa: (*alist))
		{
			(*aref) = &aa;
			for(auto bb: (*blist))
			{
				(*bref) = &bb;
				if( wherefunc())
				{
					func();
					break;
				}
			}
		}
	}
	
	
	//=========end plain select function
	
	//=========start List<A> select function
	
	
	void selectManyToMany(List<A> & retlist)
	{
		selectOneToMany(retlist);
	}
	
	void selectOneToMany(List<A> & retlist)
	{
		for(auto bb: (*blist))
		{
			(*bref) = &bb;
			for(auto aa: (*alist))
			{
				(*bref) = & aa;
				if( wherefunc())
				{
					retlist.PushBack(aa);
					break;
				}
			}
		}
	}
	
	void selectManyToOne(List<A> & retlist)
	{
		selectOneToMany(retlist);
	}
	
	
	void selectOneToOne(List<A> & retlist)
	{
		//todo optimize by removing entries. 
		for(auto aa: (*alist))
		{
			(*aref) = &aa;
			for(auto bb: (*blist))
			{
				(*bref) = & bb;
				if( wherefunc())
				{
					retlist.PushBack(aa);
					break;
				}
			}
		}
	}
	
	//=========end List<A> select function
	//=========start List<B> select function
	void selectManyToMany(List<B> & retlist)
	{
		selectManyToOne(retlist);
	}
	
	void selectOneToMany(List<B> & retlist)
	{
		selectManyToOne(retlist);
	}
	
	void selectManyToOne(List<B> & retlist)
	{
		for(auto aa: (*alist))
		{
			(*aref) = &aa;
			for(auto bb: (*blist))
			{
				(*bref) = & bb;
				if( wherefunc())
				{
					retlist.PushBack(bb);
					break;
				}
			}
		}
	}
	
	void selectOneToOne(List<B> & retlist)
	{
		//todo optimize by removing entries. 
		for(auto aa: (*alist))
		{
			(*aref) = &aa;
			for(auto bb: (*blist))
			{
				(*bref) = & bb;
				if( wherefunc())
				{
					retlist.PushBack(aa);
					break;
				}
			}
		}
	}
	
	
	//=========end List<B> select function
	//=========start List<C> select function
	template<class C>
	void selectManyToMany(List<C> & retlist)
	{
		for(auto aa: (*alist))
		{
			(*aref) = &aa;
			for(auto bb: (*blist))
			{
				(*bref) = & bb;
				if( wherefunc())
				{
					C c;
					mapper(c, aa, bb);
					retlist.PushBack(c);
				}
			}
		}
	}
	
	template<class C>
	void selectOneToMany(List<C> & retlist)
	{
		for(auto bb: (*blist))
		{
			(*bref) = &bb;
			for(auto aa: (*alist))
			{
				(*aref) = & aa;
				if( wherefunc())
				{
					C c;
					mapper(c, aa, bb);
					retlist.PushBack(c);
					break;
				}
			}
		}
	}
	
	template<class C>
	void selectManyToOne(List<C> & retlist)
	{
		for(auto aa: (*alist))
		{
			(*aref) = &aa;
			for(auto bb: (*blist))
			{
				(*bref) = & bb;
				if( wherefunc())
				{
					C c;
					mapper(c, aa, bb);
					retlist.PushBack(c);
					break;
				}
			}
		}
	}
	
	template<class C>
	void selectOneToOne(List<C> & retlist)
	{
		//todo optimize by removing search entries. 
		for(auto aa: (*alist))
		{
			(*aref) = &aa;
			for(auto bb: (*blist))
			{
				(*bref) = & bb;
				if( wherefunc())
				{
					C c;
					mapper(c, aa, bb);
					retlist.PushBack(c);
					break;
				}
			}
		}
	}
	
	
	//=========end List<C> select function
};


template<class A, class B>
Query2List<A, B> from(List<A> & alist, A * & aref, List<B> & blist, B *& bref)
{
	return Query2List<A, B>(alist, aref, blist, bref);
}















	struct person
	{
		mint id = -1;
		String first = "";
		String last = "";
		mint addressid = -1;
	};
	
	struct person2
	{
		String name = "";
	};
	
	struct address
	{
		mint id = -1;
		String street = "";
		String zip = "";
	};
	
	struct combo
	{
		String name = "";
		String street = "";
		String zip = "";
	};
	
	
	struct addresscount
	{
		String name = "";
		mint count = 1;
		List<address> addresses;
	};
	


void makemapper()
{
	mapper<combo, person, address>([](combo & c, person & p, address & a)
	{
		StringBuffer buf;
		buf + p.first + " " + p.last;
		buf.ToString(c.name);
		c.street = a.street;
		c.zip = a.zip;
	});
	
	mapper<person2, person>([](person2 & p2, person p)
	{
		StringBuffer buf;
		buf + p.first + " " + p.last;
		buf.ToString(p2.name);
	});
	
	mapper<List<person2>, List<person>>([](List<person2> & p2, List<person>&  p)
	{
		for(auto i: p)
		{
			person2 pp2;
			mapper(pp2, p);
			p2.PushBack(pp2);
		}
		
	});
	
}


int main()
{
	makemapper();
	
	
	List<person> plist((person[]){
		{0, "matt", "bob", 0},
		{0, "matt", "bob", 1},
		{1, "tyson", "mike", 1},
		{2, "bla", "blob", 2},
		{3, "andrew", "blob", 0}
	});
	
	List<address> alist((address[]){
		{0, "123 elm street", "1234567"},
		{1, "456 bla street", "4444444"},
		{2, "88 ima street", "788"}
		
	});
	
	
	List<combo> clist;
	
	
	
	{
		address * a;
		person * p;
		
		from(plist, p, alist, a)
		.where(p->addressid == a->id)
		.selectManyToMany(clist);
		
		for(auto i: clist)
		{
			
			cout << "name " << i.name << " street: " << i.street << " zip "<<  i.zip el;
		}
		
		map<mint, addresscount> counting;
		
		from(plist, p, alist, a)
		.where(p->addressid == a->id)
		.selectManyToMany([&]()
		{
			if ( counting.find(p->id) == counting.end() ) 
			{
				StringBuffer buff;
				buff + p->first + " "  + p->last;
				buff.ToString(counting[p->id].name);
				counting[p->id].addresses.PushBack((*a));
			} 
			else 
			{
			  counting[p->id].count++;
			  counting[p->id].addresses.PushBack((*a));
			}
		});
		
		for(auto i: counting)
		{
			cout << i.second.name << " " << i.second.count el;
			for(auto a: i.second.addresses)
			{
				cout <<"# " << a.street << " " << a.zip el;
			}
		}
		
		
	}
	
	
	return 0;
}

