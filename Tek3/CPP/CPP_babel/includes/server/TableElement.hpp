/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** TableElement
*/

#ifndef TABLEELEMENT_HPP_
#define TABLEELEMENT_HPP_

#include <iostream>
#include <vector>

namespace babel {

    class TableRelation;

    class TableUser {
        public:
            TableUser(int id = -1, std::string name = "", std::string password = "", bool online = false);
            explicit TableUser(TableUser *ptr);
            virtual ~TableUser() = default;

            int getId(void) const;
            void setId(int id);

            std::string getName(void) const;
            void setName(std::string name);

            std::string getPassword(void) const;
            void setPassword(std::string password);

            bool getOnline(void) const;
            void setOnline(bool online);

            bool isEmpty(void) const;
            void clear(void);

            std::vector<babel::TableRelation> getListRelation(void) const;
            void setListRelation(std::vector<babel::TableRelation> &list);

            void operator=(const TableUser &element);
            friend std::ostream &operator<<(std::ostream &os, TableUser &element)
            { return os << "Id: " << element.getId() << " | Name: '" << element.getName() << "' | Password: '" << element.getPassword() << "' | Online: " << element.getOnline(); }
        private:
            int _id;
            std::string _name;
            std::string _password;
            bool _online;
            std::vector<TableRelation> _relationUser;

    };

    class TableRelation {
        public:
            TableRelation(int user_id = -1, int friend_id = -1);
            explicit TableRelation(TableRelation *ptr);
            virtual ~TableRelation() = default;

            int getUserId(void) const;
            void setUserId(int user_id);

            int getFriendId(void) const;
            void setFriendId(int friend_id);

            bool isEmpty(void) const;
            void clear(void);

            void operator=(const TableRelation &element);
            friend std::ostream &operator<<(std::ostream &os, TableRelation &element)
            { return os << "User Id: " << element.getUserId() << " | Friend Id: " << element.getFriendId(); }
        private:
            int _userId;
            int _friendId;
    };

}

#endif /* !TABLEELEMENT_HPP_ */
