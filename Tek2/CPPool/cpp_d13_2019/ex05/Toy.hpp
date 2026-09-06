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

        class Error {
	        public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK,
                };
		        Error();
                ~Error() = default;
                std::string what() const;
                std::string where() const;
            	void setType(ErrorType type);

		        ErrorType type;
            protected:
            private:
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
        virtual bool speak_es(std::string statement);


	    Toy & operator=(Toy const & toy);
		Toy & operator<<(std::string const & ascii);

        Error const & getLastError() const;

	protected:
        ToyType type;
        std::string name;
        Picture picture;
	    Error error;
	private:
};

std::ostream & operator<<(std::ostream & os, Toy const & toy);


#endif /* !Toy_hpp */
