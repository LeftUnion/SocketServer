#include <BaseSocket.hpp>

//Constructors
BaseSocket::BaseSocket(const std::string& ip, const std::string& port) 
{
    addr.sin_family = AF_INET;
    addr.sin_port = htons(std::stoi(port));
    addr.sin_addr.s_addr = inet_addr(ip.c_str());

    this->mSocketfd = ISocket::create();
    ISocket::bind(ip, port);
}

BaseSocket::~BaseSocket() //+
{
    BaseSocket::close(this->mSocketfd);
}

//Methods
bool BaseSocket::bind(const std::string &ip, const std::string &port)
{
    int rBind = ::bind(mSocketfd, reinterpret_cast<sockaddr*>(&addr), sizeof (addr));
    if(rBind < 0)
    {
        //TODO
        perror("Bind: ");
        status = SocketStatus::err_socket_bind;
        return false;
    }
    return true;
}

bool BaseSocket::listen(const size_t& users) //+
{
    int rListen = ::listen(this->mSocketfd, users);
    std::cout << "Start listening on port: " << ntohs(this->addr.sin_port) << std::endl;
    if(rListen < 0)
    {
        //TODO
        perror("Listen: ");
        this->status = SocketStatus::err_socket_listen;
    }
    return rListen;
}

int BaseSocket::accept(const size_t &hostSockfd, struct sockaddr& userAddr, socklen_t addrlen)
{
    int clientSocket = ::accept(hostSockfd, reinterpret_cast<sockaddr*>(&userAddr), &addrlen);
    if(clientSocket < 0)
    {
        perror("Accept: ");
        this->status = SocketStatus::err_socket_accept;
    }
            return clientSocket;
}

SocketStatus BaseSocket::getStatus()
{
    return this->status;
}

socklen_t BaseSocket::getSocketfd()
{
    return this->mSocketfd;
}

int BaseSocket::connect(const int socketfd, const struct sockaddr& connectAddr, socklen_t addrlen)
{
    int rConnect = ::connect(socketfd, reinterpret_cast<sockaddr*>(&addr), addrlen);
    std::cout << "Conncted!" << std::endl;
    if(rConnect < 0)
    {
        //TODO
        perror("Connect: ");
        this->status = SocketStatus::err_socket_connect;
    }
    return rConnect;
}

int BaseSocket::close(const socklen_t& socketfd) //+
{
    int rClose = close(socketfd);
    std::cout << "Socket #" << this->mSocketfd << " closed" << std::endl;
    if(rClose == -1)
    {
        //TODO
        perror("Close: ");
    }
    this->status = SocketStatus::disconnected;
    return rClose;
}

//Getters|Setters
