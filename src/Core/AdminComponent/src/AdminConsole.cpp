#include <AdminConsole.hpp>
#include <ServerManager.hpp>

bool Admin::AdminConsole::inputCommand()
{

    Admin::cin >> getAdminConsole()->cmdLine;
    if(ServerManager::getServerManager()->exec(getAdminConsole()->cmdLine))
        return true;

    Admin::cout << "Such command does not exist";
    return false;
}

Admin::AdminConsole *Admin::AdminConsole::getAdminConsole()
{
    if(AdminConsole::insAdminConsole == nullptr)
    {
        AdminConsole::insAdminConsole = new AdminConsole();
    }
    return AdminConsole::insAdminConsole;
}
