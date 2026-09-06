/*
** EPITECH PROJECT, 2020
** a
** File description:
** laide
*/

#include <fstream>
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    std::cout << "Dr." << name << ": I'm Dr." << name << "! How do you kreog?" << std::endl;
    this->name = name;
    this->isWork = true;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string name_patient = patient->getName();
    std::cout << "Dr." << this->name << ": So what's goerking you Mr." << name_patient << "?" << std::endl;
    std::ofstream fichier(name_patient + ".report", std::ios::out | std::ios::trunc);
 
    if (!fichier) {
        return;
    }
    std::string list[] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};
    fichier << list[random()% 5];
    fichier.close();
    patient->poke();
}

void KoalaDoctor::timeCheck(void)
{
    if (this->isWork == true) {
        std::cout << "Dr." << this->name << ": Time to get to work!" << std::endl;
        this->isWork = false;
    } else if (this->isWork == false) {
        this->isWork = true;
        std::cout << "Dr." << this->name << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

std::string KoalaDoctor::getName(void)
{
    return (this->name);
}