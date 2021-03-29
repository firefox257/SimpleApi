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



class asyncobj
{
	
	public:
	
	virtual void operator()()
	{
	}
};


class asyncworkers
{
	queue<asyncobj*> masterqueue;
	
	thread threadworker[32];
	
	mutex mtx;
	bool keeprunning = true;
	
	public:
	asyncworkers()
	{
		//cout << "start workers" el;
		for(int i = 0; i < 32; i++)
		{
			threadworker[i] = thread([&]()
			{
				unique_lock lck(mtx, defer_lock);
				
				while(keeprunning)
				{
					lck.lock();
					if(!masterqueue.empty())
					{
						asyncobj * n = masterqueue.front();
						masterqueue.pop();
						(*n)();
						delete(n);
						n = 0;
						
						
					}
					lck.unlock();
					this_thread::yield();
					
					
				}//when while
				
				
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


class voidasync: public asyncobj
{
	function<void()> _func;
	public:
	voidasync(function<void()> func)
	{
		_func = func;
	}
	void operator()()
	{
		_func();
	}
};

class try1async: public asyncobj
{
	int _id;
	function<void(int)> _func;
	public:
		try1async(function<void(int)> func, int id)
	{
	_func = func;
		_id = id;
	}
	void operator()()
	{
		_func(_id);
	}
};
int main()
{
	int count = 0;
	mutex mtx;
	for(int i = 0; i < 1000; i++)
	{
	
		asyncrun(new try1async([&](int id)
		{
			//cout << "hi there " el;
			unique_lock lck(mtx, defer_lock);
			lck.lock();
			count++;
			//int per = (int)(((float)count / 2000000.0f) * 100.0f);
			//cout << per el;
			lck.unlock();
			
		}, i));
	}
	cout << "end adding" el;
	
	sleepSeconds(3);
	asyncrun(new voidasync([]()
	{
		
		cout << "hi there 1" el;
		
	}));
	sleepSeconds(5);
	asyncrun(new voidasync([]()
	{
		
		cout << "hi there 2" el;
		
	}));
	
	
	sleepSeconds(3);
	cout << "count " << count el;
	
	
    return 0;
}
