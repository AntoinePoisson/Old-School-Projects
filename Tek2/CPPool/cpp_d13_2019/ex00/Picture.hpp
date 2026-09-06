/*
** EPITECH PROJECT, 2020
** Picture
** File description:
** Picture
*/

#ifndef Picture_hpp
#define Picture_hpp

#include <iostream>
#include <fstream>

class Picture {
	public:
		Picture();
        Picture(const std::string &file);
		~Picture();

        bool getPictureFromFile(const std::string &file = "");

        std::string data;
	protected:
	private:
};

#endif /* !Picture_hpp */
