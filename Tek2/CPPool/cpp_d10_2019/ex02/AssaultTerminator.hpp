/*
** EPITECH PROJECT, 2020
** AssaultTerminator
** File description:
** AssaultTerminator
*/

#ifndef AssaultTerminator_hpp
#define AssaultTerminator_hpp

#include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
	public:
		AssaultTerminator();
		AssaultTerminator(const AssaultTerminator & assaultterminator);
		~AssaultTerminator();

		ISpaceMarine * clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

	protected:
	private:
};

#endif /* !AssaultTerminator_hpp */
