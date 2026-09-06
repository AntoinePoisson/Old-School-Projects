/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** ctrl_c
*/

#include "zappy.h"

void handle_ctr_c(int useless)
{
    server_t *server = get_server();

    if (useless) {
    }
    server->quit_server = true;
}