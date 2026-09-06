/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component AComponent
*/

#ifndef COMMONCOMPONENTACOMPONENT_HPP_
#define COMMONCOMPONENTACOMPONENT_HPP_

#include <string>
#include "components/IComponent.hpp"

namespace rtype {
    namespace component {

        struct AComponent : public IComponent
        {
            AComponent() = default;
            virtual ~AComponent() = default;
        };

    }
}

#endif /* !COMMONCOMPONENTACOMPONENT_HPP_ */
