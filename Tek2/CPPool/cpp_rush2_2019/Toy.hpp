/*
** EPITECH PROJECT, 2020
** Toh.hpp
** File description:
** Rush2
*/

#ifndef TOY_HPP
#define TOY_HPP

#include "Object.hpp"

class Toy : public Object {
    public:
        Toy(std::string str);
        ~Toy();
        virtual void isTaken() const = 0;
    private:
};

#endif