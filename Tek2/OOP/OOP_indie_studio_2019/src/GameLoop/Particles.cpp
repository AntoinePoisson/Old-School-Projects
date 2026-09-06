/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** Particles.cpp
*/

#include "Particles.hpp"

indie::Particles::Particles(const int &x, const int &z, const int &orientation, const int &size)
{
    ps = indie::irrlicht->smgr->addParticleSystemSceneNode(false);
    core::vector3df dir;

    if (orientation == 0)
        dir = core::vector3df(0.f, 0.f, 0.022f);
    else if (orientation == 1)
        dir = core::vector3df(0.f, 0.f, -0.022f);
    else if (orientation == 2)
        dir = core::vector3df(0.022f, 0.f, 0.f);
    else
        dir = core::vector3df(-0.022f, 0.f, 0.f);

    int age = ((75 / indie::irrlicht->fps) / 0.018) * size * 2.0;
    scene::IParticleEmitter *em = ps->createBoxEmitter(
        core::aabbox3d<f32>(-7, 0, -7, 7, 1, 7), // emitter size
        dir,                                     // initial direction
        80, 100,                                 // emit rate
        video::SColor(0, 255, 255, 255),         // darkest color
        video::SColor(0, 255, 255, 255),         // brightest color
        age, age + 40, 0,                              // min and max age, angle
        core::dimension2df(1.f, 1.f),            // min size
        core::dimension2df(1.f, 1.f));           // max size

    ps->setEmitter(em); // this grabs the emitter

    scene::IParticleAffector *paf = ps->createFadeOutParticleAffector(SColor(128, 255, 255, 255));

    ps->addAffector(paf); // same goes for the affector

    ps->setScale(core::vector3df(.1, .1, .1));
    ps->setMaterialFlag(video::EMF_LIGHTING, false);
    ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
    irr::video::ITexture *textureTmp = indie::irrlicht->driver->getTexture("./ressources/images/explosion.png");
    if (textureTmp == nullptr)
        throw (indie::error::Image("./ressources/images/explosion.png"));
    ps->setMaterialTexture(0, textureTmp);
    ps->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL);
    ps->setPosition(core::vector3df(x, 0, z));
}

indie::Particles::~Particles()
{
    ps->remove();
}