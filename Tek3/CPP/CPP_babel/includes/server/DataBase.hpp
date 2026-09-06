/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** DataBase
*/

#ifndef DATABASE_HPP_
#define DATABASE_HPP_

#include "sqlite3.h"
#include "HandleSqlite.hpp"
#include "TableElement.hpp"
#include "IDataBase.hpp"

namespace babel {

    class DataBase : public IDataBase {
        public:
            DataBase(std::string name = "./database");
            ~DataBase();

            TableUser registerNewUser(std::string &name, std::string &password, bool online);
            TableUser loginUser(std::string &name, std::string &password);
            TableUser logoutUser(int id);

            TableRelation addUserRelation(int user_id, int friend_id);
            void removeRelation(int user_id, int friend_id);
            bool isUserRelationWith(int user_id, int friend_id);
            std::vector<TableRelation> getRelationList(int user_id);
            TableUser getUser(int user_id);
        private:
            std::string _nameDb;
            babel::HandleSqlite _sqlite;
            sqlite3 *_db;
    };

}

#endif /* !DATABASE_HPP_ */
