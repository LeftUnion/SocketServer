#include <ServerSocket.hpp>

#include <string>

#include <iostream>

Network::ServerSocket::ServerSocket()
{

    struct sockaddr_in socketAddr;
    socketAddr.sin_addr.s_addr = SERVER_ADDRES;
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_port = SERVER_PORT;

    baseSocket = socket(PF_UNIX, SOCK_STREAM, IPPROTO_TCP);
    if(baseSocket < 0)
    {
        std::cout << "ERROR: socket creating";
        close(baseSocket);
        exit(0);
    }
    else
        std::cout << "Socket has been created...";

    socklen_t size = sizeof (socketAddr);
    int isSocketBind = bind(baseSocket, reinterpret_cast<struct sockaddr*>(&socketAddr), size);
    if(isSocketBind < 0)
    {
        std::cout << "ERROR: socket bind";
        close(baseSocket);
        exit(0);
    }
    else
        std::cout << "Socket has been bind...";

    int isListen = listen(baseSocket, MAX_USERS);
    if(isListen < 0)
    {
       std::cout << "ERROR: socket listening";
       close(baseSocket);
       exit(0);
    }
    else
        std::cout << "Socket is listening";

    acceptSocket = accept(baseSocket, reinterpret_cast<struct sockaddr*>(&socketAddr), &size);
    if(acceptSocket >= 0)
    {
        size_t userId = 1;
        std::cout << "User #" << userId << " connected";
        userId++;

        std::string msg = "Connected";
        send(baseSocket, &msg, sizeof(msg), 0);

        while (acceptSocket > 0)
        {
            recv(baseSocket, &msg, sizeof(msg), 0);

        }
    }

}

Network::ServerSocket::~ServerSocket()
{
    close(baseSocket);
}
