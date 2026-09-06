/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System NetworkClient
*/

#ifndef CLIENTSYSTEMNETWORKCLIENT_HPP_
#define CLIENTSYSTEMNETWORKCLIENT_HPP_

#include "singleton/ECManager.hpp"
#include "Network.hpp"

#include "systems/ASystem.hpp"
#include "systems/ISubSystem.hpp"
#include "systems/EntityFactory.hpp"

#include "entities/ComponentManager.hpp"

#include "components/Type.hpp"
#include "components/Network.hpp"



namespace rtype {
    namespace system {

        class StartNetworkClient : public ASystem
        {
            public:
                StartNetworkClient() = default;
                virtual ~StartNetworkClient() = default;

                void update(const Entity &id) final;
        };

        class CloseNetworkClient : public ASystem
        {
            public:
                CloseNetworkClient() = default;
                virtual ~CloseNetworkClient() = default;

                void update(const Entity &id) final;
        };
    }

    namespace network {

        int getRemainingSize(int header);
        int paquetParser(const std::string &buffer);
    }

    namespace subsystem {

        unsigned long getSizeComp(unsigned long &bitset);
        std::shared_ptr<rtype::component::AComponent> getComp(unsigned long &bitset, size_t &index, const std::string &msg);

        class InterpretNetworkClient: public system::ISubSystem
        {
            std::map<rtype::component::componentType, rtype::client::Image> _imageFile;
            std::map<rtype::component::componentType, rtype::client::SpriteSheet> _spriteSheetFile;
            std::map<rtype::component::componentType, rtype::client::Text> _textFile;
            std::map<rtype::component::componentType, rtype::client::Audio> _musicFile;
            std::string _font;

            public:
                InterpretNetworkClient();
                virtual ~InterpretNetworkClient() = default;

                void update(const Entity &id);
                void handleEndPointMssg(const std::string &msg);
                void handleEndMssg(const std::string &msg);
                void handleDeleteCptMssg(const std::string &msg);
                void handleRefreshMssg(const std::string &msg);
                void updateImageTextSound(Entity &entity, rtype::component::componentType type);
                int deleteComponentsHelper(const Entity &id, const Signature &sig);
                std::map<rtype::idBitset, std::shared_ptr<rtype::component::AComponent>> getComponentFromMessage(const std::string &msg, unsigned long bitset);
        };

    }

}

#endif /* !CLIENTSYSTEMNETWORKCLIENT_HPP_ */
