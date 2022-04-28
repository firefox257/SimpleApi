#include <iostream>
#include <functional>
#include <unordered_map>
#include <map>
#include <variant>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

class Exception
{
    public:
    Exception()
    {

    }
    Exception(string message)
    {
        Message = message;
    }
    string Message;
    list<Exception> InnerException;
};
class ConvertException: public Exception
{
    public:
    ConvertException(string message): Exception(message)
    {

    }
};

class RouteException: public Exception
{
    public:
    RouteException(string message): Exception(message)
    {

    }
};



template<class N>
class DIObj
{
	public:
	N * n = 0;
	int * count = 0;
	DIObj()
	{
		//n = new N;
		count = new int;
		(*count) = 1;
	}
	DIObj(const DIObj<N> & p)
	{
		n = p.n;
		count = p.count;
		(*count)++;
	}
    DIObj(N * nptr)
    {
        n = nptr;
        count = new int;
        (*count) = 1;
    }
	~DIObj()
	{
		(*count)--;
		if((*count) <=0)
		{
			delete(n);
			delete(count);
		}
	}
	DIObj<N> & operator=(const DIObj<N> & p)
	{
		(*count)--;
		if((*count)<=0)
		{
			delete(n);
			delete(count);
		}
		n = p.n;
		count = p.count;
		(*count)++;
		return (*this);
	}
    DIObj<N> & operator=(N * nptr)
    {
        (*count)--;
		if((*count)<=0)
		{
			delete(n);
			delete(count);
            count = new int;
            (*count) = 0;
		}
		n = nptr;
		(*count)++;
		return (*this);
    }
	N* operator->()
	{
		return n;
	}
	
	N& operator *()
	{
		return (*n);
	}
	
	
	void Release()
	{
		(*count)--;
		if((*count) <=0)
		{
			delete(n);
			delete(count);
		}
		n = new N;
		count = new int;
		(*count) = 1;
	}
};

template<class N>
class DI
{
    template<class O>
    static DIObj<N> GetSinglton()
    {
        static const DIObj<N> obj = new O();
        return obj;
    }
    template<class O>
    static DIObj<N> GetInstance()
    {
        DIObj<N> obj = new O();
        return obj;
    }
    static DIObj<N> GetNone()
    {
        //change out later
        throw "Not Implemented";
    }
    public:

    static DIObj<N> (*Get)();

    template<class O>
    static void SetSinglton()
    {
        Get = GetSinglton<O>;
    }
    template<class O>
    static void SetInstance()
    {
        Get = GetInstance<O>;
    }

};
template<class N>
DIObj<N> (*DI<N>::Get)() = DI<N>::GetNone;

