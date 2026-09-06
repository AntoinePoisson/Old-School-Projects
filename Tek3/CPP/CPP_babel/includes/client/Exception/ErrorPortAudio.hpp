/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** ErrorPortAudio
*/

#ifndef ERRORPORTAUDIO_HPP_
#define ERRORPORTAUDIO_HPP_

#include "AException.hpp"

namespace babel {

    class ErrorPortAudio : public AException {
        public:
            ErrorPortAudio(std::string component = "[PA]", std::string message = "Error Port Audio", int returnValue = 84);
            virtual ~ErrorPortAudio() = default;
    };

}

#endif /* !ERRORPORTAUDIO_HPP_ */
