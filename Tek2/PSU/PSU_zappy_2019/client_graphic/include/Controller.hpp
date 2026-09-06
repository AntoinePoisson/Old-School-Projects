/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Controller
*/

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "Interpreter.hpp"
#include "Graphic.hpp"
#include "Exception.hpp"
#include <iostream>

class Controller {
        Graphic _graphic;
        Interpreter _interpreter;
    public:
        Controller(int x, int y, const Interpreter &interpreter);
        Controller(int ac, const char **av);
        ~Controller() = default;
        void loop();
};

#endif