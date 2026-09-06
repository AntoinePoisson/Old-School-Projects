/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 319
*/

#include "client.h"
#include "logging_client.h"

int cmd_319(char **tab)
{
    if (tab && tab[0] && tab[1] && tab[2] && tab[3])
        client_event_thread_message_received(tab[0], tab[1], tab[2], tab[3]);
    return (0);
}