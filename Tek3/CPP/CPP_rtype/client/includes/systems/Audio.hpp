/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Systems
*/

#ifndef COMMONSYSTEMAUDIO_HPP
#define COMMONSYSTEMAUDIO_HPP

#include <map>
#include <iostream>
#include "systems/Exception.hpp"
#include "systems/ASystem.hpp"
#include "entities/ComponentManager.hpp" // for ComponentManager
#include "entities/IManager.hpp" // for Signature
#include "components/Sound.hpp"


namespace rtype {
    namespace system {

        class Audio : public ASystem
        {
            rtype::entity::ComponentManager &_ecm;

        public:
            Audio(rtype::entity::ComponentManager &ecm);
            ~Audio();

            void update(const Entity &e);

            void setVolumeAll(const Entity &entity, double volume);
            void setVolume(const Entity &entity, double volume);
            void pauseAll(const Entity &entity);
            void pause(const Entity &entity);
            void resumeAll(const Entity &entity);
            void resume(const Entity &entity);
            void restartAudioAll(const Entity &entity);
            void restartAudio(const Entity &entity);
        };
    }
}

#endif /* !COMMONSYSTEMAUDIO_HPP_ */
