/*
** EPITECH PROJECT, 2020
** IconveyorBelt
** File description:
** IconveyorBelt
*/

#include "PapaXmasConveyorBelt.hpp"
#include "IconveyorBelt.hpp"

IconveyorBelt::IconveyorBelt()
{
    this->WrapOnConveyor = nullptr;
}

IconveyorBelt::~IconveyorBelt()
{
}


IconveyorBelt *IconveyorBelt::CreateConveyorBelt()
{
    return (new IconveyorBelt());
}

bool IconveyorBelt::IN(Wrap *wrap)
{
    if (!wrap)
        return (false);
    if (this->WrapOnConveyor != nullptr) {
        std::cout << "Can't use In" << std::endl;
        return (false);
    }
    this->WrapOnConveyor = wrap;
    return (true);
}

bool IconveyorBelt::OUT(PapaXmasConveyorBelt * papaXmasConveyorBelt)
{
    if (WrapOnConveyor == nullptr)
        return (false);
    papaXmasConveyorBelt->setWrapOnConveyor(this->WrapOnConveyor);
    this->WrapOnConveyor = nullptr;
    return (true);
}

bool IconveyorBelt::setWrapOnConveyor(Wrap *obj)
{
    if (this->WrapOnConveyor != nullptr) {
        std::cout << "Error Can't Adding Wrap in IconveorBelt" << std::endl;
        return (false);
    }
    this->WrapOnConveyor = obj;
    return (true);
}

Wrap *IconveyorBelt::getWrapOnConveyor()
{
    return (this->WrapOnConveyor);
}

Object *IconveyorBelt::take()
{
    WrapOnConveyor->openMe();

    Object *save = WrapOnConveyor;
    WrapOnConveyor = nullptr;
    return (save);
}

void IconveyorBelt::put(Wrap *wrap)
{
    if (WrapOnConveyor) {
        std::cout << "WrapOnConveyor Already exist" << std::endl;
        return;
    }
    WrapOnConveyor = wrap;
}