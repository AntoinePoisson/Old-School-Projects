/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** GameEngine
*/

#include "GameEngine.hpp"
#include "systems/Network.hpp"
#include "singleton/ECManager.hpp"
#include "systems/TimerGame.hpp"
#include "systems/CheckEndGame.hpp"
#include "systems/CheckCollisionServer.hpp"
#include "systems/ShootServer.hpp"
#include "systems/InterpretCollisionServer.hpp"
#include "components/Type.hpp"
#include "components/Collisions.hpp"
#include "systems/LoadMethodeMob.hpp"
#include "systems/MobServer.hpp"
#include "systems/PlayerAlive.hpp"
#include "Server.hpp"
#include <chrono>

rtype::GameEngine::GameEngine(const rtype::entity::Entity &serverEntity, std::vector<boost::shared_ptr<rtype::OOP::Client>> &squad)
: _serverEntityId(serverEntity), _squad(squad)
{}

void rtype::GameEngine::createPlayers(const rtype::entity::Entity &entityId)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    int index = 1;
    for (auto &e : handler.getComponent<rtype::component::ListClientNetwork>(entityId)._list) {
        rtype::entity::Entity ids = handler.createEntity();
        rtype::component::ItsPlayer itsPlayer;
        rtype::component::Collision collision;
        rtype::component::Type type((index == 1 ? rtype::component::componentType::PLAYERRED : (index == 2 ? rtype::component::componentType::PLAYERBLUE : (index == 3 ? rtype::component::componentType::PLAYERGREEN : (rtype::component::componentType::PLAYERPURPLE)))));
        rtype::component::Position pos(PLAYER_INIT_X, ((PLAYER_INIT_Y * index) + 120));
        rtype::component::Life life(PLAYER_INIT_LIFE);
        rtype::component::Surface size(PLAYER_HEIGHT, PLAYER_WIDTH); //+ Mettre la Vrai hitbix des player
        rtype::component::Level level(1);
        handler.addComponent(ids, pos);
        handler.addComponent(ids, type);
        handler.addComponent(ids, collision);
        handler.addComponent(ids, life);
        handler.addComponent(ids, size);
        handler.addComponent(ids, itsPlayer);
        handler.addComponent(ids, level);
        e.first = ids;
        index++;
    }
}


rtype::entity::Entity rtype::GameEngine::createBullet(const rtype::component::Destination &dest, const rtype::component::Position &pos, const rtype::component::Type &type, const rtype::component::Speed &speed)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::entity::Entity idBullet = handler.createEntity();
    rtype::component::ItsBullet itsBullet;
    rtype::component::Collision collision;
    rtype::component::StartingTime startTime(std::chrono::system_clock::now());
    rtype::component::StartCriteria startCriteria(pos, dest);
    rtype::component::Surface surf((type._type == rtype::component::componentType::BULLET1 ? BULLET_HEIGHT1 : (type._type == rtype::component::componentType::BULLET2 ? BULLET_HEIGHT2 : (type._type == rtype::component::componentType::BULLET3 ? BULLET_HEIGHT3 : (BULLET_HEIGHT4)))),
                                    (type._type == rtype::component::componentType::BULLET1 ? BULLET_WIDTH1 : (type._type == rtype::component::componentType::BULLET2 ? BULLET_WIDTH2 : (type._type == rtype::component::componentType::BULLET3 ? BULLET_WIDTH3 : (BULLET_WIDTH4)))));
    rtype::component::DeletOrPrint delOrPrint;
    rtype::component::Damage dmg = (type._type == rtype::component::componentType::BULLET1 ? rtype::component::Damage(BULLET_DMG1, rtype::component::DamageType::PHYSICAL) : (type._type == rtype::component::componentType::BULLET2 ? rtype::component::Damage(BULLET_DMG2, rtype::component::DamageType::PHYSICAL) : (type._type == rtype::component::componentType::BULLET3 ? rtype::component::Damage(BULLET_DMG3, rtype::component::DamageType::PHYSICAL) : (rtype::component::Damage(BULLET_DMG4, rtype::component::DamageType::PHYSICAL)))));

    handler.addComponent(idBullet, itsBullet);
    handler.addComponent(idBullet, collision);
    handler.addComponent(idBullet, startTime);
    handler.addComponent(idBullet, startCriteria);
    handler.addComponent(idBullet, dest);
    handler.addComponent(idBullet, pos);
    handler.addComponent(idBullet, type);
    handler.addComponent(idBullet, speed);
    handler.addComponent(idBullet, surf);
    handler.addComponent(idBullet, delOrPrint);
    handler.addComponent(idBullet, dmg);

    return idBullet;
}

