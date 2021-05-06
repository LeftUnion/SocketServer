#include <CommandLine.hpp>

std::shared_ptr<CommandLine> CommandLine::mCommandLine;
std::mutex CommandLine::mMutex{};

const std::map <std::string, Admin::commandType> CommandLine::availableCommands =
{
    {"start",       Admin::START},
    {"stop",        Admin::STOP},
    {"restart",     Admin::RESTART},
    {"info",        Admin::INFO},
    {"help",        Admin::HELP},
};

bool CommandLine::inputCommand()
{
    std::cin >> mCmdLine;

    auto command = availableCommands.find(mCmdLine)->second;
    if(Admin::ServerManager::getServerManager()->exec(command))
        return true;

    std::cout << "Such command does not exist";
    return false;
}

std::shared_ptr<CommandLine> CommandLine::getCommandLine()
{
    std::lock_guard<std::mutex> lock(mMutex);
    if(mCommandLine == nullptr)
        mCommandLine.reset(new CommandLine);

    return mCommandLine;
}
