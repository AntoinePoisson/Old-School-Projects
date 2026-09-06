cmake_minimum_required(VERSION 3.11)

project(bomberman)

set(CMAKE_CXX_STANDARD 17)

if(UNIX)

include_directories(
        includes
        includes/LoadingSave
        includes/menu
        includes/Irrlicht
        includes/map
        includes/Audio
        includes/PositionEngine
        includes/Players
        includes/object
        includes/throw
        includes/GameLoop
        includes/EndGame
        libs/Irrlicht/include
        libs/SFML/include
)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/Irrlicht/)

link_libraries(Irrlicht)

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -W -lIrrlicht -lGL -lsfml-audio")

add_executable(bomberman
        src/Main.cpp
        src/loadingSave/LoadingSave.cpp
        src/menu/MainMenu.cpp
        src/menu/SelectMenu.cpp
        src/base/image.cpp
        src/menu/SplashMenu.cpp
        src/menu/ModalMenu.cpp
        src/menu/AMenu.cpp
        src/audio/Audio.cpp
        src/map/Map.cpp
        src/object/Box.cpp
        src/object/Floor.cpp
        src/object/PowerSpeedUp.cpp
        src/object/PowerMoreBomb.cpp
        src/object/PowerPassBox.cpp
        src/object/PowerUpRangeBomb.cpp
        src/object/Bomb.cpp
        src/object/Wall.cpp
        src/object/PlayerModel.cpp
        src/object/WallInside.cpp
        src/object/AObject.cpp
        src/menu/SettingsMenu.cpp
        src/menu/HTPMenu.cpp
        src/throw/Error.cpp
        src/throw/ImageError.cpp
        src/throw/MeshError.cpp
        src/throw/AudioError.cpp
        src/GameLoop/GameLoop.cpp
        src/GameLoop/Particles.cpp
        src/EndGame/EndGame.cpp
        src/irrlicht/Event.cpp
        src/tools/Clock.cpp
)

target_link_libraries(bomberman Irrlicht stdc++fs)

elseif(WIN32)

include_directories(
        includes
        includes/LoadingSave
        includes/menu
        includes/Irrlicht
        includes/map
        includes/Audio
        includes/PositionEngine
        includes/Players
        includes/object
        includes/throw
        includes/GameLoop
        includes/EndGame
        libs/Irrlicht/include
        libs/SFML_Window/include
)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/Irrlicht/)

link_libraries(Irrlicht)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/SFML_Window/)
link_libraries(sfml-audio-d)

add_executable(bomberman
        src/Main.cpp
        src/loadingSave/LoadingSave.cpp
        src/menu/MainMenu.cpp
        src/menu/SelectMenu.cpp
        src/base/image.cpp
        src/menu/SplashMenu.cpp
        src/menu/ModalMenu.cpp
        src/menu/AMenu.cpp
        src/audio/Audio.cpp
        src/map/Map.cpp
        src/object/Box.cpp
        src/object/Floor.cpp
        src/object/PowerSpeedUp.cpp
        src/object/PowerMoreBomb.cpp
        src/object/PowerPassBox.cpp
        src/object/PowerUpRangeBomb.cpp
        src/object/Bomb.cpp
        src/object/Wall.cpp
        src/object/PlayerModel.cpp
        src/object/WallInside.cpp
        src/object/AObject.cpp
        src/menu/SettingsMenu.cpp
        src/menu/HTPMenu.cpp
        src/throw/Error.cpp
        src/GameLoop/GameLoop.cpp
        src/GameLoop/Particles.cpp
        src/EndGame/EndGame.cpp
        src/irrlicht/Event.cpp
        src/tools/Clock.cpp
)

target_link_libraries(bomberman Irrlicht sfml-audio)

endif(UNIX)