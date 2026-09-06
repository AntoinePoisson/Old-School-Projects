/*
** EPITECH PROJECT, 2020
** a
** File description:
** laide
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string str)
{
    this->name = str;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << this->name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (str.compare("Mars") == 0) {
        std::cout << "Mr." << this->name << ": Mars, and it kreogs!" << std::endl;
        return (true);
    }
    if (str.compare("Buronzand") == 0) {
        std::cout << "Mr." << this->name << ": And you'll sleep right away!" << std::endl;
        return (true);
    }
    std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
    return (false);
}

void SickKoala::overDrive(std::string str)
{
    std::cout << "Mr." << this->name << ": ";
    for (int i = 0; str[i]; i++) {
        if (strncmp(&str[i],"Kreog!", 6) == 0) {
            std::cout << "1337!";
            i += 5;
        }
        else
            std::cout << str[i];
    }
    std::cout << std::endl;
}

std::string SickKoala::getName(void)
{
    return (this->name);
}