rtype::entity::Entity rtype::GameEngine::createBullet(double destX, double destY, double posX, double posY, int type, double speed)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::entity::Entity idBullet = handler.createEntity();
    rtype::component::ItsBullet itsBullet;
    rtype::component::Collision collision;
    rtype::component::StartingTime startTime(std::chrono::system_clock::now());
    rtype::component::Destination dest(destX, destY);
    // rtype::component::Position pos(posX, posY);
    rtype::component::Position pos(posX + PLAYER_WIDTH + 5, posY + PLAYER_HEIGHT / 2 - BULLET_HEIGHT1 / 2);
    rtype::component::StartCriteria startCriteria(pos, dest);
    rtype::component::Speed speedBullet(speed);
    rtype::component::Type typeBullet((type == 1 ? rtype::component::componentType::BULLET1 : (type == 2 ? rtype::component::componentType::BULLET2 : (type == 3 ? rtype::component::componentType::BULLET3 : (rtype::component::componentType::BULLET4)))));
    rtype::component::Surface surf((type == 1 ? BULLET_HEIGHT1 : (type == 2 ? BULLET_HEIGHT2 : (type == 3 ? BULLET_HEIGHT3 : (BULLET_HEIGHT4)))),
                                    (type == 1 ? BULLET_WIDTH1 : (type == 2 ? BULLET_WIDTH2 : (type == 3 ? BULLET_WIDTH3 : (BULLET_WIDTH4)))));
    rtype::component::DeletOrPrint delOrPrint;
    rtype::component::Damage dmg = (type == 1 ? rtype::component::Damage(BULLET_DMG1, rtype::component::DamageType::PHYSICAL) : (type == 2 ? rtype::component::Damage(BULLET_DMG2, rtype::component::DamageType::PHYSICAL) : (type == 3 ? rtype::component::Damage(BULLET_DMG3, rtype::component::DamageType::PHYSICAL) : (rtype::component::Damage(BULLET_DMG4, rtype::component::DamageType::PHYSICAL)))));

    handler.addComponent(idBullet, itsBullet);
    handler.addComponent(idBullet, collision);
    handler.addComponent(idBullet, startTime);
    handler.addComponent(idBullet, dest);
    handler.addComponent(idBullet, pos);
    handler.addComponent(idBullet, startCriteria);
    handler.addComponent(idBullet, speedBullet);
    handler.addComponent(idBullet, typeBullet);
    handler.addComponent(idBullet, surf);
    handler.addComponent(idBullet, delOrPrint);
    handler.addComponent(idBullet, dmg);

    return idBullet;
}

