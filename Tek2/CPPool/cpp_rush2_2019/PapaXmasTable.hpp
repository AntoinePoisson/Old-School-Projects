/*
** EPITECH PROJECT, 2020
** PapaXmasTable
** File description:
** PapaXmasTable
*/

#ifndef PapaXmasTable_h
#define PapaXmasTable_h

#include "Itable.hpp"

class Itable;

class PapaXmasTable : public Itable {
	public:
		PapaXmasTable();
		~PapaXmasTable();

		bool addTable(Object *obj);

	protected:
	private:
		int table_size = 100;
};

#endif /* !PapaXmasTable_h */
