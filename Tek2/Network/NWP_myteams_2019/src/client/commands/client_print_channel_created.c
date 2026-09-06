/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 312
*/

#include "client.h"
#include "logging_client.h"

int cmd_312(char **tab)
{
    if (tab && tab[0] && tab[1] && tab[2])
        client_print_channel_created(tab[0], tab[1], tab[2]);
    return (0);
}