#ifndef ASYNC_HPP
#define ASYNC_HPP

#include <stdint.h>
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



class AsyncObjBase
{
    DoneState * doneptr = 0;
    public:
    virtual void operator()() = 0;

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

class AsyncObj: public AsyncObjBase
{
    function<void()> _func;
    public:
    AsyncObj(function<void()> func)
	{
		_func = func;
	}

    void operator()()
	{
		_func();
	}

};

template<class OBJ, class FUNC, class ... ARGS>
class AsyncClassFunc: public AsyncObjBase
{
    OBJ * optr = 0;
    FUNC Func;
    tuple<ARGS...> tup;
    public:
    AsyncClassFunc(OBJ & o, FUNC func, ARGS ... args)
    {
        optr = &o;
        Func = func; 
        tup =  tuple<ARGS...>(args...);
    }

    void operator()()
	{
		apply(Func, tuple_cat(make_tuple(optr), tup) );
	}

};

/*
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
*/

#define NUMBEROFASYNCCORES 256
class AsyncWorkers
{
	queue<AsyncObjBase*> masterqueue;
	
	thread * threadworker[NUMBEROFASYNCCORES];
	queue<int> inactivethreadworkerid;
	
	
	
	mutex addqueuemtx;
	mutex threadrenewmtx;
	
	
	public:
	AsyncWorkers()
	{
		for(int i = 0; i < NUMBEROFASYNCCORES; i++)
		{
			threadworker[i] = new thread([](){});
			inactivethreadworkerid.push(i);
		}
		
	}
	~AsyncWorkers()
	{
		for(int i = 0; i < NUMBEROFASYNCCORES; i++)
		{
			(*threadworker[i]).join();
			delete(threadworker[i]);
		}
	}
	void Add(AsyncObjBase * asyncobject)
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
				threadworker[threadid] = new thread([&](int id)
				{
					bool empty = false;
					AsyncObjBase * n;
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

void AsyncRun( DoneState & done, function<void()> func)
{
	AsyncObj * asyncobject = new AsyncObj(func);
	(*asyncobject).SetWaiter(done);
	 __ASYNCWORKERS.Add(asyncobject);
}

void AsyncRun(DoneStateQueue & donequeue, function<void()> func)//asyncobj * asyncobject, donestate & done)
{
	AsyncObj * asyncobject = new AsyncObj(func);
	(*asyncobject).SetWaiter(donequeue.Create());
	 __ASYNCWORKERS.Add(asyncobject);

}


template<class OBJ, class FUNC, class ... ARGS>
void AsyncRunClass(OBJ & o, FUNC func, ARGS&&... args)
{
     __ASYNCWORKERS.Add(new AsyncClassFunc<OBJ, FUNC, ARGS...>(o, func, args...));
}

template<class OBJ, class FUNC, class ... ARGS>
void AsyncRunClass( DoneState & done, OBJ & o, FUNC func, ARGS &&... args)
{
    auto asyncobject = new AsyncClassFunc<OBJ, FUNC, ARGS&&...>(o, func, args...);
	(*asyncobject).SetWaiter(done);
    __ASYNCWORKERS.Add(asyncobject);
}

template<class DONESTATEQUEUE, class OBJ, class FUNC, class ... ARGS>
void AsyncRunClass(DONESTATEQUEUE & donequeue, OBJ & o, FUNC func, ARGS&&... args)
{
   auto asyncobject = new AsyncClassFunc<OBJ, FUNC, ARGS...>(o, func, args...);
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
