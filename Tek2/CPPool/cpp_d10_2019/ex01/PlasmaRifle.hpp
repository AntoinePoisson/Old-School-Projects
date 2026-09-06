/*
** EPITECH PROJECT, 2020
** PlasmaRifle
** File description:
** PlasmaRifle
*/

#ifndef PlasmaRifle_hpp
#define PlasmaRifle_hpp

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		~PlasmaRifle();

		void attack() const;

	protected:
	private:
};

#endif /* !PlasmaRifle_hpp */
