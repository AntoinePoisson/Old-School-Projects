/*
** EPITECH PROJECT, 2020
** TacticalMarine
** File description:
** TacticalMarine
*/

#ifndef TacticalMarine_hpp
#define TacticalMarine_hpp

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
	public:
		TacticalMarine();
		TacticalMarine(const TacticalMarine & tacticalmarine);
		~TacticalMarine();

		ISpaceMarine * clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

	protected:
	private:
};

#endif /* !TacticalMarine_hpp */
