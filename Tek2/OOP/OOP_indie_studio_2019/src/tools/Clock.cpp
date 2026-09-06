/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** Clock.cpp
*/

#include "Clock.hpp"

indie::Clock::Clock()
{
    this->_clock = std::chrono::system_clock::now();
}

indie::Clock::Clock(const indie::Clock &copy)
{
    *this = copy;
}

void indie::Clock::restart()
{
    this->_clock = std::chrono::system_clock::now();
}

int indie::Clock::getElapsedTime()
{
    std::chrono::duration<double, std::milli> delta = std::chrono::system_clock::now() - this->_clock;

    return (delta.count());
}