#!/bin/bash

kill $(sudo netstat -ltnp | grep ':4200' | awk  '{print $7}' | cut -d '/' -f 1)