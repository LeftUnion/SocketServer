#include <AdminConsole.hpp>

#include <QString>
#include <QTextStream>

int main()
{
    while (true)
    {
        Admin::AdminConsole::getAdminConsole()->inputCommand();
    }

    return 0;
}
