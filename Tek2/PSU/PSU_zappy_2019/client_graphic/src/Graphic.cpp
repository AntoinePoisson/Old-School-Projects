/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Graphic
*/

#include "Graphic.hpp"

Graphic::Graphic(int x, int y): _x(x), _y(y), _cells(x, y), _window(sf::VideoMode(800, 600), "Zappy Graphic Client"), _close(false) {
    if (sizeCell * _scale_cell * x > 1080) {
        _scale_cell = 1080.f / (x * sizeCell);
    }
    if (sizeCell * _scale_cell * y > 720) {
        _scale_cell = 720.f / (y * sizeCell);
    }
    for (auto asset: mapAssets)
        loadAsset(asset.first);
};

void Graphic::displayItem(int i, std::pair<enum Element, unsigned int> key, pos_t pos, Cell cell)
{
    static bool init = false;
    static sf::Text text;
    static sf::Font font;
    pos_t new_pos = pos;

    if (!init) {
        init = true;
        font.loadFromFile("client_graphic/assets/font.ttf");
        text.setFont(font);
        text.setCharacterSize(10);
        text.setFillColor(sf::Color(0, 0, 0));
        text.setOutlineColor(sf::Color(255, 255, 255));
    }
    if (i == 0) {
        new_pos = {pos.first, pos.second};
    }
    if (i == 1) {
        new_pos = {pos.first + (_scale_cell * sizeCell) / 3 * 1, pos.second};
    }
    if (i == 2) {
        new_pos = {pos.first + (_scale_cell * sizeCell) / 3 * 2, pos.second};
    }
    if (i == 3) {
        new_pos = {pos.first, pos.second + (_scale_cell * sizeCell) / 3 * 1};
    }
    if (i == 4) {
        new_pos = {pos.first + (_scale_cell * sizeCell) / 3 * 1, pos.second + (_scale_cell * sizeCell) / 3 * 1};
    }
    if (i == 5) {
        new_pos = {pos.first + (_scale_cell * sizeCell) / 3 * 2, pos.second + (_scale_cell * sizeCell) / 3 * 1};
    }
    if (i == 6) {
        new_pos = {pos.first, pos.second +  (_scale_cell * sizeCell) / 3 * 2};
    }
    if (i == 7) {
        new_pos = {pos.first + (_scale_cell * sizeCell) / 3 * 1, pos.second + (_scale_cell * sizeCell) / 3 * 2};
    }
    if (i == 8) {
        new_pos = {pos.first + (_scale_cell * sizeCell) / 3 * 2, pos.second + (_scale_cell * sizeCell) / 3 * 2};
    }
    if (key.first != NOTHING) {
        draw(mapEnumKey[key.first], {static_cast<float>(new_pos.first), static_cast<float>(new_pos.second)});
        if (key.second > 1) {
            text.setString(std::to_string(key.second));
            text.setPosition(sf::Vector2f(new_pos.first + 3, new_pos.second - 1));
            _window.draw(text);
        }
        fflush(stdout);
    }
}

void Graphic::displayCell(int x, int y) {
    draw("cell", sf::Vector2f((float) x* sizeCell * _scale_cell, (float)y* sizeCell * _scale_cell));
    for (int i = 0
        ; i < _cells.getCell(x, y)._arr.size(); i++) {
        if (_cells.getCell(x, y)._arr[i].first != NOTHING) {
            displayItem(i, _cells.getCell(x, y)._arr[i], {(float)x* sizeCell * _scale_cell, (float)y* sizeCell * _scale_cell}, _cells.getCell(x, y));
        }
    }
}

void Graphic::displayMap() {
    this->_window.clear();
    for (int y = 0; y < _y; y++) {
        for (int x = 0; x < _x; x++) {
            displayCell(x, y);
        }
    }
    this->_window.display();
}

void Graphic::loadAsset(const std::string &key)
{
    if (!_assets[key]._texture.loadFromFile(assets_dir + mapAssets[key])) {
        throw GraphicException("load asset failed");
    }
    _assets[key]._sprite.setTexture(_assets[key]._texture);
    if (_scale_cell != 1) {
        _assets[key]._sprite.setScale(_scale_cell, _scale_cell);
    }
}

void Graphic::draw(const std::string &key, sf::Vector2f pos)
{
    this->_assets[key]._sprite.setPosition(pos);
    this->_window.draw(this->_assets[key]._sprite);
}

void Graphic::refreshMap(const std::vector<cell_t> &cells)
{
    for (auto cell: cells)
        _cells.updateCell(cell.x, cell.y, cell);
}

bool Graphic::isOpen()
{
    if (!this->_window.isOpen() || _close == true)
        return (false);
    return (true);
}

Graphic::~Graphic()
{
    this->_window.close();
}

bool Graphic::windowClose()
{
    if (this->isOpen())
        if (_window.pollEvent(_event))
            if (_event.type == sf::Event::Closed) {
                _close = true;
                return true;
            }
    return false;
}