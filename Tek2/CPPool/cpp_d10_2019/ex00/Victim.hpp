/*
** EPITECH PROJECT, 2020
** Victim
** File description:
** Victim
*/

#ifndef Victim_H
#define Victim_H

#include <iostream>

class Victim {
	public:
		explicit Victim(std::string name);
		~Victim();

        std::string getName() const;

		void getPolymorphed() const;

	protected:
        std::string _name;
	private:
};

std::ostream & operator<<(std::ostream & os, Victim & victim);

#endif /* !Victim_H */
