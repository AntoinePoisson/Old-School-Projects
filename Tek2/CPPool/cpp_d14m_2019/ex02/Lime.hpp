/*
** EPITECH PROJECT, 2020
** Lime
** File description:
** Lime
*/

#ifndef Lime_hpp
#define Lime_hpp

#include "Lemon.hpp"
#include "Fruit.hpp"

class Lime : public Lemon {
	public:
		Lime();
		~Lime();

		virtual std::string getName() const;
		virtual int getVitamins() const;

	protected:
	private:
};

#endif /* !Lime_hpp */
