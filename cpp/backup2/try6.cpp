#include <iostream>
#include <tuple> 
//s02 e08
using namespace std;

template<typename... ARGS>
void f(const ARGS&... args)
{
    // this is first way to get the number of arguments
    constexpr auto size = sizeof...(ARGS);
    std::cout<<size <<std::endl;
	
	auto tup = make_tuple(args...);
	//get<2>(bar) = 100; 
	
	
}


class try1
{
	public:
	int i;
	try1()
	{
		cout << "init\r\n";
	}
};


int main()
{
	
	try1 * tt1 = new try1;
	cout << tt1 << "\r\n";
	
	try1 * tt2 = new (tt1) try1();
	cout << tt2 << "\r\n";
	
	/*
	double f1 = 0.0000000000123456789;
	
	cout << f1 << "\r\n";
	
	f("hi ther", true, 1, 123.123);
	*/
	
	return 0;
}