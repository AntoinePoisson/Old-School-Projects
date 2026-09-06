/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** EntityComponent.test
*/

#include <gtest/gtest.h>
#include "entities/ComponentManager.hpp"
#include "components/Physics.hpp"
#include "components/Life.hpp"
#include "singleton/ECManager.hpp"

TEST(ENTITYCOMPONENT_TEST, ENTITY_CREATION)
{
    rtype::entity::ComponentManager ecMan;
    struct rtype::component::Surface s(9, 10);

    const rtype::entity::Entity name = ecMan.createEntity(Signature(64), s);
    struct rtype::component::Surface &res = ecMan.getComponent<rtype::component::Surface>(name);

    res._width = 20;
    res._height = 29;

    struct rtype::component::Surface &res2 = ecMan.getComponent<rtype::component::Surface>(name);

    EXPECT_EQ(res2._width, 20);
    EXPECT_EQ(res2._height, 29);
}

TEST(ENTITYCOMPONENT_TEST, ENTITY_SIGNATURE)
{
    rtype::entity::ComponentManager ecMan;
    struct rtype::component::Surface s(9, 10);
    struct rtype::component::Position pos(9, 10);

    const rtype::entity::Entity name = ecMan.createEntity(Signature(64), s);

    ecMan.addComponent(name, pos);

    auto sig = ecMan._eMan.getSignature(name);

    std::cout << sig.to_ullong() << std::endl;

    EXPECT_TRUE(sig.to_ulong() == 65);
}

TEST(ENTITYCOMPONENT_TEST, SINGLETON_TEST)
{
    auto ecM = rtype::singleton::ECManager::get();

    struct rtype::component::Surface s(9, 10);

    const rtype::entity::Entity name = ecM.createEntity(Signature(64), s);
    struct rtype::component::Surface &res = ecM.getComponent<rtype::component::Surface>(name);

    res._width = 20;
    res._height = 29;

    struct rtype::component::Surface &res2 = ecM.getComponent<rtype::component::Surface>(name);

    EXPECT_EQ(res2._width, 20);
    EXPECT_EQ(res2._height, 29);
}

TEST(ENTITYCOMPONENT_TEST, SINGLETON_TEST2)
{
    auto ecM = rtype::singleton::ECManager::get();

    struct rtype::component::Surface s(9, 10);

    const rtype::entity::Entity name = ecM.createEntity(0);
    
    auto sig = ecM._eMan.getSignature(name);

    EXPECT_EQ(sig.to_ullong(), 0);
}

TEST(ENTITYCOMPONENT_TEST, SHARED_PTR_TEST)
{
    auto ecM = rtype::singleton::ECManager::get();

    // struct rtype::component::Surface s(9, 10);

    std::shared_ptr<rtype::component::Surface> s(new rtype::component::Surface(9, 10));

    const rtype::entity::Entity name = ecM.createEntity(Signature(64), s);
    struct rtype::component::Surface &res = ecM.getComponent<rtype::component::Surface>(name);

    res._width = 20;
    res._height = 29;

    struct rtype::component::Surface &res2 = ecM.getComponent<rtype::component::Surface>(name);

    EXPECT_EQ(res2._width, 20);
    EXPECT_EQ(res2._height, 29);
}

TEST(ENTITYCOMPONENT_TEST, GET_FROM_CPT_TYPE_TEST)
{
    auto ecM = rtype::singleton::ECManager::get();

    std::shared_ptr<rtype::component::Surface> s(new rtype::component::Surface(9, 10));
    std::shared_ptr<rtype::component::Surface> s2(new rtype::component::Surface(10, 10));

    const rtype::entity::Entity name = ecM.createEntity(Signature(64), s);
    const rtype::entity::Entity name2 = ecM.createEntity(Signature(64), s2);

    auto res = ecM._cMan.getComponentsFromType<rtype::component::Surface>();

    EXPECT_EQ(res.size(), 2);

    res[name]->_width = 2;

    EXPECT_EQ(s->_width, 2);
}

TEST(ENTITYCOMPONENT_TEST, GET_FROM_CPT_TYPE_TEST2)
{
    auto ecM = rtype::singleton::ECManager::get();

    std::shared_ptr<rtype::component::Surface> s(new rtype::component::Surface(9, 10));

    const rtype::entity::Entity name = ecM.createEntity(Signature(64), s);

    auto res = ecM._cMan.getComponentFromType<rtype::component::Surface>();

    EXPECT_EQ(res.first, name);
}