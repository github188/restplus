#ifndef _RESTPLUS_BASE_RESPONSE_
#define _RESTPLUS_BASE_RESPONSE_

namespace restplus
{
    #include <string>
    #include "http_status_code.h"

    class BaseResponse
    {
    public:
        void set_status(HttpStatusCode status)
        {
            this->status = status;
        }

        void set_message(std::string message)
        {
            this->message = message;
        }

    private:
        HttpStatusCode status;
        string message;
    };
}

#endif
