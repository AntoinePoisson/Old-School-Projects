/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Systems
*/

#ifndef COMMONSYSTEMWINDOW_HPP
#define COMMONSYSTEMWINDOW_HPP

#include <map>
#include <iostream>
#include "systems/Exception.hpp"
#include "systems/ASystem.hpp"
#include "entities/ComponentManager.hpp" // for ComponentManager
#include "entities/IManager.hpp" // for Signature
#include "components/Display.hpp"
#include "components/Events.hpp"
#include "components/Physics.hpp"
#include "components/Window.hpp"


namespace rtype {
    namespace subsystem {

        struct SpriteSheetHelper//add in map
        {
            std::string file;
	    int _offset;
            int _nbSheet;
            time_t _duration;
            bool _loop;// true by default
        };
    }

    namespace system {

        class Window : public ASystem
        {
            rtype::entity::ComponentManager &_ecm;
            Entity _window;//entity
            Entity _event;//entity

        public:
            Window(rtype::entity::ComponentManager &ecm);
            ~Window();

            void update(const Entity &e);
            void updateKeyboardEvent(rtype::component::SFMLWindow &window);
            void updateMouseEvent(rtype::component::SFMLWindow &window);
            void close();
        };
    }
}

#endif /* !COMMONSYSTEMWINDOW_HPP_ */
