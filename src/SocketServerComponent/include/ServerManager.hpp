#ifndef SERVERMANAGER_HPP
#define SERVERMANAGER_HPP

#include <UseCases.hpp>
#include <DataBase.hpp>
#include <ConnectionHandler.hpp>
#include <MessageHandler.hpp>

#include <map>
#include <string>
#include <thread>
#include <mutex>

extern std::mutex data;

/*
 * Этот класс должен организовать работу отдельных компонентов сервера.
 * У него должны быть объекты каждого подконтрольного класса через указатель.
 * Users) За хранение/проверку пользователей овечает DataBase
 * Logger) Фиксирование действий.
 * Socket) Стартовые параметры конечной точки подключения
*/

class ServerManager
{
//TODO    DataBase const lol();

    std::map<std::string, availableCommands> const cmdStoI =
    {
        {"help", HELP},
        {"start", START},
        {"restart", RESTART},
        {"stop", STOP},
        {"showusers", SHOWUSERS},
        {"kick", KICK},
        {"messageto", MESSAGETO},
        {"messageall", MESSAGEALL},
        {"exit", EXIT}
    };

    static uint8_t const COUNT_HELP_EXPR = 8;
    std::array<std::string, COUNT_HELP_EXPR> const helpEpressions =
    {
        "start - start the server ",
        "restart - restart the server ",
        "stop - stop work of the server ",
        "showusers - list of online users ",
        "kick userName(arg1) - kick user(arg1), if one is online ",
        "messageto userName(arg1) message(arg2) - send a user(arg1) a message(arg2) ",
        "messageall message(arg1) - send all users a message(arg1) ",
        "exit - stop server and stop the terminal execution"
    };

    std::map<std::string, std::string> cfgInit =
    {
        {"ip", ""},
        {"port", ""},
        {"maxUsers", ""}
    };

    std::shared_ptr<Socket> mHostSocket;
    std::shared_ptr<ConnectionHandler> mListener;
    std::shared_ptr<MessageHandler> mMessanger;
    std::thread waitConnection;
    std::thread messangeThread;


public:
    ServerManager() = default;
    ~ServerManager() = default;

    void exec(const std::string &&cmd);

private:
    bool checkCfg(const std::string &filePath);
    void listenToUsers(Socket serverSocket);
    void help() const;
    void start();
    void restart();
    void stop();
    void showusers();
    void kick();
    void messageto(std::string userLogin);
    void messageall();
    void exit();

};


#endif // SERVERMANAGER_HPP
