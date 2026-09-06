#!/bin/bash

mv Makefile ./ressources/
mkdir ./build
cd ./build/
cmake ../
make
mv ./bomberman ../
cd ../
cp libs/Irrlicht/Irrlicht.dll build/
./bomberman
rm -f Makefile
mv ./ressources/Makefile .