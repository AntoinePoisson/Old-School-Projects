/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 303
*/

#include "client.h"
#include "logging_client.h"

int cmd_303(char **tab)
{
    if (tab && tab[0] && tab[1])
        client_event_private_message_received(tab[0], tab[1]);
    return (0);
}