#include <CommandLine.hpp>

void CommandLine::parser(std::string inputLine)
{

}

bool CommandLine::inputCmd()
{
    //todo Parser
    std::cout << "Admin@command: ";
    std::getline(std::cin, currentCmd);
    commandsHistory->push(currentCmd);
    server.exec(std::move(currentCmd));


}

//std::shared_ptr<std::queue<std::string> > CommandLine::getCommandsHistroy() const
//{
//   return std::make_shared<std::queue<std::string>>(commandsHistory);
//}

