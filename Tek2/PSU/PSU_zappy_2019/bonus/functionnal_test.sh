#!/bin/sh

./zappy_server -p 4201 -x 10 -y 10 -n name1 name2 -c 2 -f 10 &
sleep 1
./zappy_ai -p 4201 -n name1 &
sleep 0.3
./zappy_ai -p 4201 -n name2 &
