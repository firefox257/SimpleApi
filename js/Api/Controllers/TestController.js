

Route.Set("GET", "/api/test/*", undefined, (req, res, id) =>
{
	
	return {
		id: id
	};
	
});

Route.Set("GET", "/api/testobj/", undefined, (req, res)=>
{
	console.log("Here1");
});

Route.Set("GET", "/api/testauth/", undefined, (req, res)=>
{
	throw new UnauthorizedException();
});

Route.Set("POST", "/api/testpost/", TestRequest, (req, res, request)=>
{
	
	var t = new TestResponse();
	t.Id = request.Id;
	t.Msg = "hi there";
	return t;
});


