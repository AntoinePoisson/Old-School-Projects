/*
** EPITECH PROJECT, 2020
** KoalaBot
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    this->_serial = serial;
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms &Arms)
{
    this->_Arms = Arms; 
}

void KoalaBot::setParts(const Legs &Legs)
{
    this->_Legs = Legs; 
}

void KoalaBot::setParts(const Head &Head)
{
    this->_Head = Head; 
}

///////////////////////////////////////////////////

void KoalaBot::swapParts(Arms &arms)
{
    Arms save = this->_Arms;
    this->_Arms = arms;
    arms = save;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs save = this->_Legs;
    this->_Legs = legs;
    legs = save;
}

void KoalaBot::swapParts(Head &head)
{
    Head save = this->_Head;
    this->_Head = head;
    head = save;
}

///////////////////////////////////////////////////

void KoalaBot::informations()
{
    std::cout << "[KoalaBot] " << this->_serial << "\n";
    _Arms.informations();
    _Legs.informations();
    _Head.informations();
}

bool KoalaBot::status()
{
    if (_Arms.isFunctionnal() && _Legs.isFunctionnal() && _Head.isFunctionnal())
        return (true);
    return (false);
}