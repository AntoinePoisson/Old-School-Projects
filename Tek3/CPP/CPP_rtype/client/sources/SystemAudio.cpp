/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemAudio
*/

#include "systems/Audio.hpp"
#include <ctime>
#include <iostream>

rtype::system::Audio::Audio(rtype::entity::ComponentManager &ecm)
    : _ecm(ecm)
{
    rtype::component::GlobalVolume globVol;
    auto pair = _ecm._cMan.getComponentFromType<rtype::component::Unremovable>();

    pair.second->entities.push_back(_ecm.createEntity(Signature(idGlobalVolume), globVol));
}

rtype::system::Audio::~Audio()
{
}

void rtype::system::Audio::update(const Entity &entity_id)
{
    // std::cout << "audio" << std::endl;
    auto entities = _ecm._eMan.getEntities();

    for (auto it = entities.begin(); it != entities.end(); it++) {
        auto compSound = it->second & Signature(idSound);
        auto compMusic = it->second & Signature(idMusic);

        if (compSound.count()) {
            rtype::component::Sound &sound = _ecm.getComponent<rtype::component::Sound>(it->first);

            if (!sound._loaded)
                continue;
            if (!sound._playing && !sound._paused) {
                if (sound._loop)
                    if (!sound._loopStarted) {
                        sound._sound.setLoop(true);
                        sound._loopStarted = true;
                    }
                sound._sound.play();
                sound._playing = true;
                auto vol = _ecm._cMan.getComponentFromType<rtype::component::GlobalVolume>();
                sound._sound.setVolume(vol.second->_volume);
                // std::cerr << "SOUND vol.second->_volume = " << vol.second->_volume << std::endl;
            }
        } else if (compMusic.count()) {
            rtype::component::Music &music = _ecm.getComponent<rtype::component::Music>(it->first);

            if (!music._loaded)
                continue;
            if (!music._playing && !music._paused) {
                if (music._loop)
                    if (!music._loopStarted) {
                        music._music.setLoop(true);
                        music._loopStarted = true;
                    }
                music._music.play();
                music._playing = true;
                auto vol = _ecm._cMan.getComponentFromType<rtype::component::GlobalVolume>();
                music._music.setVolume(vol.second->_volume);
                // std::cerr << "MUS vol.second->_volume = " << vol.second->_volume << std::endl;
            }
        }
    }
}

void rtype::system::Audio::setVolumeAll(const Entity &entity, double volume)
{
    auto entities = _ecm._eMan.getEntities();

    std::cerr << "[CLIENT]: [SYSTEM]: [AUDIO]: [SETVOLUMEALL]: new vol = " << volume  << std::endl;
    for (auto it = entities.begin(); it != entities.end(); it++)
        this->setVolume(it->first, volume);
}

void rtype::system::Audio::setVolume(const Entity &entity, double volume)
{
    auto sig = _ecm._eMan.getSignature(entity);
    auto compSound = sig & Signature(idSound);
    auto compMusic = sig & Signature(idMusic);

    if (compSound.count()) {
        rtype::component::Sound &sound = _ecm.getComponent<rtype::component::Sound>(entity);

        if (!sound._loaded)
            return;
        std::cerr << "sound vol = " << sound._sound.getVolume() << std::endl;
        sound._sound.setVolume(volume);
        std::cerr << "AFTER sound vol = " << sound._sound.getVolume() << std::endl;
    } else if (compMusic.count()) {
        rtype::component::Music &music = _ecm.getComponent<rtype::component::Music>(entity);

        if (!music._loaded)
            return;
        std::cerr << "music vol = " << music._music.getVolume() << std::endl;
        music._music.setVolume(volume);
        std::cerr << "AFTER music vol = " << music._music.getVolume() << std::endl;
    }
}

void rtype::system::Audio::pauseAll(const Entity &entity)
{
    auto entities = _ecm._eMan.getEntities();

    for (auto it = entities.begin(); it != entities.end(); it++)
        this->pause(it->first);
}

void rtype::system::Audio::pause(const Entity &entity)
{
    auto sig = _ecm._eMan.getSignature(entity);
    auto compSound = sig & Signature(idSound);
    auto compMusic = sig & Signature(idMusic);

    if (compSound.count()) {
        rtype::component::Sound &sound = _ecm.getComponent<rtype::component::Sound>(entity);

        if (!sound._paused && sound._loaded) {
            sound._sound.pause();
            sound._paused = true;
        }
    } else if (compMusic.count()) {
        rtype::component::Music &music = _ecm.getComponent<rtype::component::Music>(entity);

        if (!music._paused && music._loaded) {
            music._music.pause();
            music._paused = true;
        }
    }
}

void rtype::system::Audio::resumeAll(const Entity &entity)
{
    auto entities = _ecm._eMan.getEntities();

    for (auto it = entities.begin(); it != entities.end(); it++)
        this->resume(it->first);
}

void rtype::system::Audio::resume(const Entity &entity)
{
    auto sig = _ecm._eMan.getSignature(entity);
    auto compSound = sig & Signature(idSound);
    auto compMusic = sig & Signature(idMusic);

    if (compSound.count()) {
        rtype::component::Sound &sound = _ecm.getComponent<rtype::component::Sound>(entity);

        if (sound._paused && sound._loaded) {
            sound._sound.play();
            sound._paused = false;
        }
    } else if (compMusic.count()) {
        rtype::component::Music &music = _ecm.getComponent<rtype::component::Music>(entity);

        if (music._paused && music._loaded) {
            music._music.play();
            music._paused = false;
        }
    }
}

void rtype::system::Audio::restartAudioAll(const Entity &entity)
{
    auto entities = _ecm._eMan.getEntities();

    for (auto it = entities.begin(); it != entities.end(); it++)
        this->restartAudio(it->first);
}

void rtype::system::Audio::restartAudio(const Entity &entity)
{
    auto sig = _ecm._eMan.getSignature(entity);
    auto compSound = sig & Signature(idSound);
    auto compMusic = sig & Signature(idMusic);

    if (compSound.count()) {
        rtype::component::Sound &sound = _ecm.getComponent<rtype::component::Sound>(entity);

        if (!sound._loaded)
            return;
        sound._sound.stop();
        sound._sound.play();
        sound._paused = false;
        sound._playing = false;
    } else if (compMusic.count()) {
        rtype::component::Music &music = _ecm.getComponent<rtype::component::Music>(entity);

        if (!music._loaded)
            return;
        music._music.stop();
        music._music.play();
        music._paused = false;
        music._playing = false;
    }
}
