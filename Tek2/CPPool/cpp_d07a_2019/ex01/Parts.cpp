/*
** EPITECH PROJECT, 2020
** Parts
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Arms::~Arms()
{
}

bool Arms::isFunctionnal()
{
    return (this->_functionnal);
}

std::string Arms::serial()
{
    return (this->_serial);
}

void Arms::informations()
{
    std::cout << "\t[Parts] Arms " << this->_serial;
    
    if (this->_functionnal)
        std::cout << " status : OK\n";
    else
        std::cout << " status : KO\n";
}

////////////

Legs::Legs(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Legs::~Legs()
{
}

bool Legs::isFunctionnal()
{
    return (this->_functionnal);
}

std::string Legs::serial()
{
    return (this->_serial);
}

void Legs::informations()
{
    std::cout << "\t[Parts] Legs " << this->_serial;
    
    if (this->_functionnal)
        std::cout << " status : OK\n";
    else
        std::cout << " status : KO\n";
}

////////////

Head::Head(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Head::~Head()
{
}

bool Head::isFunctionnal()
{
    return (this->_functionnal);
}

std::string Head::serial()
{
    return (this->_serial);
}

void Head::informations()
{
    std::cout << "\t[Parts] Head " << this->_serial;
    
    if (this->_functionnal)
        std::cout << " status : OK\n";
    else
        std::cout << " status : KO\n";
}