/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Graphic
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_

#include "shared.h"
#include "Map.hpp"
#include <SFML/Graphics.hpp>
#include <map>
#include "Exception.hpp"


const std::string assets_dir = "./client_graphic/assets/";

typedef struct Img
{
    sf::Sprite _sprite;
    sf::Texture _texture;
} Img;

static std::map<std::string, std::string> mapAssets = {
    {"cell", "cell.png"},
    {"player_up", "player_up.png"},
    {"player_down", "player_down.png"},
    {"player_left", "player_left.png"},
    {"player_right", "player_right.png"},
    {"food", "food.png"},
    {"linemate", "linemate.png"},
    {"deraumere", "deraumere.png"},
    {"sibur", "sibur.png"},
    {"mendiane", "mendiane.png"},
    {"phiras", "phiras.png"},
    {"thystame", "thystame.png"},
    {"egg", "egg.png"}
};

static std::map<enum Element, std::string> mapEnumKey = {
    {PLAYER_UP, "player_up"},
    {PLAYER_DOWN, "player_down"},
    {PLAYER_LEFT, "player_left"},
    {PLAYER_RIGHT, "player_right"},
    {FOOD, "food"},
    {LINEMATE, "linemate"},
    {DERAUMERE, "deraumere"},
    {SIBUR, "sibur"},
    {MENDIANE, "mediane"},
    {PHIRAS, "phiras"}, 
    {THYSTAME, "thystame"},
    {EGG, "egg"}
};

class Graphic {
    float _scale_cell = 1;
    int _x;
    int _y;
    Map _cells;
    std::map<std::string, Img> _assets;

    sf::RenderWindow _window;
    sf::Event _event;
    bool _close;


    public:
        Graphic(int x, int y);
        ~Graphic();
        //private
        void displayItem(int i, std::pair<enum Element, unsigned int> key, pos_t pos, Cell cell);
        void displayCell(int x, int y);
        
        //public
        void displayMap();
        bool isOpen();

        // private
        void loadAsset(const std::string &key);
        void draw(const std::string &key, sf::Vector2f pos);

        //public
        void refreshMap(const std::vector<cell_t> &cell);
        bool windowClose();
};

#endif