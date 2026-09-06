cmake_minimum_required(VERSION 3.10)

project(Babel)



    # set CPP version
set(CMAKE_CXX_STANDARD 17)
    # handle Qt Projet
#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5 REQUIRED
    Core
    Gui
    Widgets
    Network
)


if(UNIX)
    add_definitions(-Wall -Wextra -g3 -pedantic -Wno-deprecated-copy -lboost_serialization)
elseif(WIN32)
else()
endif(UNIX)



    # Handle Conan
include(build/conanbuildinfo.cmake)
conan_basic_setup()



    # Header
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/common
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/client
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/client/Exception
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/server
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/server/Exception
)

set(INCLUDES_QT
    includes/client/SocketUDP.h
    includes/client/SocketTCP.h
    includes/client/ISocket.h
    includes/client/DataClient.h
    includes/client/IData.h
    includes/client/INetwork.h
    includes/client/ClientNetwork.h
    includes/client/ClientUi.h
    includes/client/test.h
    includes/client/widge.h
)


    # Sources
set(SERVER
    src/server/Main.cpp
    src/server/Server.cpp
    src/server/Client.cpp
    src/server/Exception/HandleCtrlC.cpp
    src/server/Exception/QuitServer.cpp
    src/server/Exception/FataleErrorSql.cpp
    src/server/Exception/ErrorSql.cpp
    src/server/HandleBoostNetwork.cpp
    src/server/QueuePacket.cpp
    src/server/Package.cpp
    src/server/HandleSqlite.cpp
    src/server/DataBase.cpp
    src/server/TableElement.cpp
    src/server/HandleCommande.cpp
)

set(CLIENT
    src/client/SocketUDP.cpp
    src/client/SocketTCP.cpp
    src/client/DataClient.cpp
    src/client/Main.cpp
    src/client/ClientUi.cpp
    src/client/ClientNetwork.cpp
    src/client/Exception/ErrorPortAudio.cpp
    src/client/Exception/ErrorAOpus.cpp
    src/client/Exception/CantUsePA.cpp
    src/client/AOpus.cpp
    src/client/APortAudio.cpp
    src/client/HandlerAudio.cpp
)

set(COMMON
    src/common/AException.cpp
    src/common/TransfertData.cpp
)



    # Create Exec
add_executable(babel_client
    ${CLIENT}
    ${COMMON}
    ${INCLUDES_QT}
)

add_executable(babel_server
    ${SERVER}
    ${COMMON}
)



    # Link lib
target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets Qt5::Network Qt5::Gui -lpthread -lportaudio)
target_link_libraries(babel_server ${CONAN_LIBS} -lboost_serialization)
