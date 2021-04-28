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
	List<A> * alist;
	A ** aref;
	function<mbool()> wherefunc;
	
	public:
	Query1List(List<A>  & al, A *& a)
	{
		alist = &al;
		aref = &a;
	}
	Query1List<A> whereDef(function<mbool()> func)
	{
		wherefunc = func;
		return (*this);
	}
	void select(function<void()> func)
	{
		for(auto i: (*alist))
		{
			(*aref) = &i;
			if( wherefunc())
			{
				func();
			}
		}
	}
	
	void select(List<A> & retlist)
	{
		for(auto i: (*alist))
		{
			(*aref) = &i;
			if( wherefunc())
			{
				retlist.PushBack(i);
			}
		}
	}
	
	
	template<class B>
	void select(List<B> & retlist)
	{
		
		for(auto i: (*alist))
		{
			(*aref) = &i;
			if( wherefunc())
			{
				B b;
				mapper(b, i);
				retlist.PushBack(b);
			}
		}
	}
	
	
	template<class B, class C>
	void select(List<B> & retlist, const C & c )
	{
		
		for(auto i: (*alist))
		{
			(*aref) = &i;
			if( wherefunc())
			{
				B b;
				mapper(b, i, (C&)c);
				retlist.PushBack(b);
			}
		}
	}
	template<class B, class C, class D>
	void select(List<B> & retlist, const C & c , const D & d)
	{
		
		for(auto i: (*alist))
		{
			(*aref) = &i;
			if( wherefunc())
			{
				B b;
				mapper(b, i, (C&)c, (D&)d);
				retlist.PushBack(b);
			}
		}
	}
	
	
	void selectFirst(function<void()> func)
	{
		
		for(auto i: (*alist))
		{
			(*aref) = &i;
			if( wherefunc())
			{
				func();
				return;
			}
		}
	}
	
	
	void selectFirst( A & ret)
	{
		for(auto i: (*alist))
		{
			(*aref) = &i;
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
		for(auto i: (*alist))
		{
			(*aref) = &i;
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
	//=========start List<C> const d select function
	
	template<class C, class D>
	void selectManyToMany(List<C> & retlist, const D & d)
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
					mapper(c, aa, bb, (D&)d);
					retlist.PushBack(c);
				}
			}
		}
	}
	
	template<class C, class D>
	void selectOneToMany(List<C> & retlist, const D & d)
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
					mapper(c, aa, bb, (D&)d);
					retlist.PushBack(c);
					break;
				}
			}
		}
	}
	
	template<class C, class D>
	void selectManyToOne(List<C> & retlist, const D & d)
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
					mapper(c, aa, bb, (D&)d);
					retlist.PushBack(c);
					break;
				}
			}
		}
	}
	
	template<class C, class D>
	void selectOneToOne(List<C> & retlist, const D & d)
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
					mapper(c, aa, bb, (D&)d);
					retlist.PushBack(c);
					break;
				}
			}
		}
	}
	
	
	//=========end List<C> const d select function
	
	
};


template<class A, class B>
Query2List<A, B> from(List<A> & alist, A * & aref, List<B> & blist, B *& bref)
{
	return Query2List<A, B>(alist, aref, blist, bref);
}




template<class A, class B>
void AddListItem(List<A> & alist, B & b)
{
	A a;
	mapper(a, b);
	alist.PushBack(a);
	
}

template<class A, class B, class C>
void AddListItem(List<A> & alist, B & b, C & c)
{
	A a;
	mapper(a, b, c);
	alist.PushBack(a);
	
}





	struct person
	{
		mint id = -1;
		String first = "";
		String last = "";
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
	
	
	struct personaddress
	{
		mint personid = -1;
		mint addressid = -1;
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
	
	struct invoice
	{
		mint id = -1;
		mint personid = -1;
		String line = "";
	};
	
	struct invoiceitem
	{
		mint id = -1;
		mint invoiceid = -1;
		String item = "";
		
	};

	
	struct personinvoice
	{
		String name = "";
		struct invoice
		{
			String line = "";
			List<String> items;
			
		};
		List<personinvoice::invoice> invoices;
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
	
	mapper<personinvoice, person>([](personinvoice & pi, person & p)
	{
		
		StringBuffer buff;
		buff + p.first + " " + p.last;
		buff.ToString(pi.name);
	});
	
	mapper<personinvoice::invoice, invoice>([](personinvoice::invoice & pinv, invoice & inv)
	{
		pinv.line = inv.line;
	});
	
	mapper<String, invoiceitem>([](String & str, invoiceitem & item)
	{
		str = item.item;
	});
}


void func(personinvoice & pi)
{
	
	pi.invoices.PushBack(personinvoice::invoice());
}

int main()
{
	

	
	
	makemapper();
	
	
	List<person> plist((person[]){
		{0, "matt", "bob"},
		{1, "tyson", "mike"},
		{2, "bla", "blob"},
		{3, "andrew", "blob"}
	});
	
	List<address> alist((address[]){
		{0, "123 elm street", "1234567"},
		{1, "456 bla street", "4444444"},
		{2, "88 ima street", "788"}
	});
	
	List<personaddress> palist((personaddress[]){
		{0, 0},
		{0, 1},
		{1, 1},
		{2, 2},
		{3, 0}
	});
	
	
	List<combo> clist;
	
	
	
	
	
	List<invoice> ilist((invoice[]){
		{0, 0, "magic tickets"},
		{1, 1, "water show"}
	});
	
	List<invoiceitem> itlist((invoiceitem[]){
		{0, 0, "2 adults $7.95"},
		{1, 0, "matic wand free"}
	});
	
	
	personinvoice piv;
	{
		
		person * p;
		invoice * inv;
		invoiceitem * invitem;
		from(plist, p)
		.where(p->first == "matt")
		.selectFirst([&]()
		{
			mapper(piv, (*p));
			
			from(ilist, inv)
			.where(inv->personid == p->id)
			.select([&]()
			{
				personinvoice::invoice inv1;
				mapper(inv1, (*inv));
				from(itlist, invitem)
				.where(invitem->invoiceid == inv->id)
				.select(inv1.items);
				piv.invoices.PushBack(inv1);
				
			});
			
		});
	}
	
	
	cout << piv.name el;
	for(auto a: piv.invoices)
	{
		cout << "\t" << a.line el;
		for(auto b: a.items)
		{
			
			cout << "\t\t" << b el;
		}
	}
	
	
	
	return 0;
}

