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

    std::shared_ptr<Socket> mHostSocket;
    std::shared_ptr<ConnectionHandler> mListener;
    std::shared_ptr<MessageHandler> mMessanger;
    std::thread waitConnection;
    std::thread messangeThread;
    std::map<std::string, std::string> cfgInit = {
        {"ip", ""},
        {"port", ""},
        {"maxUsers", ""}
    };

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
