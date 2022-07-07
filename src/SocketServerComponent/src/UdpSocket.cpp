#include <UdpSocket.hpp>

//Constructors

//Methods

UdpSocket::UdpSocket(std::string ip, std::string port) : BaseSocket(ip, port) {}

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
//Getters|Setters
