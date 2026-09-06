project(rtype_test)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

SET(GCC_COMPILE_FLAGS "-g3 --coverage")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

conan_basic_setup()

#source from server

## -- COMMON --
set(PATH_COMMON ../common)
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
set(PATH_CLIENT ../client)
set(CLIENT_INCLUDES ${PATH_CLIENT}/includes)
#set(CLIENT_FLAGS -Wall -Wextra -g3 -pedantic -Wno-deprecated-copy)
set(CLIENT_SOURCES
    ${PATH_CLIENT}/sources/SystemWindow.cpp
    ${PATH_CLIENT}/sources/SystemAudio.cpp
    ${PATH_CLIENT}/sources/SystemPrediction.cpp
    ${PATH_CLIENT}/sources/SystemNetworkClient.cpp
    ${PATH_CLIENT}/sources/MediatorClient.cpp
    #${PATH_CLIENT}/sources/Mediator.cpp
    ${PATH_CLIENT}/sources/SceneManager.cpp
    ${PATH_CLIENT}/sources/SubSystemsClient.cpp
    ${PATH_CLIENT}/sources/NetworkTCP.cpp
    ${PATH_CLIENT}/sources/NetworkUDP.cpp
    ${PATH_CLIENT}/sources/EntityFactory.cpp
)


## -- SERVER --
set(PATH_SERVER ../server)
set(SERVER_INCLUDES ${PATH_SERVER}/includes)
# set(SERVER_FLAGS -Wall -Wextra -g3 -fPIC -pedantic -Wno-deprecated-copy)
set(SERVER_SOURCES
    # ${PATH_SERVER}/sources/SystemNetworkServer.cpp
    ${PATH_SERVER}/sources/SystemNetwork.cpp
    ${PATH_SERVER}/sources/SubSystems.cpp
)

#test src
set(TEST_SRC
    Main.cpp
    client/System.test.cpp
    client/Network.test.cpp
    common/EntityComponent.test.cpp
)

include_directories(${CMAKE_INCLUDE_PATH}
                ../common/includes
                ../client/includes
                ../server/includes
)

#add_executable(rtype_test ${COMMON_SOURCES} ${TEST_SRC} ${SERVER_SOURCES})
add_executable(rtype_test ${COMMON_SOURCES} ${TEST_SRC} ${CLIENT_SOURCES})

message(STATUS "${CONAN_LIBS}")

target_link_libraries(rtype_test ${CONAN_LIBS} gtest gtest_main pthread)
