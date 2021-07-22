#ifndef SMTPTR_HPP
#define SMTPTR_HPP



template<class N>
class SmtPtr
{
	public:
	N * n = 0;
	mint * count = 0;
	SmtPtr()
	{
		n = new N;
		count = new mint;
		(*count) = 1;
	}
	SmtPtr(const SmtPtr<N> & p)
	{
		n = p.n;
		count = p.count;
		(*count)++;
	}
	~SmtPtr()
	{
		(*count)--;
		if((*count) <=0)
		{
			delete(n);
			delete(count);
		}
	}
	SmtPtr<N> & operator=(const SmtPtr<N> & p)
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
		count = new mint;
		(*count) = 1;
	}
};

//create cascading method with a getter and setter. 
#define $cm(T, NA, G, S) T & NA() G CMPARENT & NA(const T & v) {S  return (*((CMPARENT*)this));}

//create a cascading methode that is simple for a getter setter, pointing to the backer variable. 
#define $scm(T, NA, B) T & NA(){ return B;} CMPARENT & NA(const T & v) { B = v; return (*((CMPARENT*)this));}



#endif