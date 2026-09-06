#!/bin/bash

if [ -d "./build" ]; then
    rm -frv ./build/
    rm -frv ./CMakeFiles/
    rm -frv ./CMakeCache.txt
    rm -frv ./cmake_install.cmake
    rm -frv ./fclean
    rm -frv ./r-type_server
    rm -frv ./r-type_client
    rm -frv ./vgcore.*
    rm -frv ./common/CMakeFiles
    rm -frv ./server/CMakeFiles
    rm -frv ./client/CMakeFiles
    # reset
fi

if (mkdir build && cd build &&
    conan install .. --build=missing); then
    if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]
        then cd build && cmake .. -G "Unix Makefiles" && cmake -build . && make -j 4
    else
        cd build && cmake .. -G "Visual Studio 16 2019" && cmake -build . && MSBuild.exe RType.sln
    fi
    echo -e '\n ~ \033[0;32mSuccess Compile\033[0m ~'
else
    echo -e '\n\033[0;31m /!\\ Failure Compile /!\\\033[0m'
    rm -fr build
fi
