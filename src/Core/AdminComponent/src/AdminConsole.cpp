#include <AdminConsole.hpp>
#include <ServerManager.hpp>

#include <QTextStream>

bool Admin::AdminConsole::inputCommand()
{
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    cin >> getAdminConsole()->cmdLine;
    if(ServerManager::getServerManager()->exec(getAdminConsole()->cmdLine))
        return true;

    cout << "Such command does not exist";
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
