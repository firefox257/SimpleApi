
#ifndef LIST_CPP
#define LIST_CPP
#include <list>
#include "Types.hpp"
#include "DataIO.hpp"

template<class N>
class Array;

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
	
	
};

#endif
