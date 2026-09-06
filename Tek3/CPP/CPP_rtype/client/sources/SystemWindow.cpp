/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemWindow
*/

#include "systems/Window.hpp"
#include "MediatorClient.hpp"
#include <ctime>
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <chrono>

rtype::system::Window::Window(rtype::entity::ComponentManager &ecm)
    : _ecm(ecm)
{
    std::shared_ptr<rtype::component::SFMLWindow> win(new rtype::component::SFMLWindow);
    rtype::component::SFMLEvent sEvent;
    rtype::component::ListAction actions;
    rtype::component::KeyboardEvent event({});
    rtype::component::MouseEvent mouse({});
    auto pair = _ecm._cMan.getComponentFromType<rtype::component::Unremovable>();

    _window = _ecm.createEntity(Signature(idSFMLWindow), win);
    _event = _ecm.createEntity(Signature(idSFMLEvent + idListAction + idKeyboardEvent + idMouseEvent), sEvent, actions, event, mouse);
    pair.second->entities.push_back(_window);
    pair.second->entities.push_back(_event);
}

rtype::system::Window::~Window()
{
    std::cerr << "[CLIENT]: [SYSTEM]: [WINDOW]: DTOR" << std::endl;
    auto comp = _ecm._eMan.getSignature(_window) & Signature(idSFMLWindow);

    if (comp.count() != 0)
        try {
            rtype::component::SFMLWindow &window = _ecm.getComponent<rtype::component::SFMLWindow>(_window);

            if (window._window.isOpen())
                window._window.close();
        } catch (const rtype::component::Exception &e) {
            std::cerr << e.what() << std::endl;
            std::cerr << "[CLIENT]: [SYSTEM]: [WINDOW]: [DTOR]: incomplete window entity" << std::endl;
        }
}

