#ifndef CONNECTIONHANDLER_HPP
#define CONNECTIONHANDLER_HPP

#include <UseCases.hpp>
#include <ISocket.hpp>

#include <mutex>
#include <list>
#include <sys/epoll.h>

/*
 * Этот класс занимается обработкой входящих соединений.
 * Он должен знать Макс Пользователей.(Можно менять и узнавать).
 *
*/
struct epoll_event;

class ConnectionHandler
{
    std::shared_ptr<Socket> hostSocket;
    std::shared_ptr<std::list<User>> mOnlineUsers;

    int pollingfd;
    epoll_event ev;

    char* buffer = new char[1024];

    //Preset Phrases
    const char* welcomeMsg  = "Welocome!\nInput your login and password.\n";
    const char* authMsg     = "Welocome!\nInput your login and password.\n";
    const char* errorMsg    = "Wrong login or pass! Try Again!\n";
    const char* loginMsg    = "Input your login: ";
    const char* passwordMsg = "Input your password: ";

public:
    ConnectionHandler(const std::shared_ptr<Socket> hostSocket);
    ~ConnectionHandler() = default;

    void userAuth();
    int polfd() const;
    std::shared_ptr<std::list<User>> getOnlineUsers();
private:


};

#endif // CONNECTIONHANDLER_HPP

