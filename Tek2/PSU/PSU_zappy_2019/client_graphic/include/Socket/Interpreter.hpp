/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Interpreter
*/

#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "Client.hpp"
#include "shared.h"

class Interpreter: public Client {
    public:
        Interpreter(unsigned short portNb);//: Client(portNb) {}
        ~Interpreter() = default;

        std::vector<struct cell_s> readCells(int nbOfStructs);
        int readHeader();
};

#endif