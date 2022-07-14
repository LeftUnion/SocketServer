#include <TcpSocket.hpp>

//Constructors

//Methods

TcpSocket::TcpSocket(int socketfd, sockaddr_in addr) : BaseSocket(socketfd, addr){}
TcpSocket::TcpSocket(std::string ip, std::string port) : BaseSocket(ip, port)
{
    create();
    bind();
}

int TcpSocket::create() //+
{
    int socketInit = socket(AF_INET, SOCK_STREAM, 0);
    if(socketInit < 0)
    {
        perror("Init: ");
        this->status = SocketStatus::err_socket_init;
        return -1;
    }
    else
        return socketInit;
}
