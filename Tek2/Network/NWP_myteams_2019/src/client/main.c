/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** new_client
*/

#include "client.h"

int end(int value)
{
    static int ref = 0;

    ref += value;
    return ref;
}

int main(int ac, const char **av)
{
    int val = check_args(av[1], ac);

    if (val == Ok)
        return my_teams_client(av[1], av[2]);
    return (val);
}
