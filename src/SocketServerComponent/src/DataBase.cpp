#include <DataBase.hpp>

DataBase::DataBase(std::string DBMS, std::string dataBase, std::string table)
{
    mDataBase.reset(new QSqlDatabase);
    mDataBase->addDatabase("QPSQL");
    mDataBase->setDatabaseName("left");
    mDataBase->setUserName("left");
    mDataBase->setPassword("");
    mDataBase->commit();
}

//bool DataBase::isUserExists(const std::string &login) const
//{
//   TODO  mDataBase exec("SELECT login FROM serverusers WHERE login = 'lox'");
//}
