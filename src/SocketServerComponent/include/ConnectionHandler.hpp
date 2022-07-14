#ifndef CONNECTIONHANDLER_HPP
#define CONNECTIONHANDLER_HPP

#include <UseCases.hpp>
#include <ISocket.hpp>
#include <User.hpp>

#include <list>
#include <memory>
/*
 * Этот класс занимается обработкой входящих соединений.
 * Он должен знать Макс Пользователей.(Можно менять и узнавать).
 *
*/

class ConnectionHandler
{
    std::shared_ptr<BaseSocket> hostSocket;
    std::shared_ptr<std::list<User>> mOnlineUsers;

    //Preset Phrases
    static const char* MSG_WELCOME;
    static const char* MSG_AUTH;
    static const char* MSG_ERROR;
    static const char* MSG_LOGIN;
    static const char* MSG_PASSWORD;

public:
    ConnectionHandler(const std::shared_ptr<BaseSocket> hostSocket);
    ~ConnectionHandler() = default;

    bool acceptConnection();
    bool userAuth(User &inUser);
    int polfd() const;
    std::shared_ptr<std::list<User>> getOnlineUsers();
private:


};

#endif // CONNECTIONHANDLER_HPP

