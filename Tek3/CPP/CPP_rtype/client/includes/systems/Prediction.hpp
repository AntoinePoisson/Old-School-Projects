#ifndef PREDICTION_SYSTEMS
#define PREDICTION_SYSTEMS

#include "systems/ASystem.hpp"
#include "entities/ComponentManager.hpp" // for ComponentManager
#include "entities/IManager.hpp" // for Signature
#include "components/Physics.hpp"

#include <math.h>
#include <chrono>

namespace rtype {
    namespace system {

        class Prediction: public ASystem
        {
            private:
                rtype::entity::ComponentManager &_ecMan;

            public:
                Prediction(rtype::entity::ComponentManager &ecMan);
                ~Prediction() = default;

                void update(const Entity &e);

                void moveEntities(const std::map<Entity, Signature> &entitiesToHandle);
                void handleNextPosition(const Entity &id);
                void handleDestination(const Entity &id, 
                    const std::chrono::time_point<std::chrono::system_clock> &now = std::chrono::system_clock::now());
        };
    }
}

#endif
