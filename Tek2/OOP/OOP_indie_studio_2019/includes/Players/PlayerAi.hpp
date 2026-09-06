/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerAi
*/

#ifndef PLAYERAI_HPP_
#define PLAYERAI_HPP_

#include <map>
#include <utility>
#include <cmath>
#include <array>

#include "AObject.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Bomb.hpp"

namespace indie
{
    template<typename T>
    class PlayerAi : public APlayer {
        public:
            PlayerAi(const T &x = 0, const T &y = 0, const T &z = 0, const int8_t &color = 0);
            virtual ~PlayerAi() = default;

            void setBinding(const T &left = 0, const T &up = 0, const T &right = 0, const T &down = 0, const T &bomb = 0) final;
            direction_t checkCanMove(const int &input) const final;
            int checkPlayers(const std::vector<Box> &boxes, const std::vector<APlayer *> &players);
            void setMap(Map &map, std::vector<std::shared_ptr<Bomb>> bombs);
            ObjectType getType() const final;
        private:
            const std::pair<bool, int> checkBomb(const std::vector<Box> &boxes);
            bool canAttack(const vector3di &you, const vector3di &target);
            bool boxPresent(T x, T z, const std::vector<Box> &boxes);
        private:
            std::map<std::pair<T, T>, T> _map;
            indie::Clock _wait;
            int _actual;
            int _moves;
            int _direction;
    };
}

template<typename T>
indie::PlayerAi<T>::PlayerAi(const T &x, const T &y, const T &z, const int8_t &color)
    : _actual(0), _moves(MULTIPLICATOR), _direction(-1)
{
    _nbr_bomb = DEFAULT_NBR_BOMB;
    setObject("./ressources/assets/player/bomberman.md3");
    _color = color;
    setTexture(std::string("./ressources/assets/player/body" + std::to_string(color) + ".png"));
    setPosition(x, y, z);
    _texture->setAnimationSpeed(50);
    _size = std::round(std::cbrt(_obj->getBoundingBox().getVolume()));
    _wait.restart();
}

template<typename T>
void indie::PlayerAi<T>::setBinding(const T &left, const T &up, const T &right, const T &down, const T &bomb)
{
    return;
}

template<typename T>
indie::direction_t indie::PlayerAi<T>::checkCanMove(const int &input) const
{
    switch (input) {
        case 0: return indie::Left;
        case 1: return indie::Up;
        case 2: return indie::Right;
        case 3: return indie::Down;
        case 4: if (_nbr_bomb > 0)
                    return indie::Bomber;
        default: return indie::None;
    };
}

template<typename T>
void indie::PlayerAi<T>::setMap(indie::Map &map, std::vector<std::shared_ptr<indie::Bomb>> bombs)
{
    int i = 0, j = 0;

    for (auto line : map.getMap()) {
        for (auto x : line)
            _map[std::make_pair(i, j++)] = (x == indie::map::mapElement_t::Nothing) ? ' ' : 'x';
        j = 0;
        ++i;
    }
    for (auto &box : map.getBox())
        switch (box.getType()) {
            case indie::ObjectType::NONE: _map[std::make_pair(box.getZ() / (3 * MULTIPLICATOR), box.getX() / (3 * MULTIPLICATOR))] = ' '; break;
            case indie::ObjectType::BOX: _map[std::make_pair(box.getZ() / (3 * MULTIPLICATOR), box.getX() / (3 * MULTIPLICATOR))] = 'z'; break;
            default: _map[std::make_pair(box.getZ() / (3 * MULTIPLICATOR), box.getX() / (3 * MULTIPLICATOR))] = 'p';
        }
    for (auto bomb : bombs) {
        if (!bomb->getState())
            continue;
        std::array<bool, 4> stop = {false};
        const int x = bomb->getCenter().Z / (3 * MULTIPLICATOR), y = bomb->getCenter().X / (3 * MULTIPLICATOR);

        _map[std::make_pair(x, y)] = 'o';
        for (int a(1); a < bomb->getRangeBomb() + 1; a++) {
            if (!stop[0] && _map[std::make_pair(x + a, y)] != 'x')
                { if (_map[std::make_pair(x + a, y)] == 'z') stop[0] = true; _map[std::make_pair(x + a, y)] = 'o'; } else stop[0] = true;
            if (!stop[1] && _map[std::make_pair(x - a, y)] != 'x')
                { if (_map[std::make_pair(x - a, y)] == 'z') stop[1] = true; _map[std::make_pair(x - a, y)] = 'o'; } else stop[1] = true;
            if (!stop[2] && _map[std::make_pair(x, y + a)] != 'x')
                { if (_map[std::make_pair(x, y + a)] == 'z') stop[2] = true; _map[std::make_pair(x, y + a)] = 'o'; } else stop[2] = true;
            if (!stop[3] && _map[std::make_pair(x, y - a)] != 'x')
                { if (_map[std::make_pair(x, y - a)] == 'z') stop[3] = true; _map[std::make_pair(x, y - a)] = 'o'; } else stop[3] = true;
        }
    }
    _actual = _map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR) + 1)];
    _up     = _map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 2, getCenter().X / (3 * MULTIPLICATOR) + 1)];
    _down   = _map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR), getCenter().X / (3 * MULTIPLICATOR) + 1)];
    _right  = _map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR) + 2)];
    _left   = _map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR))];
}

