/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** gameLoop.hpp
*/

#ifndef __GAMELOOP_HPP_
#define __GAMELOOP_HPP_

#include "AMenu.hpp"
#include "WrapPlayers.hpp"
#include "Player.hpp"
#include "Indie.hpp"
#include "Map.hpp"

namespace indie
{
    class Game : public AMenu
    {
        public:
            Game();
            Game(indie::Map &map, indie::WrapPlayers<int> &wrapping);
            virtual ~Game() = default;

            indie::ObjectType checkAndMove(const direction_t &direction, int x, int z, float speed, bool thoughtBox, int rangeBomb, int nbrBomb);

            void setWrap(indie::WrapPlayers<int> &wrapping);
            void run();
        protected:
            bool isPause = false;
            void setUpPause();
            void setUnpause();
            void launchSettings();
            void launchSave();
            void launchMainMenu();
            void launchEndGame();
            void quit();
            void printNbBombs(int i, int pos_x, int pos_y);
            void printBombUI(void);
            void printDeadPlayers();
            indie::WrapPlayers<int> _wrapping;
            indie::Map _map;
    };
}

#endif