#ifndef SERVERMANAGER_HPP
#define SERVERMANAGER_HPP

#include <ServerSocket.hpp>

#include <QTextStream>
#include <QString>

namespace Admin
{
    using Qt::endl;
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    class ServerManager
    {
        //fields
        public:

            /*!
             * \brief status - статус сервера(0 - down, 1 - up)
             */
            bool serverStatus; //TODO: MAY BE PRIVATE FIELD

            /*!
             * \brief executeCmd - метод, исполняющий доступные команды
             * \param cmd - консольная команда
             * \return 0 - команда не выполнена, 1 - команда успешно выполнена
             */
            bool exec(QString &cmd, QString arg1 = "");

        private:

            //конструктор по умолчанию
            ServerManager() = default;

        protected:

            Network::ServerSocket* Socket;
            static ServerManager* insServerManager;

        //methods
        public:

            ServerManager(ServerManager &other) = delete;

            void operator=(const ServerManager&) = delete;

            static ServerManager* getServerManager();


        //available commands
        private:

            /*!
             * \brief getStatus - получение статуса сервера
             * \return 0 - server is down, 1 - server is up
             */
            bool getStatus();

            /*!
             * \brief start - запуск сервера
             */
            void start();

            /*!
             * \brief stop - выключение сервера
             */
            void stop();

            /*!
             * \brief restart - перезапуск сервера
             */
            void restart();

            /*!
             * \brief messageAll - отправить сообщение всем участникам сервера
             * \param msg - сообщение
             */
           // void messageAll(const QString &msg); TODO

            /*!
             * \brief info - выводит информацию о сервере
             */
            void info();

            /*!
             * \brief help - вывод списка доступных комманд
             */
            void help();
    };

    ServerManager* ServerManager::insServerManager = nullptr;
}

#endif // SERVERMANAGER_HPP
