#!/bin/bash

cd tests && rm -rf build && mkdir build && cd build && conan install .. --build=missing
# ./clear.sh ; cd tests && rm -rf build && mkdir build && cd build && conan install .. --build=missing

if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]
    then cmake .. -G "Unix Makefiles" && cmake -build . && make -j 4 && ./bin/rtype_test && cd ../../ && gcovr
else
    cmake .. -G "Visual Studio 16 2019" && cmake -build . && MSBuild.exe Babel.sln && ./bin/babel_test
fi
