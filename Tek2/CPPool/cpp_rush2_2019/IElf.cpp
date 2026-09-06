/*
** EPITECH PROJECT, 2020
** IElf
** File description:
** IElf
*/

#include "IElf.hpp"

IElf::IElf()
{
    name = "";
    iTable = nullptr;
    iConveyorBelt = nullptr;
    leftHand = nullptr;
    rigthHand = nullptr;
}

IElf::IElf(std::string str)
{
    name = str;
    iTable = nullptr;
    iConveyorBelt = nullptr;
    leftHand = nullptr;
    rigthHand = nullptr;
}

void IElf::putAtWorkPlace(Itable *it, IconveyorBelt *ic)
{
    iTable = it;
    iConveyorBelt = ic;
}

void IElf::switchHandContent()
{
    Object *temp = leftHand;

    leftHand = rigthHand;
    rigthHand = temp;
}

void IElf::fillHands()
{
    Wrap *wrap;

    if (!rigthHand && iConveyorBelt) {
        wrap = new Wrap;
        iConveyorBelt->IN(wrap);
        rigthHand = iConveyorBelt->take();
    }
    if (!leftHand && iTable) {
        leftHand = iTable->take();
    }
}

void IElf::putLeftinRigth()
{
    if (rigthHand && leftHand) {
        dynamic_cast<Wrap *>(rigthHand)->openMe();
        dynamic_cast<Wrap *>(rigthHand)->wrapMeThat(leftHand);
        leftHand = nullptr;
        std::cout << "test" << std::endl;
    }
}

void IElf::sendRigthHandContent(PapaXmasConveyorBelt *papa)
{
    if (rigthHand && iConveyorBelt) {
        iConveyorBelt->put(dynamic_cast<Wrap *>(rigthHand));
        rigthHand = nullptr;
        iConveyorBelt->OUT(papa);
    }
}

void IElf::makeGift(PapaXmasConveyorBelt *papa)
{
    fillHands();
    putLeftinRigth();
    switchHandContent();
    fillHands();
    putLeftinRigth();
    sendRigthHandContent(papa);
}