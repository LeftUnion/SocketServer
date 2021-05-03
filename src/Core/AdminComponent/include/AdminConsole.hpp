#ifndef ADMINCONSOLE_HPP
#define ADMINCONSOLE_HPP

#include <QString>
#include <map>

namespace Admin
{
    /*!
     * \brief The commandType enum - перечисление доступных комманд
     */
    enum commandType
    {
        START,
        STOP,
        RESTART,
        MESSAGEALL,
        INFO,
        HELP,
    };

    const std::map <QString, commandType> availableCommands =
    {
        {"start",       START},
        {"stop",        STOP},
        {"restart",     RESTART},
        {"messageAll",  MESSAGEALL},
        {"info",        INFO},
        {"help",        HELP},
    };

    /*!
     * \brief The AdminConsole class - класс консоли администратора
      */
    class AdminConsole
    {
        //fields
        private:

            //конструктор по умолчанию
            AdminConsole() = default;

            /*!
             * \brief cmdLine - консоль, в которую вводятся команды
             */
            QString cmdLine;

        protected:

            /*!
             * \brief insAdminConsole - представитель класса
             */
            static AdminConsole* insAdminConsole;

        public:

            //Запрещает копирование
            AdminConsole (AdminConsole &other) = delete;

            //Запрет оператора присваивания
            void operator=(const AdminConsole&) = delete;

            /*!
             * \brief getAdminConsole - геттер представителя класса
             * \return - представитель класса
             */
            static AdminConsole *getAdminConsole();

            /*!
             * \brief inputCommand - метод, отвечающий за ввод команды
             * \return 0 - команда не выполнена, 1 - команда выполнена
             */
            bool inputCommand();
    };

    AdminConsole* AdminConsole::insAdminConsole = nullptr;
}

#endif // ADMINCONSOLE_HPP
