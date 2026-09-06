/*
** EPITECH PROJECT, 2019
** CCP_plazza_2019
** File description:
** Encrypt.hpp
*/

#ifndef ENCRYPT_HPP
#define ENCRYPT_HPP

#include <string>

namespace Plazza {

    class Encrypt {
        public:
            Encrypt(std::string message);
            virtual ~Encrypt() = default;

            std::string pack();
            std::string unpack();

        private:
            std::string mess;
            char c;
    };

}

#endif