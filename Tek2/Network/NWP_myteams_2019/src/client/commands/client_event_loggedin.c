/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 300
*/

#include "client.h"
#include "logging_client.h"

int cmd_300(char **tab)
{
    if (tab && tab[0] && tab[1])
        client_event_loggedin(tab[0], tab[1]);
    return (0);
}