/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** HandlerAudio
*/

#include "IAudio.hpp"

    //! Public
babel::HandlerAudio::HandlerAudio()
: _time(std::time(nullptr)), _empty(true)
{}

babel::HandlerAudio::HandlerAudio(std::vector<int> const &sound)
: _time(std::time(nullptr)), _empty(false), _opus(sound)
{}

babel::HandlerAudio::~HandlerAudio()
{
}

void babel::HandlerAudio::setData(std::vector<int> const &sound)
{
    _opus.setData(sound);
    _empty = false;
}

std::vector<int> babel::HandlerAudio::getData(void) const
{
    return (_opus.getData());
}

std::vector<unsigned char> babel::HandlerAudio::encrypted(std::vector<int> data)
{
    if (ENABLE_OPUS) {
        return (_opus.encryptData(data));
    } else {
        // for (auto &el : data) {
        //     std::cout << el << std::endl;
        // }
        // std::cout << "===========================" << std::endl;
        std::vector<unsigned char> result(FRAMES_PER_BUFFER * 4);
        memcpy(result.data(), data.data(), FRAMES_PER_BUFFER * sizeof(int));
        return (result);
    }
}

std::vector<int> babel::HandlerAudio::decrypted(std::vector<unsigned char> data)
{
    if (ENABLE_OPUS) {
        return (_opus.decryptData(data));
    } else {
        std::vector<int> result(FRAMES_PER_BUFFER);
        // std::cout << "AAA" << std::endl;
        memcpy(result.data(), data.data(), (FRAMES_PER_BUFFER * 4));
        // for (auto &el : result) {
        //     std::cout << el << std::endl;
        // }
        // std::cout << "+ + + + + + + + + + + + + + +" << std::endl;
        return (result);
    }
}

std::time_t babel::HandlerAudio::getTime(void) const
{
    return (_time);
}

bool babel::HandlerAudio::isEmpty(void) const
{
    return (_empty);
}

void babel::HandlerAudio::clear(void)
{
    _empty = true;
    _opus.clear();
}

void babel::HandlerAudio::operator=(HandlerAudio element)
{
    this->_time = element._time;
    this->_empty = element._empty;
    this->setData(element._opus.getData());
}
