/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <iostream>
#include "../Teddy.hpp"
#include "../LittlePony.hpp"
#include "../Box.hpp"
#include "../GiftPaper.hpp"

Object **MyUnitTests();
Object *MyUnitTests(Object **);

int main()
{   
    Object **arr = MyUnitTests();

    arr[0]->isTaken();
    arr[1]->isTaken();
    std::cout << arr[0]->getTitle() << " is a LittlePony" << std::endl;
    std::cout << arr[1]->getTitle() << " is a Teddy" << std::endl;

    Object **temp = new Object*[4];

    temp[0] = new Teddy("cuddles");
    temp[1] = new Box("The Box");
    temp[2] = new GiftPaper("Pretty GiftPaper");
    temp[3] = nullptr;

    Object *wrapObj = MyUnitTests(temp);

    std::cout << "Obj is a " << wrapObj->getTitle() << std::endl;
    dynamic_cast<GiftPaper *>(wrapObj)->openMe();
    Object *temp1 = dynamic_cast<GiftPaper *>(wrapObj)->getObject();
    std::cout << "Obj is a " << dynamic_cast<Box *>(temp1)->getTitle() << std::endl;

    dynamic_cast<Box *>(temp1)->openMe();
    Object *temp2 = dynamic_cast<Box *>(temp1)->getObject();
    std::cout << "open it and you will find " << temp2->getTitle() << std::endl;

}