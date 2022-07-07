#include <TcpSocket.hpp>

//Constructors

//Methods

TcpSocket::TcpSocket(std::string ip, std::string port) : BaseSocket(ip, port) {}

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
