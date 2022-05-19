#ifndef ROUTE_HPP
#define ROUTE_HPP
#include <stdint.h>
#include <unordered_map>
#include "Utils.hpp"
#include "Factory.hpp"

template<class REQUEST, class RESPONSE>
class Route
{

   
    public:
    
    virtual void Handel(REQUEST & req, RESPONSE & resp) = 0;

 
    inline void Send(void * req, void * resp)
    {
        Handel(*((REQUEST*)req), *((RESPONSE*)resp));
    }

    MakeID(Route<REQUEST, RESPONSE>);

};




class Routes
{
    protected: 
    static unordered_map<uint64_t, void(*)(void * , void *)> maps;

    template<class A>
    static void SetStatic(void * request, void * response)
    {
        static A a;
       a.Send(request, response);

    }
    template<class A>
    static void SetInstance(void * request, void * response)
    {
        A a;
        a.Send(request, response);

    }
    
    public:

    template<class A>
    static void Static()
    {
        maps[A::Id()] = SetStatic<A>;
    }
   
    template<class A>
    static void Instance()
    {
        maps[A::Id()] = SetInstance<A>;
    }

    template<class REQUEST, class RESPONSE>
    static void Send(REQUEST & request, RESPONSE & response)
    {
        FactoryScopeReset();
        maps[Route<REQUEST, RESPONSE>::Id()](&request, &response);
    }



};
unordered_map<uint64_t, void(*)(void *, void *)> Routes::maps;

#endif
