/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 320
*/

#include "client.h"
#include "logging_client.h"

int cmd_320(char **tab)
{
    if (tab && tab[0] && tab[1] && tab[2] && tab[3])
        client_print_reply_created(tab[0], tab[1], (time_t)atoi(tab[2]),
            tab[3]);
    return (0);
}