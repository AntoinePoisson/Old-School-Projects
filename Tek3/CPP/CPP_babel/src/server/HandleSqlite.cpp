/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** HandleSqlite
*/

#include "HandleSqlite.hpp"

    //* Public User
sqlite3 *babel::HandleSqlite::openDataBase(std::string &name, sqlite3 *db)
{
    std::string sqlUsers("CREATE TABLE IF NOT EXISTS Users ("\
        "id  INTEGER  PRIMARY  KEY   AUTOINCREMENT  NOT NULL,"\
        "name                  TEXT  UNIQUE         NOT NULL,"\
        "password              TEXT                 NOT NULL,"\
        "online                BOOL                 NOT NULL);");
    std::string sqlRelation("CREATE TABLE IF NOT EXISTS RelationUsers ("\
        "user_id    INT  NOT NULL,"\
        "friend_id  INT  NOT NULL);");
    std::string tmp;
    char *sqlError = nullptr;

    if (sqlite3_open(name.c_str(), &db))
        throw FataleErrorSql("[SQL-Fatale]", "Can't open DataBase (" + std::string(sqlite3_errmsg(db)) + ")");
    if (sqlite3_exec(db, sqlUsers.c_str(), nullptr, nullptr, &sqlError) != SQLITE_OK) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw FataleErrorSql("[SQL-Fatale]", "Can't Create Users Table (" + tmp + ")");
    }
    if (sqlite3_exec(db, sqlRelation.c_str(), nullptr, nullptr, &sqlError) != SQLITE_OK) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw FataleErrorSql("[SQL-Fatale]", "Can't Create RelationUsers Table (" + tmp + ")");
    }
    std::cout << "[DataBase]: Open Success." << std::endl;
    return (db);
}

sqlite3 *babel::HandleSqlite::closeDataBase(sqlite3 *db)
{
    sqlite3_close(db);
    return (db);
}

babel::TableUser babel::HandleSqlite::addUser(sqlite3 *db, std::string name, std::string password, bool online)
{
    char *sqlError = nullptr;
    std::string tmp;
    std::string sql("INSERT INTO Users "\
        "(name, password, online) VALUES "\
        "('" + name + "','" + password + "', " + (online ? "1" : "0") + ");");
    std::cout << ("[Query]: SQL INSERT \"" + sql + "\".") << std::endl;

    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &sqlError) != SQLITE_OK) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw ErrorSql("[SQL]", "Failure SQL INSERT (" + tmp + ")");
    }
    return (getUser(db, -1, name));
}

babel::TableUser babel::HandleSqlite::getUser(sqlite3 *db, int id, std::string name)
{
    char *sqlError = nullptr;
    std::string tmp;
    std::string sql("SELECT * FROM Users WHERE ");
    std::shared_ptr<TableUser> store = std::make_unique<TableUser>();

    if (id == -1 && name.empty())
        return (babel::TableUser());
    if (id != -1) {
        sql += "id = " + std::to_string(id) + " ";
        if (!name.empty())
            sql += " AND name = '" + name + "'";
    } else if (!name.empty()) {
        sql += "name = '" + name + "'";
    }
    sql += ";";
    std::cout << ("[Query]: SQL Get \"" + sql + "\".") << std::endl;
    if (sqlite3_exec(db, sql.c_str(), callbackGetUser, (void *)store.get(), &sqlError)) { //! a faire
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw ErrorSql("[SQL]", "Failure SQL GET user (" + tmp + ")");
    }
    return (babel::TableUser(store.get()));
}

babel::TableUser babel::HandleSqlite::updateUser(sqlite3 *db, int id, std::string name, std::string password, int online)
{
    char *sqlError = nullptr;
    bool oneParameter = false;
    std::string tmp;
    std::string sql("UPDATE Users SET ");

    if ((id == -1) || (name.empty() && password.empty() && online <= -1))
        return (babel::TableUser());
    if (!name.empty()) {
        sql += "name = '" + name + "' ";
        oneParameter = true;
    }
    if (!password.empty()) {
        if (oneParameter)
            sql += " , ";
        sql += "password = '" + password + "' ";
        oneParameter = true;
    }
    if (online >= 0) {
        if (oneParameter)
            sql += " , ";
        sql += "online = " + std::string((online == 0 ? "0" : "1")) + " ";
        oneParameter = true;
    }
    sql += " WHERE id = " + std::to_string(id) + ";";
    if (oneParameter == false)
        return (babel::TableUser());
    std::cout << ("[Query]: SQL Update \"" + sql + "\".") << std::endl;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &sqlError) != SQLITE_OK) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw ErrorSql("[SQL]", "Failure SQL Update user (" + tmp + ")");
    }
    return (getUser(db, id));
}

