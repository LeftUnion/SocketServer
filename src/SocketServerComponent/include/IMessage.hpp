#ifndef IMESSAGE_HPP
#define IMESSAGE_HPP

#include <stdio.h>


class IMessage
{
public:
    IMessage() = default;
    ~IMessage() = default;

protected:
    virtual size_t getSize(void) = 0;

};

#endif // IMESSAGE_HPP