/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** IDataBase
*/

#ifndef IDATABASE_HPP_
#define IDATABASE_HPP_

#include "TableElement.hpp"

namespace babel {

    class IDataBase {
        public:
            virtual ~IDataBase() = default;

            virtual TableUser registerNewUser(std::string &name, std::string &password, bool online) = 0;
            virtual TableUser loginUser(std::string &name, std::string &password) = 0;
            virtual TableUser logoutUser(int id) = 0;
            virtual TableRelation addUserRelation(int user_id, int friend_id) = 0;
            virtual void removeRelation(int user_id, int friend_id) = 0;
            virtual bool isUserRelationWith(int user_id, int friend_id) = 0;
            virtual std::vector<TableRelation> getRelationList(int user_id) = 0;
            virtual TableUser getUser(int user_id) = 0;
    };

}

#endif /* !IDATABASE_HPP_ */
