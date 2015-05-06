#include <iostream>
#include "include/service.h"

using namespace std;

namespace restplus
{
	Service::Service()
	{
		cout<<"constructor for service"<<endl;
	}

	void Service::Start()
	{
		cout<<"start"<<endl;
	}

	void Service::Stop()
	{
		cout<<"stop"<<endl;
	}

	void Service::RegisterResource(const Resource& resource)
	{
		cout<<"register resource"<<endl;
	}

	Service& Service::SetPort(int port)
	{
		cout<<"set port"<<endl;
		return *this;
	}

	Service& Service::SetMaximumConnections(int value)
	{
		return *this;
	}

	void Service::SetAuthenticationHandler(void (*callback)(const Request&, Response&))
	{
		cout<<"set authentication handler"<<endl;
	}

	void Service::SetErrorHandler(void (*callback)(const Request&, Response&))
	{
		cout<<"set error handler"<<endl;
	}
}
