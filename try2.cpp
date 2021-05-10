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



template<int A>
class CharArray
{
	mchar data[A];
	
	public:
	CharArray()
	{
		data[0] = 0;
	}
	
	CharArray(const mchar * d)
	{
		mint at = 0;
		while(d[at] != 0 && at <= A)
		{
			data[at] = d[at];
			at++;
		}
		data[at] = 0;
	}
	CharArray(mchar * d)
	{
		mint at = 0;
		while(d[at] != 0 && at <= A)
		{
			data[at] = d[at];
			at++;
		}
		data[at] = 0;
	}
	CharArray(String & str)
	{
		mint ss = str.Size();
		if(ss > A) ss = A;
		mchar * strc = str.cstr();
		for(mint i = 0; i < ss; i++)
		{
			
			data[i] = strc[i];
		}
		data[ss] = 0;
	}
	
	mint Size()
	{
		return A;
	}
	operator mchar *()
	{
		return data;
	}
	
	CharArray<A> & operator = (const mchar * d)
	{
		mint at = 0;
		while(d[at] != 0 && at <= A)
		{
			data[at] = d[at];
			at++;
		}
		data[at] = 0;
		return (*this);
	}
	CharArray<A> & operator = (mchar * d)
	{
		mint at = 0;
		while(d[at] != 0 && at <= A)
		{
			data[at] = d[at];
			at++;
		}
		data[at] = 0;
		reutrn (*this);
	}
	CharArray<A> & operator = (String & str)
	{
		
		mint ss = str.Size();
		if(ss > A) ss = A;
		mchar * strc = str.cstr();
		for(mint i = 0; i < ss; i++)
		{
			
			data[i] = strc[i];
		}
		data[ss] = 0;
	}
	
};





template<class A>
class Query1List
{
	List<A> * alist;
	function<mbool(A&)> wherefunc;
	
	public:
	Query1List(List<A>  & al)
	{
		alist = &al;
	}
	Query1List<A> where(function<mbool(A&)> func)
	{
		wherefunc = func;
		return (*this);
	}
	void select(function<void(A&)> func)
	{
		for(auto a: (*alist))
		{
			if( wherefunc(a))
			{
				func(a);
			}
		}
	}
	
	void selectFirst(function<void(A&)> func)
	{
		for(auto a: (*alist))
		{
			if( wherefunc(a))
			{
				func(a);
				return;
			}
		}
	}
	
};


template<class A>
Query1List<A> from(List<A> & alist)
{
	return Query1List<A>(alist);
}





template<class A, class B>
class Query2List
{
	List<A> * alist;
	//A ** aref;
	
	List<B> * blist;
	//B ** bref;
	
	function<mbool(A&, B &)> wherefunc;
	
	public:
	Query2List(List<A>  & al, List<B> & bl)
	{
		alist = &al;
		//aref = &a;
		
		blist = &bl;
		//bref = &b;
	}
	Query2List<A, B> where(function<mbool(A &, B &)> func)
	{
		wherefunc = func;
		return (*this);
	}
	
	//=========start plain select function
	void selectManyToMany(function<void(A&, B&)> func)
	{
		for(auto aa: (*alist))
		{
			//(*aref) = &aa;
			for(auto bb: (*blist))
			{
				//(*bref) = &bb;
				if( wherefunc(aa, bb))
				{
					func(aa, bb);
				}
			}
		}
	}
	
	void selectOneToMany(function<void(A&, B&)> func)
	{
		for(auto bb: (*blist))
		{
			for(auto aa: (*alist))
			{
				if( wherefunc(aa, bb))
				{
					func(aa, bb);
					break;
				}
			}
		}
	}
	
	void selectManyToOne(function<void(A &, B &)> func)
	{
		for(auto aa: (*alist))
		{
			for(auto bb: (*blist))
			{
				if( wherefunc(aa, bb))
				{
					func(aa, bb);
					break;
				}
			}
		}
	}
	
	void selectOneToOne(function<void(A&, B&)> func)
	{
		//todo optimize by removing entries
		for(auto aa: (*alist))
		{
			for(auto bb: (*blist))
			{
				if( wherefunc(aa, bb))
				{
					func(aa, bb);
					break;
				}
			}
		}
	}
	
};


template<class A, class B>
Query2List<A, B> from(List<A> & alist, List<B> & blist)
{
	return Query2List<A, B>(alist, blist);
}




template<class A, class B>
void joinList(List<A> & alist, B & b)
{
	A a;
	mapper(a, b);
	alist.PushBack(a);
	
}

template<class A, class B, class C>
void joinList(List<A> & alist, B & b, C & c)
{
	A a;
	mapper(a, b, c);
	alist.PushBack(a);
	
}

#define query(F, A, W, WC, S, SC)\
F.W([&]A -> mbool\
{\
	return WC;\
})\
.S([&]A SC)



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
	
	
	

/*
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

*/
void func(personinvoice & pi)
{
	
	pi.invoices.PushBack(personinvoice::invoice());
}

int main()
{
	






















	List<String> list1;
	for(int i = 0; i < 50000000; i++)
	{
		StringBuffer buff;
		buff + "try" + i;
		String str1;
		buff.ToString(str1);
		
		list1.PushBack(str1);
	}
	
	cout << "start" el;
	
	
	query(from(list1), (auto l),
	where, l =="try49999999",
	selectFirst,
	{
		
		cout << l el;
	});
	
	/*makemapper();
	
	
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
	
	{
		
		
		
		List<combo>clist;
		
		query(from(plist, palist), (auto p, auto pa), 
		where, p.id == pa.personid, 
		selectOneToMany, 
		{
			
			query(from(alist), (auto a), 
			where, a.id == pa.addressid,
			selectFirst,
			{
				joinList(clist, p, a);
				
			});
			
			
		});
		
		
		cout << clist.Size() el;
		for(auto i: clist)
		{
			cout << i.name << " " << i.street << " " << i.zip el;
		}
		cout << "================================" el;
		
		
		List<personinvoice> pilist;
		query(from(plist, ilist), (auto p, auto inv),
		where, p.id == inv.personid,
		selectOneToOne,
		{
			personinvoice pi1;
			mapper(pi1, p);
			
			query(from(ilist), (auto inv1),
			where, inv1.personid == p.id,
			select,
			{
				personinvoice::invoice inv2;
				mapper(inv2, inv1);
				
				query(from(itlist), (auto item),
				where, item.invoiceid == inv1.id,
				select,
				{
					joinList(inv2.items, item);
					
				});
				
				pi1.invoices.PushBack(inv2);
				
			});
			
			pilist.PushBack(pi1);
		});
		
		
		for(auto a: pilist)
		{
			cout << a.name el;
			for(auto b: a.invoices)
			{
				cout << "\t" << b.line el;
				for(auto c: b.items)
				{
					
					cout << "\t\t" << c el;
				}
			}
		}
	}
	
	*/
	
	
	
	return 0;
}

