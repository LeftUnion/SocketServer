#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include <string>

namespace Message
{
    /*!
     * \brief The MessageType enum - типы сообщений
     */
    enum MessageType
    {
        text,
        img
    };

    /*!
     * \brief The MessageInfo struct - информация о сообщении (кто, что, тип данных, кому)
     */
    struct MessageInfo
    {
        std::string sender;
        std::string message;
        MessageType type;
        std::string getter;
    };

    class MessageHandler
    {
        void imgFormating(std::string &msg);  //TODO RETURN
        void txtFormating(std::string &msg);  //TODO RETURN
    };
}

#endif // MESSAGEHANDLER_HPP
