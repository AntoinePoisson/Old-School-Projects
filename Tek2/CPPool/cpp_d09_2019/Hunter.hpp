/*
** EPITECH PROJECT, 2020
** Hunter
** File description:
** Hunter
*/

#ifndef Hunter_H
#define Hunter_H

#include "Warrior.hpp"

class Hunter : public Warrior {
	public:
		Hunter(const std::string &name, int level);
		~Hunter();

    int RangeAttack();
    void RestorePower();

	protected:
	private:
};

#endif /* !Hunter_H */
