/*
** EPITECH PROJECT, 2020
** Squad
** File description:
** Squad
*/

#ifndef Squad_hpp
#define Squad_hpp

#include <iostream>
#include <string.h>
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad {
	public:
		Squad();
        Squad(const Squad & squad);
		~Squad();

        int getCount() const;
        ISpaceMarine *getUnit(int);
        int push(ISpaceMarine *);
        void increasing_table();
        Squad & operator=(const Squad & squad);

	protected:
        int count;
        int position;
        int size_tab;
        ISpaceMarine **list;
	private:
};

#endif /* !Squad_hpp */
