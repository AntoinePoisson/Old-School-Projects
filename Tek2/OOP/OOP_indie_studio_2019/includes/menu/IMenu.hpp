/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** IMenu.hpp
*/

#ifndef __IMENU_HPP_
#define __IMENU_HPP_

#include "Indie.hpp"

namespace indie
{
    class IMenu
    {
        public:
            virtual ~IMenu() = default;

            virtual void run() = 0;
            virtual void background(const std::string &path) = 0;
            virtual void image(int x, int y, const std::string &path, int alpha = 255) = 0;
            virtual void previousButton(int x, int y, void (*ptr)()) = 0;
    };
}

#endif