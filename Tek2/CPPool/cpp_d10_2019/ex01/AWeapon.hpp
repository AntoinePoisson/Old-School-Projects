/*
** EPITECH PROJECT, 2020
** AWeapon
** File description:
** AWeapon
*/

#ifndef AWeapon_hpp
#define AWeapon_hpp

#include <iostream>

class AWeapon {
	public:
		AWeapon(const std::string &name, int apcost, int damage);
		virtual ~AWeapon();
		std::string const & getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;

	protected:
		std::string name;
		int apcost;
		int damage;
	private:
};

#endif /* !AWeapon_hpp */
