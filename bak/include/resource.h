#ifndef _RESTPLUS_RESOURCE_H_
#define _RESTPLUS_RESOURCE_H_

#include "method.h"
#include "request.h"
#include "response.h"

using namespace std;

namespace restplus
{
	class Resource
	{
		public:
			void SetPath(const string& path);
			void SetMethodHandler(const Method& verb, Response (*callback)(const Request&));

			virtual ~Resource();
	};
}

#endif
