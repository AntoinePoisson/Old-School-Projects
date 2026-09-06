
#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator()
    : _quantity(0)
{
}

void Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void Oxygenator::useOxygen(int quantity)
{
    LifeCriticalError error("Not enough oxygen to live.", "Oxygenator");
    MissionCriticalError error_two("Not enough oxygen to continue the mission.", "Oxygenator");

    if (_quantity - quantity <= 10)
        throw(error);
    if (_quantity - quantity <= 20)
        throw(error_two);
    _quantity -= quantity;
}
