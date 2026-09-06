/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 305
*/

#include "client.h"
#include "logging_client.h"

int cmd_305(char **tab)
{
    if (tab && tab[0] && tab[1])
        client_print_subscribed(tab[0], tab[1]);
    return (0);
}