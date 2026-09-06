/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** NCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <string>
#include <vector>
#include <ncurses.h>
#include <stdlib.h>
#include <chrono>
#include <bits/stdc++.h> 
#include <sys/select.h>

#include "throw/Error.hpp"
#include "IGraphics.hpp"

namespace Plazza {

    class NCurses : public Plazza::IGraphics {
        public:
            NCurses(std::string prompt);
            virtual ~NCurses() = default;

            void displayLine(std::string line, bool cmd = true);
            std::string getInputCommand();
            void refreshWin();
            void destroy();
        private:
            void displayMessage();
            void displayListCmd(std::vector<std::string> list, WINDOW *win);
            void displayListOrder(std::vector<std::string> list, WINDOW *win);

            WINDOW *top;
            WINDOW *left;
            WINDOW *right;
            int maxX;
            int maxY;
            int halfX;
            int halfY;
            std::vector<std::string> listOrder;
            std::vector<std::string> listCmd;
            bool isDestroy;
            int cas;
            int indexCmd;
            std::string command;
            std::string prompt;
            std::chrono::time_point<std::chrono::system_clock> timeStart;
    };

}


#endif /* !DISPLAY_HPP_ */