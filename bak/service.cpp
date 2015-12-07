#include <iostream>
#include "restplus.h"

using namespace std;

namespace restplus
{
	Service::Service()
	{

	}

	void Service::Start()
	{
		int fd = Platform::ServerSocket();
		if(fd < 0) return;
	
		Platform::DoAccept(fd);	
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
