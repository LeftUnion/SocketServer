//#ifndef MESSAGEHANDLER_HPP
//#define MESSAGEHANDLER_HPP

//#include <UseCases.hpp>
//#include <User.hpp>

//#include <map>
//#include <mutex>
//#include <list>
//#include <queue>
//#include <memory>

//struct DataBuffer
//{
//    int size = 0;
//    char* ptr = nullptr;

//};

//class Message
//{
//    Message() = default;
//};

//class AudioMessage : public Message
//{

//};

//class TextMessage : public Message
//{

//};

//class VideoMessage : public Message
//{

//};

//class FileMessage : public Message
//{

//};

//class MessageHandler
//{
//    char* buffer = new char[1024];
//    std::queue<std::pair<const User, std::string>> messages;
//    std::list<> readSockets;
//    std::list<> writeSockets;
//    std::shared_ptr<std::list<User>> onlineUsers = nullptr;

//public:
//    MessageHandler(const std::shared_ptr<std::list<User>> monlineUsers, int somefd);
//    ~MessageHandler() = default;

//    void checkForMessage();
//private:
//    void resendMessages();

//};



//#endif // MESSAGEHANDLER_HPP
