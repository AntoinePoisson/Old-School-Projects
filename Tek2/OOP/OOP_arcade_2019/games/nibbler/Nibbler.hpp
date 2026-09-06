/*
** EPITECH PROJECT, 2020
** Nibbler
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP
#define NIBBLER_HPP

#include <cmath>
#include <iostream>
#include <ctime>
#include <chrono>
#include "IGames.hpp"

#define nbrBoardElement 99
#define indexFruit 100
#define indexHeadSnake 101
#define indexFirstTailSnake 102

namespace ArcadeGame {

    enum entityOrientation {
        UP,
        DOWN,
        RIGHT,
        LEFT,
    };

    class Nibbler : public Arcade::IGames {
        public:
            Nibbler();
            ~Nibbler() = default;

            Arcade::IGames *create();

            std::vector<display_t> &getInitState();
            std::vector<display_t> &getState();
            void move(char input);
            Arcade::statusGame &getStatus();
            void restart();
            uint64_t getScore();
            bool speedGame();
        protected:
        private:
            std::vector<display_t> initState;
            std::vector<display_t> map;
            std::vector<display_t> tmp;
            Arcade::statusGame gameFinish;
            std::chrono::time_point<std::chrono::system_clock> timeStart;
            uint64_t score;
            char lastDirection;

            void snakeNewPosition(float *x, float *y, char input);
            void snakeGrowUp();
            bool compareFloat(float A, float B);
            std::string spriteOrientation(ArcadeGame::entityOrientation orientation, int specialCase);
            std::string asciiOrientation(ArcadeGame::entityOrientation orientation, bool headSnake);
            ArcadeGame::entityOrientation findOrientation(float xOne, float yOne, float xTwo, float yTwo);
            void changePositionSnake(float x, float y);
            bool checkVoidCell(float x, float y);
            void spawnNewFruit();
            std::vector<display_t> &managementSamePosition(std::vector<display_t> &list);
    };

}

#endif /* !NIBBLER_HPP */
