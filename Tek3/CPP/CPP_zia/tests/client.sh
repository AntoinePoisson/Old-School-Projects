#!/bin/bash

if [[ "$1" == "-h" || "$1" == "-help" || "$1" == "--help" ]];
then
    echo -e "Bash Script:"
    echo -e "USAGE:"
    echo -e "   ./client.sh IP_SERVER PORT_SERVER  -> If necessary Build and Run Project"
    exit 0
fi

if [ $# -ne 2 ]
  then
    echo "Wrong number of Argument"
    echo "Please check: ./client.sh -h"
    exit 0
fi

clear

argIp="$1"

argPort="$2"

if [ -f "./tests/request.txt" ]; then
    echo -e "\033[0;34m (ip:\033[0m \"$argIp\" \033[0;34m| port:\033[0m \"$argPort\"\033[0;34m)\033[0m"
    echo -e "\033[0;34m \e[1m->\033[0m\033[0;34m Send \e[1mRequest\033[0m\033[0;34m From Client : \033[0m"
    cat -e ./tests/request.txt
    echo -e "\n\033[0;34m \e[1m<-\033[0m\033[0;34m Receive \e[1mResponse\033[0m\033[0;34m From Server : \033[0m"
    echo -ne "$(<./tests/request.txt)" | nc $argIp $argPort -w 3
    exit 0
fi

if [ -f "./request.txt" ]; then
    echo -e "\033[0;34m (Ip: \033[0m \"$argIp\" \033[0;34m| Port: \033[0m \"$argPort\"\033[0;34m)\033[0m"
    echo -e "\033[0;34m -> Request From Client : \033[0m"
    cat -e ./request.txt
    echo -e "\n\033[0;34m <- Response From Server : \033[0m"
    echo -ne "$(<./request.txt)" | nc $argIp $argPort -w 3
    exit 0
fi

echo -e '\n\033[0;31m  /!\\ File request.txt not found /!\\\033[0m'
