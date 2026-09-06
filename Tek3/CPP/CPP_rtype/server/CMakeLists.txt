cmake_minimum_required(VERSION 3.10)
project(RType_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
set(RUNTIME_OUTPUT_DIRECTORY build)

if(UNIX)
    # set(CMAKE_CXX_FLAGS ${SERVER_FLAGS})
else()
    # set(CMAKE_C_COMPILER C:/MinGW/bin/gcc)
    # set(CMAKE_CXX_COMPILER C:/MinGW/bin/g++)
endif(UNIX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(
    ${COMMON_INCLUDES}
    ${SERVER_INCLUDES}
    ${CLIENT_INCLUDES}
    ${PATH_SERVER}
)

add_executable(r-type_server ${SERVER_SOURCES} ${COMMON_SOURCES})

add_library(PlaneMob SHARED ${PLANEMOB_SERVER})

# add_library(OtherMob SHARED ${OTHERMOB_SERVER})

target_link_libraries(r-type_server ${CONAN_LIBS} ${SERVER_FLAGS})
target_link_libraries(r-type_server ${CONAN_LIBS} ${SERVER_FLAGS} ${PlaneMob})
# target_link_libraries(r-type_server ${CONAN_LIBS} ${SERVER_FLAGS} ${OtherMob})
