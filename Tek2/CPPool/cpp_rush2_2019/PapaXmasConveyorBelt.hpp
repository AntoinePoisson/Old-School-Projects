/*
** EPITECH PROJECT, 2020
** PapaXmasConveyor
** File description:
** PapaXmasConveyor
*/

#ifndef PapaXmasConveyorBelt_h
#define PapaXmasConveyorBelt_h

#include "IconveyorBelt.hpp"
#include "PapaXmasTable.hpp"

class IconveyorBelt;

class PapaXmasConveyorBelt : public IconveyorBelt {
	public:
		PapaXmasConveyorBelt();
		~PapaXmasConveyorBelt();

		bool sendPapaXmasTable(PapaXmasTable * papaXmasTable);

	protected:
	private:
};

#endif /* !PapaXmasConveyorBelt_g */
