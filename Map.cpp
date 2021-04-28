#ifndef MAP_CPP
#define MAP_CPP

#include <map>
#include "Types.hpp"
#include "DataIO.hpp"


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








#endif