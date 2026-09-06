/*
** EPITECH PROJECT, 2020
** Priest
** File description:
** Mage
*/

#ifndef Priest_H
#define Priest_H

#include "Mage.hpp"


class Priest : public Mage {
	public:
		Priest(const std::string &name, int level);
		~Priest();

        int CloseAttack();
        void Heal();

	protected:
	private:
};

#endif /* !Priest_H */
