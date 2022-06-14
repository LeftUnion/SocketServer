#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <vector>
#include <memory>

struct User
{
    char* login = new char[64];
    char* password = new char[64];
    int socketDS;
};

enum class SocketStatus : uint8_t
{
    connected = 0,
    err_socket_init = 1,
    err_socket_bind = 2,
    err_socket_connect = 3,
    disconnected = 4
};

class Socket
{
    int socketDs;
    std::string ip;
    int port;
    struct sockaddr_in addr;
    SocketStatus status;

public:
    Socket() = default;
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

#endif // SOCKET_HPP
