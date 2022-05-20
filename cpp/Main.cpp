#include <iostream>
#include "Utils.hpp"
#include "Factory.hpp"
#include "Route.hpp"
#include "String.hpp"
#include "Async.hpp"


#include <functional>
#include <tuple>

using namespace std;

class try1
{
    public:
    try1()
    {
        cout << "try1 init\r\n";
    }
    ~try1()
    {
        cout << "try1 destruct\r\n";
    }
    void func()
    {
        cout  << "Hi there\r\n";
    }
    void func1(int * ret, int i)
    {
        SleepMilliSeconds(3000);
        cout << "func1 " << i << "\r\n";
        *ret= i+1;
    }
};

class PingRequest
{

};
class PingResponse
{

};

class PingRoute: public Route<PingRequest, PingResponse>
{
    public:
    PingRoute()
    {
        cout << "PingRoute init\r\n";
    }
    void Handel(PingRequest & req, PingResponse & resp)
    {
        cout << "ping route\r\n";
    }
};

class itry2
{
    public:
   
    virtual ~itry2(){}
    virtual void func() = 0;
};
class try2: public itry2
{
    public:
    try2()
    {
        cout << "try2 init\r\n";
    }
    ~try2()
    {
        cout << "try2 destruct\r\n";
    }
    void func()
    {
        cout << "Hi asdfasdfasdf\r\n";
    }
};

template<class A, class B, class ... ARGS>
void func1(A & a, B  b, ARGS ... args)
{
   (a.*b)(args...);
}

template<class OBJ, class FUNC, class ... ARGS>
class callout
{
   OBJ * optr = 0;
    FUNC Func;
    tuple<ARGS...> tup;
    public:
    
    callout(OBJ & o, FUNC func, ARGS ... args)
    {
        optr = &o;
        Func = func; 
        tup =  tuple<ARGS...>(args...);
    }
    
    void call()
    {
       // ((*optr).*Func)(123);
      //return apply(mem_fun(Func), tup);
      apply(Func, tuple_cat(make_tuple(optr), tup) );
  
    }
};

void func3(int * ret)
{
    SleepMilliSeconds(1000);
    *ret = 111;
}
int main()
{
   /* int ret = 0;
    try1 t1;
    callout c1 = callout(t1, t1.func1, &ret, 127);
    cout << "ret " << ret << "\r\n";
    c1.call();
    cout << "ret " << ret << "\r\n";*/
    //cout <<  "i1 " << i1 << "\r\n";

   //try1 t1;
    //func1(t1, try1::func1, 123);




   /*Ref<itry2> t2 = new try2();
   t2->func();*/

    /*
    Factory<try1>::Scope();

    FObj<try1> t = Factory<try1>::Get();
    t->func();

    FObj<try1> t2 = Factory<try1>::Get();
    FactoryScopeReset();
    FObj<try1> t3 = Factory<try1>::Get();
*/
    

/*
    PingRequest req;
    PingResponse resp;

    Routes::Static<PingRoute>();
    Routes::Send(req, resp);
    Routes::Send(req, resp);
    */


    DoneStateQueue q1;

    AsyncRun(q1, []()
    {
        SleepMilliSeconds(5000);
        cout << "at 1\r\n";
    });
    AsyncRun(q1, []()
    {
        SleepMilliSeconds(1000);
        cout << "at 2\r\n";
    });
    try1 t1;
    int ret = 0;
    AsyncRunClass(q1, t1, t1.func1, &ret, 123 );

    cout << "ret " << ret << "\r\n";
    WaitFor(q1);
    cout << "ret " << ret << "\r\n";

    AsyncRunFunc(q1, func3, &ret);
        cout << "ret " << ret << "\r\n";
    WaitFor(q1);
    cout << "ret " << ret << "\r\n";


    return 0;
}