/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** PlaneMob
*/

#include "../includes/PlaneMob.hpp"
#include "../includes/OtherMob.hpp"
#include "Server.hpp"
#include "components/Type.hpp"
#include "components/Collisions.hpp"

extern "C" rtype::system::ILibMob *create()
{
    return (new rtype::system::PlaneMob());
}

extern "C" const Entity rtype::system::PlaneMob::createEntity(rtype::entity::ComponentManager &handler, int x, int y, int _life, int stage)
{
    rtype::entity::Entity ids = handler.createEntity();
    rtype::component::Collision collision;
    rtype::component::ItsMob mob;
    lvl = stage ? rtype::component::componentType::MONSTER1 : rtype::component::componentType::MONSTER2;
    rtype::component::Type type(lvl);
    if (x <= -1)
        x = ((std::rand() % 2000) + MAP_WIDTH + 100);
    if (y <= -1)
        y = (std::rand() % (MAP_HEIGHT - (stage ? MONSTER_HEIGHT1 : MONSTER_HEIGHT2)));
    rtype::component::Position pos(x, y);
    if (_life <= -1)
        _life = (stage ? MONSTER1_LIFE : 60);
    rtype::component::Life life(_life);
    rtype::component::Surface size(stage ? MONSTER_HEIGHT1 : MONSTER_HEIGHT2, stage ? MONSTER_WIDTH1 : MONSTER_WIDTH2); //+ Mettre la Vrai hitbix des Mob1
    rtype::component::Damage dmg(stage ? MONSTER_DMG1 : MONSTER_DMG2, rtype::component::DamageType::PHYSICAL);

    handler.addComponent(ids, collision);
    handler.addComponent(ids, mob);
    handler.addComponent(ids, type);
    handler.addComponent(ids, pos);
    handler.addComponent(ids, life);
    handler.addComponent(ids, size);
    handler.addComponent(ids, dmg);
    return (ids);
}

extern "C" void rtype::system::PlaneMob::handlerIAMob(rtype::entity::ComponentManager &handler, const Entity &id)
{
    if (handler.getComponent<rtype::component::Type>(id)._type != lvl)
        return;
    if (lvl == rtype::component::componentType::MONSTER1) {
        if (handler.getComponent<rtype::component::Position>(id)._x <= -300)
            handler.getComponent<rtype::component::Life>(id)._life = 0;
        handler.getComponent<rtype::component::Position>(id)._x -= MONSTER1_SPEED;
    } else {
        if (handler.getComponent<rtype::component::Position>(id)._x <= -300)
            handler.getComponent<rtype::component::Life>(id)._life = 0;
        handler.getComponent<rtype::component::Position>(id)._x -= 10;
    }
}
