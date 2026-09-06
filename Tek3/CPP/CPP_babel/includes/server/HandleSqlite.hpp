/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** HandleSqlite
*/

#ifndef HANDLESQLITE_HPP_
#define HANDLESQLITE_HPP_

#include <iostream>
#include "sqlite3.h"
#include "FataleErrorSql.hpp"
#include "ErrorSql.hpp"
#include "TableElement.hpp"

namespace babel {

    class HandleSqlite {
        public:
            virtual ~HandleSqlite() = default;

            static sqlite3 *openDataBase(std::string &name, sqlite3 *db);
            static sqlite3 *closeDataBase(sqlite3 *db);

            static TableUser addUser(sqlite3 *db, std::string name, std::string password, bool online = false);
            static TableUser getUser(sqlite3 *db, int id = -1, std::string name = "");
            static TableUser updateUser(sqlite3 *db, int id = -1, std::string name = "", std::string password = "", int online = -1);
            static void printUserTable(sqlite3 *db);
            static int callbackGetUser(void *takerData, int ac, char **av, char **_);
            static int callbackPrintUsers(void *_, int ac, char **av, char **cols);

            static TableRelation addRelation(sqlite3 *db, int user_id, int friend_id);
            static TableRelation getRelation(sqlite3 *db, int user_id, int friend_id);
            static std::vector<TableRelation> getAllRelation(sqlite3 *db, int id);
            static TableRelation getNotOrderRelation(sqlite3 *db, int id, int _id);
            static void removeRelation(sqlite3 *db, int user_id, int friend_id);
            static void printRelationTable(sqlite3 *db);
            static int callbackGetRelation(void *found, int ac, char **av, char **_);
            static int callbackGetAllRelation(void *store, int ac, char **av, char **_);
            static int callbackPrintRelation(void *_, int ac, char **av, char **cols);
    };
}

#endif /* !HANDLESQLITE_HPP_ */
