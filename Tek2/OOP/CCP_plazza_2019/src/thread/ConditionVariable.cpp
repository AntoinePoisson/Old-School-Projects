/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Condition Variable
*/

#include "thread/ConditionVariable.hpp"

Plazza::ConditionVariable::ConditionVariable()
{
}

Plazza::ConditionVariable::~ConditionVariable()
{
}

void Plazza::ConditionVariable::notify_one()
{
    _condVar.notify_one();
}

void Plazza::ConditionVariable::notify_all()
{
    _condVar.notify_all();
}

void Plazza::ConditionVariable::wait(std::unique_lock<std::mutex> &lock)
{
    _condVar.wait(lock);
}