#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP
#include <UseCases.hpp>
#include <map>
#include <Socket.hpp>
#include <mutex>
#include <list>
#include <queue>
#include <sys/epoll.h>

typedef std::pair<const User, char*> msgSender;

struct DataBuffer
{
    int size = 0;
    char* ptr = nullptr;

};

class Message
{
    Message() = default;
};

class AudioMessage : public Message
{

};

class TextMessage : public Message
{

};

class VideoMessage : public Message
{

};

class FileMessage : public Message
{

};

struct epoll_event;

class MessageHandler
{
    char* buffer = new char[1024];
    std::queue<std::pair<const User, std::string>> messages;
    std::shared_ptr<std::list<User>> onlineUsers = nullptr;
    epoll_event events[20];
    int pofd;
public:
    MessageHandler(const std::shared_ptr<std::list<User>> monlineUsers, int somefd);
    ~MessageHandler() = default;

    void checkForMessage();
private:
    void resendMessages();

};



#endif // MESSAGEHANDLER_HPP
