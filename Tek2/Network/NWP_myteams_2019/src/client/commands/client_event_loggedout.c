/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 301
*/

#include "client.h"
#include "logging_client.h"

int cmd_301(char **tab)
{
    if (tab && tab[0] && tab[1])
        client_event_loggedout(tab[0], tab[1]);
    return (0);
}