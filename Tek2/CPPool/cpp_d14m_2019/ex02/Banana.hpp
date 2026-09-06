/*
** EPITECH PROJECT, 2020
** Banana
** File description:
** Banana
*/

#ifndef Banana_hpp
#define Banana_hpp

#include <iostream>
#include "Fruit.hpp"

class Banana : public Fruit {
	public:
		Banana();
		~Banana();

		virtual std::string getName() const;
		virtual int getVitamins() const;

	protected:
	private:
};

#endif /* !Banana_hpp */
