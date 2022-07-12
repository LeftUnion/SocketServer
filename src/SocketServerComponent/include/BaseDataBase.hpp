#ifndef BASEDATABASE_HPP
#define BASEDATABASE_HPP

#include <QSqlDatabase>
#include <QSqlQuery>

#include <iostream>
#include <string>

class BaseDataBase
{
protected:
    std::string dataBaseType;

private:
    static const std::string Q_CREATE_TABLE;
    static const std::string Q_ADD_USER;
    //TODO HASH FUNC + PASSWORD
    QSqlDatabase dataBase;
    bool initDb();

public:
    BaseDataBase(std::string&& type);
    ~BaseDataBase() = default;

    BaseDataBase(const BaseDataBase&) = delete;
    BaseDataBase& operator=(const BaseDataBase&) = delete;
    BaseDataBase(const BaseDataBase&&) = delete;
    BaseDataBase& operator=(const BaseDataBase&&) = delete;

    std::exception createUsersTable() noexcept;
    std::exception addUser(std::string userName, std::string pwHash); //TODO HASH

};
std::string input() noexcept;


#endif // BASEDATABASE_HPP
