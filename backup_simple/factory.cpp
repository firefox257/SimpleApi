
#ifndef FACTORY_CPP
#define FACTORY_CPP

#include <functional>
using namespace std;


template <class N>
class factory
{
	static function<N*()> _get;
	
	static bool _isstatic;
	
	N * _n;
	public:
	
	static void set(function<N*()> func, bool isstatic)
	{
		_get = func;
		_isstatic = isstatic;
	}
	
	inline static N* get()
	{
		return _get();
	}
	
	factory()
	{
		_n = _get();
	}
	~factory()
	{
		
		if(!_isstatic)
		{
			delete(_n);
		}
	}
	N * operator ->()
	{
		return _n;
	}
	
};
template<class N>
function<N*()> factory<N>::_get;
template<class N>
bool factory<N>::_isstatic;

#endif
