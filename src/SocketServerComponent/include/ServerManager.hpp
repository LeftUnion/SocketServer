#ifndef SERVERMANAGER_HPP
#define SERVERMANAGER_HPP

#include <UseCases.hpp>
#include <BaseDataBase.hpp>
#include <ConnectionHandler.hpp>
#include <MessageHandler.hpp>
#include <TcpSocket.hpp>

#include <map>
#include <string>
#include <thread>
#include <mutex>


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

    static const std::map<std::string, availableCommands> cmdStoI;
    static const std::vector<std::string> helpEpressions;

    std::map<std::string, std::string> cfgInit;

    std::shared_ptr<BaseSocket> mHostSocket;

    std::shared_ptr<ConnectionHandler> mListener;
    //std::shared_ptr<MessageHandler> mMessanger;
    std::thread waitConnection;
    std::thread messangeThread;


public:
    ServerManager() = default;
    ~ServerManager() = default;

    void exec(const std::string &&cmd);

private:
    bool checkCfg(const std::string &filePath);
    void listenToUsers(ISocket& serverSocket);
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
