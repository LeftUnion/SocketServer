#include <CommandLine.hpp>

int main()
{
    CommandLine userConsole;
    try
    {
        while (true)
            userConsole.inputCmd();
    }
    catch (...)
    {
        std::cout << "Error";
    }
    return 0;
}
