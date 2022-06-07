requestAnimationFrame("Route.js");

class RouteError extends Error{};

const Route = (function()
{

    var routes = {};
    var at =
    {
        Set(route, handelFunc)
        {
            var r = routes;
            route.split("/").map(i=>
                {
                    i = i.trim();
                    if(r[i] == undefined)r[i] = {};
                    r = r[i];
                });
            r["___func"] = handelFunc;
        },
        Send(route, req, resp)
        {
            Route.Reset();
            var q = [];
            q.push(req);
            q.push(resp);
            var r = routes;
            route.split("/").map(i=>
                {
                    i = i.trim();
                    if(r[i] == undefined && r["*"] == undefined) 
                    {
                        throw new RouteError(`No Route for ${route}`);
                    }
                    else if(r[i] == undefined)
                    {
                        r = r["*"];
                        q.push(i);
                    }
                    else
                    {
                        r = r[i];
                    }
                });
                
            r["___func"].apply(null, q);
        }
    };

    return at;
})();

globalThis.RouteError = RouteError;
globalThis.Route = Route;


/*

Route.Set("hi/*/at/*", (req, resp, a1, a2) =>
{
   console.log(`${a1} ${a2}`);
});

Route.Send("hi/123/at/bla", 1, 2);*/
