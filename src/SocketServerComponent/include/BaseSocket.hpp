#ifndef BASESOCKET_HPP
#define BASESOCKET_HPP

#include "ISocket.hpp"

#include <iostream>

enum class SocketStatus : uint8_t 
{
    connected = 0,
    err_socket_init = 1,
    err_socket_bind = 2,
    err_socket_listen = 3,
    err_socket_accept = 4,
    err_socket_connect = 5,
    disconnected = 6
};

class BaseSocket : public ISocket 
{

//Fileds
protected:
    socklen_t mSocketfd; 
    struct sockaddr_in addr;
    SocketStatus status = SocketStatus::disconnected;

//Methods-members
public:
    //Constructors
    BaseSocket(const std::string& ip, const std::string& port); //+
    ~BaseSocket(); //+

    BaseSocket(const BaseSocket&) = delete; //+
    BaseSocket& operator=(const BaseSocket&) = delete;//+
    BaseSocket(const BaseSocket&&) = delete;//+
    BaseSocket& operator=(const BaseSocket&&) = delete;//+

    //Methods-Func
    bool listen(const size_t& users) override final; //+
    int accept(const size_t &hostSockfd, sockaddr &userAddr, socklen_t addrlen) override final;
    int connect(const int sokcetfd, const struct sockaddr& connectAddr, socklen_t addrlen) override final;

    //Getters|Setters
    SocketStatus getStatus();
    socklen_t getSocketfd();

private:
    bool bind(const std::string& ip, const std::string& port) override final;
    int close(const socklen_t& socketfd) override final;



};



#endif // BASESOCKET_HPP
