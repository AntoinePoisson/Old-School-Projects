/*
** EPITECH PROJECT, 2020
** Pacman
** File description:
** Pacman
*/

#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <cmath>
#include <iostream>
#include <ctime>
#include <chrono>
#include <map>
#include "IGames.hpp"

namespace ArcadeGame {

    enum entityOrientation {
        UP,
        DOWN,
        RIGHT,
        LEFT,
    };

    class Pacman : public Arcade::IGames {
        public:
            Pacman();
            ~Pacman() = default;

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
            std::vector<std::string> sMap;
            std::vector<unsigned int> iGhosts;
            std::vector<unsigned int> sGhosts;
            int MapXSize;
            int MapYSize;
            Arcade::statusGame gameFinish;
            std::chrono::time_point<std::chrono::system_clock> timeStart;
            std::chrono::time_point<std::chrono::system_clock> tStartGhosts;
            std::chrono::time_point<std::chrono::system_clock> tStartPUp;
            std::chrono::time_point<std::chrono::system_clock> tDeathGhost;
            std::chrono::time_point<std::chrono::system_clock> tDeathPacman;
            uint64_t score;
            unsigned int iPlayer;
            unsigned int iObj;
            bool powerUp;
            bool dying;
            float cellSize;


            void genStrMap();
            void genLayerMap(char l, bool map);
            void genDisplay(char c, int x, int y, bool map);
            void updateEffect();
            unsigned int pacgumsLeft();
            void moveObject(unsigned int iObj, char input);
            void moveGhosts();
            unsigned int isInStartGhost(unsigned int iGhost);
            void possibleMoveGhost(unsigned int iGhost, std::string &mv);
            void animate(unsigned int index, char input, std::string const &sPath);
            unsigned int collision(float x, float y, std::string const &obj);
            bool compareFloat(float A, float B);
    };

}

#endif /* !PACMAN_HPP */
