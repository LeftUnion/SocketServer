#ifndef BASEMESSAGE_HPP
#define BASEMESSAGE_HPP

class enum messageType
{
    textMessage = 0,
    voiceMessage,
    picture,
    video,
    audio
}

class BaseMessage
{
private:
    /* data */
public:
    BaseMessage();
    ~BaseMessage();
};

#endif // BASEMESSAGE_HPP