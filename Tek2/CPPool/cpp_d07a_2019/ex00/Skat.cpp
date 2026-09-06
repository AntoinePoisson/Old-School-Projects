/*
** EPITECH PROJECT, 2020
** Skat
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimpaks)
{
    this->_name = name;
    this->_stimpaks = stimpaks;
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return (this->_stimpaks);
}

const std::string &Skat::name()
{
    return (this->_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number <= this->_stimpaks) {
        this->_stimpaks -= number;
        stock += number;
        std::cout << "Keep the change.\n";
    } else {
        std::cout << "Don't be greedy\n";
    }
}

void Skat::addStimPaks(unsigned int number) {
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?\n";
    } else {
        this->_stimpaks += number;
    }
}

void Skat::useStimPaks()
{
    if (this->_stimpaks > 0) {
        std::cout << "Time to kick some ass and chew bubble gum.\n";
        this->_stimpaks -= 1;
    } else {
        std::cout << "Mediiiiiic\n";
    }
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " << this->_stimpaks << " stimpaks remaining sir!\n";
}