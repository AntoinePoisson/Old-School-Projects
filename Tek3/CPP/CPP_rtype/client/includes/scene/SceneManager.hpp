#ifndef SCENE_MANAGER_HPP_
#define SCENE_MANAGER_HPP_

#include "systems/ASystem.hpp"
// #include "entities/ComponentManager.hpp"
#include "singleton/ECManager.hpp"
#include "scene/EnumScene.hpp"
#include "systems/ASystem.hpp"
#include "systems/Window.hpp"
#include "systems/Audio.hpp"
#include "systems/Prediction.hpp"
#include "systems/NetworkTCP.hpp"
#include "systems/NetworkUDP.hpp"
#include "SubSystemsClient.hpp"
#include "systems/NetworkClient.hpp"
#include "systems/EntityFactory.hpp"

#include "components/Unremovable.hpp"
#include "MediatorClient.hpp"

#include <algorithm> 

namespace rtype {
    // namespace oop {
    namespace client {
            // class EnityFactory {
                /**/
            // }

        enum NetworkWriterIndex {
            TCP = 0,
            UDP = 1
        };

        using SystemList = std::vector<std::shared_ptr<rtype::system::ASystem>> ;
        using SubSystemList = std::vector<std::shared_ptr<rtype::system::ISubSystem>> ;
        // using ptr_system = std::shared_ptr<rtype::system::ASystem>;

        class SceneManager {
            private:
                rtype::entity::ComponentManager &_ecMan = rtype::singleton::ECManager::get();
                rtype::client::EntityFactory _eFac;

                std::shared_ptr<rtype::component::Unremovable> _preserved_entities;
                
                Entity _sceneId;
                enum scenes _currentScene;

                SystemList _sysListGame;
                SystemList _sysListMenu;

                SubSystemList _subSysList;

            public:
                SceneManager(const std::string &addr = "127.0.0.1", const short &port = 4242); //create a scene entity that pointer toward the menu
                ~SceneManager();
                void loop();

                enum scenes getCurrentScene();
                
                void setupSceneSystemLists();

                void clearSceneEntities();

                SystemList &getSystems();

                void applySceneEntities();
            //check if the scene has changed, and 
            //if its the case, it will erase all the system, and entities related to this scene
            // addSystem() //add sys
            // addEntity() //
        };
    }
}
#endif