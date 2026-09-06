#!/bin/bash

if [ ! -d "./build" ];
    then ./build.sh
fi

if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]
    then cd build && make -j 4 &&
        [[ $# = 0 ]] && ./client/bin/r-type_client "localhost" "8589" || ./client/bin/r-type_client $1 $2
else
    MSBuild.exe RType_client.sln && ./bin/r-type_client.exe
fi
