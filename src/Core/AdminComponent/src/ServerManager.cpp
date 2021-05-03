#include <ServerManager.hpp>
#include <AdminConsole.hpp>

bool Admin::ServerManager::exec( QString &cmd , QString arg1)
{
    commandType command = availableCommands.find(cmd)->second;;
    switch (command)
    {
        case START:
            start();
            return true;

        case STOP:
            stop();
            return true;

        case RESTART:
            restart();
            return true;
//TODO
//        case MESSAGEALL:
//            messageAll(arg1);
//            return true;

        case INFO:
            info();
            return true;

        case HELP:
            help();
            return true;
    }

    return false;
}

Admin::ServerManager *Admin::ServerManager::getServerManager()
{
    if(ServerManager::insServerManager == nullptr)
    {
        ServerManager::insServerManager = new ServerManager();
    }
    return ServerManager::insServerManager;
}

bool Admin::ServerManager::getStatus()
{
    return serverStatus;
}

void Admin::ServerManager::start()
{
    if(serverStatus == 0)
    {
        serverStatus = 1;
        Admin::ServerManager::Socket = new Network::ServerSocket();
    }
    else
        Admin::cout << "The server is already up";
}

void Admin::ServerManager::stop()
{
    if (serverStatus == 1)
    {
        serverStatus = 0;
        delete (Socket);
    }
    else
        Admin::cout << "The server is already down";
}

void Admin::ServerManager::restart()
{
    if(serverStatus == 1)
    {
        serverStatus = 0;
        stop();

        serverStatus = 1; //may be swap below
        start();
     }
    else
        Admin::cout << "The Server is down";
}
//TODO
//void Admin::ServerManager::messageAll(const QString &msg)
//{

//}

void Admin::ServerManager::help()
{
    Admin::cout << "Available commands:" << endl;
    Admin::cout << "start - запуск сервеа" << endl;
    Admin::cout << "stop - выключение сервеа" << endl;
    Admin::cout << "restart - перезапуск сервеа" << endl;
    Admin::cout << "messageAll - отправить сообщение всем участникам сервера" << endl;
    Admin::cout << "info - выводит информацию о сервере" << endl;
    Admin::cout << "help - выводит список доступных команд" << endl;
}
//TODO
void Admin::ServerManager::info()
{

}
