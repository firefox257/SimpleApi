
class UnauthorizedException extends Error 
{
	constructor()
	{
		super("Unauthorized");
	}
	
};
globalThis.UnauthorizedException = UnauthorizedException;

class NotImplementedException extends Error 
{
	constructor()
	{
		super("Not Implemented");
	}
};
globalThis.NotImplementedException = NotImplementedException;

class BadRequestException extends Error
{
	constructor(msg)
	{
		if(msg == undefined) super("Bad Reqeust");
		else super(msg);
	}
};
globalThis.BadRequestException = BadRequestException;

class ForbiddenException extends Error
{
	constructor(msg)
	{
		if(msg == undefined) super("Forbidden");
		else super(msg);
	}
};
globalThis.ForbiddenException = ForbiddenException;

class NotFoundException extends Error
{
	constructor(msg)
	{
		if(msg == undefined) super("Not found");
		else super(msg);
	}
};
globalThis.NotFoundException = NotFoundException;

class NotAcceptableException extends Error
{
	constructor(msg)
	{
		if(msg == undefined) super("Not Acceptable");
		else super(msg);
	}
};
globalThis.NotAcceptableException = NotAcceptableException;
