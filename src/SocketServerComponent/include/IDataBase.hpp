#ifndef IDATABASE_HPP
#define IDATABASE_HPP

#include <string>


class IDataBase
{

public:
    IDataBase() = default;
    ~IDataBase() = default;

    IDataBase(const IDataBase&) = delete;
    IDdataBase& operator=(const IDataBase&) = delete;
    IDataBase(const IDataBase&&) = delete;
    IDdataBase& operator=(const IDataBase&&) = delete;

    //TODO EXCEPTIONS
protected:
    virtual bool createDB(const std::string&& DBMS) = 0;
    virtual bool signInDB(std::string dBName, std::string userName, std::string password) = 0;
    virtual bool isOpen() = 0;
    virtual bool insert(const std::string& table, std::string&& data) = 0;
    virtual bool select(const std::string& table, std::string&& request) = 0;



}
    DataBase::DataBase(std::string DBMS, std::string dataBase, std::string table)
{
    mDataBase.reset(new QSqlDatabase);
    mDataBase->addDatabase("QPSQL");
    mDataBase->setDatabaseName("left");
    mDataBase->setUserName("left");
    mDataBase->setPassword("");
    mDataBase->commit();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("bigblue");
    db.setDatabaseName("flightdb");
    db.setUserName("acarlson");
    db.setPassword("1uTbSbAs");
    bool ok = db.open();
}
};

#endif // IDATABASE_HPP
