/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** SelectMenu.hpp
*/

#ifndef __SELECTMENU_HPP_
#define __SELECTMENU_HPP_

#include "AMenu.hpp"
#include "SettingsMenu.hpp"
#include "GameLoop.hpp"
#include "WrapPlayers.hpp"
#include "Player.hpp"
#include "PlayerAi.hpp"

namespace indie
{
    typedef struct selectPlayer_s
    {
        void *player;
        bool isAi;
    } selectPlayer_t;

    class SelectMenu : public AMenu
    {
        public:
            SelectMenu() = default;
            virtual ~SelectMenu() = default;

            void run();
            void play();
            void assign();
        protected:
            void printBackground();

            indie::WrapPlayers<int> wrapping;
            std::vector<indie::selectPlayer_t> _players = {};
            int8_t select = -1;
            int8_t direction = -1;
            int8_t buttonSelect = -1;
            int8_t buttonDirection = -1;
    };
}

#endif