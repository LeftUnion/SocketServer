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
    int socketDs;
    std::string ip;
    int port;
    struct sockaddr_in addr;
    SocketStatus status;

public:
    Socket(std::string ip, std::string port);
    ~Socket();

    void listenAddr(const int &countUsers);
    int acceptConnection();

    int getSocketDs() const;
    std::string getServerIP() const;
    int getPort() const;
    SocketStatus getStatus() const;
private:

    int create();
    void bindAddr();

};

#endif // TCPSOCKET_HPP
