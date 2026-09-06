/*
** EPITECH PROJECT, 2019
** exec_backticks.c
** File description:
** exec_backticks
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

int exec_backticks(variable_t *var, char *arg, int fd)
{
    int result = 0;
    int save = dup(1);

    dup2(fd, 1);
    var->arg = find_backslash(arg);
    result = is_operator(var);
    dup2(save, 1);
    return (result);
}
