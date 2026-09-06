/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Display
*/

#ifndef COMMONCOMPONENTDISPLAY_HPP_
#define COMMONCOMPONENTDISPLAY_HPP_

#include "components/Exception.hpp"
#include "components/AComponent.hpp"
#include "components/Physics.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

namespace rtype {
    namespace component {

        enum drawOrder {
            FIRST = 0, // background
            SECOND, // player, enemies, bullet, ...
            THIRD, // Menu and it's button
        };

        struct Text : public AComponent
        {
            Text(const std::string &font, const std::string &str, int x, int y, size_t size = 24,
                 sf::Color color = sf::Color::White, long style = sf::Text::Regular)
                : AComponent(), _str(str), _loaded(true), _pos(x, y)
            {
                if (!_font.loadFromFile(font)) {
                    std::cerr << "[COMMON]: [COMPONENT]: [TEXT]: can't load font file : " << font << std::endl;
                    // throw Exception("can't load font '" + font + "'", "COMMON]: [COMPONENT]: [TEXT");
                    _loaded = false;
                    return;
                }
                _path = font;
                _color = color;
                _style = style;
                _size = size;
                _text.setFont(_font);
                _text.setString(str);
                _text.setCharacterSize(size);
                _text.setFillColor(color);
                _text.setStyle(style);
            };

            Text(const Text &t) : AComponent(), _font(t._font), _pos(t._pos) {
                _text.setFont(_font);
                _text.setString(t._str);
                _text.setCharacterSize(t._size);
                _text.setFillColor(t._color);
                _text.setStyle(t._style);
                _style = t._style;
                _color = t._color;
                _loaded = t._loaded;
                _str = t._str;
                _size = t._size;
                // _pos = t._pos;
            }
            std::string _path;
            sf::Font _font;
            sf::Text _text;
            std::string _str;
            size_t _size;
            bool _loaded;
            sf::Color _color;
            long _style;
            Position _pos;
        };

        struct Sprite : public AComponent
        {
            Sprite(const std::string &image) : AComponent(), _loaded(true), _rect(sf::Vector2f(120.f, 50.f))
            {
                if (!_texture.loadFromFile(image)) {
                    std::cerr << "[COMMON]: [COMPONENT]: [SPRITE]: can't load image file : " << image << std::endl;
                    // throw Exception("can't load image '" + image + "'", "COMMON]: [COMPONENT]: [SPRITE");
                    _loaded = false;
                    return;
                }
                _sprite.setTexture(_texture);
            };

            Sprite(const Sprite &cpy) : _texture(cpy._texture), _sprite(_texture) {
                // std::cout << "cpy" << std::endl;
                _rect = cpy._rect;
                _loaded = cpy._loaded;
            }

            bool _loaded;
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::RectangleShape _rect;
        };

        struct SpriteSheet : public AComponent
        {
            SpriteSheet(int offset, int nbSheet, 
                std::chrono::milliseconds duration, bool loop = true)
                : AComponent(), _offset(offset), _nbSheet(nbSheet),
                  _duration(duration), _loop(loop), _lastPos(0), _firstTurn(true) {
                        _lastTime = std::chrono::system_clock::now();
                        _creationDate = _lastTime;
                        // std::chrono::miliiseconds _creationDate = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch()).count();

                        // _lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch()).count();
                  };
                  //cpy ctor

            int _offset;
            int _nbSheet;
            std::chrono::milliseconds _duration;
            // time_t _duration;
            bool _loop;
            bool _firstTurn;
            int _lastPos;
            // std::chrono::milliseconds _lastTime;
            std::chrono::time_point<std::chrono::system_clock>  _lastTime;
            std::chrono::time_point<std::chrono::system_clock>  _creationDate;
        };

        struct DisplayOrder : public AComponent
        {
            DisplayOrder(drawOrder order) : AComponent(), _order(order) {};

            drawOrder _order;
        };

        struct TimerMob : public AComponent
        {
            TimerMob(std::time_t timer, double x, double y)
                : AComponent(), _timer(timer), _x(x), _y(y) {};

            double _x;
            double _y;
            std::time_t _timer;
        };
    }
}

#endif /* !COMMONCOMPONENTDISPLAY_HPP_ */
