

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
	
	donestate * doneptr = 0;
	public:
	
	
	
	
	virtual void operator()()
	{
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

#define NUMBEROFASYNCCORES 256
class asyncworkers
{
	queue<asyncobj*> masterqueue;
	
	thread threadworker[NUMBEROFASYNCCORES];
	
	mutex mtx;
	bool keeprunning = true;
	
	public:
	asyncworkers()
	{
		//cout << "start workers" el;
		for(int i = 0; i < NUMBEROFASYNCCORES; i++)
		{
			threadworker[i] = thread([&]()
			{
				unique_lock lck(mtx, defer_lock);
				
				while(keeprunning)
				{
					lck.lock();
					bool empty = masterqueue.empty();
					lck.unlock();
					if(!empty)
					{
						lck.lock();
						asyncobj * n = masterqueue.front();
						masterqueue.pop();
						lck.unlock();
						
						(*n)();
						
						(*n).done();
						delete(n);
						n = 0;
						
						
					}
					//lck.unlock();
					this_thread::yield();
					
					
				}//end while
				
				
			});
			
		}
		//cout << "end workers " el;
	}
	~asyncworkers()
	{
		keeprunning = false;
		sleepSeconds(5);
	}
	void add(void * asyncobject)
	{
		unique_lock addlck(mtx, defer_lock);
		addlck.lock();
		masterqueue.push((asyncobj*)asyncobject);
		addlck.unlock();
		
	}
	
};

void asyncrun(void * asyncobject)
{
	static asyncworkers workers;
	workers.add(asyncobject);
	
}

void asyncrun(void * asyncobject, donestate & done)
{
	static asyncworkers workers;
	asyncobj * asyncptr = (asyncobj*)asyncobject;
	(*asyncptr).setWaiter(done);
	workers.add(asyncobject);
	
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

