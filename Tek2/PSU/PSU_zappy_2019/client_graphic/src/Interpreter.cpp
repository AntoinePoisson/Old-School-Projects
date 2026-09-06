/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Interpreter
*/

#include "Interpreter.hpp"

Interpreter::Interpreter(unsigned short portNb): Client(portNb) {}

std::vector<struct cell_s> Interpreter::readCells(int nbOfStructs)
{
    std::vector<struct cell_s> cells;

    for (int i = 0; i < nbOfStructs;) {
        // std::cout << i << std::endl;
        if (serverIsWriting() == true) {
            // std::cout << i << std::endl;
            cell_s cell = listenToServer<struct cell_s>();
            cells.push_back(cell);
            i++;
        }
    }
    return (cells);
}

int Interpreter::readHeader()
{
    return listenToServer<int>();
}
