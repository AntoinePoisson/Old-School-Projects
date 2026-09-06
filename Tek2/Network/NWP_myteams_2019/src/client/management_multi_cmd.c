/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** management_multi_cmd
*/

#include "client.h"

static int calcul_size_cmd(char *cmd);

char **management_multi_cmd(char *cmd)
{
    int size = calcul_size_cmd(cmd);
    char **res = calloc(size + 1, sizeof(char *));
    int size_line = 0;
    int index = 0;

    if (!res || !cmd || !strlen(cmd))
        return (NULL);
    for (int i = 0; size > 0 && cmd[index]; i++, size--,
        size_line = 0, index++) {
        for (int s = index; cmd[s] && cmd[s] != '\n'; s++, size_line++);
        if (size_line <= 0) break;
        if (!(res[i] = calloc(size_line + 10, 1))) return (NULL);
        for (int e = 0; cmd[index] && cmd[index] != '\n' && size_line > 0;
            size_line--, e++) {
            res[i][e] = cmd[index];
            res[i][e + 1] = '\n';
            index++;
        }
    }
    return (res);
}

static int calcul_size_cmd(char *cmd)
{
    int res = 0;

    for (int i = 0; cmd && cmd[i]; i++)
        if (cmd[i] == '\n')
            res++;
    return (res ? res : 1);
}