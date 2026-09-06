/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 401
*/

#include "client.h"
#include "logging_client.h"

int cmd_401(char **tab)
{
    if (tab && tab[0])
        client_error_unknown_user(tab[0]);
    return (0);
}