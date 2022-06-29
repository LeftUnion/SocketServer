#ifndef COMMANDLINE_HPP
#define COMMANDLINE_HPP

#include <ICommandLine.hpp>
#include <ServerManager.hpp>

#include <iostream>
#include <queue>

class CommandLine : public ICommandLine
{

    std::queue<std::string> commandsHistory[100];
    ServerManager server;
    std::string currentCmd;

public:
    CommandLine() = default;
    ~CommandLine() = default;
    bool inputCmd() override;

private:
    void parser(std::string inputLine);
    std::shared_ptr<std::queue<std::string>> getCommandsHistroy() const;

};

#endif // COMMANDLINE_HPP

