/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemTimerGame
*/

#include "systems/TimerGame.hpp"

void rtype::system::TimerGame::update(const Entity &id)
{
    if (id.size()) {
    }
    static clock_t timer;
    static bool defined = false;

    if (!defined) {
        timer = clock();
        defined = true;
    }
    while (timer + (CLOCKS_PER_SEC / TIMERGAME) > clock()) {
    }
    timer += CLOCKS_PER_SEC / TIMERGAME;

}
