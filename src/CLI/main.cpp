#include <CommandLine.hpp>

int main()
{
    while (true)
        CommandLine::getCommandLine()->inputCommand();
}
