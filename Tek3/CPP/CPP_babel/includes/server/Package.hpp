/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** Package
*/

#ifndef PACKAGE_HPP_
#define PACKAGE_HPP_

#include <iostream>
#include "AsioNetwork.hpp"
#include "TransfertData.hpp"

namespace babel {

    class Package {
        public:
            explicit Package(transfertData_t *transfert);
            explicit Package(std::string data);
            virtual ~Package() = default;

            std::string get(void);
            int getOp(void) const;
            std::vector<std::string> getParameter(void) const;
            bool is_empty(void);
            void print(void);
            std::string deserialize(boost::asio::streambuf &data);

            void operator=(const Package &element);
            bool operator==(const Package &element);
            void operator+=(const Package &element);
            Package operator+(const Package &element);
            std::string operator<<(const std::string &element);

            friend std::ostream &operator<<(std::ostream &os, Package &element)
            { return os << element.get(); }
        private:
            void parceParameter(std::string &data);

            std::string _data;
            std::vector<std::string> _dataParameter;
            int _dataOP;
    };

}
#endif /* !PACKAGE_HPP_ */
