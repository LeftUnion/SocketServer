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
    //std::queue<BaseMessage> messageHistory; TODO IN DB
    std::string userName;

public:
    User(int&& socket);
    ~User();

};



#endif // USER_HPP
