/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** TableElement
*/

#include "TableElement.hpp"

    //* Public
babel::TableUser::TableUser(int id, std::string name, std::string password, bool online)
: _id(id), _name(name), _password(password), _online(online)
{}

babel::TableUser::TableUser(babel::TableUser *ptr)
: _id(ptr->getId()), _name(ptr->getName()), _password(ptr->getPassword()), _online(ptr->getOnline())
{}

int babel::TableUser::getId(void) const
{
    return (_id);
}

void babel::TableUser::setId(int id)
{
    _id = id;
    if (id < 0)
        _id = -1;
}

std::string babel::TableUser::getName(void) const
{
    return (_name);
}

void babel::TableUser::setName(std::string name)
{
    _name = name;
}

std::string babel::TableUser::getPassword(void) const
{
    return (_password);
}

void babel::TableUser::setPassword(std::string password)
{
    _password = password;
}

bool babel::TableUser::getOnline(void) const
{
    return (_online);
}

void babel::TableUser::setOnline(bool online)
{
    _online = online;
}

bool babel::TableUser::isEmpty(void) const
{
    return ((_id == -1 && _name.empty() && _password.empty()) ? true : false);
}

void babel::TableUser::clear(void)
{
    _id = -1;
    _name.clear();
    _password.clear();
    _online = false;
}

void babel::TableUser::setListRelation(std::vector<babel::TableRelation> &list)
{
    _relationUser.clear();
    _relationUser = list;
}

std::vector<babel::TableRelation> babel::TableUser::getListRelation(void) const
{
    return (_relationUser);
}


void babel::TableUser::operator=(const TableUser &element)
{
    _id = element._id;
    _name = element._name;
    _password = element._password;
    _online = element._online;
    _relationUser.clear();
    _relationUser = element.getListRelation();
}



    //* Private
babel::TableRelation::TableRelation(int user_id, int friend_id)
: _userId(user_id), _friendId(friend_id)
{}

babel::TableRelation::TableRelation(babel::TableRelation *ptr)
: _userId(ptr->getUserId()), _friendId(ptr->getFriendId())
{}


int babel::TableRelation::getUserId(void) const
{
    return (_userId);
}

void babel::TableRelation::setUserId(int user_id)
{
    _userId = user_id;
    if (user_id < 0)
        _userId = -1;
}

int babel::TableRelation::getFriendId(void) const
{
    return (_friendId);
}

void babel::TableRelation::setFriendId(int friend_id)
{
    _friendId = friend_id;
    if (friend_id < 0)
        _friendId = -1;
}

bool babel::TableRelation::isEmpty(void) const
{
    return ((_userId == -1 && _friendId == -1) ? true : false);
}

void babel::TableRelation::clear(void)
{
    _friendId = -1;
    _userId = -1;
}

void babel::TableRelation::operator=(const TableRelation &element)
{
    _userId = element._userId;
    _friendId = element._friendId;
}