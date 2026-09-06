/*
** EPITECH PROJECT, 2020
** AEnemy
** File description:
** AEnemy
*/

#ifndef AEnemy_hpp
#define AEnemy_hpp

#include <iostream>

class AEnemy {
	public:
		AEnemy(int hp, const std::string & type);
		virtual ~AEnemy();

		virtual void takeDamage(int damage);
		std::string const & getType() const;
		int getHP() const;

	protected:
	private:
		int hp;
		std::string type;
};

#endif /* !AEnemy_hpp */
