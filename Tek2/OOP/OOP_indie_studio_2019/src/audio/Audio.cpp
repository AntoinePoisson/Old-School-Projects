/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Audio
*/

#include "Audio.hpp"
#include "Indie.hpp"

    //! Public
void indie::Audio::setVolume(int v)
{
    #ifdef __linux__
    if (v > 100) {
        v = 100;
    } else if (v < 0){
        v = 0;
    }
    indie::irrlicht->volume = v;
    for (int i = 0; i < listMusics.size(); i++)
        listMusics.at(i).second->setVolume(v);
    #endif
}

void indie::Audio::setSpecificVolume(std::string name, unsigned int v)
{
    #ifdef __linux__
    if (v > 100)
        v = 100;
    for (int i = 0; i < listMusics.size(); i++) {
        if (listMusics.at(i).first == name) {
            listMusics.at(i).second->setVolume(v);
            listMusics.at(i).second->play();
            return;
        }
    }
    listMusic_t newElement = std::make_pair(name, new sf::Music());
    if (!newElement.second->openFromFile(name)) {
        throw (indie::error::Audio(name));
    }
    newElement.second->setVolume(v);
    newElement.second->play();
//    std::cout << "Set sound: " << v << std::endl;
    listMusics.push_back(newElement);
    #endif
}

void indie::Audio::play(std::string name)
{
    #ifdef __linux__
    if (name.empty())
        throw (indie::error::Audio());
    for (int i = 0; i < listMusics.size(); i++) {
        if (listMusics.at(i).first == name) {
            listMusics.at(i).second->play();
            listMusics.at(i).second->setVolume(indie::irrlicht->volume);
            return;
        }
    }
    listMusic_t newElement = std::make_pair(name, new sf::Music());
    if (!newElement.second->openFromFile(name)) {
        throw (indie::error::Audio(name));
    }
    newElement.second->play();
    newElement.second->setVolume(indie::irrlicht->volume);
//    std::cout << "Set sound: " << indie::irrlicht->volume << std::endl;
    listMusics.push_back(newElement);
    #endif
}

void indie::Audio::stop(std::string name)
{
    #ifdef __linux__
    if (name.empty())
        return;
    for (int i = 0; i < listMusics.size(); i++)
        if (listMusics.at(i).first == name) {
            listMusics.at(i).second->stop();
            return;
        }
    #endif
}

void indie::Audio::pause(std::string name)
{
    #ifdef __linux__
    if (name.empty())
        return;
    for (int i = 0; i < listMusics.size(); i++)
        if (listMusics.at(i).first == name) {
            listMusics.at(i).second->pause();
            return;
        }
    #endif
}

sf::SoundSource::Status indie::Audio::getStatus(std::string name)
{
    #ifdef __linux__
    if (name.empty())
        return (sf::SoundSource::Status::Stopped);
    for (int i = 0; i < listMusics.size(); i++)
        if (listMusics.at(i).first == name)
            return (listMusics.at(i).second->getStatus());
    return (sf::SoundSource::Status::Stopped);
    #else
    return (sf::SoundSource::Status::Stopped);
    #endif
}

bool indie::Audio::getLoop(std::string name)
{
    #ifdef __linux__
    if (name.empty())
        return (false);
    for (int i = 0; i < listMusics.size(); i++)
        if (listMusics.at(i).first == name)
            return (listMusics.at(i).second->getLoop());
    return (false);
    #else
    return (false);
    #endif
}

void indie::Audio::setloop(std::string name, bool isLoop)
{
    #ifdef __linux__
    if (name.empty())
        return;
    for (int i = 0; i < listMusics.size(); i++)
        if (listMusics.at(i).first == name) {
            listMusics.at(i).second->setLoop(isLoop);
            return;
        }
    #endif
}