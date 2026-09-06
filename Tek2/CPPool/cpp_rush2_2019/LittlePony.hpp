/*
** EPITECH PROJECT, 2020
** LittlePony
** File description:
** Rush2
*/

#ifndef LITTLEPONY_HPP
#define LITTLEPONY_HPP

#include "Object.hpp"
#include "Toy.hpp"

class LittlePony : public Toy
{
    public:
        LittlePony(std::string str);
        ~LittlePony();
        void isTaken() const;
};

#endif