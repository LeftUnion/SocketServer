#include <UdpSocket.hpp>

//Constructors

//Methods

UdpSocket::UdpSocket(int socketfd, sockaddr_in addr) : BaseSocket(socketfd, addr){}
UdpSocket::UdpSocket(std::string ip, std::string port) : BaseSocket(ip, port)
{
    mSocketfd = create();
    bind();
}

int UdpSocket::create() //+
{
    int socketInit = socket(AF_INET, SOCK_DGRAM, 0);
    if(socketInit < 0)
    {
        perror("Init: ");
        this->status = SocketStatus::err_socket_init;
        return -1;
    }
    else
        return socketInit;
}
//Getters|Setters
