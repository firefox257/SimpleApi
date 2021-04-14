#ifndef GETSET_CPP
#define GETSET_CPP
#include <functional>


template<class N>
class getset
{
	function<N&()> _get;
	function<void(const N &)> _set;
	public:
	getset(function<N&()> get, function<void (const N&)> set)
	{
		_get = get;
		_set = set;
	}
	
	N& operator = (const N& n)
	{
		_set(n);
		return _get();
	}
	operator N&()
	{
		
		return _get();
	}
	
};
#define $gs(T, N, G, S) getset<T> N = getset<T>([&]()-> T &\
G,\
[&](const T & v)\
S);

#endif
