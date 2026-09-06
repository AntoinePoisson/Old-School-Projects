/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 321
*/

#include "client.h"
#include "logging_client.h"

int cmd_321(char **tab)
{
    if (tab && tab[0] && tab[1] && tab[2] && tab[3])
        client_thread_print_replies(tab[0], tab[1], (time_t)atoi(tab[2]),
        tab[3]);
    return (0);
}