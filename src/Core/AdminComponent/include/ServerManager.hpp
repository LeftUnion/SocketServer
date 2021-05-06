#ifndef SERVERMANAGER_HPP
#define SERVERMANAGER_HPP

#include <ServerSocket.hpp>
#include <MessageHandler.hpp>

#include <string>

#include <memory>
#include <mutex>
#include <iostream>

namespace Admin
{
    enum commandType
    {
        START,
        STOP,
        RESTART,
        INFO,
        HELP,
    };

    class ServerManager
    {
        public:
            bool exec(commandType type);
            static std::shared_ptr<ServerManager> getServerManager();

            ServerManager(ServerManager &other) = delete;
            void operator=(const ServerManager&) = delete;

        private:
            ServerManager() = default;
            static std::shared_ptr<ServerManager> mServerManager;
            static std::mutex mMutex;

            bool serverStatus;

            std::shared_ptr<Network::ServerSocket> Socket;//?

            //available commands
            bool getStatus();
            void start();
            void stop();
            void restart();
            void info();
            void help();
    };
}

#endif // SERVERMANAGER_HPP
