#ifndef UDPSOCKET_HPP
#define UDPSOCKET_HPP

#include "BaseSocket.hpp"

class UdpSocket : public BaseSocket
{

public:
    UdpSocket() = default;
    UdpSocket(int socketfd, sockaddr_in addr);
    UdpSocket(std::string ip, std::string port);; //+
    ~UdpSocket() = default; //+

private:
    int create() override final; //+
};



#endif //UDPSOCKET_HPP
