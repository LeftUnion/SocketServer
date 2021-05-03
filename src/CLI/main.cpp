#include <AdminConsole.hpp>

int main()
{
    while (true)
        Admin::AdminConsole::getAdminConsole()->inputCommand();

    return 0;
}
