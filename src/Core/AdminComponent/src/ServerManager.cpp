#include <ServerManager.hpp>

std::shared_ptr<Admin::ServerManager> Admin::ServerManager::mServerManager = nullptr;
std::mutex Admin::ServerManager::mMutex{};

bool Admin::ServerManager::exec(commandType type)
{
    switch (type)
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

        case INFO:
            info();
            return true;

        case HELP:
            help();
            return true;
    }

    return false;
}

std::shared_ptr<Admin::ServerManager> Admin::ServerManager::getServerManager()
{
    std::lock_guard<std::mutex> lock(mMutex);
    if(mServerManager == nullptr)
        mServerManager.reset(new ServerManager);

    return mServerManager;
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
        Admin::ServerManager::Socket.reset(new Network::ServerSocket);
    }
    else
        std::cout << "The server is already up";
}

void Admin::ServerManager::stop()
{
    if (serverStatus == 1)
    {
        serverStatus = 0;
    }
    else
        std::cout << "The server is already down";
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
        std::cout << "The Server is down";
}

void Admin::ServerManager::help()
{
    std::cout << "Available commands:"                    << std::endl;
    std::cout << "start - запуск сервеа"                  << std::endl;
    std::cout << "stop - выключение сервеа"               << std::endl;
    std::cout << "restart - перезапуск сервеа"            << std::endl;
    std::cout << "info - выводит информацию о сервере"    << std::endl;
    std::cout << "help - выводит список доступных команд" << std::endl;
}
//TODO
void Admin::ServerManager::info()
{

}
