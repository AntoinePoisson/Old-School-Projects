/*
** EPITECH PROJECT, 2020
** Core
** File description:
** Core
*/

#ifndef CORE_HPP
#define CORE_HPP

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
#include "LoadHandling.hpp"
#include "Error.hpp"

#ifndef DISPLAY_T
#define DISPLAY_T

typedef struct display_s {
    std::string ascii;
    std::string foreground;
    std::string background;
    std::string image;
    float x;
    float y;
    bool isPrint;
} display_t;

#endif

namespace Arcade {

    enum Value {
        RETURN_SUCCESS = 0,
        RETURN_ERROR = 84,
        INPUT_NOTHING = -1,
        INPUT_CLOSE = 0,
        INPUT_W = 119,
        INPUT_A = 97,
        INPUT_E = 101,
        INPUT_O = 111,
        INPUT_P = 112,
        INPUT_R = 114,
        INPUT_M = 109,
        INPUT_ESCAPE = 27,
        INPUT_Z = 122,
        INPUT_S = 115,
        INPUT_Q = 113,
        INPUT_D = 100,
        INPUT_VALIDE = 10,
    };

    class Core {
        public:
            Core(const char *paramLib);
            ~Core();

            Value launchCore();
        private:
            std::string libParam;

            std::string scoreName;
            uint64_t scoreValue;

            int windowHeight;
            int windowWidth;

            std::string highScoreName;
            uint64_t highScoreValue;

            bool changeScoreName;

            char input;
            char saveInputGame;

            int indexCurrentLibHandle;
            int indexCurrentGameHandle;

            void *currentLibHandle;
            void *currentGameHandle;

            Arcade::IGraphics *graphics;
            Arcade::IGames *games;

            std::vector<std::string> handleLibs;
            std::vector<std::string> handleGames;

            std::vector<display_t> listDisplay;

            std::string reworkNameLib(std::string);
            void displayMenu();
            Arcade::statusGame displayGame();
            int positionToDisplay(float pos, int sizeMax);

            void managementInputLib();
            void managementInputGame();

            void changeLib(bool isNextLib);
            void changeGame(std::string nameGame, bool callInMenu, bool isNextGame);

            bool finalCondition();
            void changeHighScore();
    };
}

#endif /* !CORE_HPP */
