/*
** EPITECH PROJECT, 2020
** IElf
** File description:
** IElf
*/

#ifndef IELF_H
#define IELF_H

#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Box.hpp"
#include "Itable.hpp"
#include "IconveyorBelt.hpp"
#include "PapaXmasConveyorBelt.hpp"

class IElf {
	public:
		IElf();
        IElf(std::string str);
		~IElf();
        void putAtWorkPlace(Itable *, IconveyorBelt *);
        void makeGift(PapaXmasConveyorBelt *);
	private:
        void switchHandContent();
        void fillHands();
        void putLeftinRigth();
        void sendRigthHandContent(PapaXmasConveyorBelt *);
        Itable *iTable;
        IconveyorBelt *iConveyorBelt;
        Object *leftHand;
        Object *rigthHand;
        std::string name;
};

#endif /* !IELF_H */
