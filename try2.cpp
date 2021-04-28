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
//#include "Array.cpp"
//#include "List.cpp"

#include "Async.cpp"
#include "SmtPtr.hpp"
#include "Mapper.cpp"
using namespace std;
#define el << "\r\n"


template<class N>
class Array;

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


template<class N>
class ListNode
{
	public:
	
	N n;
	ListNode<N> * prev = 0;
	ListNode<N> * next = 0;
	
};

template<class N>
class ListData
{
	public:
	
	ListNode<N> * h = 0;
	ListNode<N> * t = 0;
	mint size = 0;
	
	~ListData()
	{
		Clear();
	}
	void Clear()
	{
		ListNode<N> * ptr = h;
		while(ptr !=0)
		{
			
			ListNode<N> * ptr1 = ptr;
			ptr = ptr->next;
			delete(ptr1);
		}
		h = 0;
		t = 0;
		size = 0;
	}
	
	void PushBack(const N & n)
	{
		if(h == 0)
		{
			
			h = t = new ListNode<N>;
			h->n = n;
			size++;
		}
		else
		{
			t->next = new ListNode<N>;
			t->next->n = n;
			t->next->prev = t;
			
			t = t->next;
			size++;
		}
	}
	void PushFront(const N & n)
	{
		if(h == 0)
		{
			
			h = t = new ListNode<N>;
			h->n = n;
			size++;
		}
		else
		{
			ListNode<N> * ptr = new ListNode<N>;
			ptr->n = n;
			h->prev = ptr;
			ptr->next = h;
			h = ptr;
			size++;
		}
	}
	
	void Remove(ListNode<N> * ptr)
	{
		if(size > 0)
		{
			if(ptr->next != 0)
			{
				ptr->next->prev = ptr->prev;
			}
			
			
			if(ptr->prev != 0)
			{
				ptr->prev->next = ptr->next;
			}
			delete(ptr);
			size--;
			if(size == 0)
			{
				h = t = 0;
			}
		}
	}
	
	void PopBack()
	{
		ListNode<N> * ptr = t;
		t = t->prev;
		size--;
		t->next = 0;
		if(size == 0)
		{
			h= t = 0;
		}
		delete(ptr);
	}
	
	void PopFront()
	{
		ListNode<N> * ptr = h;
		h = h->next;
		h->prev = 0;
		size--;
		if(size == 0)
		{
			h = t = 0;
		}
		delete(ptr);
	}
};

template<class N>
class List
{
	SmtPtr<ListData<N>> ref;
	
	public:
	
	List()
	{
	}
	
	List(ArrayArg<N> n)
	{
		for(mint i = 0; i < n.size; i++)
		{
			ref->PushBack(n.data[i]);
			
		}
	}
	
	mint Size()
	{
		return ref->size;
	}
	
	void Clear()
	{
		ref->Clear();
	}
	void PushBack(const N & n)
	{
		ref->PushBack(n);
	}
	
	void PushBack(ArrayArg<N> n)
	{
		for(mint i = 0; i < n.size; i++)
		{
			ref->PushBack(n.data[i]);
			
		}
	}
	
	void PushBack(Array<N> & n)
	{
		mint s = n.Size();
		for(mint i = 0; i < s; i++)
		{
			ref->PushBack(n[i]);
			
		}
	}
	
	void PushFront(const N & n)
	{
		ref->PushFront(n);
	}
	
	void PushFront(ArrayArg<N> n)
	{
		for(mint i = 0; i < n.size; i++)
		{
			ref->PushFront(n.data[i]);
			
		}
	}
	
	void PushFront(Array<N> & n)
	{
		mint s = n.Size();
		for(mint i = 0; i < s; i++)
		{
			ref->PushFront(n[i]);
			
		}
	}
	
	
	inline void PopBack()
	{
		
		ref->PopBack();
	}
	
	inline void PopFront()
	{
		ref->PopFront();
	}
	
	
	inline N & Front()
	{
		return ref->h->n;
	}
	inline N & Back()
	{
		return ref->t->n;
	}
	
	
	
	
	List<N> & operator = (ArrayArg<N> a)
	{
		ref->Clear();
		PushBack(a);
		return (*this);
	}
	
	List<N> & operator = (Array<N> & a)
	{
		ref->Clear();
		PushBack(a);
		return (*this);
		
	}
	
	class Iterator
	{
		public:
		ListNode<N> * ptr = 0;
		Iterator()
		{
			
		}
		Iterator(ListNode<N> * n)
		{
			ptr = n;
		}
		
