#ifndef _RESTPLUS_SERVICE_H
#define _RESTPLUS_SERVICE_H

#include "resource.h"
#include "request.h"
#include "response.h"

namespace restplus
{
	class Service
	{
		public:
			Service();

			void Start();
			void Stop();
			void RegisterResource(const Resource& resource);

			Service& SetPort(int);
			Service& SetMaximumConnections(int);
			Service& SetConnectionTimeout(int);

			void SetAuthenticationHandler(void (*callback)(const Request&, Response&));
			void SetErrorHandler(void (*callback)(const Request&, Response&));

		private:
			int port;
			int maximumConnections;
			int connectionTimeout;
	};
}

#endif
