#ifndef ISOCKET_HPP 
#define ISOCKET_HPP

#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <exception>

class ISocket {
public:
    ISocket() = default; //+
    ~ISocket() = default; //+
    virtual bool listen(const size_t& users) = 0; //+
    virtual int accept(const size_t& hostSockfd,  struct sockaddr& userAddr, socklen_t addrlen) = 0; //+
    virtual int connect(const int hostScoketfd, const struct sockaddr& connectAddr, socklen_t addrlen) = 0; //+

protected:
    virtual int create() = 0; //+
    virtual int close(const socklen_t& socketfd) = 0; //+
    virtual bool bind(const std::string& ip, const std::string& port) = 0; //+

};

#endif // ISOCKET_HPP
