/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Mutex
*/

#include "thread/Mutex.hpp"

Plazza::Mutex::Mutex()
{
}

Plazza::Mutex::~Mutex()
{
}

void Plazza::Mutex::lock()
{
    _stdMutex.lock();
}

void Plazza::Mutex::unlock()
{
    _stdMutex.unlock();
}

bool Plazza::Mutex::trylock()
{
    return (_stdMutex.try_lock());
}