/*
** EPITECH PROJECT, 2020
** Mage
** File description:
** Mage
*/

#ifndef Mage_H
#define Mage_H

#include "Character.hpp"

class Mage : virtual public Character {
	public:
		Mage(const std::string &name, int level);
		~Mage();

        int CloseAttack();
        int RangeAttack();
        void RestorePower();

	protected:
	private:
};

#endif /* !Mage_H */
