cmake_minimum_required(VERSION 3.10)
project(Zia)

## Setup
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
set(RUNTIME_OUTPUT_DIRECTORY build)

## Path Variable
set(PATH_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/includes/)
set(PATH_SRC ${CMAKE_CURRENT_SOURCE_DIR}/sources/)
set(PATH_TEST ${CMAKE_CURRENT_SOURCE_DIR}/tests/)

######################################
## All Path to CPP Header files
# INCLUDES:
include_directories(
    ${PATH_INCLUDES}
    sources/
)


## All CPP Sources files
# SOURCES:
set(MAIN ${PATH_SRC}/Main.cpp)
set(SOURCES
    ${PATH_SRC}/api/config/Conf.cpp
    ${PATH_SRC}/api/config/Json.cpp
    ${PATH_SRC}/api/context/Context.cpp
    ${PATH_SRC}/api/context/Request.cpp
    ${PATH_SRC}/api/context/Response.cpp
    ${PATH_SRC}/api/io/Connection.cpp
    ${PATH_SRC}/api/modules/Logger.cpp
    ${PATH_SRC}/client/Client.cpp
    ${PATH_SRC}/core/Core.cpp
    ${PATH_SRC}/exception/AException.cpp
    ${PATH_SRC}/loader/ManagerSharedObject.cpp
    ${PATH_SRC}/pipeline/PipelineHandlers.cpp
    ${PATH_SRC}/server/ServerNetwork.cpp
    ${PATH_SRC}/tools/HandleResponse.cpp
    ${PATH_SRC}/fileWatcher/FileWatcher.cpp
)
######################################


if(UNIX) ## Linux
    add_definitions(-Wall -Wextra -pedantic -Wno-deprecated-copy -g)
    set(FLAGS -Wall -Wextra -g3 -fPIC -pedantic -Wno-deprecated-copy -ldl)
    set(FLAGS_TEST -Wall -Wextra -fPIC -pedantic -Wno-deprecated-copy -ldl gtest gtest_main --coverage)

    ## Setup Conan
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()

    ## Generate Executable
    add_executable(zia ${MAIN} ${SOURCES})

    ## Linking Library
    target_link_libraries(zia ${CONAN_LIBS} ${FLAGS})

    ## Generer Modules
    add_subdirectory(modules)

    ######################################
    ## Unit Tests

    # Sources of Tests
    set(SOURCES_TESTS
        ${PATH_TEST}/Main.cpp
    )

    # Flags
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

    # Testing Up
    enable_testing()

    # Generate Binary
    add_executable(zia_tests EXCLUDE_FROM_ALL ${SOURCES_TESTS} ${SOURCES})

    # Linking Binary and Libs
    target_link_libraries(zia_tests ${CONAN_LIBS} ${FLAGS_TEST})

    # Addings CMake Rules for only compile tests
    add_custom_target(tests_run)
    add_dependencies(tests_run zia_tests)
    ######################################


else() ## Windows

    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()

    ## Generate Executable
    add_executable(zia ${MAIN} ${SOURCES})

    ## Linking Library
    target_link_libraries(zia ${CONAN_LIBS})

    ## Generer Modules
    add_subdirectory(modules)

endif(UNIX)


