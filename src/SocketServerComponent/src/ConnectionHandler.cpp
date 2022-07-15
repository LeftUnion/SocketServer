#include <ConnectionHandler.hpp>

const char* ConnectionHandler::MSG_WELCOME  = "Welocome!\nInput your login and password.\n";
const char* ConnectionHandler::MSG_AUTH     = "Input your login and password in format: \"login_password\"\n";
const char* ConnectionHandler::MSG_ERROR    = "Wrong login or pass! Try Again!\n";
const char* ConnectionHandler::MSG_LOGIN    = "Input your login: ";
const char* ConnectionHandler::MSG_PASSWORD = "Input your password: ";

ConnectionHandler::ConnectionHandler(const std::shared_ptr<BaseSocket> hostSocket)
{
    this->hostSocket = hostSocket;
    mOnlineUsers = std::make_shared<std::list<User>>();
    usersDataBase = std::make_shared<BaseDataBase>("QPSQL");
    usersDataBase->createUsersTable();
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
    std::string buffer;
    int userWriteSocketfd = inUser.getWriteSocket()->getSocketfd();

    send(userWriteSocketfd, MSG_AUTH, sizeof (MSG_AUTH), 0);
    recv(userWriteSocketfd, &buffer, sizeof (buffer), 0);

    char divChar = ' ';
    auto divPos = buffer.find(divChar);
    std::string login = buffer.substr(0, divPos) ;
    std::string password = buffer.substr(divPos + 1, buffer.size() - 1);
    if(usersDataBase->checkUserExists(login, password))
    {
        isAuth = true;
    }
    else
    {
        usersDataBase->addUser(login, password);
        isAuth = true;
    }

    if(!isAuth)
    {
        inUser.getWriteSocket()->close(userWriteSocketfd);
        return  isAuth;
    }

    inUser.setReadSocket(makeReadSocket());
    return isAuth;
}

std::unique_ptr<BaseSocket> ConnectionHandler::makeReadSocket()
{
    std::unique_ptr<TcpSocket> ReadSocket = std::make_unique<TcpSocket>("localhost", "somePort");
    ReadSocket->listen(1);
    return std::move(ReadSocket);
}


std::shared_ptr<std::list<User>> ConnectionHandler::getOnlineUsers()
{
   return mOnlineUsers;
}
