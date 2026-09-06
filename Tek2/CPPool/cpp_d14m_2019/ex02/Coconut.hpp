/*
** EPITECH PROJECT, 2020
** Coconut
** File description:
** Coconut
*/

#ifndef Coconut_hpp
#define Coconut_hpp

#include "Fruit.hpp"

class Coconut : public Fruit {
	public:
		Coconut();
		~Coconut();

		virtual std::string getName() const;
		virtual int getVitamins() const;

	protected:
	private:
};

#endif /* !Coconut_hpp */
