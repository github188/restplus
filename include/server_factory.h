#ifndef _RESTPLUS_SERVER_FACTORY_H_
#define _RESTPLUS_SERVER_FACTORY_H_

namespace restplus
{
    #include "base_server.h"

    class ServerFactory
    {
    public:
        static BaseServer create_server(int port);
    };
}

#endif
