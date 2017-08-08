#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H
#include <string>
#include <map>
#include <winsock2.h>
#include "Response.hpp"
#include "../Request.hpp"

class Socket;
class SocketServer;
class Router;

class HttpRequest: public Request
{
    friend class Router;
private:
    std::map<std::string, std::string> path;
    std::map<std::string, std::string> query;
    std::map<std::string, std::string> body;
    Socket* socket;
    Response* response;
public:
    const std::string route;
    const std::string method;
    HttpRequest(const std::string r, const std::string m);
    ~HttpRequest();
    void setResponse(Response* response);
};

#endif // HTTP_REQUEST_H
