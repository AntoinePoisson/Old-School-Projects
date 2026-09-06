/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Events
*/

#ifndef COMMONCOMPONENTEVENTS_HPP_
#define COMMONCOMPONENTEVENTS_HPP_

#include "components/AComponent.hpp"
#include <SFML/Graphics.hpp>

namespace rtype {
    namespace component {

        enum keyboardEventType {
            RIGHT = 1,
            LEFT = 2,
            UP = 4,
            DOWN = 8,
            SHOOT = 16,
            MENU = 32,
            PLAY = 64,
            QUIT = 128,
            TUTORIAL = 256,// keep it?
        };

        struct ListAction : public AComponent
        {
            ListAction() : AComponent()
            {
                _list = {
                    {rtype::component::RIGHT, sf::Keyboard::Right},
                    {rtype::component::LEFT, sf::Keyboard::Left},
                    {rtype::component::UP, sf::Keyboard::Up},
                    {rtype::component::DOWN, sf::Keyboard::Down},
                    {rtype::component::SHOOT, sf::Keyboard::S},
                    {rtype::component::MENU, sf::Keyboard::Pause},
                    {rtype::component::PLAY, sf::Keyboard::Insert},
                    {rtype::component::QUIT, sf::Keyboard::Escape},
                    {rtype::component::TUTORIAL, sf::Keyboard::T}
                };
            };

            std::map<rtype::component::keyboardEventType, int> _list;
        };

        struct SFMLEvent : public AComponent
        {
            SFMLEvent() : AComponent() {};

            sf::Event _event;
        };

        struct KeyboardEvent : public AComponent
        {
            KeyboardEvent(std::vector<keyboardEventType> keys) : AComponent(), _keys(keys) {};

            std::vector<keyboardEventType> _keys;
        };

        struct MouseEvent : public AComponent
        {
            MouseEvent(std::vector<sf::Vector2i> pos) : AComponent(), _pos(pos) {};

            std::vector<sf::Vector2i> _pos;
        };

        struct ConceidedDamage : public AComponent
        {
            ConceidedDamage(double damage) : AComponent(), _damageAmount(damage) {};

            double _damageAmount;
        };

    }
}

#endif /* !COMMONCOMPONENTEVENTS_HPP_ */
