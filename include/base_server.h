#ifndef _RESTPLUS_BASE_ROUTER_H_
#define _RESTPLUS_BASE_ROUTER_H_

namespace restplus
{
    #include "base_router.h"

    class BaseServer
    {
    public:
        BaseServer& set_port(int port)
        {
            this->port = port;
            return *this;
        }

        BaseServer& max_thread(int max_thread)
        {
            this->max_thread = max_thread;
            return *this;
        }
        
        BaseServer& set_router(const BaseRouter& router)
        {
            this->router = router;
            return *this;
        }

        virtual void start();

    private:
        int port;
        int max_thread;
        BaseRouter router;
    };
}

#endif
