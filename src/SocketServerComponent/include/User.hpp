#ifndef USER_HPP
#define USER_HPP

#include <ISocket.hpp>

#include <memory>
#include <queue>

class User
{
private:
    std::unique_ptr<ISocket> mSocket;
    std::queue<IMessage> messageHistory;
    //TODO insert login and password into DB

public:
    User();
    ~User();

    Socket getSocket();

};


#endif // USER_HPP