void rtype::system::Window::update(const Entity &entity_id)
{
    // std::cout << "update window" << std::endl;
    if ((_ecm._eMan.getSignature(_window) & Signature(idSFMLWindow)).count() == 0) {
        throw Exception("NO window component", "CLIENT]: [SYSTEM]: [WINDOW]: [UPDATE");
        return;
    }
    try {
        _ecm.getComponent<rtype::component::SFMLWindow>(_window);
    } catch (const rtype::component::Exception &e) {
        std::cerr << e.what() << std::endl;
        throw Exception("incomplete window entity", "CLIENT]: [SYSTEM]: [WINDOW]: [UPDATE");
    }
    rtype::component::SFMLWindow &window = _ecm.getComponent<rtype::component::SFMLWindow>(_window);
    auto entities = _ecm._cMan.getComponentsFromType<rtype::component::DisplayOrder>();

    if (!window._window.isOpen())
        throw Exception("window already closed", "CLIENT]: [SYSTEM]: [WINDOW]: [UPDATE");
    window._window.clear(sf::Color::Black);
    std::vector<Entity> lisDelete;

    for (int order = 0; order < 3; order++)
        for (auto it = entities.begin(); it != entities.end(); ) {
            if (it->second->_order != order) {
                it++;
                continue;
            }
            auto compSprt = _ecm._eMan.getSignature(it->first) & Signature(idSprite);
            auto compSprtSh = _ecm._eMan.getSignature(it->first) & Signature(idSpriteSheet);
            auto compTxt = _ecm._eMan.getSignature(it->first) & Signature(idText);
            auto compPos = _ecm._eMan.getSignature(it->first) & Signature(idPosition);
            auto compSurf = _ecm._eMan.getSignature(it->first) & Signature(idSurface);
            auto compStartTime = _ecm._eMan.getSignature(it->first) & Signature(idStartingTime);

            if (compStartTime.count() != 0 && compSprtSh.count() != 0 &&
                compSurf.count() != 0 && compSprt.count() != 0 && compPos.count() != 0) {
                rtype::component::Sprite &sprite = _ecm.getComponent<rtype::component::Sprite>(it->first);
                rtype::component::SpriteSheet &sprtSheet = _ecm.getComponent<rtype::component::SpriteSheet>(it->first);
                const rtype::component::Position &pos = _ecm.getComponent<rtype::component::Position>(it->first);
                const rtype::component::Surface &surf = _ecm.getComponent<rtype::component::Surface>(it->first);
                const rtype::component::StartingTime &startTime = _ecm.getComponent<rtype::component::StartingTime>(it->first);
                std::time_t now = std::time(nullptr);
                int offset = 0;

                auto time_now = std::chrono::system_clock::now();

                // auto milinow = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch()).count();
                int duration = std::chrono::duration_cast<std::chrono::milliseconds>(time_now - sprtSheet._creationDate).count();

                if (sprtSheet._loop || sprtSheet._firstTurn) {
                    offset = (duration / sprtSheet._duration.count()) % sprtSheet._nbSheet * sprtSheet._offset;
                    // offset = (duration / sprtSheet._duration.count()) % sprtSheet._nbSheet * surf._width / sprtSheet._nbSheet;
                    // offset = ((int)(((now - startTime._startAt) % (sprtSheet._duration * sprtSheet._nbSheet)) / sprtSheet._duration) % sprtSheet._nbSheet) + sprtSheet._offset;
                    // offset = ;
                }
                if (offset < sprtSheet._lastPos)
                    sprtSheet._firstTurn = false;
                else
                    sprtSheet._lastPos = offset;
                if (sprite._loaded) {
                    sprite._sprite.setTextureRect(sf::IntRect(offset, 0, surf._width, surf._height));
                    sprite._sprite.setPosition(sf::Vector2f(pos._x, pos._y));
                    window._window.draw(sprite._sprite);
                    // std::cerr << "UUID = " << it->first << std::endl;
                    // std::cerr << "SPRITESHEET OFFSET = " << offset << std::endl;
                } else {
                    sprite._rect.setSize(sf::Vector2f(surf._width, surf._height));
                    sprite._rect.setPosition(sf::Vector2f(pos._x, pos._y));
                    window._window.draw(sprite._rect);
                }
            } else if (compSprt.count() != 0 && compPos.count() != 0) {
                rtype::component::Sprite &sprite = _ecm.getComponent<rtype::component::Sprite>(it->first);
                const rtype::component::Position &pos = _ecm.getComponent<rtype::component::Position>(it->first);

                if (sprite._loaded) {
                    // if (ecMan._cMan.getComponentFromType<rtype::component::Scene>().second->_scene == rtype::client::scenes::GAME) {
                    //     std::cerr << "SPRITE POS X = " << pos._x << std::endl;
                    //     std::cerr << "SPRITE POS Y = " << pos._y << std::endl;
                    // }
                    sprite._sprite.setPosition(sf::Vector2f(pos._x, pos._y));
                    window._window.draw(sprite._sprite);
                } else if (compSurf.count() != 0) {
                    const rtype::component::Surface &surf = _ecm.getComponent<rtype::component::Surface>(it->first);
                    sprite._rect.setSize(sf::Vector2f(surf._width, surf._height));
                    sprite._rect.setPosition(sf::Vector2f(pos._x, pos._y));
                    window._window.draw(sprite._rect);
                }
                if ((_ecm._eMan.getSignature(it->first) & Signature(idType)).count() != 0 &&
                    (_ecm._eMan.getSignature(it->first) & Signature(idPosition)).count() != 0 &&
                    (_ecm._eMan.getSignature(it->first) & Signature(idTimerMob)).count() != 0) {
                    rtype::component::Type &type = _ecm.getComponent<rtype::component::Type>(it->first);

                    if (type._type >= rtype::component::componentType::MONSTER1 &&
                        type._type <= rtype::component::componentType::MONSTER4) {
                        rtype::component::Position &pos = _ecm.getComponent<rtype::component::Position>(it->first);
                        rtype::component::TimerMob &timer = _ecm.getComponent<rtype::component::TimerMob>(it->first);

                        // std::cerr << "TIME SUB = " << std::time(nullptr) - timer._timer << std::endl;
                        if (timer._x == pos._x && timer._y == pos._y
                            && std::time(nullptr) - timer._timer >= 2) {
                            lisDelete.push_back(it->first);
                            // continue;
                        } else if (timer._x != pos._x || timer._y != pos._y) {
                            timer._x = pos._x;
                            timer._y = pos._y;
                            timer._timer = std::time(nullptr);
                        }
                    }
                }
            }
            if (compTxt.count() != 0 && compPos.count() != 0) {
                rtype::component::Text &textCpt = _ecm.getComponent<rtype::component::Text>(it->first);

                if (!textCpt._loaded)
                    continue;
                textCpt._text.setPosition(sf::Vector2f(textCpt._pos._x, textCpt._pos._y));
                window._window.draw(textCpt._text);
            }
            it++;//replace by deleting it from the map
        }
    window._window.display();
    for (Entity del : lisDelete) {
        _ecm.deleteEntity(del);
        std::cerr << "DELETEEEEEEEEE" << std::endl;
    }
    try {
        rtype::component::SFMLEvent &sEvent = _ecm.getComponent<rtype::component::SFMLEvent>(_event);
        if (window._window.pollEvent(sEvent._event)) {
            this->updateKeyboardEvent(window);
            this->updateMouseEvent(window);
        }
    } catch (const rtype::component::Exception &e) {
        std::cerr << e.what() << std::endl;
        throw Exception("wrong sfml event", "CLIENT]: [SYSTEM]: [WINDOW]: [UPDATE]");
    }
}

