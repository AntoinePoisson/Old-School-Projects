/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WrapPlayers
*/

#ifndef WRAPPLAYERS_HPP_
#define WRAPPLAYERS_HPP_

#include "Player.hpp"
#include "PlayerAi.hpp"
#include "Bomb.hpp"

namespace indie
{
    template<typename T>
    class WrapPlayers {
        public:
            WrapPlayers() = default;
            ~WrapPlayers() = default;

            void addPlayer(const T &x, const T &y, const T &z, const int8_t &color = 0);
            void addPlayer(Player<T> *player);
            void addPlayerAi(const T &x, const T &y, const T &z, const int8_t &color = 0);
            void addPlayerAi(PlayerAi<T> *player);
            void addBomb(int x, int y, int z, int range);
            int getNbrAlivePlayer(void);
            int getIndexLastPlayerAlive(void);
            std::vector<Player<T> *> getPlayers() const;
            std::vector<PlayerAi<T> *> getPlayersAi() const;
            std::vector<APlayer *> getAllPlayers() const;
            std::vector<std::shared_ptr<Bomb>> getBomb() const;
        public:
            std::vector<Player<T> *> _players;
            std::vector<PlayerAi<T> *> _aiPlayers;
            std::vector<std::shared_ptr<Bomb>> _bomb;
            int _indexAlive = 0;
    };
}

template<typename T>
void indie::WrapPlayers<T>::addPlayer(indie::Player<T> *player)
{
    _players.push_back(player);
}

template<typename T>
void indie::WrapPlayers<T>::addPlayer(const T &x, const T &y, const T &z, const int8_t &color)
{
    _players.push_back(new indie::Player<T>(x, y, z, color));
}

template<typename T>
void indie::WrapPlayers<T>::addPlayerAi(indie::PlayerAi<T> *player)
{
    _aiPlayers.push_back(player);
}

template<typename T>
void indie::WrapPlayers<T>::addPlayerAi(const T &x, const T &y, const T &z, const int8_t &color)
{
    _aiPlayers.push_back(new indie::PlayerAi<T>(x, y, z, color));
}

template<typename T>
void indie::WrapPlayers<T>::addBomb(int x, int y, int z, int range)
{
    std::shared_ptr<indie::Bomb> bomb = std::make_shared<indie::Bomb>(x, y, z, range);

    _bomb.push_back(bomb);
}

template<typename T>
std::vector<indie::Player<T> *> indie::WrapPlayers<T>::getPlayers() const
{
    return _players;
}

template<typename T>
std::vector<indie::PlayerAi<T> *> indie::WrapPlayers<T>::getPlayersAi() const
{
    return _aiPlayers;
}

template<typename T>
std::vector<indie::APlayer *> indie::WrapPlayers<T>::getAllPlayers() const
{
    std::vector<indie::APlayer *> res;

    for (auto player : _players)
        res.push_back(player);
    for (auto ai : _aiPlayers)
        res.push_back(ai);
    return res;
}

template<typename T>
int indie::WrapPlayers<T>::getNbrAlivePlayer(void)
{
    int indexCurrent = 0;
    int nbr = 0;

    for (auto player : _players) {
        if (player->getState() == true) {
            nbr++;
            _indexAlive = indexCurrent;
        }
        indexCurrent++;
    }
    for (auto ai : _aiPlayers) {
        if (ai->getState() == true) {
            nbr++;
            _indexAlive = indexCurrent;
        }
        indexCurrent++;
    }
    return (nbr);
}

template<typename T>
int indie::WrapPlayers<T>::getIndexLastPlayerAlive(void)
{
    return (_indexAlive);
}

template<typename T>
std::vector<std::shared_ptr<indie::Bomb>> indie::WrapPlayers<T>::getBomb() const
{
    return _bomb;
}

#endif /* !WRAPPLAYERS_HPP_ */
