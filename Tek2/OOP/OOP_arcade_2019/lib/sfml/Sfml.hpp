/*
** EPITECH PROJECT, 2020
** Sfml
** File description:
** Sfml
*/

#ifndef SFML_HPP
#define SFML_HPP

#include <SFML/Graphics.hpp>
#include "IGraphics.hpp"

namespace ArcadeLib {

    class Sfml : public Arcade::IGraphics {
        public:
            Sfml();
            ~Sfml() = default;

            Arcade::IGraphics *create();
            char getEvent();
            void print(display_t &display);
            void destructor();
            void refresh();
            int getWindowHeight();
            int getWindowWidth();
            bool clockDisplay();

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            sf::Event event;
            sf::Clock limitSwitchLib;
            sf::Font font;
            sf::Text text;
    };

}

#endif /* !SFML_HPP */
