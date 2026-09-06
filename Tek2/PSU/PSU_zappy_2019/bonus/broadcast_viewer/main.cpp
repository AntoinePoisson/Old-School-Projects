/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** main.cpp
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>

void shiftX(int &pos1, int &pos2, int sizeX)
{
    pos1 -= 1;
    pos2 -= 1;
    if (pos1 < 0)
        pos1 = sizeX - 1;
    if (pos2 < 0)
        pos2 = sizeX - 1;
}

void shiftY(int &pos1, int &pos2, int sizeY)
{
    pos2 -= 1;
    pos1 -= 1;
    if (pos1 < 0)
        pos1 = sizeY - 1;
    if (pos2 < 0)
        pos2 = sizeY - 1;
}

int main(void)
{
    sf::RenderWindow *window = new sf::RenderWindow(
        sf::VideoMode(
            700,
            700
        ),
        "Broadcast viewer",
        sf::Style::Close | sf::Style::Resize
    );
    int x = 10;
    int y = 10;
    int size = 30;
    srand(time(NULL));

    int pos1X = rand() % x;
    int pos1Y = rand() % y;

    int pos2X = rand() % x;
    int pos2Y = rand() % y;

    sf::Event event;
    sf::Font font;
    sf::Text text;

    int offsetX = 0;
    int offsetY = 0;

    font.loadFromFile("font.ttf");
    text.setFont(font);
    text.setCharacterSize(size / 2);
    text.setColor(sf::Color::Cyan);
    while (window->isOpen()) {
        while (window->pollEvent(event))
            ;
        //     if (event.key.code == sf::Keyboard::Escape)
        //         window->close();
        for (int yy = 0; yy < y; yy++) {
            for (int xx = 0; xx < x; xx++) {
                sf::VertexArray line(sf::LinesStrip, 2);
                line[0].position = sf::Vector2f(size * xx, size * yy);
                line[0].color  = sf::Color::White;
                line[1].position = sf::Vector2f(size * xx + size, size * yy);
                line[1].color = sf::Color::White;
                window->draw(line);

                line[0].position = sf::Vector2f(size * xx, size * yy + size);
                line[0].color  = sf::Color::White;
                line[1].position = sf::Vector2f(size * xx + size, size * yy + size);
                line[1].color = sf::Color::White;
                window->draw(line);

                line[0].position = sf::Vector2f(size * xx, size * yy);
                line[0].color  = sf::Color::White;
                line[1].position = sf::Vector2f(size * xx, size * yy + size);
                line[1].color = sf::Color::White;
                window->draw(line);

                line[0].position = sf::Vector2f(size * xx + 30, size * yy);
                line[0].color  = sf::Color::White;
                line[1].position = sf::Vector2f(size * xx + 30, size * yy + size);
                line[1].color = sf::Color::White;
                window->draw(line);
                offsetX = xx + 1;
            }
            offsetY = yy + 1;
        }
        text.setString("S");
        text.setPosition(sf::Vector2f(size * pos1X + (size / 4), size * pos1Y + (size / 4)));
        window->draw(text);
        text.setString("D");
        text.setPosition(sf::Vector2f(size * pos2X + (size / 4), size * pos2Y + (size / 4)));
        window->draw(text);
        sf::VertexArray lineOrientation(sf::LinesStrip, 2);
        lineOrientation[0].position = sf::Vector2f(size * pos1X + (size / 2), size * pos1Y + (size / 2));
        lineOrientation[0].color  = sf::Color::Red;
        lineOrientation[1].position = sf::Vector2f(size * pos2X + (size / 2), size * pos2Y + (size / 2));
        lineOrientation[1].color = sf::Color::Green;
        window->draw(lineOrientation);


        int result1X = pos1X;
        int result2X = pos2X;

        int result1Y = pos1Y;
        int result2Y = pos2Y;

        for (; abs(result1X - result2X) > x / 2; shiftX(result1X, result2X, x));
        for (; abs(result1Y - result2Y) > y / 2; shiftY(result1Y, result2Y, y));
        for (int yy = 0; yy < y; yy++) {
            for (int xx = 0; xx < x; xx++) {
                sf::VertexArray line(sf::LinesStrip, 2);
                line[0].position = sf::Vector2f(size * xx + offsetX * size, size * yy + offsetY * size);
                line[0].color  = sf::Color(150, 150, 255);
                line[1].position = sf::Vector2f(size * xx + size + offsetX * size, size * yy + offsetY * size);
                line[1].color = sf::Color(150, 150, 255);
                window->draw(line);

                line[0].position = sf::Vector2f(size * xx + offsetX * size, size * yy + size + offsetY * size);
                line[0].color  = sf::Color(150, 150, 255);
                line[1].position = sf::Vector2f(size * xx + size + offsetX * size, size * yy + size + offsetY * size);
                line[1].color = sf::Color(150, 150, 255);
                window->draw(line);

                line[0].position = sf::Vector2f(size * xx + offsetX * size, size * yy + offsetY * size);
                line[0].color  = sf::Color(150, 150, 255);
                line[1].position = sf::Vector2f(size * xx + offsetX * size, size * yy + size + offsetY * size);
                line[1].color = sf::Color(150, 150, 255);
                window->draw(line);

                line[0].position = sf::Vector2f(size * xx + 30 + offsetX * size, size * yy + offsetY * size);
                line[0].color  = sf::Color(150, 150, 255);
                line[1].position = sf::Vector2f(size * xx + 30 + offsetX * size, size * yy + size + offsetY * size);
                line[1].color = sf::Color(150, 150, 255);
                window->draw(line);
            }
        }

        text.setString("S");
        text.setPosition(sf::Vector2f(size * result1X + (size / 4) + (offsetX * size), size * result1Y + (size / 4) + (offsetY * size)));
        window->draw(text);
        text.setString("D");
        text.setPosition(sf::Vector2f(size * result2X + (size / 4) + (offsetX * size), size * result2Y + (size / 4) + (offsetY * size)));
        window->draw(text);
        sf::VertexArray lineOrientationFinal(sf::LinesStrip, 2);
        lineOrientationFinal[0].position = sf::Vector2f(size * result1X + (size / 2) + (offsetX * size), size * result1Y + (size / 2) + (offsetY * size));
        lineOrientationFinal[0].color  = sf::Color::Red;
        lineOrientationFinal[1].position = sf::Vector2f(size * result2X + (size / 2) + (offsetX * size), size * result2Y + (size / 2) + (offsetY * size));
        lineOrientationFinal[1].color = sf::Color::Green;
        window->draw(lineOrientationFinal);

        window->display();
        static bool bo = false;
        if (bo == false) {
            bo = true;
            float deg = (atan2(result1X - result2X, result1Y - result2Y) * 180 / M_PI) + 180.f;
            int degFinal = static_cast<int>(deg) % 360;
            std::cout << "degrees: " << std::to_string(degFinal) << std::endl;
        }
    }
    return (0);
}