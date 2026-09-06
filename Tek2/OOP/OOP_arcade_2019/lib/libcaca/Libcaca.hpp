/*
** EPITECH PROJECT, 2020
** Libcaca
** File description:
** Libcaca
*/

#ifndef LIBCACA_HPP
#define LIBCACA_HPP

#include <chrono>

#include "IGraphics.hpp"
#include "caca/caca.h"

namespace ArcadeLib {

    class Libcaca : public Arcade::IGraphics {
        public:
            Libcaca();
            ~Libcaca() = default;

            Arcade::IGraphics *create();
            char getEvent();
            void print(display_t &display);
            void destructor();
            void refresh();
            int getWindowHeight();
            int getWindowWidth();
            bool clockDisplay();

        private:
            caca_canvas_t *canvas;
            caca_display_t *window;
            caca_event_t event;
            std::chrono::time_point<std::chrono::system_clock> timeStart;
    };

}

#endif /* !LIBCACA_HPP */
