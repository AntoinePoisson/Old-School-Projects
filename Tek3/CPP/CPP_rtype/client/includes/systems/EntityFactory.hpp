/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Display
*/

#ifndef ENTT_FACTORY_HPP
#define ENTT_FACTORY_HPP

#include "components/Exception.hpp"
#include "components/AComponent.hpp"

#include "components/Type.hpp"
#include "components/Display.hpp"
#include "components/Physics.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "singleton/ECManager.hpp"

namespace rtype {
    namespace client {

        struct Button
        {

            double x;
            double y;
            double xTxt;
            double yTxt;

            // enum rtype::component::drawOrder order;

            std::string fontPath;
            std::string textString;
            size_t textSize;

            std::string imagePath;

            int offset;
            int nbSheet;
            std::chrono::milliseconds duration;
            bool loop;

            enum rtype::component::buttonAction action;

            int width;
            int height;

           std::chrono::time_point<std::chrono::system_clock> start_at;

            //sound ?
            // std::string soundPath;
            //loop = false;
        };

        struct Image
        {
            enum rtype::component::drawOrder order;
            std::string path;

            double x;
            double y;
        };

        struct SpriteSheet
        {
            double x;
            double y;

            std::string imagePath;
            
            enum rtype::component::drawOrder order;

            std::chrono::time_point<std::chrono::system_clock> startTime;

            int offset;
            int nbSheet;
            std::chrono::milliseconds duration;
            bool loop;

            int width;
            int height;
        };

        struct Audio
        {
            std::string path;
            bool music;
            bool loop;
            double offset;
            double volume;
        };

        struct Text
        {
            double x;
            double y;

            std::string path;
            std::string str;
            size_t size;
            sf::Color color;
            long style;
        };

        class EntityFactory
        {
            private:
                rtype::entity::ComponentManager &_ecMan = rtype::singleton::ECManager::get();

            public:
                EntityFactory() = default;
                ~EntityFactory() = default;

                void createButton(const struct Button &buttons);
                void createButtons(const std::vector<struct Button> &buttons);
                const Entity createSimpleImage(const struct Image &img);
                const Entity createSpriteSheet(const struct SpriteSheet &img);

                void createAudio(const Audio &aud, Entity &uuid);
                void createText(const Text &txt, Entity &uuid);
                void createImage(const Image &img, Entity &uuid);
                void createSpriteSheet(const SpriteSheet &img, Entity &uuid);
        };
    }
}
#endif
