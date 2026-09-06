/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** IAudio
*/

#ifndef IAUDIO_HPP_
#define IAUDIO_HPP_

#include <ctime>
#include <iostream>
#include <cstring>
#include "AOpus.hpp"
#include "ErrorPortAudio.hpp"

#define ENABLE_OPUS true

namespace babel {

    class HandlerAudio {
        public:
            HandlerAudio();
            HandlerAudio(std::vector<int> const &sound);
            ~HandlerAudio();

            void setData(std::vector<int> const &sound);
            std::vector<int> getData(void) const;

            std::vector<unsigned char> encrypted(std::vector<int> data);
            std::vector<int> decrypted(std::vector<unsigned char> data);
            std::time_t getTime(void) const;
            bool isEmpty(void) const;
            void clear(void);

            void operator=(HandlerAudio element);
        private:
            bool _encrypt;
            std::time_t _time;
            bool _empty;
            AOpus _opus;
    };

    class IAudio {
        public:
            virtual ~IAudio() = default;

            virtual void playSound(HandlerAudio audio) = 0;
            virtual HandlerAudio getSound(void) = 0;
            virtual void restartSound(void) = 0;
    };

}

#endif /* !IAUDIO_HPP_ */
