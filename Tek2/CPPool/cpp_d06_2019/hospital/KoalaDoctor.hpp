/*
** EPITECH PROJECT, 2020
** KoalaDoctor
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_H
#define KOALADOCTOR_H

#include <iostream>
#include <iomanip>
#include <string.h>
#include "SickKoala.hpp"

class KoalaDoctor {
	public:
		KoalaDoctor(std::string);
		~KoalaDoctor();
        void diagnose(SickKoala *);
		void timeCheck(void);
		std::string getName(void);

	private:
	int isWork;
    std::string name;
};

#endif /* !KOALADOCTOR_H */
