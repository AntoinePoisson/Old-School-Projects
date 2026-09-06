/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** Particles.hpp
*/

#ifndef __PARTICLES_HPP_
#define __PARTICLES_HPP_

#include "Indie.hpp"
#include "Clock.hpp"

namespace indie
{
    class Particles
    {
        public:
            Particles() = default;
            Particles(const int &x, const int &z, const int &orientation, const int &size);
            virtual ~Particles();
        private:
            irr::scene::IParticleSystemSceneNode *ps = NULL;
            indie::Clock duration;
    };
}

#endif