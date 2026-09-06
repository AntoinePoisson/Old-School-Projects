/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LoadHandling
*/

#ifndef LOADHANDLING_HPP_
#define LOADHANDLING_HPP_

#include <iostream>
#include <vector>
#include <regex>
#include <fstream>

#include <dlfcn.h>
#include <dirent.h>

#include <chrono>
#include <unistd.h>

#include "IGraphics.hpp"
#include "IGames.hpp"
#include "Error.hpp"

namespace Arcade {

    template <class T>
    class LoadHandling {
        public:
            virtual ~LoadHandling() = default;

            void load(T pathLib, T pathGames, T pathScore, T libParam);
            std::vector<T> getLibs();
            std::vector<T> getGames();
            T getHighScoreName();
            uint64_t getHighScoreValue();
            bool checkFunctLib(bool isGameLib, T nameLib);
        private:
            void loadLibs(T libParam);
            void loadGames();
            void loadScore();
            T libParam;
            T linkToLibs;
            T linkToGames;
            T linkToScore;
            T pathLib;
            T pathGames;
            T pathScore;

            std::vector<T> handleLibs;
            std::vector<T> handleGames;

            T highScoreName;
            uint64_t highScoreValue;
    };

}


#endif /* !LOADHANDLING_HPP_ */
