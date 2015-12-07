#ifndef _RESTPLUS_RESPONSE_H
#define _RESTPLUS_RESPONSE_H

#include <string>
#include <map>

using namespace std;

namespace restplus
{
	class Response
	{
		public:
			string GetHeader(const string& name) const;
			string GetStatusMessage() const;
			int GetStatusCode() const;

			void SetHeader(const string& name, const string& value);
			void SetBody(const string& body);
			void SetStatusCode(const int value);
			void SetStatusMessage(const string& value);

		private:
			int mStatusCode;
			string mStatusMessage;
			string mBody;
			multimap<string, string> mHeaders;
	};
}

#endif
