/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 306
*/

#include "client.h"
#include "logging_client.h"

int cmd_306(char **tab)
{
    if (tab && tab[0] && tab[1])
        client_print_unsubscribed(tab[0], tab[1]);
    return (0);
}