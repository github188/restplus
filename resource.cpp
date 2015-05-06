#include <iostream>
#include "include/resource.h"

using namespace std;

namespace restplus
{
	void Resource::SetPath(const string& path)
	{
		cout<<"set path"<<endl;
	}

	void Resource::SetMethodHandler(const Method& verb, Response (*callback)(const Request&))
	{
		cout<<"set method handler"<<endl;
	}

	Resource::~Resource()
	{
		cout<<"destructor for resource"<<endl;
	}
}
