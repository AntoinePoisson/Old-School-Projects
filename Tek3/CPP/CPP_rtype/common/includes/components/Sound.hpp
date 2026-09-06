/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Sound
*/

#ifndef COMMONCOMPONENTSOUND_HPP_
#define COMMONCOMPONENTSOUND_HPP_

#include "components/AComponent.hpp"
#include "components/Exception.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

namespace rtype {
    namespace component {

        struct Sound : public AComponent
        {
            Sound(const std::string &sound, bool loop, double offset = 0, double volume = 100)
                : AComponent(), _loop(loop), _loopStarted(false), _loaded(true)
            {
                if (!_buffer.loadFromFile(sound)) {
                    std::cerr << "[COMMON]: [COMPONENT]: [SOUND]: can't load sound file : " << sound << std::endl;
                    // throw Exception("can't load sound '" + sound + "'", "COMMON]: [COMPONENT]: [SOUND");
                    _loaded = false;
                    return;
                }
                _sound.setBuffer(_buffer);
                _sound.setPlayingOffset(sf::seconds(offset));
                _sound.setVolume(volume);
            };

            bool _loaded;
            sf::SoundBuffer _buffer;
            sf::Sound _sound;
            bool _loop;
            bool _loopStarted;
            bool _playing;
            bool _paused;
        };

        struct Music : public AComponent
        {
            Music(const std::string &music, bool loop, double offset = 0, double volume = 100)
                : AComponent(), _loop(loop), _loopStarted(false), _loaded(true)
            {
                if (!_music.openFromFile(music)) {
                    std::cerr << "[COMMON]: [COMPONENT]: [MUSIC]: can't load music file : " << music << std::endl;
                    // throw Exception("can't load music '" + music + "'", "COMMON]: [COMPONENT]: [MUSIC");
                    _loaded = false;
                    return;
                }
                _music.setPlayingOffset(sf::seconds(offset));
                _music.setVolume(volume);
            };

            ~Music() {
                _music.stop();
            }

            bool _loaded;
            sf::Music _music;
            bool _loop;
            bool _loopStarted;
            bool _playing;
            bool _paused;
        };

        struct GlobalVolume : public AComponent
        {
            GlobalVolume(double volume = 100) : AComponent(), _volume(volume) {};

            double _volume;
        };
    }
}

#endif /* !COMMONCOMPONENTSOUND_HPP_ */
