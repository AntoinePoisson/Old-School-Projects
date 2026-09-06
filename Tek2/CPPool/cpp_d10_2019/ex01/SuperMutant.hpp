/*
** EPITECH PROJECT, 2020
** SuperMutant
** File description:
** SuperMutant
*/

#ifndef SuperMutant_hpp
#define SuperMutant_hpp

#include "AEnemy.hpp"

class SuperMutant : public AEnemy {
	public:
		SuperMutant();
		~SuperMutant();

	void takeDamage(int damage);

	protected:
	private:
};

#endif /* !SuperMutant_hpp */
