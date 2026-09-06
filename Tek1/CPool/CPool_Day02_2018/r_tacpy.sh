#!/bin/bash

export MY_LINE1='42'
export MY_LINE2='24'

cut -d : -f 1 | sed -n '2~2p' | tac * | rev 
