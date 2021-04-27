#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include <QString>

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
        QString sender;
        QString message;
        MessageType type;
        QString getter;
    };

    class MessageHandler
    {
        void imgFormating(QString &msg);  //TODO RETURN
        void txtFormating(QString &msg);  //TODO RETURN
    };
}

#endif // MESSAGEHANDLER_HPP
