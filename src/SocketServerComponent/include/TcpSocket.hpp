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

public:
    TcpSocket(std::string ip, std::string port) : BaseSocket(ip, port) {}; //+
    ~TcpSocket() = default; //+

    void listenAddr(const int &countUsers);
    int acceptConnection();

    int getSocketDs() const;
    std::string getServerIP() const;
    int getPort() const;
    SocketStatus getStatus() const;
private:

    int create(); //+
    void bindAddr();

};

int TcpSocket::create() //+
{
    int socketInit = socket(AF_INET, SOCK_STREAM, 0);
    if(socketInit < 0)
    {
        perror("Init: ");
        this->status = SocketStatus::err_socket_init;
    }
    else
        return this->socketfd = socketInit;
}


#endif // TCPSOCKET_HPP
