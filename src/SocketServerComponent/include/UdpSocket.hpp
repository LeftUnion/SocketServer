#ifndef UDPSOCKET_HPP
#define UDPSOCKET_HPP

#include "BaseSocket.hpp"

class UdpSocket : public BaseSocket
{

public:
    UdpSocket(std::string ip, std::string port) : BaseSocket(ip, port) {}; //+
    ~UdpSocket() = default; //+

private:
    int create() override final; //+

};

int UdpSocket::create() //+
{
    int socketInit = socket(AF_INET, SOCK_DGRAM, 0);
    if(socketInit < 0)
    {
        perror("Init: ");
        this->status = SocketStatus::err_socket_init;
    }
    else
        return this->socketfd = socketInit;
}

#endif //UDPSOCKET_HPP
