/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** commands_function_extension
*/

#include "zappy.h"

static char *direction_look_eject_norme(int look, client_t *cli);

char *direction_look_eject(int look, client_t *cli)
{
    if (look == Up && cli->look == Up)
        return ("5");
    if (look == Up && cli->look == Down)
        return ("1");
    if (look == Up && cli->look == Left)
        return ("3");
    if (look == Up && cli->look == Right)
        return ("7");
    if (look == Down && cli->look == Up)
        return ("1");
    if (look == Down && cli->look == Down)
        return ("5");
    if (look == Down && cli->look == Left)
        return ("7");
    if (look == Down && cli->look == Right)
        return ("3");
    if (look == Left && cli->look == Up)
        return ("7");
    return (direction_look_eject_norme(look, cli));
}

static char *direction_look_eject_norme(int look, client_t *cli)
{
    if (look == Left && cli->look == Down)
        return ("3");
    if (look == Left && cli->look == Left)
        return ("5");
    if (look == Left && cli->look == Right)
        return ("1");
    if (look == Right && cli->look == Up)
        return ("3");
    if (look == Right && cli->look == Down)
        return ("7");
    if (look == Right && cli->look == Left)
        return ("1");
    if (look == Right && cli->look == Right)
        return ("5");
    return ("1");
}