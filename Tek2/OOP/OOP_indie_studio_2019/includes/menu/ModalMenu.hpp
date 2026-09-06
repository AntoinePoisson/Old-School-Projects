/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** ModalMenu.hpp
*/

#ifndef __MODALMENU_HPP_
#define __MODALMENU_HPP_

#include "AMenu.hpp"
#include "Indie.hpp"

namespace indie
{
    class ModalMenu : public AMenu
    {
        public:
            ModalMenu() = default;
            virtual ~ModalMenu() = default;

            void run();
            void openPlayMenu(void);
    };
}

#endif