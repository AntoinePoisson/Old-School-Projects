/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** MainMenu.hpp
*/

#ifndef __MAINMENU_HPP_
#define __MAINMENU_HPP_

#include "AMenu.hpp"
#include "SettingsMenu.hpp"
#include "HTPMenu.hpp"

namespace indie
{
    class MainMenu : public AMenu
    {
        public:
            MainMenu() = default;
            virtual ~MainMenu() = default;

            void run();
            void openPlayMenu(void);
            void openSettings(void);
            void openHTP(void);
        private:
            void exitGame(void);
            void printBackground();
    };
}

#endif