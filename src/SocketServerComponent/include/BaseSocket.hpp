#ifndef BASESOCKET_HPP
#define BASESOCKET_HPP

#include "ISocket.hpp"

enum class SocketStatus : uint8_t
{
    connected = 0,
    err_socket_init = 1,
    err_socket_bind = 2,
    err_socket_connect = 3,
    disconnected = 4
};

class BaseSocket : public ISocket
{
    SocketStatus status = SocketStatus::disconnected;

public:
    BaseSocket(const std::string& ip, const std::string& port);
    ~BaseSocket() = default;
    bool listen(const size_t& users) override final;
    int accept(const int& hostSocketfd, sockaddr, socklen_t addrlen) override final;

private:
    virtual int create(const std::string& ip, const std::string& port);
    bool bind(const int& hostSocketfd) override final;

    SocketStatus getStatus();
};


#endif // BASESOCKET_HPP