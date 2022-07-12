#include <ConnectionHandler.hpp>


#include <sys/epoll.h>

ConnectionHandler::ConnectionHandler(const std::shared_ptr<BaseSocket> hostSocket)
{
    mOnlineUsers = std::make_shared<std::list<User>>();
    this->hostSocket = hostSocket;
}

void ConnectionHandler::userAuth()
{
    //main Connection Loop
    while (true) {

        User inUser;
        bool isAuth = true;
        inUser.socketDS = hostSocket->acceptConnection();
        send(inUser.socketDS, welcomeMsg, sizeof(welcomeMsg), 0);

        ev.events = EPOLLIN | EPOLLOUT;
        ev.data.fd = pollingfd;
        if(epoll_ctl(pollingfd, EPOLL_CTL_ADD, inUser.socketDS, &ev))
            perror("Epoll add");

        //send/get login
        send(inUser.socketDS, loginMsg, sizeof(loginMsg), 0); //TODO BD Check
        recv(inUser.socketDS, buffer, sizeof(buffer), 0);
        if(sizeof(buffer) > 0)
            inUser.login = buffer;

        //send/get password
        send(inUser.socketDS, passwordMsg, sizeof(passwordMsg), 0);
        do {
            recv(inUser.socketDS, inUser.password, sizeof(inUser.password), 0);
            recv(inUser.socketDS, buffer, sizeof(buffer), 0);
        } while(inUser.password != buffer);
        if(sizeof(buffer) > 0)
            inUser.password = buffer;

        if(isAuth == true)
        {
            send(inUser.socketDS, authMsg, sizeof(authMsg), 0);
            mOnlineUsers->push_back(inUser);
        }
        else
            close(inUser.socketDS);
    }
}

int ConnectionHandler::polfd() const
{
    return pollingfd;
}

std::shared_ptr<std::list<User>> ConnectionHandler::getOnlineUsers()
{
   return mOnlineUsers;
}
