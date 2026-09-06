/*
** EPITECH PROJECT, 2019
** my_alias.c
** File description:
** my_alias
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my_shell.h"

static char *create_new_line(char **arg)
{
    int size = 0;
    char *new = NULL;

    for (int i = 0; arg != NULL && arg[i] != NULL; i++)
        size += (my_strlen(arg[i]) + 1);
    new = my_malloc(size + 1);
    if (new == NULL)
        exit(84);
    size = 0;
    for (int i = 1; arg && arg[i]; i++) {
        for (int a = 0; arg[i][a]; a++, size++)
            new[size] = arg[i][a];
        if (arg[i + 1] != NULL && arg[i] != NULL)
            new[size++] = ' ';
    }
    return (new);
}

static int management_alias(variable_t *var)
{
    char **new_tab = NULL;
    int i = 0;

    if (var->alias == NULL && (var->alias = my_malloc_two_d(1)) == NULL)
        return (84);
    new_tab = my_malloc_two_d(count_arg(var->alias) + 2);
    for (i= 0; var->alias && var->alias[i]; i++)
        new_tab[i] = var->alias[i];
    free(var->alias);
    var->alias = new_tab;
    var->alias[i] = create_new_line(var->arg_two_d);
    return (0);
}

int add_alias(variable_t *var)
{
    int i = 0;

    for (i = 0; var->alias && var->alias[i]; i++)
        if (check_alias(var->alias[i], var->arg_two_d[1]) == 0) {
            free(var->alias[i]);
            var->alias[i] = create_new_line(var->arg_two_d);
            return (0);
        }
    return (management_alias(var));
}

int exec_my_alias(variable_t *var)
{
    if (count_arg(var->arg_two_d) == 1) {
        for (int i = 0; var->alias && var->alias[i]; i++) {
            my_putstr(var->alias[i]);
            my_putchar('\n');
        }
        return (0);
    }
    if (count_arg(var->arg_two_d) == 2) {
        for (int i = 0; var->alias && var->alias[i]; i++)
            if (check_alias(var->alias[i], var->arg_two_d[1]) == 0) {
                my_putstr(var->alias[i]);
                my_putchar('\n');
            return (0);
        }
    }
    if (count_arg(var->arg_two_d) >= 3)
        return (add_alias(var));
    return (0);
}