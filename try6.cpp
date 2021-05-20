#include <iostream>
#include <tuple> 
//s01 e04
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





int main()
{
	
	double f1 = 0.0000000000123456789;
	
	cout << f1 << "\r\n";
	
	f("hi ther", true, 1, 123.123);
	
	return 0;
}