/*
** EPITECH PROJECT, 2020
** Lemon
** File description:
** Lemon
*/

#ifndef Lemon_hpp
#define Lemon_hpp

#include <iostream>
#include "Fruit.hpp"

class Lemon : public Fruit {
	public:
		Lemon();
		~Lemon();

		virtual std::string getName() const;
		virtual int getVitamins() const;

	protected:
	private:
};

#endif /* !Lemon_hpp */
