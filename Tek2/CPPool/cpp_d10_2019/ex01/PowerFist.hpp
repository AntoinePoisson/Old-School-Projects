/*
** EPITECH PROJECT, 2020
** PowerFist
** File description:
** PowerFist
*/

#ifndef PowerFist_hpp
#define PowerFist_hpp

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
	public:
		PowerFist();
		~PowerFist();

		void attack() const;

	protected:
	private:
};

#endif /* !PowerFist_hpp */
