#include "CommandLine.hpp"
#include "exception"

#include <memory>

int main()
{
    bool isEOP = false;
    std::unique_ptr<ICommandLine> adminConsole = std::make_unique<ICommandLine>();
    try
    {
        do
        {
            isEOP = adminConsole->inputCmd();/* code */
        } while (isEOP);
        
            
    }
    catch(const std::exception& err)
    {
        std::cout << "ERROR: " << err.what();
    }
    catch (...)
    {
        std::cout << "Error";
    }
    return 0;
}
