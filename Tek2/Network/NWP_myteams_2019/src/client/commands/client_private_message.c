/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 304
*/

#include "client.h"
#include "logging_client.h"

int cmd_304(char **tab)
{
    if (tab && tab[0] && tab[1] && tab[2])
        client_private_message_print_messages(tab[0], (time_t)atoi(tab[1]),
            tab[2]);
    return (0);
}