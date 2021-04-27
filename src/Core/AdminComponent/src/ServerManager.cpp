#include <ServerManager.hpp>
#include <AdminConsole.hpp>
#include <ServerSocket.hpp>

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
        insServerManager = new ServerManager();
    }
    return insServerManager;
}

bool Admin::ServerManager::getStatus()
{
    return serverStatus;
}

void Admin::ServerManager::start()
{
    serverStatus = 1;


}

void Admin::ServerManager::stop()
{
    serverStatus = 0;
}

void Admin::ServerManager::restart()
{
    serverStatus = 0;
    stop();

    serverStatus = 1; //may be swap below
    start();
}
//TODO
//void Admin::ServerManager::messageAll(const QString &msg)
//{

//}

void Admin::ServerManager::help()
{
    cout << "Available commands:" << endl;
    cout << "start - запуск сервеа" << endl;
    cout << "stop - выключение сервеа" << endl;
    cout << "restart - перезапуск сервеа" << endl;
    cout << "messageAll - отправить сообщение всем участникам сервера" << endl;
    cout << "info - выводит информацию о сервере" << endl;
    cout << "help - выводит список доступных команд" << endl;
}
//TODO
void Admin::ServerManager::info()
{

}
