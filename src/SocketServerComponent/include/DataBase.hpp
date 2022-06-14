#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QSqlDatabase>

#include <memory>
#include <string.h>

class DataBase
{
    std::shared_ptr<QSqlDatabase> mDataBase;

public:
    DataBase(std::string DBMS, std::string dataBase, std::string table);
    ~DataBase();
    bool isUserExists(const std::string& login) const;
    void addNewUser(const std::string& login, const std::string& password) const;

private:

};

#endif // DATABASE_HPP

