/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 404
*/

#include "client.h"
#include "logging_client.h"

int cmd_404(char **tab)
{
    if (tab && tab[0])
        client_error_unknown_thread(tab[0]);
    return (0);
}