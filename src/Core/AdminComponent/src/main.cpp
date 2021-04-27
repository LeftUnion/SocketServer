#include <AdminConsole.hpp>

#include <QString>
#include <QTextStream>

int main()
{
    while (true)
    {
        bool isRightCmd;
        do
        {
            isRightCmd = Admin::AdminConsole::getAdminConsole()->inputCommand();

        } while(!isRightCmd);
    }

    return 0;
}
