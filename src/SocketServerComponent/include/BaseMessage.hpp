#ifndef BASEMESSAGE_HPP
#define BASEMESSAGE_HPP

#include <string>

enum class messageType
{
    textMessage = 0,
    voiceMessage,
    picture,
    video,
    audio
};

class BaseMessage
{
protected:
    size_t size = 0;
    std::string sender = nullptr;
    std::string getter = nullptr;
    messageType type;

public:
    BaseMessage(std::string sender, std::string getter, std::string message, messageType type);
    ~BaseMessage();

    BaseMessage(const BaseMessage&);
    BaseMessage& operator=(const BaseMessage&);
    BaseMessage(const BaseMessage&&) = delete;
    BaseMessage& operator=(const BaseMessage&&) = delete;
    operator bool();


};

#endif // BASEMESSAGE_HPP
