#include "CommandLine.hpp"

#include <memory>

int main()
{
    bool isEOP = false;
    std::unique_ptr<ICommandLine> adminConsole = std::make_unique<CommandLine>();
    try
    {
        do
        {
            isEOP = adminConsole->inputCmd();/* code */
        } while (isEOP);
        
            
    }
    catch (...)
    {
        std::cout << "Error";
    }
    return 0;
}
