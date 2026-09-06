/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** GameEngine
*/

#ifndef SERVERGAMEENGINE_HPP_
#define SERVERGAMEENGINE_HPP_

#include <vector>
#include "Server.hpp"
#include "entities/AManager.hpp"

namespace rtype {

    class GameEngine {
        private:
            const rtype::entity::Entity _serverEntityId;
            std::vector<boost::shared_ptr<rtype::OOP::Client>> &_squad;

            void createPlayers(const rtype::entity::Entity &entityId);
            void destroyPlayers(const rtype::entity::Entity &entityId);
            void destroyAllEntity(const rtype::entity::Entity &entityId);
        public:
            GameEngine(const rtype::entity::Entity &serverEntity, std::vector<boost::shared_ptr<rtype::OOP::Client>> &squad);
            ~GameEngine() = default;
            void run(void);
            static rtype::entity::Entity createBullet(const rtype::component::Destination &dest, const rtype::component::Position &pos, const rtype::component::Type &type, const rtype::component::Speed &speed = rtype::component::Speed(SPEED_BULLET));
            static rtype::entity::Entity createBullet(double destX, double destY, double posX, double posY, int type, double speed = SPEED_BULLET);
            static rtype::entity::Entity createBullet(void);
            static rtype::entity::Entity createMob(const rtype::component::Position &pos, const rtype::component::Type &type, const rtype::component::Life &life = rtype::component::Life(MONSTER_LIFE));
            static rtype::entity::Entity createMob(double posX, double posY, int type, double life = MONSTER_LIFE);
            static rtype::entity::Entity createMob(void);
            static bool checkIfEntityIs(const rtype::entity::Entity &entityId, const rtype::whoIs &type);
    };

}
#endif /* !GAMEENGINE_HPP_ */
