#ifndef COMMANDLINE_HPP
#define COMMANDLINE_HPP

#include <AdminInterface.hpp>
#include <ServerManager.hpp>

#include <iostream>
#include <queue>



class CommandLine : public AdminI
{
    std::queue<std::string> commandsHistory[100];
    ServerManager server;
    std::string currentCmd;

public:
    CommandLine() = default;
    ~CommandLine() = default;
    void parser(std::string inputLine);
    void inputCmd() override;
    std::shared_ptr<std::queue<std::string>> getCommandsHistroy() const;
private:
};

#endif // COMMANDLINE_HPP

