/*
** EPITECH PROJECT, 2020
** KreogCom
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial)
{
    std::cout << "KreogCom " << serial << " initialized\n";
    this->_x = x;
    this->_y = y;
    this->_serial = serial;
    this->_next = NULL;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->_serial << " shutting down\n";
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *element = new KreogCom(x, y, serial);
    element->_next = this->_next;
    this->_next = element;
}

void KreogCom::removeCom()
{
    if (this->_next) {
        std::cout << "KreogCom " << this->_serial << " shutting down\n";
        this->_next = this->_next->_next;
    }
}

KreogCom *KreogCom::getCom()
{
    return (this->_next);
}

void KreogCom::ping()
{
    std::cout << "KreogCom " << this->_serial << " currently at " << this->_x << " " << this->_y << "\n";
}

void KreogCom::locateSquad()
{
    if (this->_next) {
        this->_next->locateSquad();
    }
    std::cout << "KreogCom " << this->_serial << " currently at " << this->_x << " " << this->_y << "\n";
}