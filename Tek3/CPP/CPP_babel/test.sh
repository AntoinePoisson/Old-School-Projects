#!/bin/sh

./babel_server 4201 &
sleep 1
./babel_client 127.0.0.1 4201 &
sleep 1
./babel_client 127.0.0.1 4201 &