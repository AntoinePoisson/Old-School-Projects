/*
** EPITECH PROJECT, 2020
** ISquad
** File description:
** ISquad
*/

#ifndef __ISQUAD_HPP__
# define __ISQUAD_HPP__

# include "ISpaceMarine.hpp"

class ISquad {
    public:
        virtual ~ISquad() {}
        virtual int getCount() const = 0;
        virtual ISpaceMarine* getUnit(int) = 0;
        virtual int push(ISpaceMarine*) = 0;
};

#endif
