/*
** EPITECH PROJECT, 2020
** Buzz
** File description:
** Buzz
*/

#ifndef Buzz_hpp
#define Buzz_hpp

#include "Toy.hpp"

class Buzz : public Toy {
	public:
		Buzz(std::string const & name, std::string const & ascii = "buzz.txt");
		~Buzz();

        void speak(std::string statement);
        bool speak_es(std::string statement);


	protected:
	private:
};

#endif /* !Buzz_hpp */
