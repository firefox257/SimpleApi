

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
	queue<int> inactivethreadworkerid;
	
	
	
	mutex mtx;
	mutex inactivemtx;
	
	//bool keeprunning = true;
	
	public:
	asyncworkers()
	{
		for(int i = 0; i < NUMBEROFASYNCCORES; i++)
		{
			inactivethreadworkerid.push(i);
		}
		
		//cout << "start workers" el;
		/*for(int i = 0; i < NUMBEROFASYNCCORES; i++)
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
					
					this_thread::yield();
					
					
				}//end while
				
				
			});
			
		}*/
		//cout << "end workers " el;
	}
	~asyncworkers()
	{
		//sleepSeconds(5);
	}
	void add(void * asyncobject)
	{
		unique_lock addlck(mtx, defer_lock);
		addlck.lock();
		masterqueue.push((asyncobj*)asyncobject);
		addlck.unlock();
		
		unique_lock inaclck(mtx, defer_lock);
		inaclck.lock();
		bool inacempty = inactivethreadworkerid.empty();
		inaclck.unlock();
		
		if(!inacempty)
		{
			inaclck.lock();
			int atid =inactivethreadworkerid.front();
			inactivethreadworkerid.pop();
			inaclck.unlock();
			
			threadworker[atid] = thread([&](int id)
			{
				unique_lock lck(mtx, defer_lock);
				bool empty = false;
				while(!empty)
				{
					lck.lock();
					empty = masterqueue.empty();
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
					
					//this_thread::yield();
					
					
				}//end while
				
				
				unique_lock invactivelck(mtx, defer_lock);
				invactivelck.lock();
				inactivethreadworkerid.push(id);
				invactivelck.unlock();
				
			}, atid);
			
		}
		
		
	}
	
};



asyncworkers __ASYNCWORKERS;

void asyncrun(void * asyncobject)
{
	//static asyncworkers workers;
	 __ASYNCWORKERS.add(asyncobject);
	
}

void asyncrun(void * asyncobject, donestate & done)
{
	//static asyncworkers workers;
	asyncobj * asyncptr = (asyncobj*)asyncobject;
	(*asyncptr).setWaiter(done);
	 __ASYNCWORKERS.add(asyncobject);
	
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

