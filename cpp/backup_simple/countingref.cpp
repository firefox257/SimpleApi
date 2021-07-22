#ifndef COUNTINGREF_CPP
#define COUNTINGREF_CPP
/*
Counting reference smart pointer with cascading methods. 
to use example

struct crtry1data
{
	int x;
	int y;
};
class crtry1: public countingref<crtry1, crtry1data>
{
	public:
	#define CMPARENT crtry1
	$cm(int, x,
	{
		
		return n->x;
	}, 
	{
		
		n->x = v;
	});
	$scm(int, y, n->y);
	
	crtry1()
	{
		
	}
	crtry1(int xx, int yy)
	{
		x(xx).y(yy);
	}
	//provide implmentation for it to assign properly.
	crtry1 & operator = (const crtry1 & n)
	{
		refequals(n);
		return (*this);
	}
	
};

crtry1 crfunc()
{
	crtry1 t1(123, 124);
	//or methode cascading t1.x(123).y(124);
	
	
	cout << "here1 " << t1.x() << " " << t1.y() el;
	return t1;
}

int main()
{
  crtry1 crt1;
  crt1 = crfunc();
  //or crtry1 crt1 = crfunc(); works as well.
  
	
	cout << crt1.x() << " " << crt1.y() el;
	

  return 0;
}


*/




template<class PARENT, class NODE>
class countingref
{
	protected:
	NODE * n = new NODE;
	int * count = new int;
	public:
	
	
	countingref()
	{
		//cout << "create" el;
		n = new NODE;
		count = new int;
		(*count) = 1;
	}
	countingref(const PARENT & p)
	{
		delete(n);
		delete(count);
		//cout << "copy constructor " el;
		n = p.n;
		count = p.count;
		(*count)++;
	}
	~countingref()
	{
		(*count)--;
		if((*count) <=0)
		{
			//cout << "delete" el;
			delete(count);
			delete(n);
		}
	}
	
	void refequals(const PARENT & p)
	{
		(*count)--;
		if((*count) <=0)
		{
			//cout << "delete = " el;
			delete(n);
			delete(count);
		}
		n = p.n;
		count = p.count;
		(*count)++;
	}
	
	
};


#define $cm(T, NA, G, S) T & NA() G CMPARENT & NA(const T & v) {S  return (*((CMPARENT*)this));}
#define $scm(T, NA, B) T & NA(){ return B;} CMPARENT & NA(const T & v) { B = v; return (*((CMPARENT*)this));}



#endif
