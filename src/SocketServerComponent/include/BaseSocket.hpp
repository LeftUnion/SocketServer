#ifndef BASESOCKET_HPP
#define BASESOCKET_HPP

#include "ISocket.hpp"

enum class SocketStatus : uint8_t 
{
    connected = 0,
    err_socket_init = 1,
    err_socket_bind = 2,
    err_socket_listen = 3,
    err_socket_connect = 4,
    disconnected = 5
};

class BaseSocket : public ISocket 
{

public:
    BaseSocket(const std::string& ip, const std::string& port); //+
    ~BaseSocket(); //+

    bool listen(const size_t& users) override final;
    int accept(const size_t& hostSockfd, const struct sockaddr& userAddr, socklen_t addrlen) override final;
    
    SocketStatus getStatus();
    socklen_t getSocketfd();

protected:
    socklen_t socketfd;
    struct sockaddr_in addr;
    SocketStatus status = SocketStatus::disconnected;
    int create() override;

private:
    bool bind(const std::string& ip, const std::string& port) override final;
    int close(const socklen_t& socketfd) override final;

};

BaseSocket::BaseSocket(const std::string& ip, const std::string& port) //+
{
    this->socketfd = ISocket::create();
    ISocket::bind(ip, port);
}

BaseSocket::~BaseSocket() //+
{
    close(this->socketfd);
}


bool BaseSocket::bind(const std::string &ip, const std::string &port)
{
    int rBind = ::bind(socketfd, reinterpret_cast<sockaddr*>(&addr), sizeof (addr));
    if(rBind < 0)
    {
        perror("Bind: ");
        status = SocketStatus::err_socket_bind;
        return false;
    }
    return true;
}

bool BaseSocket::listen(const size_t& users) //+
{
    int rListen = ::listen(this->socketfd, users);
    if(rListen < 0)
    {
        perror("Listen: ");
        this->status = SocketStatus::err_socket_listen;
    }
    return rListen;
}

int BaseSocket::close(const socklen_t& socketfd) //+
{
    int isOk = close(socketfd);
    if(isOk == -1)
    {
        //Todo Error
    }
    this->status = SocketStatus::disconnected;s
    return isOk;
}



#endif // BASESOCKET_HPP
