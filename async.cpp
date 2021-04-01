

#ifndef ASYNC_CPP
#define ASYNC_CPP


#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <functional>
#include <future>
#include <thread>
#include <mutex>
#include <chrono>
#include <tuple>
#include <utility>
#include <stdlib.h>

using namespace std;

#define el << "\r\n"


void sleepSeconds(int seconds)
{
	this_thread::sleep_for(chrono::seconds(seconds));
}


class donestate
{
	bool _done = false;
	public:
	
	void operator =(bool state)
	{
		_done = state;
	}
	
	operator bool()
	{
		return _done;
	}
	
};

class donestatequeue: public queue<donestate>
{
	public:
	
	donestate & create()
	{
		
		push(donestate());
		return back();
		
	}
};


class asyncobj
{
	function<void()> _func;
	donestate * doneptr = 0;
	public:
	
	asyncobj(function<void()> func)
	{
		_func = func;
	}
	
	virtual void operator()()
	{
		_func();
	}
	void setWaiter(donestate & donewait)
	{
		doneptr = &donewait;
	}
	void done()
	{
		if(doneptr != 0)
		{
			(*doneptr) = true;
		}
	}
	
};

/*template<class...Args>
class asyncobj: public asyncbase
{
	function<void(Args...)> _func;
	tuple<Args...> _args;
	public:
	asyncobj(Args... args)
	{
		_args = tuple(args...);
	}
	asyncobj * run(function<void(Args...)> func)
	{
		_func = func;
		return this;
	}
	void operator()()
	{
		apply(_func, _args);
	}
	
};*/

#define NUMBEROFASYNCCORES 256
class asyncworkers
{
	queue<asyncobj*> masterqueue;
	
	thread * threadworker[NUMBEROFASYNCCORES];
	queue<int> inactivethreadworkerid;
	
	
	
	mutex addqueuemtx;
	mutex threadrenewmtx;
	
	
	public:
	asyncworkers()
	{
		for(int i = 0; i < NUMBEROFASYNCCORES; i++)
		{
			threadworker[i] = new thread([](){});
			inactivethreadworkerid.push(i);
		}
		
	}
	~asyncworkers()
	{
		for(int i = 0; i < NUMBEROFASYNCCORES; i++)
		{
			(*threadworker[i]).join();
			delete(threadworker[i]);
		}
	}
	void add(asyncobj * asyncobject)
	{
		unique_lock addlck(addqueuemtx, defer_lock);
		addlck.lock();
			masterqueue.push(asyncobject);
		addlck.unlock();
		
		
		unique_lock threadrenewlck(addqueuemtx, defer_lock);
		threadrenewlck.lock();
			bool incactiveempty = inactivethreadworkerid.empty();
			int threadid;
			if(!incactiveempty)
			{
				threadid = inactivethreadworkerid.front();
				inactivethreadworkerid.pop();
			}
		threadrenewlck.unlock();
		
		if(!incactiveempty)
		{
				(*threadworker[threadid]).join();
				delete(threadworker[threadid]);
				//cout << "start thread" el;
				threadworker[threadid] = new thread([&](int id)//, mutex & addqueuemtx, 	queue<asyncobj*> & masterqueue)
				{
					bool empty = false;
					asyncobj * n;
					do
					{
						unique_lock addlck(addqueuemtx, defer_lock);
						addlck.lock();
							empty = masterqueue.empty();
							if(!empty)
							{
								n = masterqueue.front();
								masterqueue.pop();
							}
						addlck.unlock();
						if(!empty)
						{
							(*n)();
							(*n).done();
							delete(n);
						}
						
					}
					while(!empty);
					
					unique_lock threadrenewlck(threadrenewmtx, defer_lock);
					threadrenewlck.lock();
						inactivethreadworkerid.push(id);
					threadrenewlck.unlock();
					
				}, threadid);
				//cout << "end thread" el;
			
			
		}
		
		
	}
	
};



asyncworkers __ASYNCWORKERS;

void asyncrun(function<void()> func)//asyncobj * asyncobject)
{
	
	 __ASYNCWORKERS.add(new asyncobj(func));
	
}

void asyncrun(function<void()> func, donestate & done)//asyncobj * asyncobject, donestate & done)
{
	//cout << "start async" el;
	asyncobj * asyncobject = new asyncobj(func);
	(*asyncobject).setWaiter(done);
	 __ASYNCWORKERS.add(asyncobject);
	//cout << "end async" el;
}

void waitfor(donestate &done)
{
	while(!done)
	{
		this_thread::yield();
	}
}

void waitforAll(donestatequeue & donequeue)
{
	while(!donequeue.empty())
	{
		donestate * dptr = &(donequeue.front());
		while(!(*dptr))
		{
			this_thread::yield();
		}
		donequeue.pop();
	}
}


#endif