rtype::entity::Entity rtype::GameEngine::createBullet(void)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::entity::Entity idBullet = handler.createEntity();
    rtype::component::ItsBullet itsBullet;
    rtype::component::Collision collision;
    rtype::component::StartingTime startTime(std::chrono::system_clock::now());
    rtype::component::Destination dest(0, 0);
    rtype::component::Position pos(0, 0);
    rtype::component::StartCriteria startCriteria(pos, dest);
    rtype::component::Speed speedBullet(0);
    rtype::component::Type typeBullet(rtype::component::componentType::BULLET1);
    rtype::component::Surface surf(BULLET_HEIGHT1, BULLET_WIDTH1);
    rtype::component::Damage dmg(BULLET_DMG1, rtype::component::DamageType::PHYSICAL);
    rtype::component::DeletOrPrint delOrPrint;

    handler.addComponent(idBullet, itsBullet);
    handler.addComponent(idBullet, collision);
    handler.addComponent(idBullet, startTime);
    handler.addComponent(idBullet, dest);
    handler.addComponent(idBullet, pos);
    handler.addComponent(idBullet, startCriteria);
    handler.addComponent(idBullet, speedBullet);
    handler.addComponent(idBullet, typeBullet);
    handler.addComponent(idBullet, surf);
    handler.addComponent(idBullet, delOrPrint);
    handler.addComponent(idBullet, dmg);

    return idBullet;
}

rtype::entity::Entity rtype::GameEngine::createMob(const rtype::component::Position &pos, const rtype::component::Type &type, const rtype::component::Life &life)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::entity::Entity idMonster = handler.createEntity();
    rtype::component::ItsMob itsMonster;
    rtype::component::Collision collision;
    rtype::component::Surface surf = (type._type == rtype::component::componentType::MONSTER1 ? rtype::component::Surface(MONSTER_HEIGHT1, MONSTER_WIDTH1) : (type._type == rtype::component::componentType::MONSTER2 ? rtype::component::Surface(MONSTER_HEIGHT2, MONSTER_WIDTH2) : (type._type == rtype::component::componentType::MONSTER3 ? rtype::component::Surface(MONSTER_HEIGHT3, MONSTER_WIDTH3) : (rtype::component::Surface(MONSTER_HEIGHT4, MONSTER_WIDTH4)))));
    rtype::component::Damage dmg = (type._type == rtype::component::componentType::MONSTER1 ? rtype::component::Damage(MONSTER_DMG1,rtype::component::DamageType::PHYSICAL) : (type._type == rtype::component::componentType::MONSTER2 ? rtype::component::Damage(MONSTER_DMG2,rtype::component::DamageType::PHYSICAL) : (type._type == rtype::component::componentType::MONSTER3 ? rtype::component::Damage(MONSTER_DMG3,rtype::component::DamageType::PHYSICAL) : (rtype::component::Damage(MONSTER_DMG4,rtype::component::DamageType::PHYSICAL)))));

    handler.addComponent(idMonster, itsMonster);
    handler.addComponent(idMonster, pos);
    handler.addComponent(idMonster, type);
    handler.addComponent(idMonster, life);
    handler.addComponent(idMonster, collision);
    handler.addComponent(idMonster, surf);
    handler.addComponent(idMonster, dmg);

    return idMonster;
}

rtype::entity::Entity rtype::GameEngine::createMob(double posX, double posY, int index, double li)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::entity::Entity idMonster = handler.createEntity();
    rtype::component::ItsMob itsMonster;
    rtype::component::Position pos(posX, posY);
    rtype::component::Type type((index == 1 ? rtype::component::componentType::MONSTER1 : (index == 2 ? rtype::component::componentType::MONSTER2 : (index == 3 ? rtype::component::componentType::MONSTER3 : (rtype::component::componentType::MONSTER4)))));
    rtype::component::Life life(li);
    rtype::component::Collision collision;
    rtype::component::Surface surf = (index == 1 ? rtype::component::Surface(MONSTER_HEIGHT1, MONSTER_WIDTH1) : (index == 2 ? rtype::component::Surface(MONSTER_HEIGHT2, MONSTER_WIDTH2) : (index == 3 ? rtype::component::Surface(MONSTER_HEIGHT3, MONSTER_WIDTH3) : (rtype::component::Surface(MONSTER_HEIGHT4, MONSTER_WIDTH4)))));
    rtype::component::Damage dmg = (index == 1 ? rtype::component::Damage(MONSTER_DMG1, rtype::component::DamageType::PHYSICAL) : (index == 2 ? rtype::component::Damage(MONSTER_DMG2, rtype::component::DamageType::PHYSICAL) : (index == 3 ? rtype::component::Damage(MONSTER_DMG3, rtype::component::DamageType::PHYSICAL) : (rtype::component::Damage(MONSTER_DMG4, rtype::component::DamageType::PHYSICAL)))));

    handler.addComponent(idMonster, itsMonster);
    handler.addComponent(idMonster, pos);
    handler.addComponent(idMonster, type);
    handler.addComponent(idMonster, life);
    handler.addComponent(idMonster, collision);
    handler.addComponent(idMonster, surf);
    handler.addComponent(idMonster, dmg);

    return idMonster;
}

