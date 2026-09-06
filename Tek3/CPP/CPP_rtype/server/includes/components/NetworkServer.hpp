/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component NetworkServer
*/

#ifndef SERVERCOMPONENTNETWORKSERVER_HPP_
#define SERVERCOMPONENTNETWORKSERVER_HPP_

#include "components/Network.hpp"
#include "components/AComponent.hpp"

namespace rtype {
    namespace component {

        struct ListClientNetwork : public AComponent
        {
           ListClientNetwork() = default;
            ~ListClientNetwork() = default;

            std::vector<std::pair<std::string, rtype::component::OpponentNetworkInfo>> _list;
        };

    }
}

#endif /* !SERVERCOMPONENTNETWORKSERVER_HPP_ */
