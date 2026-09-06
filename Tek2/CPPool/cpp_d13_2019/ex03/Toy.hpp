/*
** EPITECH PROJECT, 2020
** Toy
** File description:
** Toy
*/

#ifndef Toy_hpp
#define Toy_hpp

#include <iostream>
#include <fstream>
#include "Picture.hpp"


class Toy {
	public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY,
        };
		Toy();
    	Toy(ToyType type, std::string const & name, std::string const & ascii);
		virtual ~Toy();

        ToyType getType() const;
        std::string const & getName() const;
        std::string const & getAscii() const;

        void setName(std::string const &name);
        bool setAscii(std::string const &name);

        virtual void speak(std::string statement);

	    Toy & operator=(Toy const & toy);

	protected:
        ToyType type;
        std::string name;
        Picture picture;
	private:
};

#endif /* !Toy_hpp */
