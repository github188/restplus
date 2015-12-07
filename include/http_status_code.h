#ifndef _RESTPLUS_HTTP_STATUS_CODE_H_
#define _RESTPLUS_HTTP_STATUS_CODE_H_

namespace restplus
{
    enum class HttpStatusCode
    {
        OK = 200,
        Accepted = 202,
        MethodNotAllowed = 405,
    };
}

#endif
