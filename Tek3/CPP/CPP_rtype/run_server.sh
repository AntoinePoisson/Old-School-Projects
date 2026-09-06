#!/bin/bash

if [ ! -d "./build" ];
    then ./build.sh
fi

if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ];
    then cd build && make -j 4 && clear && ./server/bin/r-type_server $1 $2
else
    MSBuild.exe RType_server.sln && cd .. && ./build/bin/r-type_server.exe
fi
