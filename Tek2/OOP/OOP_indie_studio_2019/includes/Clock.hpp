/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** Clock.hpp
*/

#ifndef __CLOCK_HPP_
#define __CLOCK_HPP_

#include "Indie.hpp"
#include <chrono>

namespace indie
{
    class Clock
    {
        public:
            Clock();
            Clock(const indie::Clock &copy);
            virtual ~Clock() = default;

            int getElapsedTime();
            void restart();
        private:
            #ifdef  __linux__
                std::chrono::_V2::system_clock::time_point _clock;
            #else
                std::chrono::system_clock::time_point _clock;
            #endif
    };
}

#endif