#ifndef _RESTPLUS_BASE_RESOURCE_H_
#define _RESTPLUS_BASE_RESOURCE_H_

namespace restplus
{
    #include <string>
    #include "base_resource.h"

    class BaseRouter
    {
    public:
        virtual void attach(std::string path, const BaseResource& resource);
    };
}

#endif
