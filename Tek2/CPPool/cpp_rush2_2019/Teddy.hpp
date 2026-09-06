/*
** EPITECH PROJECT, 2020
** Teddy.hpp
** File description:
** Rush2
*/

#ifndef TEDDY_HPP
#define TEDDY_HPP

#include "Object.hpp"
#include "Toy.hpp"

class Teddy : public Toy {
    public:
        Teddy(std::string str);
        ~Teddy();
        void isTaken() const;
};

#endif