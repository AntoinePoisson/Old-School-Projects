/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** 302
*/

#include "client.h"
#include "logging_client.h"

int cmd_302(char **tab)
{
    int status = 0;

    if (tab && tab[0] && tab[1] && tab[2]) {
        status = atoi(tab[2]);
        client_print_user(tab[0], tab[1], status);
    }
    return (0);
}