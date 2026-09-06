/*
** EPITECH PROJECT, 2020
** KoalaNurse
** File description:
** KoalaNurse
*/

#ifndef SICKKOALANURSE_H
#define SICKKOALANURSE_H

#include <iostream>
#include <iomanip>
#include <string.h>
#include "SickKoala.hpp"

class KoalaNurse {
	public:
		KoalaNurse(int);
		~KoalaNurse();
		void giveDrug(std::string, SickKoala*);
		std::string readReport(std::string);
        void timeCheck(void);
		int getID(void);

	private:
        int ID;
        bool isWork;    
};

#endif /* !KoalaNurse */
