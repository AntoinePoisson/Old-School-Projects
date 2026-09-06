/*
** EPITECH PROJECT, 2020
** IconveyorBelt
** File description:
** IconveyorBelt
*/

#ifndef IconveyorBelt_hpp
#define IconveyorBelt_hpp

#include "Object.hpp"
#include "Wrap.hpp"

class PapaXmasConveyorBelt; 

class IconveyorBelt {
	public:
		IconveyorBelt();
		~IconveyorBelt();

        IconveyorBelt *CreateConveyorBelt();
        bool IN(Wrap *wrap);
        bool OUT(PapaXmasConveyorBelt * papaXmasConveyorBelt);
        bool setWrapOnConveyor(Wrap *obj);
        Wrap *getWrapOnConveyor();
        Object *take();	
        void put(Wrap *);	

	protected:
		Wrap *WrapOnConveyor;
	private:
};

#endif /* !IconveyorBelt_hpp */
