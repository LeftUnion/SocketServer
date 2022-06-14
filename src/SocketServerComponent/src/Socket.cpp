#include <Socket.hpp>
#include <iostream>

//Con|Dest ======================================================
Socket::Socket(std::string ip, std::string port)
{
    this->ip = ip;
    this->port = std::stoi(port);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(this->port);
    addr.sin_addr.s_addr = inet_addr(ip.c_str());

    create();
    std::cout << "=> Socket #" << socketDs << " has been created" << std::endl;

    bindAddr();
    std::cout << "=> Socket #" << socketDs << " binded" << std::endl;
}

Socket::~Socket()
{
    close(socketDs);
    std::cout << "=> Socket #" << socketDs << "deleted" << std::endl;
}

//Methods ======================================================
int Socket::create()
{
    socketDs = socket(AF_INET, SOCK_STREAM, 0);
    if(socketDs < 0)
    {
        perror("Init: ");
        status = SocketStatus::err_socket_init;
        return 1;
    }
    return socketDs;
}

void Socket::bindAddr()
{
    int rBind = bind(socketDs, reinterpret_cast<sockaddr*>(&addr), sizeof (addr));
    if(rBind < 0)
    {
        perror("Bind: ");
        status = SocketStatus::err_socket_bind;
        return;
    }
}

void Socket::listenAddr(const int &countUsers)
{
    int rListen = listen(this->socketDs, countUsers);
    if(rListen < 0)
    {
        perror("Listen: ");
        return;
    }

}

int Socket::acceptConnection()
{
    int rAccept = accept(this->socketDs, NULL, NULL);
    if(rAccept < 0)
    {
        perror("Accept: ");
        status = SocketStatus::err_socket_connect;
        return 0;
    }
    status = SocketStatus::connected;
    return rAccept;
}

//Get|Set ======================================================
int Socket::getSocketDs() const
{
    return socketDs;
}

std::string Socket::getServerIP() const
{
    return ip;
}

int Socket::getPort() const
{
    return port;
}

