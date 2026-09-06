/*
** EPITECH PROJECT, 2020
** ISpaceMarine
** File description:
** ISpaceMarine
*/

#ifndef __ISPACEMARINE_HPP__
# define __ISPACEMARINE_HPP__

class ISpaceMarine {
    public:
        virtual ~ISpaceMarine() {}
        virtual ISpaceMarine* clone() const = 0;
        virtual void battleCry() const = 0;
        virtual void rangedAttack() const = 0;
        virtual void meleeAttack() const = 0;
};

#endif

