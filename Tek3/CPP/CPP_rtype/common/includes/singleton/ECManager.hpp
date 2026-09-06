#ifndef SINGLETON_ECM
#define SINGLETON_ECM

#include "entities/ComponentManager.hpp" // for ComponentManager

namespace rtype {
    namespace singleton {
        class ECManager {
            public:
            static rtype::entity::ComponentManager &get();
        };
    }
}

#endif