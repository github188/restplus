#include "restplus.h"

class Student: public BaseResource
{
public:
    void handle_get(const BaseRequest& request, BaseResponse& response)
    {
        response.set_status(HttpStatusCode::OK);
        response.set_message("hello world");
    }
};

int main()
{
    BaseServer server;
    server.set_port(8000).max_thread(1);
    server.start();
}
