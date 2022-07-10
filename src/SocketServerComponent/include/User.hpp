#ifndef USER_HPP
#define USER_HPP

#include <TcpSocket.hpp>
#include <BaseMessage.hpp>

#include <memory>
#include <queue>


class User
{
private:
    static size_t userCount;
    std::unique_ptr<ISocket> mSocket;
    std::queue<BaseMessage> messageHistory;
    std::string login;
    std::string password;

    //TODO insert login and password into DB

public:
    User(int&& socket);
    ~User();

};

size_t User::userCount = 0;

#endif // USER_HPP
