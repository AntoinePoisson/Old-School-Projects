/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** launch
*/

#include "zappy.h"

value_return_t launch_server(void)
{
    if (init_server() == false)
        return (Err);
    if (loop_server() == Err) {
        destroy_server();
        fprintf(stderr, "Error Server\n");
        return (Err);
    }
    if (destroy_server() == Err)
        return (Err);
    return (Ok);
}