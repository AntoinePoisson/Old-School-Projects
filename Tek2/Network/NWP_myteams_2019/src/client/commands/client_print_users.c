/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 309
*/

#include <string.h>
#include "client.h"
#include "logging_client.h"

int cmd_309(char **tab)
{
    if (tab && tab[0] && tab[1] && tab[2])
        client_print_users(tab[0], tab[1], atoi(tab[2]));
    return (0);
}