/*
** EPITECH PROJECT, 2020
** a
** File description:
** laide
*/

#ifndef SICKKOALA_H
#define SICKKOALA_H

#include <iostream>
#include <iomanip>
#include <string.h>

class SickKoala {
	public:
		SickKoala(std::string);
		~SickKoala();
		void poke();
		bool takeDrug(std::string);
		void SickKoalas(std::string);
		void overDrive(std::string);
		std::string getName(void);
	private:
        std::string name;
};

#endif