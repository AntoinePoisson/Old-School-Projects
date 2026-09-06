/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** APortAudio
*/

#include "APortAudio.hpp"

    //! Public
babel::APortAudio::APortAudio()
 : _stream(nullptr)
{
    PaError err;

    try {
        err = Pa_Initialize();
    } catch(...) {
        throw CantUsePA();
    }
    if (err != paNoError)
        throw babel::ErrorPortAudio("[PA]", std::string(Pa_GetErrorText(err)));
    try {
        this->openStream();
        this->startRecord();
    } catch(babel::ErrorPortAudio &pa) {
        pa.print();
    }
}

babel::APortAudio::~APortAudio()
{
    try {
        this->stopRecord();
        this->closeStream();
        Pa_Terminate();
    } catch(babel::ErrorPortAudio &pa) {
        pa.print();
    }
}

void babel::APortAudio::playSound(babel::HandlerAudio audio)
{
    PaError err;

    if (audio.isEmpty())
        return;
    while (Pa_GetStreamWriteAvailable(_stream) < (long)audio.getData().size()) {
    }
    err = Pa_WriteStream(_stream, audio.getData().data(), audio.getData().size());
    audio.clear();
    if (err != paNoError) {
        try {
            this->stopRecord();
            this->closeStream();
            this->openStream();
            this->startRecord();
        } catch(babel::ErrorPortAudio &pa) {
            pa.print();
        }
    }
}

babel::HandlerAudio babel::APortAudio::getSound(void)
{
    while (Pa_GetStreamReadAvailable(_stream) < FRAMES_PER_BUFFER) {
    }
    std::vector<int> sound(FRAMES_PER_BUFFER);
    PaError err = Pa_ReadStream(_stream, sound.data(), FRAMES_PER_BUFFER);
    if (err != paNoError) {
        try {
            this->stopRecord();
            this->closeStream();
            this->openStream();
            this->startRecord();
        } catch(babel::ErrorPortAudio &pa) {
            pa.print();
        }
        return (babel::HandlerAudio());
    }
    return (babel::HandlerAudio(sound));
}

void babel::APortAudio::restartSound(void)
{
    this->stopRecord();
    this->closeStream();
    this->openStream();
    this->startRecord();
}

    //! Private
void babel::APortAudio::openStream(void)
{
    // PaError err = Pa_OpenStream(&_stream, &_inputParameters, &_outputParameters,
    //     SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff,
    //     nullptr, nullptr);
    PaError err = Pa_OpenDefaultStream(&_stream,
        2, 2, paInt16, SAMPLE_RATE,
        FRAMES_PER_BUFFER, nullptr, nullptr);

    if (err != paNoError)
        throw babel::ErrorPortAudio("[PA]", std::string(Pa_GetErrorText(err)));
}

void babel::APortAudio::closeStream(void)
{
    PaError err = Pa_CloseStream(_stream);
    if (err != paNoError)
        throw babel::ErrorPortAudio("[PA]", std::string(Pa_GetErrorText(err)));
}

void babel::APortAudio::startRecord()
{
    PaError err = Pa_StartStream(_stream);

    if (err != paNoError)
        throw babel::ErrorPortAudio("[PA]", std::string(Pa_GetErrorText(err)));
}
void babel::APortAudio::stopRecord()
{
    PaError err = Pa_StopStream(_stream);

    if (err != paNoError)
        throw babel::ErrorPortAudio("[PA]", std::string(Pa_GetErrorText(err)));
}