template<typename T>
bool indie::PlayerAi<T>::canAttack(const vector3di &you, const vector3di &target)
{
    if ((you.X / (3 * MULTIPLICATOR) + 1) == (target.X / (3 * MULTIPLICATOR) + 1) && std::abs((you.Z / (3 * MULTIPLICATOR) + 1) - (target.Z / (3 * MULTIPLICATOR) + 1)) <= getRangeBomb())
        if (((you.Z - target.Z > 0) ? _left : _right) == ' ' || ((you.Z - target.Z > 0) ? _left : _right) == 'p')
            return true;
    if ((you.Z / (3 * MULTIPLICATOR) + 1) == (target.Z / (3 * MULTIPLICATOR) + 1) && std::abs((you.X / (3 * MULTIPLICATOR) + 1) - (target.X / (3 * MULTIPLICATOR) + 1)) <= getRangeBomb())
        if (((you.X - target.X < 0) ? _up : _down) == ' ' || ((you.X - target.X < 0) ? _up : _down) == 'p')
            return true;
    return false;
}

template<typename T>
int indie::PlayerAi<T>::checkPlayers(const std::vector<indie::Box> &boxes, const std::vector<indie::APlayer *> &players)
{
    if (_moves++ < MULTIPLICATOR)
        return _direction;
    const auto in_danger = checkBomb(boxes);
    if (in_danger.first) {
        _moves = 0;
        _direction = in_danger.second;
        return -1;
    }
    vector3di you(getCenter().Z, 0, getCenter().X);
    vector3di target(0);

    for (auto player : players) {
        if (player == this || player->getState() == false)
            continue;
        if (target.X == 0 && target.Z == 0)
            target = { player->getCenter().Z, 0, player->getCenter().X };
        else if (sqrt(pow((player->getCenter().Z) - you.X, 2) + pow((player->getCenter().X) - you.Z, 2)) < sqrt(pow(target.X - you.X, 2) + pow(target.Z - you.Z, 2)))
            target = { player->getCenter().Z, 0, player->getCenter().X };
    }
    if (canAttack(you, target) && getNbBomb() > 0 && _wait.getElapsedTime() >= 2000) {
        _wait.restart();
        return 4;
    }
    for (auto &box : boxes) {
        if (box.getType() == indie::ObjectType::NONE || box.getType() == indie::ObjectType::BOX)
            continue;
        if (getNbBomb() == 0 || sqrt(pow(box.getZ() - you.X, 2) + pow(box.getX() - you.Z, 2)) < sqrt(pow(target.X - you.X, 2) + pow(target.Z - you.Z, 2)))
            target = { box.getZ(), 0, box.getX() };
    }
    auto d = std::make_pair(you.X - target.X, you.Z - target.Z);
    std::array<std::pair<int, T>, 2> choice = { (d.first > 0) ? std::make_pair(3, _down) : std::make_pair(1 , _up), (d.second > 0) ? std::make_pair(0, _left) : std::make_pair(2, _right) };

    if (abs(d.first) > 21 && (choice[0].second == ' ' || choice[0].second == 'p' || choice[0].second == 'z')) {
        if (choice[0].second == 'z' && getNbBomb() > 0 && _wait.getElapsedTime() >= 2000) {
            _wait.restart();
            return 4;
        }
        _moves = 0;
        _direction = choice[0].first;
        return -1;
    } else if (abs(d.second) > 21 && (choice[1].second == ' ' || choice[1].second == 'p' || choice[1].second == 'z')) {
        if (choice[1].second == 'z' && getNbBomb() > 0 && _wait.getElapsedTime() >= 2000) {
            _wait.restart();
            return 4;
        }
        _moves = 0;
        _direction = choice[1].first;
        return -1;
    }
    std::array<T, 2> reset = { (choice[0].first == 3) ? _up : _down, (choice[1].first == 0) ? _right : _left };

    if (abs(d.first) > 21 && (reset[0] == ' ' || reset[0] == 'p' || reset[0] == 'z')) {
        if (reset[0] == 'z' && getNbBomb() > 0 && _wait.getElapsedTime() >= 2000) {
            _wait.restart();
            return 4;
        }
        _moves = 0;
        _direction = (choice[0].first == 3) ? 1 : 3;
        return -1;
    } else if (abs(d.second) > 21 && (reset[1] == ' ' || reset[1] == 'p' || reset[1] == 'z')) {
        if (reset[1] == 'z' && getNbBomb() > 0 && _wait.getElapsedTime() >= 2000) {
            _wait.restart();
            return 4;
        }
        _moves = 0;
        _direction = (choice[1].first == 0) ? 2 : 0;
        return -1;
    }
    return 4;
}

