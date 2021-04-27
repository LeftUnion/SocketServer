#include <ServerSocket.hpp>
#include <ServerManager.hpp>

Network::ServerSocket::ServerSocket()
{
    struct sockaddr_in socketAddr;
    socketAddr.sin_addr.s_addr = SERVER_ADDRES;
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_port = SERVER_PORT;

    baseSocket = socket(PF_UNIX, SOCK_STREAM, IPPROTO_TCP);
    if(baseSocket < 0)
    {
        cout << "ERROR: socket creating";
        close(baseSocket);
        exit(0);
    }

    socklen_t size = sizeof (socketAddr);
    int isSocketBind = bind(baseSocket, reinterpret_cast<struct sockaddr*>(&socketAddr), size);
    if(isSocketBind < 0)
    {
        cout << "ERROR: socket bind";
        close(baseSocket);
        exit(0);
    }

    int isListen = listen(baseSocket, MAX_USERS);
    if(isListen < 0)
    {
       cout << "ERROR: socket listening";
       close(baseSocket);
       exit(0);
    }

    acceptSocket = accept(baseSocket, reinterpret_cast<struct sockaddr*>(&socketAddr), &size);
    if(acceptSocket >= 0)
    {
        QString msg = "Connected";
        send(baseSocket, &msg, sizeof(msg), );

        bool statusServer = Admin::ServerManager::getServerManager()->serverStatus;
        while (acceptSocket > 0 and statusServer == 1)
        {
        }
    }

}

Network::ServerSocket::~ServerSocket()
{
    close(baseSocket);
}
