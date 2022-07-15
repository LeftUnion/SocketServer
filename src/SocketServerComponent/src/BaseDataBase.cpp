#include <BaseDataBase.hpp>

const std::string BaseDataBase::Q_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS server.Users(\
                                                        user_id SERIAL PRIMARY KEY,\
                                                        login TEXT UNIQUE,\
                                                        password VARCHAR(128) NOT NULL);";

const std::string BaseDataBase::Q_ADD_USER = "INSERT INTO server.users(login, password) VALUES ";
const std::string BaseDataBase::Q_CHECK_USER = "SELECT login, password FROM server.users WHERE";

bool BaseDataBase::initDb()
{
      dataBase = QSqlDatabase::addDatabase(this->dataBaseType.c_str());
      dataBase.setHostName("localhost");
      dataBase.setDatabaseName("left");
      dataBase.setUserName("");
      dataBase.setPassword(""); //TODO CERTIFICATE
      return dataBase.open();
}

BaseDataBase::BaseDataBase(std::string&& type)
{
    this->dataBaseType = type;
    initDb();
    createUsersTable();
}

std::exception BaseDataBase::createUsersTable() noexcept
{
    dataBase.exec(Q_CREATE_TABLE.c_str());
    dataBase.commit();
}

std::exception BaseDataBase::addUser(std::string userName, std::string pwHash)
{
    std::string Q_INSERT_USER = Q_ADD_USER + "('" + userName + "', '" + pwHash + "');";
    dataBase.exec(Q_INSERT_USER.c_str());
    dataBase.commit();
    //TODO return(User exist, Not allow)
}

bool BaseDataBase::checkUserExists(std::string userName, std::string pwHash)
{
    std::string Q_CHECK_ISUSER = Q_CHECK_USER + " login = " + "'" + userName + "' " + "AND" + " password = " + "'" + pwHash + "';";
    QSqlQuery isExist = dataBase.exec(Q_CHECK_ISUSER.c_str());

    return  isExist.isSelect();
}



std::string input() noexcept
{
    std::string some;
    std::cin >> some;
    return some;
}
