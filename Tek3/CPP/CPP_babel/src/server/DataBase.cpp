/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** DataBase
*/

#include "DataBase.hpp"

babel::DataBase::DataBase(std::string name)
: _nameDb(name + ".db"), _db(nullptr)
{
    _db = babel::HandleSqlite::openDataBase(_nameDb, _db);
}

babel::DataBase::~DataBase()
{
    _db = babel::HandleSqlite::closeDataBase(_db);
}

babel::TableUser babel::DataBase::registerNewUser(std::string &name, std::string &password, bool online)
{
    TableUser result;

    try {
        result = _sqlite.addUser(_db, name, password, online);
    } catch(ErrorSql &user) {
        user.print();
    }
    return (result);
}

babel::TableUser babel::DataBase::loginUser(std::string &name, std::string &password)
{
    TableUser result;
    TableUser empty;

    try {
        result = _sqlite.getUser(_db, -1, name);
    } catch(ErrorSql &user) {
        user.print();
        return (empty);
    }
    if (result.getName() == name && result.getPassword() == password && result.getOnline() == false) {
        result.setOnline(true);
        try {
            _sqlite.updateUser(_db, result.getId(), "", "", 1);
        } catch(ErrorSql &user) {
            user.print();
            return (empty);
        }
        return (result);
    }
    return (empty);
}

babel::TableUser babel::DataBase::logoutUser(int id)
{
    TableUser result;
    TableUser empty;

    try {
        result = _sqlite.getUser(_db, id);
    } catch(ErrorSql &user) {
        user.print();
        return (empty);
    }
    result.setOnline(false);
    try {
        _sqlite.updateUser(_db, result.getId(), "", "", 0);
    } catch(ErrorSql &user) {
        user.print();
        return (empty);
    }
    return (result);
}

babel::TableRelation babel::DataBase::addUserRelation(int user_id, int friend_id)
{
    TableRelation result;

    try {
        result = _sqlite.addRelation(_db, user_id, friend_id);
    } catch(ErrorSql &relation) {
        relation.print();
    }
    return (result);
}

void babel::DataBase::removeRelation(int user_id, int friend_id)
{
    try {
        _sqlite.removeRelation(_db, user_id, friend_id);
    } catch(ErrorSql &relation) {
        relation.print();
    }
}

bool babel::DataBase::isUserRelationWith(int user_id, int friend_id)
{
    TableRelation result;

    try {
        result = _sqlite.getNotOrderRelation(_db, user_id, friend_id);
    } catch(ErrorSql &relation) {
        relation.print();
        return (false);
    }
    if (result.isEmpty())
        return (false);
    return (true);
}

std::vector<babel::TableRelation> babel::DataBase::getRelationList(int user_id)
{
    std::vector<TableRelation> result;

    try {
        result = _sqlite.getAllRelation(_db, user_id);
    } catch(ErrorSql &relation) {
        relation.print();
        return (result);
    }
    return(result);
}

babel::TableUser babel::DataBase::getUser(int user_id)
{
    TableUser result;

    try {
        result = _sqlite.getUser(_db, user_id);
    } catch(ErrorSql &relation) {
        relation.print();
        return (result);
    }
    return(result);
}
