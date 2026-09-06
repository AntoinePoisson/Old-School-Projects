/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** display
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

int display_env(variable_t const *var)
{
    if (var->env == NULL)
        return (0);
    for (int i = 0; var->env[i] != NULL; i++) {
        write(1, var->env[i], my_strlen(var->env[i]));
        write(1, "\n", 1);
    }
    return (0);
}

void display(void)
{
    char *buf = malloc(sizeof(char) * 9999);

    if (isatty(0) == 0)
        return;
    if (buf != NULL && getcwd(buf, sizeof(char) * 9999) != NULL)
        my_printf("[%s] ", buf);
    else
        my_printf("[Error] ");
    my_putstr("$> ");
    free(buf);
}
