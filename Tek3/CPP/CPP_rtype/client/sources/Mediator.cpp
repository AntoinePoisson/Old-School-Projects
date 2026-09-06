/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Mediator
*/

#include "Mediator.hpp"
#include "SubSystems.hpp"

rtype::Mediator::Mediator(rtype::entity::ComponentManager &ecMan):
_ecMan(ecMan)
{
    addSubSystem(TempSignature(idRead), std::make_shared<subsystem::NetworkRead>());
    addSubSystem(TempSignature(idWrite), std::make_shared<subsystem::NetworkAddSomeWrite>());
}

void rtype::Mediator::mediate(const Entity &entities)
{
    //browse list and call sub system
    TempSignature sig = _ecMan._eMan.getTempSignature(entities);

    for (auto sys = _subSystems.begin(); sys != _subSystems.end(); sys++) {
        auto res = sys->first & sig;
        if (res.to_ullong() == sys->first.to_ullong()) {
            sys->second->update(entities);
            resetTempSignature(entities);
        }
    }
}

// void Mediator::addSubSystem(const Signature &sig, SubSystem &subSystem)
void rtype::Mediator::addSubSystem(const TempSignature &sig, std::shared_ptr<system::ISubSystem> subSystem)
{
    if (_subSystems.find(sig) == _subSystems.end()) {
        // _subSystems[sig] = std::make_shared<SubSystem>(subSystem);
        _subSystems[sig] = subSystem;
    }
    else {
        //throw, already exists
    }
}

void rtype::Mediator::resetTempSignature(const Entity &entities)
{
    _ecMan._eMan._tempEntities[entities] = TempSignature(0);
    // if (_subSystems.find(sig) != _subSystems.end()) {
    //     _subSystems.erase(sig);
    // }
    // else {
    //     //throw, not exists
    // }
}

