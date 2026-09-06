#include <gtest/gtest.h>
#include "entities/ComponentManager.hpp"
#include "systems/Prediction.hpp"
#include "components/Physics.hpp"

rtype::component::Position testPredictionHelper(rtype::component::Position pos,
                    rtype::component::Destination dest, const std::time_t &offset)
{
    rtype::entity::ComponentManager eM;
    Signature sig(66611); //1, 2, 16, 32, 1024, 65536
    // rtype::component::Position pos(1, 1);
    // rtype::component::Destination dest(9, 4);
    rtype::component::StartingTime now(std::chrono::system_clock::now());
    rtype::component::StartingTime st_time(std::chrono::system_clock::now());
    rtype::component::Speed speed(0.0035); //usually is bellow the sound's speed which is around 360m/s
    rtype::component::Damage dm(9.0, rtype::component::DamageType::PHYSICAL);
    double initial_distance = sqrt(pow(pos._x - dest._x, 2) + pow(pos._y - dest._y, 2));
    rtype::component::StartCriteria sCriteria(pos, dest);

    auto id = eM.createEntity(sig, pos, dest, st_time, speed, dm, sCriteria);
    rtype::system::Prediction sysP(eM);

    // now._startAt += std::chrono::seconds(offset);
    // auto pred = 
    sysP.handleDestination(id, now._startAt + std::chrono::seconds(offset));
    return eM.getComponent<rtype::component::Position>(id);
}

//up right angle
TEST(SYSTEM_PREDICTION, BULLET_MOVEMENT_RIGHT_UP)
{
    rtype::component::Position pos(1, 1);
    rtype::component::Destination dest(9, 4);

    auto resPos = testPredictionHelper(pos, dest, 1);
    // EXPECT_EQ(resPos._x, 4.27);
    // EXPECT_EQ(resPos._y, 2.22);

    EXPECT_NE(round(resPos._x), 4);
    EXPECT_NE(round(resPos._y), 2);
}

//up left
TEST(SYSTEM_PREDICTION, BULLET_MOVEMENT_LEFT_UP)
{
    rtype::component::Position pos(-1, 1);
    rtype::component::Destination dest(-9, 4);

    auto resPos = testPredictionHelper(pos, dest, 1);
    // EXPECT_EQ(resPos._x, 4.27);
    // EXPECT_EQ(resPos._y, 2.22);

    EXPECT_NE(round(resPos._x), -4);
    EXPECT_NE(round(resPos._y), 2);
}

//down left
TEST(SYSTEM_PREDICTION, BULLET_MOVEMENT_LEFT_DOWN)
{
    rtype::component::Position pos(-1, -1);
    rtype::component::Destination dest(-9, -4);

    auto resPos = testPredictionHelper(pos, dest, 1);
    // EXPECT_EQ(resPos._x, 4.27);
    // EXPECT_EQ(resPos._y, 2.22);

    EXPECT_NE(round(resPos._x), -4);
    EXPECT_NE(round(resPos._y), -2);
}

//down right
TEST(SYSTEM_PREDICTION, BULLET_MOVEMENT_RD_AND_VERTICAL_MOV)
{
    rtype::component::Position pos(1, -4);
    rtype::component::Destination dest(1, -12);

    auto resPos = testPredictionHelper(pos, dest, 1);
    // EXPECT_EQ(resPos._x, 4.27);
    // EXPECT_EQ(resPos._y, 2.22);

    EXPECT_NE(round(resPos._x), 0);
    EXPECT_NE(round(resPos._y), 0);
}