void babel::HandleSqlite::printUserTable(sqlite3 *db)
{
    char *sqlError = nullptr;
    std::string tmp;
    std::string sql("SELECT * FROM Users;");

    std::cout << ("[Query]: SQL Print \"" + sql + "\".") << std::endl;
    std::cout << std::endl << "--------------------------------------------------------" << std::endl;
    std::cout << "Id\t| Name\t\t| Password\t\t| Online" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    if (sqlite3_exec(db, sql.c_str(), callbackPrintUsers, nullptr, &sqlError)) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw ErrorSql("[SQL]", "Failure SQL Print users (" + tmp + ")");
    }
    std::cout << std::endl;
}




    //* CallBack User
int babel::HandleSqlite::callbackGetUser(void *takerData, int ac, char **av, char **_)
{
    TableUser *store = (TableUser *)takerData;

    if (_ && ac) {
    }
    std::cout << "[CallBack] GetUser" << std::endl;
    store->setId(std::stoi(av[0]));
    store->setName(std::string(av[1]));
    store->setPassword(std::string(av[2]));
    store->setOnline(strcmp(av[3], "0") ? true : false);
    return (0);
}

int babel::HandleSqlite::callbackPrintUsers(void *_, int ac, char **av, char **cols)
{
    int count = 0;

    if (_ && cols) {
    }
    for (int i = 0; i < ac; i++, count++) {
        switch (count) {
            case 0: std::cout << (av[i] ? av[i] : "NONE") << "\t| ";
                break;
            case 1: std::cout << (av[i] ? av[i] : "NULL") << "\t\t | ";
                break;
            case 2: std::cout << (av[i] ? av[i] : "NULL") << "\t | ";
                break;
            case 3: std::cout << (av[i] ? av[i] : "NONE") << std::endl;
                count = -1;
                break;
            default:
                count = -1;
                std::cout << std::endl;
                break;
        }
    }
    return (0);
}



    //* Public Relation
babel::TableRelation babel::HandleSqlite::addRelation(sqlite3 *db, int user_id, int friend_id)
{
    char *sqlError = nullptr;
    std::string tmp;
    std::string sql("INSERT INTO RelationUsers "\
        "(user_id, friend_id) VALUES "\
        "(" + std::to_string(user_id) + ", " + std::to_string(friend_id) + ");");

    if (user_id == friend_id)
        return (TableRelation());
    if (getNotOrderRelation(db, user_id, friend_id).isEmpty() == false) {
        std::cout << ("[Query]: Adding Relation Already Existing.") << std::endl;
        return (TableRelation());
    }
    std::cout << ("[Query]: SQL INSERT \"" + sql + "\".") << std::endl;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &sqlError) != SQLITE_OK) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw ErrorSql("[SQL]", "Failure SQL INSERT (" + tmp + ")");
    }
    return (getRelation(db, user_id, friend_id));
}

babel::TableRelation babel::HandleSqlite::getRelation(sqlite3 *db, int user_id, int friend_id)
{
    char *sqlError = nullptr;
    bool find = false;
    std::string tmp;
    std::string sql("SELECT * FROM RelationUsers WHERE ");

    if (user_id == friend_id)
        return (TableRelation());
    sql += "user_id = " + std::to_string(user_id);
    sql += " AND friend_id = " + std::to_string(friend_id) + ";";
    std::cout << ("[Query]: SQL GET \"" + sql + "\".") << std::endl;
    if (sqlite3_exec(db, sql.c_str(), callbackGetRelation, (void *)&find, &sqlError)) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw ErrorSql("[SQL]", "Failure SQL GET (" + tmp + ")");
    }
    if (find == true) {
        return (TableRelation(user_id, friend_id));
    }
    return (TableRelation());
}

