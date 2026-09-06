/*
** EPITECH PROJECT, 2020
** Aalib
** File description:
** Aalib
*/

#ifndef AALIB_HPP
#define AALIB_HPP

#include <stdio.h>
#include <aalib.h>
#include <chrono>

#include "IGraphics.hpp"

namespace ArcadeLib {

    class Aalib : public Arcade::IGraphics {
        public:
            Aalib();
            ~Aalib() = default;

            Arcade::IGraphics *create();
            char getEvent();
            void print(display_t &display);
            void destructor();
            void refresh();
            int getWindowHeight();
            int getWindowWidth();
            bool clockDisplay();

        private:
            aa_context *context;
            std::chrono::time_point<std::chrono::system_clock> timeStart;
    };
}

#endif /* !AALIB_HPP */
