cmake_minimum_required(VERSION 3.10)

project(RType)

set(CMAKE_CXX_STANDARD 17)

if(UNIX)
else()
endif(UNIX)


## -- COMMON --
set(PATH_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/common)
set(COMMON_INCLUDES ${PATH_COMMON}/includes)
set(COMMON_SOURCES
    ${PATH_COMMON}/sources/ComponentAManager.cpp
    ${PATH_COMMON}/sources/EntityComponentManager.cpp
    ${PATH_COMMON}/sources/EntityAManager.cpp
    ${PATH_COMMON}/sources/SystemAManager.cpp
    ${PATH_COMMON}/sources/Exception.cpp
    ${PATH_COMMON}/sources/SingletonECManager.cpp
)


## -- CLIENT --
set(PATH_CLIENT ${CMAKE_CURRENT_SOURCE_DIR}/client)
set(CLIENT_INCLUDES ${PATH_CLIENT}/includes)
set(CLIENT_FLAGS "-g3" )
set(CLIENT_SOURCES
    ${PATH_CLIENT}/sources/Main.cpp
    ${PATH_CLIENT}/sources/SystemWindow.cpp
    ${PATH_CLIENT}/sources/SystemAudio.cpp
    ${PATH_CLIENT}/sources/SystemPrediction.cpp
    ${PATH_CLIENT}/sources/MediatorClient.cpp
#    ${PATH_CLIENT}/sources/Mediator.cpp
    ${PATH_CLIENT}/sources/SystemNetworkClient.cpp
    ${PATH_CLIENT}/sources/SceneManager.cpp
    ${PATH_CLIENT}/sources/NetworkTCP.cpp
    ${PATH_CLIENT}/sources/SubSystemsClient.cpp
    ${PATH_CLIENT}/sources/NetworkUDP.cpp
    ${PATH_CLIENT}/sources/EntityFactory.cpp
)


## -- SERVER --
set(PATH_SERVER ${CMAKE_CURRENT_SOURCE_DIR}/server)
set(SERVER_INCLUDES ${PATH_SERVER}/includes)
set(SERVER_FLAGS -Wall -Wextra -g3 -fPIC -pedantic -Wno-deprecated-copy)
set(PLANEMOB_SERVER
    ${PATH_SERVER}/libMobs/sources/PlaneMob.cpp
    ${PATH_COMMON}/sources/Exception.cpp
    ${PATH_COMMON}/sources/ComponentAManager.cpp
    ${PATH_COMMON}/sources/EntityComponentManager.cpp
    ${PATH_COMMON}/sources/EntityAManager.cpp
    ${PATH_COMMON}/sources/SystemAManager.cpp
    ${PATH_COMMON}/sources/SingletonECManager.cpp
)
set(OTHERMOB_SERVER
    ${PATH_SERVER}/libMobs/sources/OtherMob.cpp
    ${PATH_COMMON}/sources/Exception.cpp
    ${PATH_COMMON}/sources/ComponentAManager.cpp
    ${PATH_COMMON}/sources/EntityComponentManager.cpp
    ${PATH_COMMON}/sources/EntityAManager.cpp
    ${PATH_COMMON}/sources/SystemAManager.cpp
    ${PATH_COMMON}/sources/SingletonECManager.cpp
)
set(SERVER_SOURCES
    ${PATH_SERVER}/sources/Main.cpp
    ${PATH_SERVER}/sources/SystemNetworkServer.cpp
    ${PATH_SERVER}/sources/Mediator.cpp
    ${PATH_SERVER}/sources/SystemNetwork.cpp
    ${PATH_SERVER}/sources/SubSystems.cpp
    ${PATH_SERVER}/sources/SystemPlayerAlive.cpp
    ${PATH_SERVER}/sources/SystemNetworkServer.cpp
    ${PATH_SERVER}/sources/GameEngine.cpp
    ${PATH_SERVER}/sources/SystemMovementPlayerServer.cpp
    ${PATH_SERVER}/sources/SystemShootServer.cpp
    ${PATH_SERVER}/sources/SystemCheckCollisionServer.cpp
    ${PATH_SERVER}/sources/SystemInterpretCollisionServer.cpp
    ${PATH_SERVER}/sources/SystemCheckEndGame.cpp
    ${PATH_SERVER}/sources/SystemLoadMethodeMob.cpp
    ${PATH_SERVER}/sources/SystemMobServer.cpp
    ${PATH_SERVER}/sources/SystemTimerGame.cpp
    ${PATH_SERVER}/sources/SubSystemServer.cpp
    ${PATH_SERVER}/sources/Server.cpp
    ${PATH_SERVER}/sources/Client.cpp
)


add_subdirectory(server)
add_subdirectory(client)
