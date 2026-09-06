/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Controller
*/

#include "Controller.hpp"

Controller::Controller(int x, int y, const Interpreter &interpreter):
 _graphic(x, y), _interpreter(interpreter)
{
    _graphic.displayMap();
}

void Controller::loop()
{
    while (_graphic.isOpen()) {
        if (_interpreter.serverIsWriting() == true) {
            int value =  _interpreter.readHeader();
            // std::cout << value <<std::endl;
            if (value > 0) {
                std::vector<struct cell_s> cells = _interpreter.readCells(value);
                // std::cout << cells.size() <<std::endl;
                // std::cout << cells[20].x <<std::endl;
                // std::cout << cells[20].y <<std::endl;
                // std::cout << cells[20].food <<std::endl;
                // std::cout << cells[20].phiras <<std::endl;
                // std::cout << cells[20].players[0].id <<std::endl;
                _interpreter.listenToServerStr(); //read break char
                _graphic.refreshMap(cells);
            } else {
                //command
            }
        }
        _graphic.displayMap();
        _graphic.windowClose();
    }
}