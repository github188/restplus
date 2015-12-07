#ifndef _RESTPLUS_BASE_REQUEST_H
#define _RESTPLUS_BASE_REQUEST_H

namespace restplus
{
    #include "base_request.h"
    #include "base_response.h"

    class BaseResource
    {
    public:
        virtual void handle_get(const BaseRequest& request, BaseResponse& response)
        {
            not_implemented(request, response);
        }

        virtual void handle_post(const BaseRequest& request, BaseResponse& response)
        {
            not_implemented(request, response);
        }

        virtual void handle_post(const BaseRequest& request, BaseResponse& response)
        {
            not_implemented(request, response);
        }

        virtual void handle_delete(const BaseRequest& request, BaseResponse& response)
        {
            not_implemented(request, response);
        }

        virtual void handle_request(const BaseRequest& request, BaseResponse& response);
            
    protected:
        void not_implemented(const BaseRequest& request, BaseResponse& response);

    private:

    }
}

#endif
