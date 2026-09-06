/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Main
*/

#ifndef MAIN_HPP_
#define MAIN_HPP_

typedef std::pair<std::string, sf::Music *> listMusic_t;

namespace indie {
    Irrlicht *irrlicht;
    std::vector<listMusic_t> listMusics;
}

#endif /* !MAIN_HPP_ */
