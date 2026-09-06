/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Thread
*/

#include <iostream>
#include "thread/Thread.hpp"

Plazza::Thread::Thread()
{
}

Plazza::Thread::~Thread()
{
}

bool Plazza::Thread::joinable() const
{
    return (_stdThread.joinable());
}

std::thread::id Plazza::Thread::get_id() const
{
    return (_stdThread.get_id());
}

void Plazza::Thread::join()
{
    _stdThread.join();
}

void Plazza::Thread::detach()
{
    _stdThread.detach();
}

void Plazza::Thread::swap(Plazza::Thread t2)
{
    _stdThread.swap(t2._stdThread);
}