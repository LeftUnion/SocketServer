#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

#include <QTextStream>
#include <QString>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>


namespace Network
{
    /*!
     * \brief SERVER_PORT - порт сервера
     */
    const int SERVER_PORT = htons(1024);

    /*!
     * \brief SERVER_ADDRES - IP адрес сервера
     */
    const int SERVER_ADDRES = htonl(INADDR_ANY);

    /*!
     * \brief MAX_USERS - максимальное кол-во пользователей на сервере
     */
    const int MAX_USERS = 5;

    /*!
     * \brief cout - поток вывода
     * \return
     */
    QTextStream cout(stdin);

    class ServerSocket
    {
        public:
            ServerSocket();
            ~ServerSocket();

        private:
            int baseSocket;
            int acceptSocket;
    };
}

#endif // SERVERSOCKET_HPP
