#ifndef ISOCKET_HPP 
#define ISOCKET_HPP

#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/un.h>

class ISocket {
    
public:
    virtual bool listen(const size_t& users) = 0;
    virtual int accept(const int& hostSockfd, sockaddr, socklen_t addrlen) = 0;

private:
    virtual int create(const std::string& ip, const std::string& port) = 0;
    virtual bool bind(const int& hostSocketfd) = 0;

};

#endif // ISOCKET_HPP
