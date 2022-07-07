#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP

#include "BaseSocket.hpp"

#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <vector>
#include <memory>

class TcpSocket : public BaseSocket
{
//Fields

//Methods
public:
    TcpSocket(std::string ip, std::string port);; //+
    ~TcpSocket() = default; //+

private:
    int create() override final; //+
};


#endif // TCPSOCKET_HPP
