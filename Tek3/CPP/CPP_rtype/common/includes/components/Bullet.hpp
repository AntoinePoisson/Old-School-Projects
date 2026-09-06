/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Bullet
*/

#ifndef COMMONCOMPONENTBULLET_HPP_
#define COMMONCOMPONENTBULLET_HPP_

#include "components/AComponent.hpp"

namespace rtype {
    namespace component {

        //Map
        //old list: sprite, edgeComponent, speed, time, music, (et donc pour changer de scene, on change de map),
        //new list: sprite, sprite sheet(specify rect),
        //surface(used for sprite sheet), position, speed sprite sheet, music

        //Bullet
        //CollidedComponent, PositionComponent, DestinationComponent, StatingTimeComponent
        //SpeedComponent, (SurfaceComponent pas sûr), DamageComponent
        //SpriteComponent, AudioSoundComponent
        //sprite, sound

        //SFML
        //rotation in the range [0, 360].
        //sf::Vector2f
        //sf::FloatRect
        //sf::Texture
        //sf::Sprite
        //sf::RenderWindow
    }
}

#endif /* !COMMONCOMPONENTBULLET_HPP_ */
