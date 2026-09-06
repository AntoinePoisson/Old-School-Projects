/*
** EPITECH PROJECT, 2020
** a
** File description:
** laide
*/

#include <fstream>
#include <string.h>
#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int ID)
{
    if (!ID)
        return;
    this->isWork = true;
    this->ID = ID;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse "<< this->ID << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string medoc, SickKoala* Koala)
{
    if (Koala)
        Koala->takeDrug(medoc);
}

std::string KoalaNurse::readReport(std::string report)
{
    std::string result = "";
    char name[100];
    int i = 0;
    int count = 0;

    for (int i = 0; i != 99; name[i] = '\0', i++);
    for (; report[i] && report[i] != '.'; i++)
        name[count++] = report[i];
    if (report[i] != '.' || strncmp(".report", &report[i], 7) != 0)
        return ("");
    std::ifstream data (report, std::ifstream::in);
    if (!data)
        return ("");
    char c = data.get();
    while (data.good()) {
        result += c;
        c = data.get();
    }
    data.close();
    std::cout << "Nurse " << ID << ": Kreog! Mr." << name << " needs a " << result << "!" << std::endl;
    return (result);
}

void KoalaNurse::timeCheck(void)
{
    if (this->isWork == true) {
        std::cout << "Nurse " << ID << ": Time to get to work!" << std::endl;
        this->isWork = false;
    } else if (this->isWork == false) {
        this->isWork = true;
        std::cout << "Nurse " << ID << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

int KoalaNurse::getID(void)
{
    return (this->ID);
}