std::vector<babel::TableRelation> babel::HandleSqlite::getAllRelation(sqlite3 *db, int id)
{
    std::shared_ptr<std::vector<babel::TableRelation>> getData = std::make_shared<std::vector<babel::TableRelation>>();
    char *sqlError = nullptr;
    std::string tmp;
    std::string sql("SELECT * FROM RelationUsers WHERE ");

    sql += "user_id = " + std::to_string(id);
    sql += " OR friend_id = " + std::to_string(id) + ";";
    std::cout << ("[Query]: SQL GET \"" + sql + "\".") << std::endl;
    if (sqlite3_exec(db, sql.c_str(), callbackGetAllRelation, (void *)(&getData.get()[0]), &sqlError)) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw ErrorSql("[SQL]", "Failure SQL GET (" + tmp + ")");
    }
    std::vector<TableRelation> result;
    for (auto element : *getData) {
        if (element.getFriendId() == id) {
            result.push_back(TableRelation(element.getFriendId(), element.getUserId()));
        } else {
            result.push_back(TableRelation(element.getUserId(), element.getFriendId()));
        }
    }
    return (result);
}

babel::TableRelation babel::HandleSqlite::getNotOrderRelation(sqlite3 *db, int id, int _id)
{
    char *sqlError = nullptr;
    bool find = false;
    std::string tmp;
    std::string sql("SELECT * FROM RelationUsers WHERE ");

    if (id == _id)
        return (TableRelation());
    sql += "user_id = " + std::to_string(id);
    sql += " AND friend_id = " + std::to_string(_id);
    sql += " OR user_id = " + std::to_string(_id);
    sql += " AND friend_id = " + std::to_string(id) + ";";
    std::cout << ("[Query]: SQL GET \"" + sql + "\".") << std::endl;
    if (sqlite3_exec(db, sql.c_str(), callbackGetRelation, (void *)&find, &sqlError)) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw ErrorSql("[SQL]", "Failure SQL GET (" + tmp + ")");
    }
    if (find == true) {
        return (TableRelation(id, _id));
    }
    return (TableRelation());
}

void babel::HandleSqlite::removeRelation(sqlite3 *db, int user_id, int friend_id)
{
    char *sqlError = nullptr;
    std::string tmp;
    std::string sql("DELETE FROM RelationUsers WHERE ");

    if (user_id == friend_id)
        return;
    sql += " user_id = " + std::to_string(user_id);
    sql += " AND friend_id = " + std::to_string(friend_id);
    sql += " OR user_id = " + std::to_string(friend_id);
    sql += " AND friend_id = " + std::to_string(user_id) + ";";
    std::cout << ("[Query]: SQL REMOVE \"" + sql + "\".") << std::endl;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &sqlError) != SQLITE_OK) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw ErrorSql("[SQL]", "Failure SQL REMOVE (" + tmp + ")");
    }
}

void babel::HandleSqlite::printRelationTable(sqlite3 *db)
{
    char *sqlError = nullptr;
    std::string tmp;
    std::string sql("SELECT * FROM RelationUsers;");

    std::cout << ("[Query]: SQL Print \"" + sql + "\".") << std::endl;
    std::cout << std::endl << "-------------------" << std::endl;
    std::cout << "User_Id | Friend_Id" << std::endl;
    std::cout << "-------------------" << std::endl;
    if (sqlite3_exec(db, sql.c_str(), callbackPrintRelation, nullptr, &sqlError)) {
        tmp = std::string(sqlError);
        sqlite3_free(sqlError);
        throw ErrorSql("[SQL]", "Failure SQL Print RelationUsers (" + tmp + ")");
    }
    std::cout << std::endl;
}





    //* CallBack User
int babel::HandleSqlite::callbackGetRelation(void *found, int ac, char **av, char **_)
{
    if (_ && ac && av) {
    }
    (*((bool *)found)) = true;
    std::cout << "[CallBack] GetRelation" << std::endl;
    return (0);
}

int babel::HandleSqlite::callbackGetAllRelation(void *store, int ac, char **av, char **_)
{
    std::vector<babel::TableRelation> *result = (std::vector<babel::TableRelation> *)store;

    if (ac && _) {
    }
    result->push_back(TableRelation(std::atoi(av[0]), std::atoi(av[1])));
    return (0);
}

int babel::HandleSqlite::callbackPrintRelation(void *_, int ac, char **av, char **cols)
{
    bool count = true;

    if (_ && cols) {
    }
    for (int i = 0; i < ac; i++, count = !count) {
        if (count) {
            std::cout << (av[i] ? av[i] : "NONE") << " | ";
        } else {
            std::cout << (av[i] ? av[i] : "NONE") << std::endl;
        }
    }
    return (0);
}
