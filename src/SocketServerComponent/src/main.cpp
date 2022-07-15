#include "CommandLine.hpp"
#include <BaseDataBase.hpp>
#include "exception"

#include <memory>

int main()
{
    bool isEOP = true;
    std::unique_ptr<ICommandLine> adminConsole = std::make_unique<CommandLine>();
    try
    {
        do
        {
            isEOP = adminConsole->inputCmd();/* code */
        } while (1);
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
