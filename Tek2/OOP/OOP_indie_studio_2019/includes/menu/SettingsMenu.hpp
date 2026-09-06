/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SettingsMenu
*/

#ifndef SETTINGSMENU_HPP_
#define SETTINGSMENU_HPP_

#include "AMenu.hpp"
#include "Indie.hpp"


/*
    Idée de Settings:
        -> Music
        -> Sound
        -> Parametre graphics
*/

namespace indie {

    class SettingsMenu : public indie::AMenu {
        public:
            SettingsMenu();
            virtual ~SettingsMenu() = default;

            void run();
        private:
            void upMusic(void);
            void downMusic(void);
            void volumeBtn();
            void printBackground(void);
            void set1920x1080();
            void set1366x768();
            void set1280x720();
            void setLow();
            void setMedium();
            void setHigh();
            void restart();
            bool isOpen = true;
            int volume;
            int x;
            int volumeBtnPosition_x = 1278;
            int volumeBtnPosition_y = 258;
            bool _grab = false;
    };

}

#endif /* !SETTINGSMENU_HPP_ */
