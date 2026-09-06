#!/bin/bash

if [ -d "./build" ]; then
    rm -frv ./build/
    rm -frv ./CMakeFiles/
    rm -frv ./CMakeCache.txt
    rm -frv ./cmake_install.cmake
    rm -frv ./fclean
    rm -frv ./babel_client
    rm -frv ./babel_server
    rm -fv  ./ressources/database/*.db
    rm -fv  ./*.db
    reset
fi

if (mkdir build && cd build &&
    conan install .. && cmake .. -G "Unix Makefiles" &&
    cmake -build .); then
    cd build ; make -j 4 ; cd -
    echo -e '\033[0;32mSuccess Compile\033[0m'
else
    echo -e '\033[0;31mFails Compile\033[0m'
    rm -fr build
fi