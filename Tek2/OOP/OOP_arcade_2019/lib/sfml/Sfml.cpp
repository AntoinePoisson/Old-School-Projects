/*
** EPITECH PROJECT, 2020
** Sfml
** File description:
** Sfml
*/

#include "Sfml.hpp"

    //Constructor
ArcadeLib::Sfml::Sfml()
    : window(sf::VideoMode(1800, 1000), "SFML window", sf::Style::Titlebar | sf::Style::Close)
{
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
    window.setVerticalSyncEnabled(true);
    if (!font.loadFromFile("./resources/fonts/menu.ttf"))
        throw 0;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setString("");
    text.setFillColor(sf::Color::White);
}
    //Class Methode
extern "C" Arcade::IGraphics *create()
{
    return (new ArcadeLib::Sfml());
}

extern "C" char ArcadeLib::Sfml::getEvent() 
{
    if (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return (0);
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && limitSwitchLib.getElapsedTime().asMilliseconds() >= 100)
                return (97);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                return (98);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                return (99);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                return (100);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && limitSwitchLib.getElapsedTime().asMilliseconds() >= 100)
                return (101);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                return (102);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
                return (103);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
                return (104);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
                return (105);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
                return (106);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                return (107);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                return (108);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                return (109);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
                return (110);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
                return (111);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                return (112);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                return (113);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                return (114);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                return (115);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
                return (116);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
                return (117);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
                return (118);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                return (119);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
                return (120);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
                return (121);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                return (122);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                return (27);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                return (10);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                return (49);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                return (50);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                return (51);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                return (52);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
                return (53);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                return (54);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
                return (55);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
                return (56);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
                return (57);
        }
    }
    return (-1);
}

extern "C" void ArcadeLib::Sfml::print(display_t &display) 
{
    sf::Texture texture;
    sf::Sprite sprite;

    if (!display.isPrint)
        return;
    if (display.image != "") {
        if (!(texture.loadFromFile(display.image))) {
            std::cout << "SFML: Cannot load image: " << display.image << std::endl;
            if (display.ascii != "") {
                text.setString(display.ascii);
                text.setPosition((sf::Vector2f){display.x, display.y});
                window.draw(text);
            }
            return;
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setPosition((sf::Vector2f){display.x, display.y});
        window.draw(sprite);
    } else if (display.ascii != "") {
        text.setString(display.ascii);
        text.setPosition((sf::Vector2f){display.x, display.y});
        window.draw(text);    
    }
}

extern "C" void ArcadeLib::Sfml::destructor() 
{
    window.close();
}

extern "C" bool ArcadeLib::Sfml::clockDisplay()
{
    if (clock.getElapsedTime().asMicroseconds() > 150000) {
        clock.restart();
        return (true);
    }
    return (false);
}

extern "C" void ArcadeLib::Sfml::refresh() 
{
    window.display();
    window.clear();
}

extern "C" int ArcadeLib::Sfml::getWindowHeight()
{
    return (window.getSize().y);
}

extern "C" int ArcadeLib::Sfml::getWindowWidth()
{
    return (window.getSize().x);
}