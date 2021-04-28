#include <iostream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <functional>
#include <utility>
#include <tuple>
#include <typeinfo>
#include <algorithm>
#include <stdio.h>

#include <fstream>
#include "Types.cpp"
#include "String.cpp"
#include "DataIO.cpp"
#include "Array.cpp"
#include "List.cpp"

#include "Async.cpp"
#include "SmtPtr.hpp"
#include "Mapper.cpp"
using namespace std;
#define el << "\r\n"




struct try1
{
	List<String> names;
	
};

void func(SmtPtr<try1> & t1)
{
	cout << "here4" el;
	SmtPtr<try1> t2;
	cout << "here5" el;
	t2->names.PushBack((String)"hi there");
	t2->names.PushBack((String)"hi there123");
	cout << "here6 " el;
	t1 = t2;
	cout << "here7" el;
	
}
int main()
{
	cout << "here1" el;
	SmtPtr<try1> t1;
	cout << "here2" el;
	func(t1);
	cout << "here3" el;
	return 0;
}