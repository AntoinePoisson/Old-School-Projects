/*
** EPITECH PROJECT, 2020
** Paladin
** File description:
** Paladin
*/

#ifndef Paladin_H
#define Paladin_H

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : public Warrior, public Priest {
	public:
		Paladin(const std::string &name, int level);
		~Paladin();
        using Warrior::CloseAttack;
        using Priest::Heal;
        using Warrior::RestorePower;
        using Priest::RangeAttack;
        int Intercept();

	protected:
	private:
};

#endif /* !Paladin_H */
