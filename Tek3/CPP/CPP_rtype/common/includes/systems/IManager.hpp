/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System IManager
*/

#ifndef COMMONSYSTEMIMANAGER_HPP_
#define COMMONSYSTEMIMANAGER_HPP_

#include <string>
#include <vector>

#include "components/AManager.hpp"

namespace rtype {
    namespace system {

        class IManager
        {
            public:
                virtual ~IManager() = default;

                virtual void loop(void) = 0;
        };

    }
}


#endif /* !COMMONSYSTEMIMANAGER_HPP_ */
