#ifndef ASYNC_CPP
#define ASYNC_CPP

#include "Types.cpp"
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


void SleepHours(int d)
{
	this_thread::sleep_for(chrono::hours(d));
}
void SleepMinutes(int d)
{
	this_thread::sleep_for(chrono::minutes(d));
}
void SleepSeconds(int d)
{
	this_thread::sleep_for(chrono::seconds(d));
}
void SleepMilliSeconds(int d)
{
	this_thread::sleep_for(chrono::milliseconds(d));
}
void SleepMicroSeconds(int d)
{
	this_thread::sleep_for(chrono::microseconds(d));
}

class DoneState
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

class DoneStateQueue: public queue<DoneState>
{
	public:
	
	DoneState & Create()
	{
		
		push(DoneState());
		return back();
		
	}
};


class AsyncObj
{
	function<void()> _func;
	DoneState * doneptr = 0;
	public:
	
	AsyncObj(function<void()> func)
	{
		_func = func;
	}
	
	virtual void operator()()
	{
		_func();
	}
	void SetWaiter(DoneState & donewait)
	{
		doneptr = &donewait;
	}
	void Done()
	{
		if(doneptr != 0)
		{
			(*doneptr) = true;
		}
	}
	
};

#define NUMBEROFASYNCCORES 256
class AsyncWorkers
{
	queue<AsyncObj*> masterqueue;
	
	thread * threadworker[NUMBEROFASYNCCORES];
	queue<mint> inactivethreadworkerid;
	
	
	
	mutex addqueuemtx;
	mutex threadrenewmtx;
	
	
	public:
	AsyncWorkers()
	{
		for(mint i = 0; i < NUMBEROFASYNCCORES; i++)
		{
			threadworker[i] = new thread([](){});
			inactivethreadworkerid.push(i);
		}
		
	}
	~AsyncWorkers()
	{
		for(mint i = 0; i < NUMBEROFASYNCCORES; i++)
		{
			(*threadworker[i]).join();
			delete(threadworker[i]);
		}
	}
	void Add(AsyncObj * asyncobject)
	{
		unique_lock addlck(addqueuemtx, defer_lock);
		addlck.lock();
			masterqueue.push(asyncobject);
		addlck.unlock();
		
		
		unique_lock threadrenewlck(addqueuemtx, defer_lock);
		threadrenewlck.lock();
			mbool incactiveempty = inactivethreadworkerid.empty();
			mint threadid;
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
				threadworker[threadid] = new thread([&](mint id)
				{
					mbool empty = false;
					AsyncObj * n;
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
							(*n).Done();
							delete(n);
						}
						
					}
					while(!empty);
					
					unique_lock threadrenewlck(threadrenewmtx, defer_lock);
					threadrenewlck.lock();
						inactivethreadworkerid.push(id);
					threadrenewlck.unlock();
					
				}, threadid);
		}
		
		
	}
	
};



AsyncWorkers __ASYNCWORKERS;

void AsyncRun(function<void()> func)
{
	 __ASYNCWORKERS.Add(new AsyncObj(func));
}

void AsyncRun(function<void()> func, DoneState & done)
{
	AsyncObj * asyncobject = new AsyncObj(func);
	(*asyncobject).SetWaiter(done);
	 __ASYNCWORKERS.Add(asyncobject);
}

void AsyncRun(function<void()> func, DoneStateQueue & donequeue)//asyncobj * asyncobject, donestate & done)
{
	AsyncObj * asyncobject = new AsyncObj(func);
	(*asyncobject).SetWaiter(donequeue.Create());
	 __ASYNCWORKERS.Add(asyncobject);

}

void WaitFor(DoneState &done)
{
	while(!done)
	{
		this_thread::yield();
	}
}

void WaitFor(DoneStateQueue & donequeue)
{
	while(!donequeue.empty())
	{
		DoneState * done = &(donequeue.front());
		while(!(*done))
		{
			this_thread::yield();
		}
		donequeue.pop();
	}
}


#endif
