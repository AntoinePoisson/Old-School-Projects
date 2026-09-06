/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System AManager
*/

#ifndef COMMONSYSTEMAMANAGER_HPP_
#define COMMONSYSTEMAMANAGER_HPP_

#include <string>
#include <vector>

#include "components/AManager.hpp"
#include "systems/IManager.hpp"
#include "systems/ISystem.hpp"

namespace rtype {
    namespace system {

        class AManager : public IManager
        {
            protected:
                std::vector<ISystem> _systems;
            public:
                AManager(rtype::component::AManager &a);
                virtual ~AManager() = default;

                // void loop(void);
        };

    }
}


#endif /* !COMMONSYSTEMAMANAGER_HPP_ */
