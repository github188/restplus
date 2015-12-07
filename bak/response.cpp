#include <iostream>
#include "include/response.h"

using namespace std;

namespace restplus
{
	string Response::GetHeader(const string& name) const
	{
		cout<<"get header"<<endl;
		return "";
	}

	string Response::GetStatusMessage() const
	{
		cout<<"get status message"<<endl;
		return "";
	}

	int Response::GetStatusCode() const
	{
		cout<<"get status code"<<endl;
		return 0;
	}

	void Response::SetHeader(const string& name, const string& value)
	{
		cout<<"set header"<<endl;
	}

	void Response::SetStatusCode(const int value)
	{
		cout<<"set status code"<<endl;
	}

	void Response::SetStatusMessage(const string& value)
	{
		cout<<"set status message"<<endl;
	}
}
