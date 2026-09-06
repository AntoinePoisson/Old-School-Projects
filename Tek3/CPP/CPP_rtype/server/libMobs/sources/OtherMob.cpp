/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** PlaneMob
*/

#include "../includes/OtherMob.hpp"
#include "../includes/PlaneMob.hpp"
#include "Server.hpp"
#include "components/Type.hpp"
#include "components/Collisions.hpp"

extern "C" rtype::system::ILibMob *create()
{
    return (new rtype::system::PlaneMob());
}

extern "C" const Entity rtype::system::OtherMob::createEntity(rtype::entity::ComponentManager &handler, int x, int y, int _life, int stage)
{
    rtype::entity::Entity ids = handler.createEntity();
    rtype::component::Collision collision;
    rtype::component::ItsMob mob;
    rtype::component::Type type(rtype::component::componentType::MONSTER2);
    if (x <= -1)
        x = ((std::rand() % 2000) + MAP_WIDTH + 100);
    if (y <= -1)
        y = (std::rand() % (MAP_HEIGHT - MONSTER_HEIGHT1));
    rtype::component::Position pos(x, y);
    if (_life <= -1)
        _life = (MONSTER1_LIFE);
    rtype::component::Life life(_life);
    rtype::component::Surface size(MONSTER_HEIGHT1, MONSTER_WIDTH1); //+ Mettre la Vrai hitbix des Mob1
    rtype::component::Damage dmg(MONSTER_DMG1, rtype::component::DamageType::PHYSICAL);

    handler.addComponent(ids, collision);
    handler.addComponent(ids, mob);
    handler.addComponent(ids, type);
    handler.addComponent(ids, pos);
    handler.addComponent(ids, life);
    handler.addComponent(ids, size);
    handler.addComponent(ids, dmg);
    return (ids);
}

extern "C" void rtype::system::OtherMob::handlerIAMob(rtype::entity::ComponentManager &handler, const Entity &id)
{
    if (handler.getComponent<rtype::component::Type>(id)._type != rtype::component::componentType::MONSTER2)
        return;
    if (handler.getComponent<rtype::component::Position>(id)._x <= -300)
        handler.getComponent<rtype::component::Life>(id)._life = 0;
    handler.getComponent<rtype::component::Position>(id)._x -= (std::rand() % MONSTER1_SPEED + 5);
}
