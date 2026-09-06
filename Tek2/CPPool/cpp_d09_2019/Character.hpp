/*
** EPITECH PROJECT, 2020
** Character
** File description:
** Character
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

enum AttackRange {
	_CLOSE,
	_RANGE
};

class Character {
    public:
        static const AttackRange CLOSE = _CLOSE;
        static const AttackRange RANGE = _RANGE;

    	AttackRange Range;

        Character(const std::string &name, int level);
        ~Character();

        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getStrength() const;    
        int getPower() const;
        int getStamina() const;
        int getSpirit() const;
        int getAgility() const;
        std::string getRace() const;
        std::string getClass() const;

        int CloseAttack();
        void Heal();
        int RangeAttack();
        void RestorePower();
        void TakeDamage(int damage);

    protected:
        std::string _name;
        std::string _race;
        std::string _class;
        int _intelligence;
        int _level;
        int _strength;
        int _pv;
        int _power;
        int _stamina;
        int _spirit;
        int _agility;
};

#endif /* !CHARACTER_H */
