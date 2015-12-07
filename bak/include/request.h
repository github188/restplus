#ifndef _RESTPLUS_REQUEST_H
#define _RESTPLUS_REQUEST_H

#include <string>

using namespace std;

namespace restplus
{
	class Request
	{
		public:
			string GetPath() const;
			string GetOrigin() const;
			string GetDestination() const;
			string GetProtocol() const;
			string GetHeader(const string& name) const;
	};
}

#endif
