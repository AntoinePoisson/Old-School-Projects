/*
** EPITECH PROJECT, 2020
** save_marche_plus
** File description:
** utiles
*/

#include "server.h"

bool checker_crlf(char *cmd)
{
    int i = 0;

    for (;;) {
        if (cmd[i] == '\r' && cmd[i + 1] == '\n')
            return (true);
        if ((cmd[i] == '\n') || (cmd[i] == '\0') || i > 6000) {
            return (false);
        }
        ++i;
    }
    return (true);
}