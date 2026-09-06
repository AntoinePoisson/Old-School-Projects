/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** server.c
*/

#include "zappy.h"

int server_start(int ac, char *av[], char *env[])
{
    int right_arg = check_arg(ac, av, env);

    if (right_arg != Ok)
        return (right_arg == Err ? Err : Ok);
    signal(SIGINT, (void (*)(int))handle_ctr_c);
    signal(SIGPIPE, (void (*)(int))handle_ctr_c);
    if (launch_server() == Err)
        return (Err);
    return (Ok);
}