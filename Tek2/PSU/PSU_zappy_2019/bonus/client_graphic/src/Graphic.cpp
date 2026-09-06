/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Graphic
*/

#include "Graphic.hpp"

Graphic::Graphic(int x, int y): _x(x), _y(y), _cells(x, y), _window(sf::VideoMode(800, 600), "Zappy Graphic Client"), _close(false) {
    if (sizeCell * _scale_cell * x > 1080) {
        _scale_cell = 1080 / x;
    }
    if (sizeCell * _scale_cell * y > 720) {
        _scale_cell = 720 / y;
    }
    for (auto asset: mapAssets)
        loadAsset(asset.first);
};

void Graphic::displayItem(int i, enum Element key, pos_t pos)
{
    pos_t new_pos = pos;
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
    if (key != NOTHING) {
        draw(mapEnumKey[key], {static_cast<float>(new_pos.first), static_cast<float>(new_pos.second)});
    }
}

void Graphic::displayCell(int x, int y) {
    draw("cell", sf::Vector2f((float) x* sizeCell * _scale_cell, (float)y* sizeCell * _scale_cell));
    for (int i = 0
        ; i < _cells.getCell(x, y)._arr.size(); i++) {
        if (_cells.getCell(x, y)._arr[i] != NOTHING) {
            // std::cout << "yes"<< std::endl;
            displayItem(i, _cells.getCell(x, y)._arr[i], {(float)x* sizeCell * _scale_cell, (float)y* sizeCell * _scale_cell});
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
}

void Graphic::draw(const std::string &key, sf::Vector2f pos)
{
    // std::cout << "x = " << pos.x << std::endl;
    // std::cout << "y = " << pos.y << std::endl;
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
            if (_event.type == sf::Event::Closed)
                _close = true;
}