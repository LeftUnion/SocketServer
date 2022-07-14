#include <ConnectionHandler.hpp>

const char* ConnectionHandler::MSG_WELCOME  = "Welocome!\nInput your login and password.\n";
const char* ConnectionHandler::MSG_AUTH     = "Welocome!\nInput your login and password.\n";
const char* ConnectionHandler::MSG_ERROR    = "Wrong login or pass! Try Again!\n";
const char* ConnectionHandler::MSG_LOGIN    = "Input your login: ";
const char* ConnectionHandler::MSG_PASSWORD = "Input your password: ";

ConnectionHandler::ConnectionHandler(const std::shared_ptr<BaseSocket> hostSocket)
{
    this->hostSocket = hostSocket;
    mOnlineUsers = std::make_shared<std::list<User>>();
}

bool ConnectionHandler::acceptConnection()
{
    User tmpUser;
    sockaddr_in tmpAddr;
    int tmpSocket = hostSocket->accept(hostSocket->getSocketfd(), reinterpret_cast<sockaddr*>(&tmpAddr), nullptr);

    User inUser = User(tmpSocket, tmpAddr);
    mOnlineUsers->push_back(inUser);
    userAuth(inUser);
    return true;
}

bool ConnectionHandler::userAuth(User& inUser)
{
    bool isAuth = false;
    std::string buffer = "Auth MEssage";
    int userWriteSocketfd = inUser.getWriteSocket()->getSocketfd();

    send(userWriteSocketfd, buffer.c_str(), sizeof (buffer), 0);
    isAuth = true;
    if(!isAuth)
    {
        close(userWriteSocketfd);
        return  isAuth;
    }
    return isAuth;
}


std::shared_ptr<std::list<User>> ConnectionHandler::getOnlineUsers()
{
   return mOnlineUsers;
}
