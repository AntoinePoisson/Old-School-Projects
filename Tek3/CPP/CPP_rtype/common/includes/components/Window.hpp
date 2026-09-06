/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Events
*/

#ifndef COMMONCOMPONENTWINDOW_HPP_
#define COMMONCOMPONENTWINDOW_HPP_

#include "components/AComponent.hpp"
#include <SFML/Graphics.hpp>

namespace rtype {
    namespace component {

        struct SFMLWindow : public AComponent
        {
            SFMLWindow() : AComponent(), _window(sf::VideoMode(1920, 1080), "R-Type") {};

            sf::RenderWindow _window;
        };
    }
}

#endif /* !COMMONCOMPONENTWINDOW_HPP_ */
