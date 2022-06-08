


const Route = (function()
{

    var routes = {};
    var at =
    {
        Set(type, route, cl, handelFunc)
        {
			if(route.startsWith("/"))
			{
				route = route.substring(1, route.length);
			}
            var r = routes;
            if(r[type] == undefined) r[type] = {};
            r = r[type];
            route.split("/").map(i=>
                {
                    i = i.trim();
                    if(r[i] == undefined)r[i] = {};
                    r = r[i];
                });
            r["___func"] = {
					func: handelFunc,
					cl: cl
				};
				
        },
        Send(route, req, resp)
        {
			if(route.startsWith("/"))
			{
				route = route.substring(1, route.length);
			}
            var q = [];
            q.push(req);
            q.push(resp);
            var r = routes;
            r = r[req.method];
            route.split("/").map(i=>
                {
                    i = i.trim();
                    if(r[i] == undefined && r["*"] == undefined) 
                    {
                        throw new BadRequestException(`Bad Request as there is no Route for ${req.method} ${route}`);
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
                
                if(r["___func"].cl != undefined)
				{
					let data = [];
					req.on("data", (chunck)=>
					{
						data.push(chunck);
					});
					req.on("end", () =>
					{

						try
						{
							var dd = JSON.parse(data);
							
							var c = new r["___func"].cl();
							for(var i in c)
							{
								if(typeof c[i] != 'function' && typeof dd[i] != 'function') c[i] = dd[i];
							}
							
							if(c._required != undefined)
							{
								
								var require = c._required();
								for(var i = 0; i < require.length; i++)
								{
									if(c[require[i]] == undefined )
									{

										//console.log("require[i]: " + require[i]);
										var cc = new r["___func"].cl();
										for(var ii = 0; ii < require.length; ii++)
										{
											cc[require[ii]] = "required";
										}

										
										throw new NotAcceptableException(`Not Accepted. Request should be.\r\n ${JSON.stringify(cc)}`);
									}
								}
							}

							q.push(c);
							
							let response = r["___func"].func.apply(null, q);
							if(response != undefined)
							{
								JSONResponse(req, resp, 200, response);
							}
							else
							{
								JSONResponse(req, resp, 200, {success:true});
							}
						}
						catch(err)
						{
							ExceptionResponse(req, resp, err);
						}
					});
				}
				else
				{
					let response =  r["___func"].func.apply(null, q);
					if(response != undefined)
					{
						JSONResponse(req, resp, 200, response);
					}
					else
					{
						JSONResponse(req, resp, 200, {success:true});
					}
				}
                
            
        }
    };

    return at;
})();

globalThis.Route = Route;



//Route.Set("hi/*/at/*", undefined, (req, resp, a1, a2) =>
//{
//   console.log(`${a1} ${a2}`);
//});

//Route.Send("hi/123/at/bla", 1, 2);