rtype::entity::Entity rtype::GameEngine::createMob()
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    rtype::entity::Entity idMonster = handler.createEntity();
    rtype::component::ItsMob itsMonster;
    rtype::component::Position pos(0, 0);
    rtype::component::Type type(rtype::component::componentType::MONSTER1);
    rtype::component::Life life(1);
    rtype::component::Collision collision;
    rtype::component::Surface surf(MONSTER_HEIGHT1, MONSTER_WIDTH1);
    rtype::component::Damage dmg(MONSTER_DMG1, rtype::component::DamageType::PHYSICAL);

    handler.addComponent(idMonster, itsMonster);
    handler.addComponent(idMonster, pos);
    handler.addComponent(idMonster, type);
    handler.addComponent(idMonster, life);
    handler.addComponent(idMonster, collision);
    handler.addComponent(idMonster, surf);
    handler.addComponent(idMonster, dmg);

    return idMonster;
}

bool rtype::GameEngine::checkIfEntityIs(const rtype::entity::Entity &entityId, const rtype::whoIs &type)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();
    Signature typeSig(type);
    Signature entSig;
    try {
        entSig = handler._eMan.getSignature(entityId);
    }catch(...) {
        return (false);
    }

    auto res = typeSig & entSig;
    if (res.to_ullong() == typeSig.to_ullong())
        return true;
    return false;
}

void rtype::GameEngine::destroyPlayers(const rtype::entity::Entity &entityId)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    for (auto &e : handler._cMan.getComponentsFromType<rtype::component::ItsPlayer>()) {
        handler._eMan.removeEntity(e.first);
    }
}

void rtype::GameEngine::destroyAllEntity(const rtype::entity::Entity &entityId)
{
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    // for (auto &e : handler._eMan.getEntities()) {
    //     handler._eMan.removeEntity(e.first);
    // }
}

void rtype::GameEngine::run(void)
{
    createPlayers(_serverEntityId);
    rtype::system::LoadMethodeMob().update(_serverEntityId);
    int prevNbrMob = MONSTER_INIT_NBR;
    int stage = 0;

    while (true) {
        rtype::system::NetworkRead().update(_serverEntityId);
        rtype::system::MobServer().run(_serverEntityId, &prevNbrMob, &stage);
        rtype::system::CheckBullet().update(_serverEntityId);
        rtype::system::CheckCollisionServer().update(_serverEntityId);
        rtype::system::InterpretCollisionServer().update(_serverEntityId);
        rtype::system::PlayerAlive().run(_serverEntityId, _squad);
        try {
            rtype::system::CheckEndGame().run(_serverEntityId, _squad);
        } catch(rtype::GameIsFinish game) {
            std::cout << game.what();
            break;
        }
        rtype::system::SendEntities().update(_serverEntityId);
        rtype::system::NetworkWrite().update(_serverEntityId);
        rtype::system::TimerGame().update(_serverEntityId);
    }
    std::cout << "[Game]: END GAME !!" << std::endl;
    destroyPlayers(_serverEntityId);
    destroyAllEntity(_serverEntityId);
}