/////////////////////////////////////////////////////////////
vector<string> split (string s, string delimiter) 
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) 
    {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
std::string_view trim(std::string_view s)
{
    s.remove_prefix(std::min(s.find_first_not_of(" \t\r\v\n"), s.size()));
    s.remove_suffix(std::min(s.size() - s.find_last_not_of(" \t\r\v\n") - 1, s.size()));

    return s;
}


class QueryValues
{
    unordered_map<string, string> values;
    public:
    inline string & operator[](string key)
    {
        return values[key];
    }

    template<class A>
    A Get(string id)
    {
        stringstream convert(values[id]);
        A value;
        convert >> value;
        
        if(convert.fail())
        {
            string str1 = "could not convert " + id;
            throw ConvertException(str1);
        }

        return value;
    }

};

class QueryPath
{
    unordered_map<string, string>values;
    vector<string> paths;

    public:
    QueryPath(string path)
    {
        paths = split(path, "/");
    }


    void GetValues(string path, QueryValues & v)
    {
        vector<string> p1 = split(path, "/");
        int s = paths.size();
        for(int i = 0; i < s; i++)
        {
            if (paths[i].rfind("{", 0) == 0)
            {
                v[paths[i]] = p1[i];
            }
        }
    }

    inline vector<string> & Paths()
    {
        return paths;
    }

    inline int Size()
    {
        return paths.size();
    }
  

};



class RouteNode
{
    public:
    unordered_map<string, RouteNode *> nodes;
    RouteNode * any;
    QueryPath * qpath;
};
   

template<class A, class B>
class Route
{
   
    static RouteNode head;
    static list<RouteNode> nodelist;
    static list<QueryPath> qpathlist;

    public:

    static void Set(string path)//, function<void (A&, B&)> func)
    {
        
       vector<string> p = split(path, "/");
       int s = p.size();
       RouteNode * atnode = &head;
       for(int i = 0; i < s; i++)
       {
            string & strp = p[i];
            if (strp.rfind("{", 0) != 0)
            {
                if(atnode->nodes[strp] == 0)
                {
                    nodelist.push_back(RouteNode());
                    atnode->nodes[strp] = &nodelist.back();
                    atnode = &nodelist.back();
                }
                else
                {
                    atnode = atnode->nodes[strp];
                }
            }
            else
            {
                if(atnode->any == 0)
                {
                    nodelist.push_back(RouteNode());
                    atnode->any = &nodelist.back();
                    atnode = &nodelist.back();
                }
                else
                {
                    atnode = atnode->any;
                }
            }
       }
       qpathlist.push_back(QueryPath(path));
       atnode->qpath = &qpathlist.back();
       

    }//End setup
    static void Send(string path, QueryValues & v)
    {
        vector<string> p = split(path, "/");
       int s = p.size();
       RouteNode * atnode = &head;
       vector<string> anylist;
       for(int i = 0; i < s; i++)
       {
            string & strp = p[i];
           
            if(atnode->nodes[strp] == 0)
            {
                if(atnode->any == 0)
                {
                    string err = "Could not find round " + path;
                    throw RouteException(err);
                } 
                anylist.push_back(strp);
                atnode = atnode->any;
            }
            else
            {
                atnode = atnode->nodes[strp];
            }
       }

       if(atnode->qpath == 0)
       {
            string err = "Could not find round " + path;
            throw RouteException(err);
       }

       atnode->qpath->GetValues(path, v);  
    }

};
template<class A, class B>
list<RouteNode> Route<A, B>::nodelist;

template<class A, class B>
RouteNode Route<A, B>::head;

template<class A, class B>
list<QueryPath> Route<A, B>::qpathlist;





/*
class itry1
{
    public:

    virtual void func() =0;
};
class try1: public itry1
{
    public:
    try1()
    {
        cout << "try1 \r\n";
    }
    void func() override
    {
        cout << "Hi there \r\n";
    }
};

class try2
{
    DIObj<itry1> t1 = DI<itry1>::Get();
    public:

    void func()
    {
        cout << "try2 func\r\n";
        t1->func();
    }


};

*/



void error()
{
    throw ConvertException("error here");
}
int main()
{
    /*
    DI<itry1>::SetSinglton<try1>();
    DI<try2>::SetInstance<try2>();
  

    auto v1 = DI<itry1>::Get();
    auto v2 = DI<try2>::Get();

    v1->func();
    cout << typeid(v1).name() << "\r\n";
    v2->func();


   */

    try
    {
        QueryValues qv;
        Route<int, int>::Set("/user/{id}");
        Route<int, int>::Set("/user/{path}/update");

        Route<int, int>::Send("/user/333/update", qv);
        cout << qv.Get<int>("{path}") << "\r\n";

    }
    catch(Exception & ex)
    {
        cerr << ex.Message << "\r\n";
    }
    
   
    try
    {
        error();
    }
    catch(ConvertException & ex)
    {
        cerr << "try " << ex.Message << "\r\n";
    }
    catch(Exception & ex)
    {
        cerr << ex.Message << "\r\n";
    }
    
    
    return 0;
}