template<typename T>
bool indie::PlayerAi<T>::boxPresent(T x, T z, const std::vector<Box> &boxes)
{
    for (auto &box : boxes)
        if (box.getType() == indie::ObjectType::BOX)
            if (x == (box.getZ() / (3 * MULTIPLICATOR)) && z == (box.getX() / (3 * MULTIPLICATOR)))
                return true;
    return false;
}

template<typename T>
const std::pair<bool, int> indie::PlayerAi<T>::checkBomb(const std::vector<Box> &boxes)
{
    if (_actual != 'o')
        return std::make_pair(false, -1);
    int count(0);
    std::array<int, 4> dir = {0, 0, 0, 0};
    std::array<int, 4> urgency = {0, 0, 0, 0};
    for (count = 1; ; count++) {
        if (_map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR) + 1 - count)] == 'x' ||
            _map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR) + 1 - count)] == 'z' ||
            boxPresent(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR) + 1 - count, boxes) == true)
            { dir[0] = 10000; urgency[0] = count; break; }
        if (_map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR) + 1 - count)] != 'o')
            { dir[0] = count; break; }
    }
    for (count = 1; ; count++) {
        if (_map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1 + count, getCenter().X / (3 * MULTIPLICATOR) + 1)] == 'x' ||
            _map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1 + count, getCenter().X / (3 * MULTIPLICATOR) + 1)] == 'z' ||
            boxPresent(getCenter().Z / (3 * MULTIPLICATOR) + 1 + count, getCenter().X / (3 * MULTIPLICATOR) + 1, boxes) == true)
            { dir[1] = 10000; urgency[1] = count; break; }
        if (_map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1 + count, getCenter().X / (3 * MULTIPLICATOR) + 1)] != 'o')
            { dir[1] = count; break; }
    }
    for (count = 1; ; count++) {
        if (_map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR) + 1 + count)] == 'x' ||
            _map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR) + 1 + count)] == 'z' ||
            boxPresent(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR) + 1 + count, boxes) == true)
            { dir[2] = 10000; urgency[2] = count; break; }
        if (_map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1, getCenter().X / (3 * MULTIPLICATOR) + 1 + count)] != 'o')
            { dir[2] = count; break; }
    }
    for (count = 1; ; count++) {
        if (_map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1 - count, getCenter().X / (3 * MULTIPLICATOR) + 1)] == 'x' ||
            _map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1 - count, getCenter().X / (3 * MULTIPLICATOR) + 1)] == 'z' ||
            boxPresent(getCenter().Z / (3 * MULTIPLICATOR) + 1 - count, getCenter().X / (3 * MULTIPLICATOR) + 1, boxes) == true)
            { dir[3] = 10000; urgency[3] = count; break; }
        if (_map[std::make_pair(getCenter().Z / (3 * MULTIPLICATOR) + 1 - count, getCenter().X / (3 * MULTIPLICATOR) + 1)] != 'o')
            { dir[3] = count; break; }
    }
    if (dir[0] == 10000 && dir[1] == 10000 && dir[2] == 10000 && dir[3] == 10000) {
        std::vector<int> urg = {urgency[0], urgency[1], urgency[2], urgency[3]};
        urg.erase(std::remove_if(urg.begin(), urg.end(), [](int &x) -> bool { return x < 2; }), urg.end());
        for (auto index : {0, 1, 2, 3})
            if (urgency[index] == *min_element(urg.begin(), urg.end()))
                return std::make_pair(true, index);
    }
    return std::make_pair(true, std::distance(std::begin(dir), std::min_element(std::begin(dir), std::end(dir))));
}

template<typename T>
indie::ObjectType indie::PlayerAi<T>::getType() const
{
    return indie::ObjectType::AI;
}

#endif /* !PLAYERAI_HPP_ */
