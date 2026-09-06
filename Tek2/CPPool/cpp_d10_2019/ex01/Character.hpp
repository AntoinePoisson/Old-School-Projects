/*
** EPITECH PROJECT, 2020
** Character
** File description:
** Character
*/

#ifndef Character_hpp
#define Character_hpp

#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
	public:
		Character(const std::string & name);
		// [...]
		~Character();
		void recoverAP();
		void equip(AWeapon *weapon);
		void attack(AEnemy *enemy);
		std::string const & getName() const;
		int getAp() const;
		AWeapon *getWeapon() const;

	protected:
	private:
		std::string name;
		int ap;
		AWeapon *weapon;
};

std::ostream & operator<<(std::ostream & os ,const Character & character);


#endif /* !Character_hpp */
