#include "singleton/ECManager.hpp"

rtype::entity::ComponentManager &rtype::singleton::ECManager::get()
{
    static rtype::entity::ComponentManager ec;
    return ec;
}