/*
** EPITECH PROJECT, 2020
** Sorcerer
** File description:
** Sorcerer
*/

#ifndef Sorcerer_H
#define Sorcerer_H

#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {
	public:
		explicit Sorcerer(std::string name, std::string title);
		~Sorcerer();

        std::string getName() const;
        std::string getTitle() const;

        void polymorph(const Victim &victim) const;
        void polymorph(const Peon &peon) const;

	protected:
	private:
        std::string _name;
        std::string _title;
};

std::ostream & operator<<(std::ostream & os, Sorcerer & sorcerer);

#endif /* !Sorcerer_H */
