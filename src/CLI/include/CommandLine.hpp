#ifndef COMMANDLINE_HPP
#define COMMANDLINE_HPP

#include <ServerManager.hpp>

#include <string>

#include <mutex>
#include <memory>
#include <map>

class CommandLine
{
    public:
        CommandLine (CommandLine &other) = delete;
        void operator=(const CommandLine&) = delete;
        static std::shared_ptr<CommandLine> getCommandLine();
        bool inputCommand();

        static const std::map <std::string, Admin::commandType> availableCommands;

    private:
        CommandLine() = default;
        static std::shared_ptr<CommandLine> mCommandLine;
        static std::mutex mMutex;

        std::string mCmdLine;
};

#endif // COMMANDLINE_HPP
