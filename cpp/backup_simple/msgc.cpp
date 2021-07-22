#ifndef MSGC_CPP
#define MSGC_CPP

#include <map>
#include <functional>

template<class N>
class msgc
{
	static map<function<void(N&)> *, function<void(N&)> *> _map;
	public:
	
	static void handel(function<void(N&)> & func)
	{
		_map[&func] = &func;
	}
	
	static void send(N n)
	{
		for(auto i: _map)
		{
			(*(i.second))(n);
		}
	}
	static void remove(function<void(N&)> & func)
	{
		_map.erase(&func);
	}
	
};
template<class N>
map<function<void(N&)> *, function<void(N&)> *> msgc<N>::_map;








#endif
