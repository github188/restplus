#include "include/restplus.h"

void BaseResource::handle_request(const BaseRequest& request, BaseResponse& response)
{
    if(request.get_method() == Method::GET)
    {
        this->handle_get(request, response);
    }
    else if(request.get_method() == Method::POST)
    {
        this->handle_post(request, response);
    }
    else if(request.get_method() == Method::PUT)
    {
        this->handle_put(request, response);
    }
    else if(request.get_method() == Method::DELETE)
    {
        this->handle_delete(request, response);
    }
    else
    {
        this->not_implemented(request, response);
    }
}

void BaseResource::not_implemented(const BaseRequest& request, BaseResponse& response)
{
    response.set_status(HttpStatusCode::MethodNotAllowed);
    response.set_message("unimplemented method");
}

