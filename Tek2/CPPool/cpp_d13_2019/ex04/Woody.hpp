/*
** EPITECH PROJECT, 2020
** Woody
** File description:
** Woody
*/

#ifndef Woody_hpp
#define Woody_hpp

#include "Toy.hpp"

class Woody : public Toy {
	public:
		Woody(std::string const & name, std::string const & ascii = "woody.txt");
		~Woody();

        void speak(std::string statement);

	protected:
	private:
};

#endif /* !Woody_hpp */