void rtype::system::Window::updateKeyboardEvent(rtype::component::SFMLWindow &window)
{
    auto compSEv = _ecm._eMan.getSignature(_event) & Signature(idSFMLEvent);
    auto compLA = _ecm._eMan.getSignature(_event) & Signature(idListAction);
    auto compKEv = _ecm._eMan.getSignature(_event) & Signature(idKeyboardEvent);

    if (compSEv.count() == 0 || compLA.count() == 0 || compKEv.count() == 0) {
        throw Exception("NO event entity", "CLIENT]: [SYSTEM]: [WINDOW]: [UPDATEKEYBOARDEVENT");
        return;
    }
    try {
        _ecm.getComponent<rtype::component::SFMLEvent>(_event);
        _ecm.getComponent<rtype::component::ListAction>(_event);
        _ecm.getComponent<rtype::component::KeyboardEvent>(_event);
    } catch (const rtype::component::Exception &e) {
        std::cerr << e.what() << std::endl;
        throw Exception("incomplete event entity", "CLIENT]: [SYSTEM]: [WINDOW]: [UPDATEKEYBOARDEVENT]");
    }

    rtype::component::SFMLEvent &sEvent = _ecm.getComponent<rtype::component::SFMLEvent>(_event);
    rtype::component::ListAction &actions = _ecm.getComponent<rtype::component::ListAction>(_event);
    rtype::component::KeyboardEvent &event = _ecm.getComponent<rtype::component::KeyboardEvent>(_event);

    event._keys.clear();
    // if (window._window.pollEvent(sEvent._event)) {
        // std::cout << "event" << std::endl;
    if (sEvent._event.type == sf::Event::Closed) {
        event._keys.emplace_back(rtype::component::QUIT);
        std::cerr << "sf::Event::Closed" << std::endl;
        rtype::client::Mediator &med = rtype::client::Mediator::get();
        med.mediate(_event);
        return;
    }
    for (auto it = actions._list.begin(); it != actions._list.end(); ++it)
        if (sEvent._event.type == sf::Event::KeyReleased
            && sEvent._event.key.code == static_cast<sf::Keyboard::Key>(it->second)) {
            event._keys.emplace_back(it->first);
            rtype::client::Mediator &med = rtype::client::Mediator::get();
            med.mediate(_event);
        }
    // }
}

void rtype::system::Window::updateMouseEvent(rtype::component::SFMLWindow &window)
{
    auto compMev = _ecm._eMan.getSignature(_event) & Signature(idKeyboardEvent);
    auto compSEv = _ecm._eMan.getSignature(_event) & Signature(idSFMLEvent);

    if (compMev.count() == 0 || compSEv.count() == 0) {
        throw Exception("NO event entity", "CLIENT]: [SYSTEM]: [WINDOW]: [UPDATEMOUSEEVENT");
        return;
    }
    try {
        _ecm.getComponent<rtype::component::MouseEvent>(_event);
        _ecm.getComponent<rtype::component::SFMLEvent>(_event);
    } catch (const rtype::component::Exception &e) {
        std::cerr << e.what() << std::endl;
        throw Exception("incomplete event entity", "CLIENT]: [SYSTEM]: [WINDOW]: [UPDATEMOUSEEVENT");
    }
    rtype::component::SFMLEvent &sEvent = _ecm.getComponent<rtype::component::SFMLEvent>(_event);
    rtype::component::MouseEvent &event = _ecm.getComponent<rtype::component::MouseEvent>(_event);

    // if (window._window.pollEvent(sEvent._event)) {
    //     std::cout << "check released" << std::endl;

    if (sEvent._event.type == sf::Event::MouseButtonReleased) {
        // if (sEvent._event.type == sf::Event::MouseButtonPressed) {
        std::cout << "released" << std::endl;
        event._pos.clear();
        auto pos = sf::Mouse::getPosition(window._window);

        if (pos.x > 0 && pos.x < 1920 && pos.y > 0 && pos.y < 1080) {
            event._pos.emplace_back(pos);
            std::cerr << "MOUSE POS : x = " << pos.x << ", y = " << pos.y << std::endl;
            rtype::client::Mediator &med = rtype::client::Mediator::get();
            med.mediate(_event);
        }
    }
    // }
}

void rtype::system::Window::close()
{
    auto comp = _ecm._eMan.getSignature(_window) & Signature(idSFMLWindow);

    if (comp.count() != 0)
        try {
            rtype::component::SFMLWindow &window = _ecm.getComponent<rtype::component::SFMLWindow>(_window);
            if (window._window.isOpen())
                window._window.close();
        } catch (const rtype::component::Exception &e) {
            std::cerr << e.what() << std::endl;
            throw Exception("incomplete window entity", "CLIENT]: [SYSTEM]: [WINDOW]: [CLOSE");
        }
}
