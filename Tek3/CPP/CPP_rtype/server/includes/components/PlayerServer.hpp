/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Player
*/

#ifndef SERVERCOMPONENTPLAYERSERVER_HPP_
#define SERVERCOMPONENTPLAYERSERVER_HPP_

#include "components/AComponent.hpp"

namespace rtype {
    namespace component {

        struct ItsPlayer : public AComponent
        {
            ItsPlayer() = default;
            ~ItsPlayer() = default;
        };

       struct ItsServer: public AComponent
        {
            ItsServer() = default;
            ~ItsServer() = default;
        };

       struct ItsBullet: public AComponent
        {
            ItsBullet() = default;
            ~ItsBullet() = default;
        };

       struct ItsMob: public AComponent
        {
            ItsMob() = default;
            ~ItsMob() = default;
        };

       struct DeletOrPrint: public AComponent
        {
            DeletOrPrint() = default;
            ~DeletOrPrint() = default;

            bool print = true;
            bool delet = false;
        };

    }
}

#endif /* !SERVERCOMPONENTPLAYERSERVER_HPP_ */
