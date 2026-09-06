
#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer()
    : _water(0),
      _started(false)
{
}

void
WaterReclaimer::start()
{
    MissionCriticalError error("Not enough water to achieve the mission.", "WaterReclaimer");

    if (!_water)
        throw(error);
    _started = true;
}

void
WaterReclaimer::useWater(int water)
{
    LifeCriticalError n_one("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
    UserError n_two("Water use should be positif.", "WaterReclaimer");
    UserError n_three("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");

    if (_started == false)
        throw(n_three);
    if (water < 0)
        throw(n_two);
    if (_water - water < 0 || water < 10)
        throw(n_one);
    _water -= water;
}

void
WaterReclaimer::generateWater()
{
    MissionCriticalError error("Cannot generate water, reclaimer already full.", "WaterReclaimer");

    if (_water >= 100)
        throw(error);
    _water += 10;
}
