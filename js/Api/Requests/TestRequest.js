class TestRequest
{
	Id;
	Hi;
	_required()
	{
		const req = ["Id", "Hi"];
		return req;
	}
};
globalThis.TestRequest = TestRequest;
