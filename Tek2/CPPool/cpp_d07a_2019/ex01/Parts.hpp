/*
** EPITECH PROJECT, 2020
** Parts
** File description:
** Parts
*/

#ifndef PARTS_H
#define PARTS_H

#include <string>
#include <iostream>

class Arms {
    public:
        Arms(std::string serial = "A-01", bool functionnal = true);
        ~Arms();
        bool isFunctionnal();
        std::string serial();
        void informations();

    private:
        std::string _serial;
        bool _functionnal;
};

class Legs {
    public:
        Legs(std::string serial = "L-01", bool functionnal = true);
        ~Legs();
        bool isFunctionnal();
        std::string serial();
        void informations();

    private:
        std::string _serial;
        bool _functionnal;
};

class Head {
    public:
        Head(std::string serial = "H-01", bool functionnal = true);
        ~Head();
        bool isFunctionnal();
        std::string serial();
        void informations();

    private:
        std::string _serial;
        bool _functionnal;
};

#endif /* !PARTS */
