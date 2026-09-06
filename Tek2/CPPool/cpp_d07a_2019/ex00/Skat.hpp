/*
** EPITECH PROJECT, 2020
** Skat.hpp
** File description:
** Skat.hpp
*/

#ifndef SKAT_H
#define SKAT_H

#include <fstream>
#include <string.h>
#include <iostream>

class Skat
{
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();
        int &stimPaks();
        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();

    private:
        std::string _name = "bob";
        int _stimpaks = 15;
};

#endif /* !SKAT */
