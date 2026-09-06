/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** QueuePacket
*/

#include "QueuePacket.hpp"

    //* Public
void babel::QueuePacket::push(Package &pack)
{
    _queue.push(pack);
}

babel::Package babel::QueuePacket::pop(void)
{
    if (_queue.size() <= 0)
        return (babel::Package(""));
    Package res = _queue.front();

    _queue.pop();
    return (res);
}

babel::Package babel::QueuePacket::front(void)
{
    return (_queue.front());
}

size_t babel::QueuePacket::size(void)
{
    return (_queue.size());
}
