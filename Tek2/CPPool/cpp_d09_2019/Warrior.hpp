/*
** EPITECH PROJECT, 2020
** Warrior
** File description:
** Warrior
*/

#ifndef Warrior_H
#define Warrior_H

#include "Character.hpp"

class Warrior : virtual public Character {
    public:
        Warrior(const std::string &name, int level);
        ~Warrior();

        std::string getweaponName();
        std::string getWeaponname();
        std::string getWeaponName();

        virtual int CloseAttack();
        virtual int RangeAttack();

    protected:
        std::string _weaponName;
};

#endif /* !Warrior_H */
