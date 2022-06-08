function JSONResponse(req, res, code, obj)
{
	var head = {
		"Content-Type": mimetype(".json")
	};
	res.writeHead(code, head);
	res.write(JSON.stringify(obj));
	res.end();
}
globalThis.JSONResponse = JSONResponse;

function ExceptionResponse(req, res, err)
{
	var head = {
		"Content-Type": mimetype(".txt")
	};
	
	if(err instanceof NotImplementedException)
	{
		res.writeHead(501, head);
	}
	else if(err instanceof UnauthorizedException)
	{
		res.writeHead(401, head);
	}
	else if(err instanceof BadRequestException)
	{
		res.writeHead(400, head);
	}
	else if(err instanceof ForbiddenException)
	{
		res.writeHead(403, head);
	}
	else if(err instanceof NotFoundException)
	{
		res.writeHead(404, head);
	}
	else if(err instanceof NotAcceptableException)
	{
		res.writeHead(406, head);
	}
	else
	{
		console.log(err);
		res.writeHead(500, head);
	}
	
	res.write(err.message);
	res.end();
}
globalThis.ExceptionResponse = ExceptionResponse;


