#!/bin/bash
blih -u antoine.poisson@epitech.eu repository create $1
blih -u antoine.poisson@epitech.eu repository setacl $1 ramassage-tek r
blih -u antoine.poisson@epitech.eu repository getacl $1
