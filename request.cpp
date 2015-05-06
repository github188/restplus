#include <iostream>
#include "include/request.h"
using namespace std;

namespace restplus
{
	string Request::GetPath() const
	{
		cout<<"get path"<<endl;
	}

	string Request::GetOrigin() const
	{
		cout<<"get origin"<<endl;
	}

	string Request::GetDestination() const
	{
		cout<<"get destination"<<endl;
	}

	string Request::GetHeader(const string& name) const
	{
		cout<<"get header"<<endl;
	}
}
