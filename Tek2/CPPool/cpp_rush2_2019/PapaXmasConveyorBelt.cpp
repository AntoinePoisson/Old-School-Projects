/*
** EPITECH PROJECT, 2020
** PapaXmasConveyor
** File description:
** PapaXmasConveyor
*/

#include "PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
    this->WrapOnConveyor = nullptr;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
//    delete WrapOnConveyor;
}

bool PapaXmasConveyorBelt::sendPapaXmasTable(PapaXmasTable * papaXmasTable)
{
    if (!WrapOnConveyor) {
        std::cout << "Noting to Send" << std::endl;
        return (false);
    }
    return (papaXmasTable->addTable(WrapOnConveyor));
}