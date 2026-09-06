/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** EndGame.hpp
*/

#include "Indie.hpp"
#include "AMenu.hpp"
#include "AObject.hpp"

namespace indie
{
    class EndGame : public indie::AMenu
    {
        public:
            EndGame() = default;
            virtual ~EndGame() = default;

            void run_EndGame(int indexPlayer, std::vector<indie::APlayer *> allPlayers);
            void run();
        protected:
            void displayWinner();
            void displaySecond();
            void displayThird();
            void launchMainMenu();
            void quit();
            int _indexPlayer;
            std::vector<indie::APlayer *> _allPlayers;
            IGUIFont *font;
            IGUIStaticText *static_blue;
    };
}