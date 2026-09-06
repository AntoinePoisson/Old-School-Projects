/*
** EPITECH PROJECT, 2020
** Fruit
** File description:
** Fruit
*/

#ifndef Fruit_hpp
#define Fruit_hpp

#include <iostream>

class Fruit {
	public:
		explicit Fruit(std::string const &name, int _vitamins);
		virtual ~Fruit();

		virtual std::string getName() const;
		virtual int getVitamins() const;

	protected:
		std::string _name;
		int _vitamins;
	private:
};

#endif /* !Fruit_hpp */
