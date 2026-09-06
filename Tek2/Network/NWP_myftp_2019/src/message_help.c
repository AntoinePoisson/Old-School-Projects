/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** message_help
*/

#include "server.h"

void display_flag_help(void)
{
    printf("USAGE: ./myftp port path\
        \n       port  is the port number on which the server socket listens\
        \n       path  is the path to the home ");
    printf("directory for the Anonymous user\n");
}