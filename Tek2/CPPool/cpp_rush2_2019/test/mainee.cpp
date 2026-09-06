/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <iostream>
#include "../Teddy.hpp"
#include "../LittlePony.hpp"
#include "../Wrap.hpp"
#include "../Box.hpp"
#include "../GiftPaper.hpp"
#include "../PapaXmasConveyorBelt.hpp"
#include "../PapaXmasTable.hpp"
#include "../Itable.hpp"
#include "../IElf.hpp"
#include "../IconveyorBelt.hpp"
#include "../Object.hpp"

Object **MyUnitTests();


int main()
{   
    IconveyorBelt * iconveyorBelt = new IconveyorBelt();
    PapaXmasConveyorBelt * papaXmasConveyorBelt = new PapaXmasConveyorBelt();
    // PapaXmasTable * papaXmasTable = new PapaXmasTable();
    Itable * itable = new Itable();
    IElf * iElf = new IElf();
    // Wrap * wrap = new Wrap();
    Object **arr = MyUnitTests();

    itable->addTableObject(arr[0]);
    itable->addTableObject(arr[1]);
    iElf->putAtWorkPlace(itable, iconveyorBelt);
    iElf->makeGift(papaXmasConveyorBelt);
/*
    wrap->wrapMeThat(arr[0]);
    iconveyorBelt->IN(wrap);
    iElf->putAtWorkPlace(itable, iconveyorBelt);
    itable->addTableObject(iconveyorBelt->take());

    Wrap * wrap2 = new Wrap();
    wrap2->wrapMeThat(arr[1]);
    iconveyorBelt->IN(wrap2);
    itable->addTableObject(iconveyorBelt->take());

    Object **arr2 = MyUnitTests();
    Wrap * wrap3 = new Wrap();
    wrap3->wrapMeThat(arr2[0]);
    iconveyorBelt->IN(wrap3);
    itable->addTableObject(iconveyorBelt->take());


    Wrap * wrap4 = new Wrap();
    wrap4->wrapMeThat(arr2[1]);
    iconveyorBelt->IN(wrap4);
    iElf->putAtWorkPlace(itable, iconveyorBelt);
    itable->addTableObject(iconveyorBelt->take());

    Object **arr3 = MyUnitTests();
    Wrap * wrap5 = new Wrap();
    wrap5->wrapMeThat(arr3[0]);
    iconveyorBelt->IN(wrap5);
    itable->addTableObject(iconveyorBelt->take());

    Wrap * wrap6 = new Wrap();
    wrap6->wrapMeThat(arr3[1]);
    iconveyorBelt->IN(wrap6);
*/

}