		Iterator & operator++()
		{
			if(ptr != 0) ptr = ptr->next;
			return (*this);
		}
		Iterator & operator++(mint)
		{
			if(ptr != 0) ptr = ptr->next;
			return (*this);
		}
		
		mbool operator !=(const Iterator & node)
		{
			if(ptr == node.ptr) return false;
			return true;
		}
		 
		N & operator*()
		{
			return ptr->n;
			
		}
		
	};
	
	Iterator begin()
	{
		return Iterator(ref->h);
	}
	 
	
	const Iterator & end()
	{
		static const Iterator enditerator;
		return enditerator;
	}
	
	void remove(Iterator & i)
	{
		if(i.ptr == ref->h)
		{
			ref->PopFront();
			i.ptr = ref->h;
		}
		else if(i.ptr == ref->t)
		{
			ref->PopBack();
			i.ptr =0;
		}
		else
		{
			ListNode<N> * node = i.ptr->next;
			ref->Remove(i.ptr);
			i.ptr = node;
		}
	}
	
	
	operator Array<N>()
	{
		Array<N> a;
		a.Size(Size());
		mint count = 0;
		for(auto i: (*this))
		{
			a[count] = i;
			count++;
		}
		return a;
	}
	
	N& first()
	{
		return ref->h->n;
	}
	
};


template<class A, class B>
class MapNode
{
	public:
	A key;
	B value;
	MapNode<A, B> * left = 0;
	MapNode<A, B> * right = 0;
	
};
template<class A, class B>
class Map 
{
	public:
	MapNode<A, B> * h = 0;
	
	Map()
	{
	}
	
	
	B & operator[](const A & a)
	{
		
		if(h == 0)
		{
			h = new MapNode<A, B>;
			h->key = a;
			return h->value;
		}
		else
		{
			MapNode<A, B> * ptr = h;
			while(true)
			{
				if(a < ptr->key)
				{
					if(ptr->left == 0)
					{
						ptr->left = new MapNode<A, B>;
						ptr = ptr->left;
						ptr->key = a;
						return ptr->value;
					}
					ptr = ptr->left;
					
				}
				else if(a > ptr->key)
				{
					if(ptr->right == 0)
					{
						ptr->right = new MapNode<A, B>;
						ptr = ptr->right;
						ptr->key = a;
						return ptr->value;
					}
					ptr = ptr->right;
					
				}
				else if( a == ptr->key)
				{
					return ptr->value;
				}
			}//end while
		}//end else;
	}//
	
	
};











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





#define where(C) whereDef([&]() -> mbool \
{\
	return C;\
})


/* other quiries
template<class A, class B>
class Query2List
{
	List<A> * al;
	A ** aref;
	List<B> * bl;
	B ** bref;
	
	function<mbool()> wherefunc;
	
	public:
	Query2List(List<A>  & alist, A *& a, List<B> & blist,B *& b )
	{
		al = &alist;
		aref = &a;
		bl = &blist;
		bref = &b;
	}
	Query2List<A, B> & where(function<mbool()> func)
	{
		wherefunc = func;
		return (*this);
	}
	
	void select(function<void()> func)
	{
		for(auto ia: (*al))
		{
			(*aref) = &ia;
			for(auto ib: (*bl))
			{
				(*bref) = &ib;
				mbool b1 = wherefunc();
				if(wherefunc())
				{
					func();
					
				}
				
			}
		}
	}
	
	template<class C>
	List<C> select(function<C()> func)
	{
		List<C> retc;
		for(auto ia: (*al))
		{
			(*aref) = &ia;
			for(auto ib: (*bl))
			{
				(*bref) = &ib;
				if(wherefunc())
				{
					retc.PushBack(func());
				}
				
			}
		}
		return retc;
	}
	
	template<class C>
	void select()
	{
		
	}
	
	
};




template<class A, class B>
Query2List<A, B> from(List<A> & al, A * &aref, List<B> & bl, B * & bref)
{
	return Query2List<A, B>(al, aref, bl, bref);
}


*/











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

int main()
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
	
	
	List<person> plist((person[]){
		{0, "matt", "bob", 0},
		{0, "tyson", "mike", 0},
		{0, "bla", "blob", 0}
	});
	
	
	{
		person * p;
		List<person2> persons;
		
		from(plist, p)
		.where(p->id == 0)
		.select(persons);
		
		for(auto i: persons)
		{
			cout << i.name el;
		}
		
		List<person2> plist2;
		
		mapper(plist2, plist);
		
		for(auto i: persons)
		{
			cout << i.name el;
		}
	}
	
	
	return 0;
}

