/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** check_arg
*/

#include "ftrace.h"

char **set_program(char *binary, char **av)
{
    static char **tmp = NULL;
    int i = 0;

    if (tmp)
        return (tmp);
    for (i = 1; av[i]; i++);
    tmp = malloc(sizeof(char *) * (i - 1 + 1));
    memset(tmp, 0, sizeof(char *) * (i - 1 + 1));
    tmp[0] = binary;
    for (i = 1; av[i + 1]; i++)
        tmp[i] = strdup(av[i + 1]);
    return (tmp);
}