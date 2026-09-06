/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** Event.hpp
*/

#ifndef EVENT_HPP_
# define EVENT_HPP_

#include <iostream>
#include <vector>
#include "Indie.hpp"
#include <map>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace indie
{
    class Event : public IEventReceiver
    {
        public:
            Event();
            virtual ~Event() = default;

            virtual bool OnEvent(const SEvent& event);
            virtual bool KeyPressed(EKEY_CODE const keyCode) const;
            void setFalse();
            bool &getMouseState();
            bool &getReleaseState();
            int getKeyboardPress() const;
            bool getEscape();
            void resetMouse();
            bool getBuffer(const int &KeyCode, bool once);
            void resetBuffer(const int &KeyCode);
        private:
            bool isKeyPressed[KEY_KEY_CODES_COUNT] = {false};
            bool isMousePressed = false;
            bool isMouseReleased = false;
            int keyPressed = -1;
            bool escape = false;
            std::map<int, bool> buffer;
            std::map<int, bool> bufferRelease;
    };
}

#endif