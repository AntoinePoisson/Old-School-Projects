/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** SafeQueue
*/

#include <iostream>
#include "Plazza.hpp"
#include "thread/SafeQueue.hpp"
#include "kitchen/Order.hpp"

template <class T>
bool Plazza::SafeQueue<T>::tryPop(T &var)
{
    unsigned int size = 0;

    if (_mtx.trylock() && (size = _queue.size()) > 0) {
        var = _queue[size - 1];
        _queue.pop_back();
        _mtx.unlock();
        return (true);
    } else {
        if (size <= 0)
            _mtx.unlock();
        return (false);
    }
}

template <class T>
void Plazza::SafeQueue<T>::push(T var)
{
    _queue.push_front(var);
}

template <class T>
int Plazza::SafeQueue<T>::size()
{
    return (_queue.size());
}


template bool Plazza::SafeQueue<std::string>::tryPop(std::string &var);
template void Plazza::SafeQueue<std::string>::push(std::string var);
template int Plazza::SafeQueue<std::string>::size();
template bool Plazza::SafeQueue<Plazza::Order>::tryPop(Plazza::Order &var);
template void Plazza::SafeQueue<Plazza::Order>::push(Plazza::Order var);
template int Plazza::SafeQueue<Plazza::Order>::size();