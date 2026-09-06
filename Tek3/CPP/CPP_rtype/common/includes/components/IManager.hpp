/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component IManager
*/

#ifndef COMMONCOMPONENTIMANAGER_HPP_
#define COMMONCOMPONENTIMANAGER_HPP_

#include <string>

using Entity = std::string;

namespace rtype {
    namespace component {

        template<typename T>
        class IManager
        {
            public:
                virtual ~IManager() = default;

                virtual bool addComponent(const std::string &entity_id, const T &cpt) = 0;
                virtual bool removeComponent(const Entity &entity_id) = 0;
                virtual T &getComponent(const Entity &entity_id) = 0;
                virtual bool removeEntityComponents(const Entity &entity_id) = 0;

        };

    }
}

#endif /* !COMMONCOMPONENTIMANAGER_HPP_ */
