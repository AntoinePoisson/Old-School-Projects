/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component TempComponents
*/

#ifndef SERVERCOMPONENTTEMPCOMPONENTS_HPP_
#define SERVERCOMPONENTTEMPCOMPONENTS_HPP_

#include "components/AComponent.hpp"
#include "components/Network.hpp"

namespace rtype {
    namespace component {

        struct TempRead : public AComponent
        {
            TempRead() = default;
            ~TempRead() = default;
        };

        struct TempWrite : public AComponent
        {
            TempWrite(const std::string &a, boost::asio::ip::udp::endpoint endpoint): _message(a), _endpoint(endpoint) {};
            ~TempWrite() = default;

            std::string _message;
            rtype::component::OpponentNetworkInfo _endpoint;
        };

        struct TempInterpret : public AComponent
        {
            TempInterpret(std::pair<std::string, rtype::component::OpponentNetworkInfo> &res) : _res(res) {};
            ~TempInterpret() = default;

            std::pair<std::string, rtype::component::OpponentNetworkInfo> _res;
        };

    }
}

#endif /* !SERVERCOMPONENTTEMPCOMPONENTS_HPP_ */
