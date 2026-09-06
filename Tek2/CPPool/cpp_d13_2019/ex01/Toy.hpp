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
        };
		Toy();
    	Toy(ToyType type, std::string const & name, std::string const & ascii);
        Toy(Toy const & toy);
		~Toy();

        ToyType getType() const;
        std::string const & getName() const;
        std::string const & getAscii() const;

        void setName(std::string const &name);
        bool setAscii(std::string const &name);

	    Toy & operator=(Toy const & toy);

	protected:
	private:
        ToyType type;
        std::string name;
        Picture picture;
};

#endif /* !Toy_hpp */
