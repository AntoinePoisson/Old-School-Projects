/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** APortAudio
*/

#ifndef APORTAUDIO_HPP_
#define APORTAUDIO_HPP_

#include <memory>
#include "portaudio.h"
#include "CantUsePA.hpp"
#include "IAudio.hpp"

#define SAMPLE_RATE 48000
#define FRAMES_PER_BUFFER 480

namespace babel {

    class APortAudio : public IAudio {
        public:
            APortAudio();
            ~APortAudio();

            void playSound(HandlerAudio audio);
            HandlerAudio getSound(void);
            void restartSound(void);
        private:
            void startRecord(void);
            void stopRecord(void);
            void openStream();
            void closeStream();
            PaStream * _stream;
            // PaStreamParameters _outputParameters;
            // PaStreamParameters _inputParameters;
    };

}

#endif /* !APORTAUDIO_HPP_ */
