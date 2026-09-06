/*
** EPITECH PROJECT, 2020
** Peon
** File description:
** Peon
*/

#ifndef Peon_H
#define Peon_H

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim {
	public:
		explicit Peon(std::string name);
		~Peon();

		void getPolymorphed() const;

	protected:
	private:
};

std::ostream & operator<<(std::ostream & os, Peon & peon);

#endif /* !PeonH */
