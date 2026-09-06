/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** HTPMenu.hpp
*/

#ifndef __HTPMENU_HPP_
#define __HTPMENU_HPP_

#include "AMenu.hpp"

namespace indie
{
    class HTPMenu : public AMenu
    {
        public:
            HTPMenu() = default;
            ~HTPMenu() = default;

            void run();
            void printBackground();
        protected:
            bool isOpen = true;
    };
}

#endif