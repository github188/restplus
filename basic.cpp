#include "restplus.h"

using namespace restplus;

void authenticationHandler(const Request& request, Response& response)
{
	response.SetStatusCode(401);
}

Response getMethodHandler(const Request& request)
{
	Response response;
	response.SetBody("Hello World!");
	response.SetStatusCode(200);

	return response;
}

int main()
{
	Resource resource;
	resource.SetPath("/resource");
	resource.SetMethodHandler(GET, getMethodHandler);

	Service service;
	service.SetPort(8000);
	service.SetAuthenticationHandler(authenticationHandler);
	service.Start();
}
