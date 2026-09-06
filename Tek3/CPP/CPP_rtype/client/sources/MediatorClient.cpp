/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Mediator
*/

#include "MediatorClient.hpp"
#include "SubSystemsClient.hpp"

rtype::client::Mediator::Mediator(rtype::entity::ComponentManager &ecMan)
    : _ecMan(ecMan)
{
    // addSubSystem(Signature(idSFMLEvent + idListAction + idKeyboardEvent), std::make_shared<rtype::subsystem::EventHandler>());
    // addSubSystem(Signature(idKeyboardEvent), std::make_shared<rtype::subsystem::EventHandler>());
}

void rtype::client::Mediator::mediate(const Entity &entities)
{
    Signature sig = _ecMan._eMan.getSignature(entities);

    for (auto sys = _subSystems.begin(); sys != _subSystems.end(); sys++) {
        auto res = sys->first & sig;

        if (res.to_ullong() == sys->first.to_ullong())
            sys->second->update(entities);
    }
}

void rtype::client::Mediator::addSubSystem(const Signature &sig, std::shared_ptr<system::ISubSystem> subSystem)
{
    if (_subSystems.find(sig) == _subSystems.end()) {
        _subSystems[sig] = subSystem;
    } else {
        std::cerr << "[CLIENT]: [MEDIATOR]: [ADDSUBSYSTEM]: subsystem already exist" <<std::endl;
    }
}

void rtype::client::Mediator::replaceSubSystem(const Signature &sig, std::shared_ptr<system::ISubSystem> subSystem)
{
    if (_subSystems.find(sig) != _subSystems.end()) {
        _subSystems[sig] = subSystem;
    }
    else {
        std::cerr << "[CLIENT]: [MEDIATOR]: [REPLACE_SUBSYS]: subsystem doesn't exist" << std::endl;
    }
}

void rtype::client::Mediator::deleteSubSystem(const Signature &sig)
{
    if (_subSystems.find(sig) != _subSystems.end())
        _subSystems.erase(sig);
}

void rtype::client::Mediator::deleteAllSubSystem()
{
    for (auto &sys :_subSystems)
        deleteSubSystem(sys.first);
}
