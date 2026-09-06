/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** Event.cpp
*/

#include "Event.hpp"

indie::Event::Event()
{
    u32 i = 0;

    for (; i < KEY_KEY_CODES_COUNT; ++i)
        this->isKeyPressed[i] = false;
}

int indie::Event::getKeyboardPress() const
{
    return (this->keyPressed);
}

bool indie::Event::getEscape()
{
    if (escape) {
        escape = false;
        return (true);
    }
    return (false);
}

void indie::Event::resetMouse()
{
    this->isMouseReleased = false;
    this->isMousePressed = false;
}

void indie::Event::resetBuffer(const int &KeyCode)
{
    if (buffer.find(KeyCode) != buffer.end()) {
        buffer[KeyCode] = false;
    }
}

bool indie::Event::getBuffer(const int &KeyCode, bool once)
{
    if (buffer.find(KeyCode) == buffer.end()) {
        return (false);
    }
    if (once && buffer[KeyCode]) {
        if (bufferRelease.find(KeyCode) == bufferRelease.end()) {
            bufferRelease.insert(std::make_pair(KeyCode, true));
        } else {
            if (bufferRelease[KeyCode] == true) {
                return (false);
            }
            bufferRelease[KeyCode] = true;
        }
        return (true);
    }
    return (buffer[KeyCode]);
}

bool indie::Event::OnEvent(const SEvent& event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        this->isKeyPressed[event.KeyInput.Key] = event.KeyInput.PressedDown;
        if (event.KeyInput.PressedDown) {
            this->keyPressed = event.KeyInput.Key;
            if (this->keyPressed == KEY_ESCAPE)
                this->escape = true;
        } else
            this->keyPressed = -1;
        if (buffer.find(event.KeyInput.Key) == buffer.end()) {
            buffer.insert(std::make_pair(static_cast<int>(event.KeyInput.Key), event.KeyInput.PressedDown));
        } else {
            buffer[event.KeyInput.Key] = event.KeyInput.PressedDown;
        }
        if (!event.KeyInput.PressedDown) {
            if (bufferRelease.find(event.KeyInput.Key) == bufferRelease.end()) {
                bufferRelease.insert(std::make_pair(static_cast<int>(event.KeyInput.Key), false));
            } else {
                bufferRelease[event.KeyInput.Key] = false;
            }
        }
    }
    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
        switch(event.MouseInput.Event) {
            case EMIE_LMOUSE_PRESSED_DOWN:
                this->isMousePressed = true;
                break;
            case EMIE_LMOUSE_LEFT_UP:
                this->isMousePressed = false;
                this->isMouseReleased = true;
                return false;
        }
    }
    this->isMouseReleased = false;
    return false;
}

bool indie::Event::KeyPressed(EKEY_CODE const keyCode) const
{
    return (this->isKeyPressed[keyCode]);
}

bool &indie::Event::getMouseState()
{
    return isMousePressed;
}

bool &indie::Event::getReleaseState()
{
    return isMouseReleased;
}

// void indie::Event::setFalse()
// {
//     std::vector<bool>::iterator it;

// 	for (it = this->isKeyPressed.begin(); it != this->isKeyPressed.end(); ++it)
// 		(*it) = false;
// }