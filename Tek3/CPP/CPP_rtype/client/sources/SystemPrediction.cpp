#include "systems/Prediction.hpp"
#include "RType.hpp"
#include <chrono>

rtype::system::Prediction::Prediction(rtype::entity::ComponentManager &ecMan):
ASystem(), _ecMan(ecMan)
{}

void rtype::system::Prediction::update(const Entity &e)
{
    // std::cout << "update prediction" << std::endl;

    auto entities = _ecMan._eMan.getEntities();

    Signature cptNextPosition(rtype::idBitset::idNextPosition);
    Signature cptDestination(rtype::idBitset::idDestination);
    std::map<Entity, Signature> entitiesToHandle;

    for (auto it = entities.begin();
        it != entities.end(); it++) {
            auto res = it->second & cptNextPosition;
            if (res.count() != 0) {
               //push
               entitiesToHandle.insert({it->first, it->second});
               continue;
            }
            res = it->second & cptDestination;

            if (res.count() != 0) {
               entitiesToHandle.insert({it->first, it->second});
            }
        }
    moveEntities(entitiesToHandle);
}

void rtype::system::Prediction::handleNextPosition(const Entity &id)
{
    // have to set new position and set newNextDestination
    struct rtype::component::NextPosition &nxt = _ecMan.getComponent<rtype::component::NextPosition>(id);
    struct rtype::component::Position &cur_pos = _ecMan.getComponent<rtype::component::Position>(id);

    cur_pos._x = nxt._x;
    cur_pos._y = nxt._y;
}

// void rtype::system::Prediction::handleDestination(const Entity &id)
void rtype::system::Prediction::handleDestination(const Entity &id, const std::chrono::time_point<std::chrono::system_clock> &now)
{
    struct rtype::component::Destination &dst = _ecMan.getComponent<rtype::component::Destination>(id);
    struct rtype::component::Position &cur_pos = _ecMan.getComponent<rtype::component::Position>(id);
    struct rtype::component::StartingTime &start_t = _ecMan.getComponent<rtype::component::StartingTime>(id);
    struct rtype::component::Speed &speed = _ecMan.getComponent<rtype::component::Speed>(id);
    struct rtype::component::StartCriteria &sCrit = _ecMan.getComponent<rtype::component::StartCriteria>(id);

    int duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_t._startAt).count();

    double speed_per_milisecond = speed._speed / 1000;
    // double current_distance = sCrit._h - speed._speed * (duration);

    double current_distance = sCrit._h - speed_per_milisecond * (duration);
    std::cout << current_distance << std::endl;

    if (current_distance >= sCrit._h) {
        cur_pos._x = dst._x;
        cur_pos._y = dst._y;
    }
    else {
        cur_pos._y = sCrit._o - sCrit._sin * current_distance + sCrit._pos._y;
        cur_pos._x = sCrit._a - sCrit._cos * current_distance + sCrit._pos._x;
    }
}

void rtype::system::Prediction::moveEntities(const std::map<Entity, Signature> &entitiesToHandle)
{
    Signature cptNextPosition(rtype::idBitset::idNextPosition);
    Signature cptDestination(rtype::idBitset::idDestination);

    for (auto itEnt = entitiesToHandle.begin(); 
        itEnt != entitiesToHandle.end(); itEnt++) {
            auto res = itEnt->second & cptNextPosition;
            if (res.count() != 0) {
                //handle next dest
                handleNextPosition(itEnt->first);
                continue;
            }
            res = itEnt->second & cptDestination;
            if (res.count() != 0) {
                //handle destination
                handleDestination(itEnt->first);
            }
        }
}
