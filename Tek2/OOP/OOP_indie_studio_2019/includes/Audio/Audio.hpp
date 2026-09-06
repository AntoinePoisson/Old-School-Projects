/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Audio
*/

#ifndef MY_AUDIO_HPP_
#define MY_AUDIO_HPP_

#include <string>
#include <vector>
#include <iostream>
#ifdef  __linux__
#include "SFMLAudio.hpp"
#else
#include "SFML/Audio.hpp"
#endif
typedef std::pair<std::string, sf::Music *> listMusic_t;

namespace indie {

    extern std::vector<listMusic_t> listMusics;

    class Audio {
        public:
            virtual ~Audio() = default;

            static void setVolume(int v);
            static void setSpecificVolume(std::string name, unsigned int v);

            static void play(std::string name);
            static void stop(std::string name);
            static void pause(std::string name);
            static sf::SoundSource::Status getStatus(std::string name);
            static bool getLoop(std::string name);
            static void setloop(std::string name, bool isLoop);
    };

}

#endif /* !AUDIO_HPP_ */
