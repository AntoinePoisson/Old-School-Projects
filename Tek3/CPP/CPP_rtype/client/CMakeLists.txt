cmake_minimum_required(VERSION 3.10)
project(RType_client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
set(RUNTIME_OUTPUT_DIRECTORY build)


if(UNIX)
    SET(CMAKE_CXX_FLAGS  "${CLIENT_FLAGS}")
else()
    # set(CMAKE_C_COMPILER C:/MinGW/bin/gcc)
    # set(CMAKE_CXX_COMPILER C:/MinGW/bin/g++)
endif(UNIX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(
    ${COMMON_INCLUDES}
    ${CLIENT_INCLUDES}
    ${SERVER_INCLUDES}
)

add_executable(r-type_client ${CLIENT_SOURCES} ${COMMON_SOURCES})

target_link_libraries(r-type_client ${CONAN_LIBS})
